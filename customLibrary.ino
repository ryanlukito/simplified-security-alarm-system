#include "customLibrary.h"

/**

Ryan Krishandi Lukito - 22/497249/TK/54488
Yefta Nathaniel Wibowo - 22/492878/TK/53954

Pin untuk konfigurasi keypad
byte row_pins[ROWS] = {13, 12, 14, 27};
byte col_pins[COLS] = {26, 25, 33, 32};

Pin untuk konfigurasi LED
int pin[] = {18, 5, 19, 21};

Pin untuk konfigurasi buzzer
const int buzz_pin = 2;

**/

void setup() {
  Serial.begin(9600);
  pinMode(buzz_pin, OUTPUT);
  for (int i = 0; i < pin_len; i++) {
    pinMode(pin[i], OUTPUT);
  }
}

void loop() {
  if (!checkPassword()) {
    Serial.println("Password Salah! Silahkan Tunggu!");
    for (int i = 0; i < 5; i++) {
      activateStrobo1(pin, buzz_pin);
    }
  } else {
    Serial.println("Password Benar!");
    activateStrobo2(pin);
    delay(1000);
  }
}
