#include "customLibrary.h"

// Keypad settings
char hexa_keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte row_pins[ROWS] = {13, 12, 14, 27};
byte col_pins[COLS] = {26, 25, 33, 32};
Keypad custom_keypad = Keypad(makeKeymap(hexa_keys), row_pins, col_pins, ROWS, COLS); 

// Pin settings
int pin[] = {18, 5, 19, 21};
const int pin_len = sizeof(pin) / sizeof(int);
const int buzz_pin = 2;
int set_time = 20;

void activateStrobo1(int pin[], int buzz_pin) {
  for (int i = 0; i < pin_len; i++) {
    digitalWrite(pin[i], HIGH);
    delay(set_time);
    set_time += 20;
  }

  for (int j = 0; j < pin_len; j++) {
    digitalWrite(pin[j], LOW);
    delay(set_time);
    set_time += 20;
  }

  digitalWrite(buzz_pin, HIGH);
  delay(1000);
  digitalWrite(buzz_pin, LOW);
  delay(500);

  set_time = 0;
}

void activateStrobo2(int pin[]) {
  for (int k = 0; k < 2; k++) {
    for (int i = 0; i < pin_len; i++) {
      digitalWrite(pin[i], HIGH);
    }
    delay(500);

    for (int j = 0; j < pin_len; j++) {
      digitalWrite(pin[j], LOW);
    }
    delay(500);

    for (int i = 0; i < pin_len; i++) {
      digitalWrite(pin[i], HIGH);
    }
    delay(500);

    for (int j = 0; j < pin_len; j++) {
      digitalWrite(pin[j], LOW);
    }
    delay(500);

    for (int i = 0; i < pin_len; i++) {
      digitalWrite(pin[i], HIGH);
      delay(set_time);
      set_time += 20;
    }

    for (int j = 0; j < pin_len; j++) {
      digitalWrite(pin[j], LOW);
      delay(set_time);
      set_time += 20;
    }
    
    for (int i = 0; i < pin_len; i++) {
      digitalWrite(pin[i], HIGH);
      delay(set_time);
      set_time += 20;
    }

    for (int j = 0; j < pin_len; j++) {
      digitalWrite(pin[j], LOW);
      delay(set_time);
      set_time += 20;
    }
    set_time = 0;
  }
}

bool checkPassword() {
  Serial.println("Masukkan Password (4 Digit)");
  Serial.println("Clue: Tahun Kemerdekaan Indonesia");
  char input[4];
  int i = 0;
  while (i < 4) {
    char ves = custom_keypad.getKey();
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
