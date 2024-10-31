#include <U8g2lib.h>
#include "../config/Config.h"
#include "../game/game.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setupDisplay() {
    u8g2.begin();
    u8g2.setFont(u8g2_font_prospero_bold_nbp_tf);
}

void displayStartScreen() {
    u8g2.clearBuffer();
    u8g2.setCursor(20, 30);
    u8g2.print("snake.io");
    u8g2.setCursor(20, 45);
    u8g2.print("Start");
    u8g2.sendBuffer();  
}

void displayGameOver() {
    u8g2.clearBuffer();
    u8g2.setCursor(20, 20);
    u8g2.print("Game Over!");
    u8g2.setCursor(20, 35);
    u8g2.print("Score: ");
    u8g2.print(score);
    u8g2.setCursor(20, 50);
    u8g2.print("Play Again?");
    u8g2.sendBuffer();
}

void drawGame() {
    u8g2.clearBuffer();

    // Draw the snake
    for (const auto& segment : snake) {
        u8g2.drawBox(segment.x * 4, segment.y * 4, 4, 4); // Each segment is a 4x4 block
    }

    // Draw the food
    u8g2.drawBox(food.x * 4, food.y * 4, 4, 4); // Food is also a 4x4 block

    u8g2.sendBuffer();
}
