#include "Game.h"

Game::Game()
{
    window.create(sf::VideoMode({ 800, 600 }), "Snake Game");
}

void Game::run()
{
    while (window.isOpen())
    {
        // Check for window events
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw the snake
        snake.draw(window);

        // Show everything on the screen
        window.display();
    }
}