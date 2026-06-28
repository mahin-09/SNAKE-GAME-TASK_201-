#include "Food.h"

Food::Food()
{
    // Food size
    food.setSize({ 20.f, 20.f });

    // Food color
    food.setFillColor(sf::Color::Red);

    // Starting position
    food.setPosition({ 300.f, 200.f });
}

void Food::draw(sf::RenderWindow& window)
{
    window.draw(food);
}