#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <string>

Game::Game() : scoreText(font) // CHANGE THIS LINE
{
    srand((unsigned)time(nullptr));
    window.create(sf::VideoMode({ 800, 600 }), "Snake Game");
    window.setFramerateLimit(10);
    score = 0;

    // ADD THIS BLOCK — font and score text setup
    font.openFromFile("arial.ttf");
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition({ 10.f, 10.f });
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

        if (snake.getX() == food.getX() && snake.getY() == food.getY())
        {
            snake.grow();
            food.spawn(800, 600);
            score += 10;
        }

        window.clear(sf::Color::Black);
        food.draw(window);
        snake.draw(window);

        // ADD THIS BLOCK — draw score
        scoreText.setString("Score: " + std::to_string(score));
        window.draw(scoreText);

        window.display();
    }
}