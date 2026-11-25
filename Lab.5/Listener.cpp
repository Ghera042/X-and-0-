#include "Listener.hpp"

#include <algorithm>
#include <istream>
#include <sstream>
#include <string>
#include <vector>

static bool isOneOf(const std::string& word, const std::vector<std::string>& words) {
    return std::find(words.begin(), words.end(), word) != words.end();
}

char Listener::listenMode() {
    std::string line;
    if (!std::getline(in_, line) || isOneOf(line, { "q", "quit" })) return 'q';
    if (line == "1" || line == "2") return line[0];
    return '?';
}

char Listener::listen(int& row, int& col) {
    std::string line;
    if (!std::getline(in_, line) || isOneOf(line, { "q", "quit" })) return 'q';
    if (isOneOf(line, { "r", "restart" })) return 'r';

    std::istringstream numbers(line);
    if (numbers >> row >> col) {
        row--;
        col--;
        return 'm';
    }
    return '?';
}