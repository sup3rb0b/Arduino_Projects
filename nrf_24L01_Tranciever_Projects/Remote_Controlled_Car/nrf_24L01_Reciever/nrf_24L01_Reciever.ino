#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h> // Include the Servo library




int rightRev = 10;
int rightFor = 6;

int leftRev = 5;
int leftFor = 3;
float driveVal = 0;

int driveValAdj = 0;





RF24 radio(9, 8); // CE, CSN
const byte address[6] = "00001";

struct JoyData {
  int x;
  int y;
} joyData;

Servo myServo; // Create a Servo object

void setup() {

  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.startListening();
}

void loop() {




  if (radio.available()) {
    radio.read(&joyData, sizeof(joyData));

    
    driveVal = joyData.x - 502;
    driveValAdj = driveVal/521*255;

    digitalWrite(rightRev, LOW);

    

    if (driveVal > 0){
      analogWrite(rightFor, driveValAdj);
      analogWrite(leftFor, driveValAdj);

      analogWrite(rightRev, 0);
      analogWrite(leftRev, 0);
    }


    if (driveVal < 0){
      analogWrite(rightRev, -driveValAdj);
      analogWrite(leftRev, -driveValAdj);

      analogWrite(rightFor, 0);
      analogWrite(leftFor, 0);
    }
    // Print the joystick and servo values
    Serial.print("X-axis: ");
    Serial.print(joyData.x);
    Serial.print("\ Drive value: ");
    Serial.print(driveVal);
    Serial.print("\ Adjusted Drive value: ");
    Serial.print(driveValAdj);
    

    Serial.println();
    


  }
}

