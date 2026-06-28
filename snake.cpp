#include "Snake.h"

Snake::Snake()
{
    body.setSize({ 20.f, 20.f });
    body.setFillColor(sf::Color::Green);
    speed = 20;
    direction = 'N';

    // ADD THIS — start with 3 segments
    segments.push_back({ 100, 100 }); // head
    segments.push_back({ 80,  100 });
    segments.push_back({ 60,  100 });

    // keep x,y for compatibility
    x = 100;
    y = 100;
}

void Snake::move()
{
    // shift every segment to position of the one ahead
    for (int i = segments.size() - 1; i > 0; i--)
        segments[i] = segments[i - 1];

    // move head
    if (direction == 'U') segments[0].y -= speed;
    else if (direction == 'D') segments[0].y += speed;
    else if (direction == 'L') segments[0].x -= speed;
    else if (direction == 'R') segments[0].x += speed;

    // wrap around
    if (segments[0].x >= 800) segments[0].x = 0;
    if (segments[0].x < 0)   segments[0].x = 780;
    if (segments[0].y >= 600) segments[0].y = 0;
    if (segments[0].y < 0)   segments[0].y = 580;

    // update x,y to match head
    x = segments[0].x;
    y = segments[0].y;
}

void Snake::grow()
{
    // duplicate last segment
    segments.push_back(segments.back());
}

void Snake::moveUp() { if (direction != 'D') direction = 'U'; }
void Snake::moveDown() { if (direction != 'U') direction = 'D'; }
void Snake::moveLeft() { if (direction != 'R') direction = 'L'; }
void Snake::moveRight() { if (direction != 'L') direction = 'R'; }

void Snake::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < (int)segments.size(); i++)
    {
        // head is bright green, body is darker
        body.setFillColor(i == 0 ? sf::Color::Green : sf::Color(0, 180, 0));
        body.setPosition({ (float)segments[i].x, (float)segments[i].y });
        window.draw(body);
    }
}

int Snake::getX() { return segments[0].x; }
int Snake::getY() { return segments[0].y; }