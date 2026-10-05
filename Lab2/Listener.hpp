#pragma once

#include <iostream>
#include <sstream>
#include <string>


class Listener {
public:
    char listen(int& row, int& col) const {
        std::string line;
        if (!std::getline(std::cin, line)) return 'q';  

        if (line == "q" || line == "quit") return 'q';
        if (line == "r" || line == "restart") return 'r';

        std::istringstream in(line);
        if (in >> row >> col) {
            row--; 
            col--;
            return 'm';
        }
        return '?';
    }
};
