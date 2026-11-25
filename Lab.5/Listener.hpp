#pragma once

#include <iosfwd>

class Listener {
public:
    explicit Listener(std::istream& in) : in_(in) {}

    char listenMode();
    char listen(int& row, int& col);

private:
    std::istream& in_;
};