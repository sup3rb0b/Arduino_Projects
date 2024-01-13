#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 8);  // CE, CSN
const byte address[6] = "00001";

// Define joystick pins
const int joyXPin = A0;  // Analog input pin for X-axis
const int joyYPin = A1;  // Analog input pin for Y-axis

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.stopListening();

  // Initialize joystick pins
  pinMode(joyXPin, INPUT);
  pinMode(joyYPin, INPUT);
}

void loop() {
  // Read joystick values
  int joyX = analogRead(joyXPin);
  int joyY = analogRead(joyYPin);

  // Create a structure to hold joystick data
  struct JoyData {
    int x;
    int y;
  } joyData;

  joyData.x = joyX;
  joyData.y = joyY;

  // Send joystick data
  radio.write(&joyData, sizeof(joyData));

  delay(5);
}
