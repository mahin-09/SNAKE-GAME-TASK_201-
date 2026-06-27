#pragma once

#include <SFML/Graphics.hpp>

class Snake
{
public:
    Snake();

    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape body;
};
