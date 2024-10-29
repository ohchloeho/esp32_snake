#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../config/Config.h"

// Snake segment structure
struct Point {
    int x;
    int y;
};

// Game variables
extern std::vector<Point> snake; // Snake segments
extern Point food;               // Food position
extern int snakeLength;          // Snake length
extern bool gameOver;            // Game state
extern int score;
extern bool gameStart;

void setupGame();
void gameLoop();
void gameReset();
void updateSnake();

#endif
