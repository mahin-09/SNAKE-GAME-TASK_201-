#pragma once
#include <SFML/Graphics.hpp>

class Food
{
public:
    Food();
    void draw(sf::RenderWindow& window);
    int getX();
    int getY();
    void setPosition(int x, int y);
    void spawn(int windowWidth, int windowHeight);
private:
    sf::RectangleShape food;
};