#include "Game.h"

Game::Game()
{
    window.create(sf::VideoMode({ 800, 600 }), "Snake Game");
    window.setFramerateLimit(10);
}

void Game::run()
{
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (event->is<sf::Event::KeyPressed>())
            {
                auto key = event->getIf<sf::Event::KeyPressed>();

                if (key->code == sf::Keyboard::Key::Up)
                    snake.moveUp();

                else if (key->code == sf::Keyboard::Key::Down)
                    snake.moveDown();

                else if (key->code == sf::Keyboard::Key::Left)
                    snake.moveLeft();

                else if (key->code == sf::Keyboard::Key::Right)
                    snake.moveRight();
            }
        }

        snake.move();

        window.clear(sf::Color::Black);

        snake.draw(window);

        window.display();
    }
}