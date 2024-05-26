#ifndef CUSTOMLIBRARY_H
#define CUSTOMLIBRARY_H

#include <Keypad.h>
#include <Arduino.h>

// Keypad settings
const byte ROWS = 4;
const byte COLS = 4;
extern char hexa_keys[ROWS][COLS];
extern byte row_pins[ROWS];
extern byte col_pins[COLS];
extern Keypad custom_keypad;

// Pin settings
extern int pin[];
extern const int pin_len;
extern const int buzz_pin;
extern int set_time;

// Function declarations
void activateStrobo1(int pin[], int buzz_pin);
void activateStrobo2(int pin[]);
bool checkPassword();

#endif // CUSTOMLIBRARY_H
