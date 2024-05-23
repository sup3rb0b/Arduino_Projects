

int serialInput = 2;
int serialClock = 3;
int registerClock = 4;
int serialClear = 5;
int regArray[8] = {1,0,0,1,0,0,1,1};



//  digitalWrite()
//  pinMode()
void reset(){
  digitalWrite(serialClear,LOW);
  digitalWrite(serialClear,HIGH);
}

void setCondition (uint8_t state ){
  digitalWrite(serialInput, state);
  digitalWrite(serialClock, HIGH);
  digitalWrite(serialClock, LOW);
  digitalWrite(serialInput, LOW);


}

void assignLights(int Array[]){
  uint8_t state = LOW;
  for (int i =7 ;i > -1; i-- ){
    Serial.print("Value: ");
    Serial.print(Array[i]);
    Serial.print("Index: ");
    Serial.println(i);
    if (Array[i] == 1){
      state = HIGH;
      setCondition(state);
    }else{
      state = LOW;
      setCondition(state);
    }
  }
  digitalWrite(registerClock, HIGH);
  digitalWrite(registerClock, LOW);
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(serialInput, OUTPUT);
  pinMode(serialClock, OUTPUT);
  pinMode(registerClock, OUTPUT);
  pinMode(serialClear, OUTPUT);

  digitalWrite(serialInput,LOW);
  digitalWrite(serialClock, LOW);
  digitalWrite(registerClock, LOW);
  digitalWrite(serialClear, HIGH);

  reset();
  assignLights(regArray);
;



}

void loop() {
  // setCondition(HIGH);
  // delay(100);
  // setCondition(LOW);
  // delay(100);
  // setCondition(HIGH);
  // delay(100);
  // setCondition(HIGH);
  // delay(100);

}
