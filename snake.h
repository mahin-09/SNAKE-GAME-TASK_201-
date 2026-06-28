#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

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
    void grow();
    bool checkSelfCollision();
    bool isMoving(); // ADD THIS
    int getX();
    int getY();
private:
    sf::RectangleShape body;
    std::vector<sf::Vector2i> segments;
    int x;
    int y;
    int speed;
    char direction;
};