#pragma once

#include <SFML/Graphics.hpp>
#include <optional>

#include "Snake.h"

class Game
{
public:
    Game();
    void run();

private:
    sf::RenderWindow window;

    Snake snake;
};