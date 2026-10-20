#pragma once

#include "GameEngine.hpp"

// clasa de baza abstracta pentru afisare
class BaseRenderer {
public:
    virtual ~BaseRenderer() {}

    virtual void draw(const GameEngine& game) const = 0;
    virtual void message(const char* text) const = 0;
};
