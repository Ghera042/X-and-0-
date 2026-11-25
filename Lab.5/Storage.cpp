#include "Storage.hpp"

#ifdef _MSC_VER
#include <winsqlite/winsqlite3.h>
#pragma comment(lib, "winsqlite3.lib")
#else
#include <sqlite3.h>
#endif

Storage::Storage(const std::string& file) : db_(nullptr, sqlite3_close) {
    sqlite3* db = nullptr;
    sqlite3_open(file.c_str(), &db);
    db_.reset(db);

    sqlite3_exec(db_.get(),
                 "CREATE TABLE IF NOT EXISTS results (id INTEGER PRIMARY KEY, mode INTEGER, winner TEXT);",
                 nullptr, nullptr, nullptr);
}

void Storage::saveResult(int mode, char winner) {
    std::string who(1, winner == ' ' ? '-' : winner);

    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(db_.get(), "INSERT INTO results (mode, winner) VALUES (?, ?);", -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, mode);
    sqlite3_bind_text(stmt, 2, who.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

Stats Storage::loadStats() const {
    Stats stats{ 0, 0, 0 };

    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(db_.get(), "SELECT winner, COUNT(*) FROM results GROUP BY winner;", -1, &stmt, nullptr);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string who = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        int count = sqlite3_column_int(stmt, 1);
        if (who == "X")
            stats.xWins = count;
        else if (who == "0")
            stats.oWins = count;
        else
            stats.draws = count;
    }
    sqlite3_finalize(stmt);
    return stats;
}
