#pragma once

#include <iosfwd>

#include "BaseRenderer.hpp"

class Renderer : public BaseRenderer {
public:
    explicit Renderer(std::ostream& out) : out_(out) {}

    void draw(const GameEngine& game) const override;
    void drawMenu() const override;
    void drawHelp() const override;
    void drawInvalidChoice() const override;
    void drawInvalidMove() const override;
    void drawUnknownCommand() const override;

private:
    std::ostream& out_;
};