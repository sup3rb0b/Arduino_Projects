int serialInput = 2;
int serialClock = 3;
int registerClock = 4;
int serialClear = 5;

int digit_1[8] = {0,1,1,1,1,1,1,1};
int digit_2[8] = {1,0,1,1,1,1,1,1};
int digit_3[8] = {1,1,0,1,1,1,1,1};
int digit_4[8] = {1,1,1,0,1,1,1,1};

//					  {a, b, c, d, e, f, g, h}
int num_0[] = {1, 1, 1, 1, 1, 1, 0, 0}; // 0
int num_1[] = {0, 1, 1, 0, 0, 0, 0, 0}; // 1
int num_2[] = {1, 1, 0, 1, 1, 0, 1, 0}; // 2
int num_3[] = {1, 1, 1, 1, 0, 0, 1, 0}; // 3
int num_4[] = {0, 1, 1, 0, 0, 1, 1, 0}; // 4
int num_5[] = {1, 0, 1, 1, 0, 1, 1, 0}; // 5
int num_6[] = {1, 0, 1, 1, 1, 1, 1, 0}; // 6
int num_7[] = {1, 1, 1, 0, 0, 0, 0, 0}; // 7
int num_8[] = {1, 1, 1, 1, 1, 1, 1, 0}; // 8
int num_9[] = {1, 1, 1, 1, 0, 1, 1, 0}; // 9




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
  for (int i = 15 ;i > -1; i-- ){
    // Serial.print("Value: ");
    // Serial.print(Array[i]);
    // Serial.print("Index: ");
    // Serial.println(i);
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

void mergearray(int a[], int b[], int arr1size, int arr2size, int c[]) {
    // Resultant Array Size Declaration
    int arr_resultsize = arr1size + arr2size;
    int i, j;
    // copying array 1 elements into c array
    for (i = 0; i < arr1size; i++) {
        c[i] = a[i];
    }
    // copying array 2 elements into c array
    for (i = 0, j = arr1size; j < arr_resultsize && i < arr2size; i++, j++) {
        c[j] = b[i];  
    }
}


void initialize(){
	pinMode(serialInput, OUTPUT);
  pinMode(serialClock, OUTPUT);
  pinMode(registerClock, OUTPUT);
  pinMode(serialClear, OUTPUT);

  digitalWrite(serialInput,LOW);
  digitalWrite(serialClock, LOW);
  digitalWrite(registerClock, LOW);
  digitalWrite(serialClear, HIGH);
	reset();
}
 
