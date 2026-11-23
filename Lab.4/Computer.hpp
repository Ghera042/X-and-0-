#pragma once

#include "GameEngine.hpp"

class Computer {
public:
    Computer();

    Move chooseMove(const GameEngine& game) const;
};