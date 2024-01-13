//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h> // Include the Servo library

RF24 radio(9, 8); // CE, CSN
const byte address[6] = "00001";

struct JoyData {
  int x;
  int y;
} joyData;

Servo myServo; // Create a Servo object

void setup() {
  myServo.attach(10); // Attach the servo on Arduino pin 10
  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(&joyData, sizeof(joyData));
    
    // Map the joystick value to a servo angle
    int servoAngle = map(joyData.x, 0, 1023, 10, 170);

    // Rotate the servo
    myServo.write(servoAngle);

    // Print the joystick and servo values
    Serial.print("X-axis: ");
    Serial.print(joyData.x);
    Serial.print("\tServo angle: ");
    Serial.println(servoAngle);
  }
}
