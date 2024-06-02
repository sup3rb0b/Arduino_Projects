#include "SN74HC595.h"

int segArray[8] = {1,1,0,1,1,0,1,0};
int segArraylen = sizeof(segArray) / sizeof(segArray[0]);

int digitArray[8] = {0,1,1,1,1,1,1,1}; //the last 4 bits are not necessary and ar only present because both registers have 16 bits in total
int digitArraylen = sizeof(digitArray) / sizeof(digitArray[0]);

void setup() {
  Serial.begin(9600);
  initialize();

  


}

void loop() {
    int combinedArray[16];
    mergearray(num_1, digit_1, segArraylen, digitArraylen, combinedArray);
    assignLights(combinedArray);
    mergearray(num_2, digit_2, segArraylen, digitArraylen, combinedArray);
    assignLights(combinedArray);

    mergearray(num_3, digit_3, segArraylen, digitArraylen, combinedArray);
    assignLights(combinedArray);
    mergearray(num_4, digit_4, segArraylen, digitArraylen, combinedArray);
    assignLights(combinedArray);    
    
}
