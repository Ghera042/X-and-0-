#pragma once

#include "GameEngine.hpp"

// clasa de baza abstracta pentru afisare
class BaseRenderer {
public:
    virtual ~BaseRenderer() = default;

    virtual void draw(const GameEngine& game) const = 0;
    virtual void drawMenu() const = 0;
    virtual void drawHelp() const = 0;
    virtual void drawInvalidChoice() const = 0;
    virtual void drawInvalidMove() const = 0;
    virtual void drawUnknownCommand() const = 0;
   
};