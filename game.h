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
    bool gameOver;
    sf::Font font;
    sf::Text scoreText;
    sf::Text gameOverText;
};