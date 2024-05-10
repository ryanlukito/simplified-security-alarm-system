#ifndef TUGAS_SBM_H
#define TUGAS_SBM_H

#include <Arduino.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

class PasswordLock {
public:
  PasswordLock(byte rows, byte cols, char keys[ROWS][COLS], byte rowPins[], byte colPins[], int pins[], int buzzPin);
  bool checkPassword();
  void activateStrobo();

private:
  Keypad customKeypad;
  int* pin;
  int set_time;
  int pin_len;
  int buzz_pin;
};

#endif
