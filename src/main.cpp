#include "./config/config.h"
#include "./game/game.h"
#include <Arduino.h>

void setup()
{
    Serial.begin(115200);
    setupGame();
}

void loop() {
    gameLoop();
}