#include "Snake.h"

Snake::Snake()
{
    body.setSize({ 20.f, 20.f });
    body.setFillColor(sf::Color::Green);

    x = 100;
    y = 100;

    speed = 20;

    // No movement at the start
    direction = 'N';
}

void Snake::move()
{
    if (direction == 'U')
    {
        y = y - speed;
    }
    else if (direction == 'D')
    {
        y = y + speed;
    }
    else if (direction == 'L')
    {
        x = x - speed;
    }
    else if (direction == 'R')
    {
        x = x + speed;
    }
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