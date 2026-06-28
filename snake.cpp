#include "Snake.h"

Snake::Snake()
{
    // Snake size
    body.setSize({ 20.f, 20.f });

    // Snake color
    body.setFillColor(sf::Color::Green);

    // Starting position
    x = 100;
    y = 100;

    // Move 20 pixels each time
    speed = 20;

    // No movement at the beginning
    direction = 'N';
}

void Snake::move()
{
    if (direction == 'U')
        y = y - speed;
    else if (direction == 'D')
        y = y + speed;
    else if (direction == 'L')
        x = x - speed;
    else if (direction == 'R')
        x = x + speed;

    // ADD THIS BLOCK — wrap around walls
    if (x >= 800) x = 0;
    if (x < 0)   x = 780;
    if (y >= 600) y = 0;
    if (y < 0)   y = 580;
}

void Snake::moveUp()
{
    direction = 'U';
}

void Snake::moveDown()
{
    direction = 'D';
}

void Snake::moveLeft()
{
    direction = 'L';
}

void Snake::moveRight()
{
    direction = 'R';
}

void Snake::draw(sf::RenderWindow& window)
{
    body.setPosition({ (float)x, (float)y });
    window.draw(body);
}

int Snake::getX()
{
    return x;
}

int Snake::getY()
{
    return y;
}