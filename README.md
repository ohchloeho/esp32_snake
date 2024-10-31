# Simple Snake Game on ESP32

This is my first IOT project deployed with PlatformIO, so do provide feedback if you do have any!

The objective of this project is to learn about the project structure of a typical Arduino program, followed by these technical aspects:

- basics of C++ language (as I'm a beginner)
- how the setup and loop functions run within an Arduino program
- global variables
- input initialization

### Materials I Used

- ESP32 Wroom Module
- SSD1306 OLED display
- 5 push buttons
- Wires and breadboard

## ESP32 Pin Configurations (Wiring)

### Connecting the SSD1306

There are 4 pins on the SSD1306: GND, VCC, SCL and SDA

- GND: GND pin on ESP32
- VCC: 3V3 pin on ESP32
- SCL: D22 pin on ESP32
- SDA: D21 pin on ESP32

### Push Buttons

I used 5 push buttons for the setup, with one side of the pins connected to the GND on the ESP32, and the other side of each button according to the following pins:

- BUTTON_UP = D19
- BUTTON_DOWN = D5
- BUTTON_LEFT = D18
- BUTTON_RIGHT = D23
- BUTTON_MIDDLE = D4

![Breadboard example](https://github.com/ohchloeho/esp32_snake/blob/main/assets/breadboard.jpeg)


## How the program should work

I've added a starting screen from the initial update, where the middle button has to be pressed to start the game. This is also the same at the game over screen, where the middle button has to be pressed to restart.

### On different size displays
The snake and food segments are defined in [drawGame](https://github.com/ohchloeho/esp32_snake/blob/417868a503b49fce614d9f22f4f8ad0180ac1bf1/src/display/setup.cpp) function, and this can be changed in the 3rd and 4th parameters of the u8g2.drawBox function, depending on the size of your display.

Do remember to update the boundaries of the game as well in [updateSnake](https://github.com/ohchloeho/esp32_snake/blob/417868a503b49fce614d9f22f4f8ad0180ac1bf1/src/game/game.cpp?plain=1#L76). My display boundaries were 32 x 16 on the SSD1306 which has 128 x 64 pixels. Adjust according to your display.

