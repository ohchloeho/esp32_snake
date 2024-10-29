#include "../input/buttons.h"
#include "../display/setup.h"
#include "../config/config.h"
#include "game.h"
#include <Wire.h>
#include <Arduino.h>

// Snake and game variables
std::vector<Point> snake = {{4, 4}}; // Initial snake position
Point food = {8, 8};                 // Initial food position
int snakeLength = 1;                 // Initial snake length
bool gameOver = false;               // Game state
int score = 0;
bool gameStart = false;

void setupGame()
{
    setupButtons();
    setupDisplay();

    snake = {{4, 4}}; // Reset snake position
    snakeLength = 1;
    gameOver = false;
}

void gameReset()
{
    snake = {{4, 4}}; // Reset snake position
    snakeLength = 1;
    gameOver = false;
    gameStart = false;
    score = 0;
    food = {8, 8};
}

void gameLoop()
{
    readButtons();
    if (!gameOver && !gameStart)
    {
        displayStartScreen();
    }
    else if (!gameOver && gameStart)
    {
        updateSnake(); // Update snake position and check for game over
        drawGame();    // Draw snake, food, and score
        delay(300);    // Game speed
    }
    else
    {
        displayGameOver();
    }
}

void updateSnake()
{
    // Calculate new head position based on direction
    Point newHead = snake[0];
    switch (dir)
    {
    case UP:
        newHead.y--;
        break; // Move up
    case DOWN:
        newHead.y++;
        break; // Move down
    case LEFT:
        newHead.x--;
        break; // Move left
    case RIGHT:
        newHead.x++;
        break; // Move right
    }

    // Check for collisions with screen edges
    if (newHead.x < 0 || newHead.x >= 32 || newHead.y < 0 || newHead.y >= 16)
    {
        gameOver = true;
        return;
    }

    // Check for collisions with itself
    for (size_t i = 0; i < snake.size(); i++)
    {
        if (snake[i].x == newHead.x && snake[i].y == newHead.y)
        {
            gameOver = true;
            return;
        }
    }

    // Add new head to the front of the snake
    snake.insert(snake.begin(), newHead);

    // Check if snake eats the food
    if (newHead.x == food.x && newHead.y == food.y)
    {
        snakeLength++; // Increase snake length
        score++;
        // Generate new food location (randomly on an 8x16 grid)
        do
        {
            food.x = random(0, 32);
            food.y = random(0, 16);
        } while (food.x == newHead.x && food.y == newHead.y); // Ensure food doesn't spawn on the snake
    }
    else
    {
        // Remove the tail segment if the snake hasn't eaten
        if (snake.size() > snakeLength)
        {
            snake.pop_back();
        }
    }
}
