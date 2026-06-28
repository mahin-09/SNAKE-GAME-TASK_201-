#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include "Snake.h"
#include "Food.h"

class Game
{
public:
    Game();
    void run();
private:
    sf::RenderWindow window;
    Snake snake;
    Food food;
    int score;
    sf::Font font;       // ADD THIS
    sf::Text scoreText;  // ADD THIS
};