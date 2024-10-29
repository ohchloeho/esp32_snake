#ifndef CONFIG_H
#define CONFIG_H

// GPIO pin assignments for buttons
#define BUTTON_UP 19
#define BUTTON_DOWN 5
#define BUTTON_LEFT 18
#define BUTTON_RIGHT 23
#define BUTTON_MIDDLE 4

// Debounce settings
const unsigned long debounceDelay = 50;

// Direction variables
enum Direction { UP, DOWN, LEFT, RIGHT };
extern Direction dir;

#endif