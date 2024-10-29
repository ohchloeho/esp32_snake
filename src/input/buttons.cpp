#include <Arduino.h>
#include "../game/game.h"
#include "../config/config.h"

Direction dir = RIGHT; // Initialize the direction globally
unsigned long lastDebounceTime = 0;

void setupButtons() {
    pinMode(BUTTON_UP, INPUT_PULLUP);
    pinMode(BUTTON_DOWN, INPUT_PULLUP);
    pinMode(BUTTON_LEFT, INPUT_PULLUP);
    pinMode(BUTTON_RIGHT, INPUT_PULLUP);
    pinMode(BUTTON_MIDDLE, INPUT_PULLUP);
}

void readButtons() {
    if (digitalRead(BUTTON_UP) == LOW) {
        dir = UP;    // Set direction to UP
    } else if (digitalRead(BUTTON_DOWN) == LOW) {
        dir = DOWN;  // Set direction to DOWN
    } else if (digitalRead(BUTTON_LEFT) == LOW) {
        dir = LEFT;  // Set direction to LEFT
    } else if (digitalRead(BUTTON_RIGHT) == LOW) {
        dir = RIGHT; // Set direction to RIGHT
    } else if (digitalRead(BUTTON_MIDDLE) == LOW) {
        if(gameStart && gameOver) {
            gameReset();
            Serial.println("Game reset");
        }
        gameStart = true;
        Serial.println("Game start");
    }
}
void updateDirection() {
    unsigned long currentTime = millis();

    if (digitalRead(BUTTON_UP) == LOW && (currentTime - lastDebounceTime > debounceDelay)) {
        if (dir != DOWN) dir = UP;
        lastDebounceTime = currentTime;
    } else if (digitalRead(BUTTON_DOWN) == LOW && (currentTime - lastDebounceTime > debounceDelay)) {
        if (dir != UP) dir = DOWN;
        lastDebounceTime = currentTime;
    } else if (digitalRead(BUTTON_LEFT) == LOW && (currentTime - lastDebounceTime > debounceDelay)) {
        if (dir != RIGHT) dir = LEFT;
        lastDebounceTime = currentTime;
    } else if (digitalRead(BUTTON_RIGHT) == LOW && (currentTime - lastDebounceTime > debounceDelay)) {
        if (dir != LEFT) dir = RIGHT;
        lastDebounceTime = currentTime;
    }
}
