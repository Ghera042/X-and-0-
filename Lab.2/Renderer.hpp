#pragma once

#include "GameEngine.hpp"

class Renderer {
public:
    void draw(const GameEngine& game) const;
    void message(const char* text) const;
};
