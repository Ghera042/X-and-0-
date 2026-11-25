#pragma once

#include <memory>
#include <string>

struct sqlite3;

struct Stats {
    int xWins;
    int oWins;
    int draws;
};

class Storage {
public:
    explicit Storage(const std::string& file);

    void saveResult(int mode, char winner);
    Stats loadStats() const;

private:
    std::unique_ptr<sqlite3, int (*)(sqlite3*)> db_;
};
