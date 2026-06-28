#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <string>

Game::Game() : scoreText(font), gameOverText(font)
{
    srand((unsigned)time(nullptr));
    window.create(sf::VideoMode({ 800, 600 }), "Snake Game");
    window.setFramerateLimit(10);
    score = 0;
    gameOver = false;

    font.openFromFile("arial.ttf");

    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition({ 10.f, 10.f });

    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::Yellow);
    gameOverText.setPosition({ 150.f, 220.f });
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

                if (!gameOver)
                {
                    if (key->code == sf::Keyboard::Key::Up)
                        snake.moveUp();
                    else if (key->code == sf::Keyboard::Key::Down)
                        snake.moveDown();
                    else if (key->code == sf::Keyboard::Key::Left)
                        snake.moveLeft();
                    else if (key->code == sf::Keyboard::Key::Right)
                        snake.moveRight();
                }

                if (key->code == sf::Keyboard::Key::R && gameOver)
                {
                    snake = Snake();
                    food.spawn(800, 600);
                    score = 0;
                    gameOver = false;
                }
            }
        }

        if (!gameOver)
        {
            snake.move();

            if (snake.getX() == food.getX() && snake.getY() == food.getY())
            {
                snake.grow();
                food.spawn(800, 600);
                score += 10;
            }

            // only check collision after snake starts moving
            if (snake.checkSelfCollision() && snake.isMoving())
            {
                gameOver = true;
            }
        }

        window.clear(sf::Color::Black);

        if (!gameOver)
        {
            food.draw(window);
            snake.draw(window);
            scoreText.setString("Score: " + std::to_string(score));
            window.draw(scoreText);
        }
        else
        {
            gameOverText.setString(
                "GAME OVER!\n"
                "Score: " + std::to_string(score) + "\n"
                "Press R to restart"
            );
            window.draw(gameOverText);
        }

        window.display();
    }
}