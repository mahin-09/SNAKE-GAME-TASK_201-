#pragma once

#include <SFML/Graphics.hpp>

class Snake
{
public:
    // Constructor
    Snake();

    // Draw the snake
    void draw(sf::RenderWindow& window);

    // Move the snake
    void move();

    // Change direction
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getX();
    int getY();

private:
    sf::RectangleShape body;

    int x;
    int y;

    int speed;

    char direction;
};