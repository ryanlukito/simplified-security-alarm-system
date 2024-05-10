#include <tugas_sbm.h>


char hexa_keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte row_pins[ROWS] = {19, 18, 5, 17};
byte col_pins[COLS] = {16, 4, 0, 2};
int pin[] = {12, 27, 25, 32};
int buzz_pin = 23;

PasswordLock passwordLock(ROWS, COLS, hexa_keys, row_pins, col_pins, pin, buzz_pin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (!passwordLock.checkPassword()) {
    Serial.println("Password Salah! Silahkan Tunggu!");
    for (int i = 0; i < 5; i++) {
      passwordLock.activateStrobo();
    }
  } else {
    Serial.println("Password Benar!");
    delay(10000);
  }
}



