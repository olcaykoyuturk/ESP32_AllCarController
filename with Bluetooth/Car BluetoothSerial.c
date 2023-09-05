#include "BluetoothSerial.h"

#define PIN_IN1 27
#define PIN_IN2 26
#define PIN_ENA 14
#define PIN_IN3 18
#define PIN_IN4 19
#define PIN_ENB 5

BluetoothSerial SerialBT;

char command;

void setup() {
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);

  Serial.begin(115200);

  SerialBT.begin("ESP32"); // Bluetooth cihaz adını belirt
  Serial.println("Bluetooth Hazır! Eşleşmeye Hazır...");
}

void loop() {
  if (SerialBT.available()) {
    command = SerialBT.read(); // Bluetooth üzerinden gelen veriyi "komut" değişkenine ata
    Serial.print("Alınan command: ");
    Serial.println(command);
  }
  switch (command) {
    case 'F':
      moveForward();
      break;
    case 'B':
      moveBackward();
      break;
    case 'L':
      moveLeft();
      break;
    case 'R':
      moveRight();
      break;
    case 'S':
      moveStop();
      break;
    case 'A':
      speed(80);
      break;
    case 'B':
      speed(150);
      break;
    case 'C':
      speed(255);
      break;
  }
}

void moveForward() {
  digitalWrite(PIN_IN1, HIGH);
  digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_IN3, HIGH);
  digitalWrite(PIN_IN4, LOW);
}

void moveBackward() {
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, HIGH);
  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, HIGH);
}

void moveStop() {
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, LOW);
}

void moveLeft() {
  digitalWrite(PIN_IN1, HIGH);
  digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, HIGH);
}

void moveRight() {
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, HIGH);
  digitalWrite(PIN_IN3, HIGH);
  digitalWrite(PIN_IN4, LOW);
}

void speed(int speedValue) {
  analogWrite(PIN_ENA, speedValue);
  analogWrite(PIN_ENB, speedValue);
}



