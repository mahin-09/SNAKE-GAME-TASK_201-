#pragma once
#include <SFML/Graphics.hpp>
#include <vector> // ADD THIS

class Snake
{
public:
    Snake();
    void draw(sf::RenderWindow& window);
    void move();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void grow(); // ADD THIS
    int getX();
    int getY();
private:
    sf::RectangleShape body;
    std::vector<sf::Vector2i> segments; // ADD THIS
    int x;
    int y;
    int speed;
    char direction;
};