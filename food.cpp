#include "Food.h"
#include <cstdlib> // ADD THIS

Food::Food()
{
    food.setSize({ 20.f, 20.f });
    food.setFillColor(sf::Color::Red);
    spawn(800, 600); // CHANGED: was hardcoded position
}

void Food::spawn(int windowWidth, int windowHeight) // ADD THIS FUNCTION
{
    int x = (rand() % (windowWidth / 20)) * 20;
    int y = (rand() % (windowHeight / 20)) * 20;
    food.setPosition({ (float)x, (float)y });
}

void Food::draw(sf::RenderWindow& window)
{
    window.draw(food);
}

int Food::getX()
{
    return (int)food.getPosition().x;
}

int Food::getY()
{
    return (int)food.getPosition().y;
}

void Food::setPosition(int x, int y)
{
    food.setPosition({ (float)x, (float)y });
}