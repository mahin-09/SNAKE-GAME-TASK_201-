#include "Snake.h"

Snake::Snake()
{
    // Make the snake block 20x20 pixels
    body.setSize(sf::Vector2f(20.f, 20.f));

    // Make it green
    body.setFillColor(sf::Color::Green);

    // Starting position
    body.setPosition(sf::Vector2f(100.f, 100.f));
}

void Snake::draw(sf::RenderWindow& window)
{
    window.draw(body);
}