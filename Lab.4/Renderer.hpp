#pragma once

#include "BaseRenderer.hpp"
#include "GameEngine.hpp"

class Renderer : public BaseRenderer {
public:
    void draw(const GameEngine& game) const override;
    void message(const char* text) const override;
};
