#include "tugas_sbm.h"

PasswordLock::PasswordLock(byte rows, byte cols, char keys[ROWS][COLS], byte rowPins[], byte colPins[], int pins[], int buzzPin)
  : customKeypad(makeKeymap(keys), rowPins, colPins, rows, cols) {
    pin = pins;
    set_time = 20;
    pin_len = sizeof(pins)/sizeof(int);
    buzz_pin = buzzPin;
    pinMode(buzz_pin, OUTPUT);
    for (int i = 0; i < pin_len; i++) {
      pinMode(pin[i], OUTPUT);
    }
}


bool PasswordLock::checkPassword() {
  Serial.println("Masukkan Password (4 Digit)");
  Serial.println("Clue: Tahun Kemerdekaan Indonesia");
  char input[4];
  int i = 0;
  while(i < 4) {
    char ves = customKeypad.getKey();
    if (ves != NO_KEY) {
      Serial.println(ves);
      input[i] = ves;
      i++;
    }
    delay(100);
  }

  if (input[0] == '1' && input[1] == '9' && input[2] == '4' && input[3] == '5') {
    return true;
  } else {
    return false;
  }
}

void PasswordLock::activateStrobo() {
  for (int i = 0; i < pin_len; i++) {
    digitalWrite(pin[i], HIGH);
    delay(set_time);
    set_time += 40;
  }

  for (int j = 0; j < pin_len; j++) {
    digitalWrite(pin[j], LOW);
    delay(set_time);
    set_time += 40;
  }

  digitalWrite(buzz_pin, HIGH);
  delay(1000);
  digitalWrite(buzz_pin, LOW);
  delay(500);

  set_time = 0;
}
