int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8}; // a,b,c,d,e,f,g

int numberPatterns[10][7] = {
  {1,1,1,1,1,1,0}, // 0 er jonno
  {0,1,1,0,0,0,0}, // 1 er jonno
  {1,1,0,1,1,0,1}, // 2 er jonno
  {1,1,1,1,0,0,1}, // 3 er jonno
  {0,1,1,0,0,1,1}, // 4 er jonno
  {1,0,1,1,0,1,1}, // 5 er jonno
  {1,0,1,1,1,1,1}, // 6 er jonno
  {1,1,1,0,0,0,0}, // 7 er jonno
  {1,1,1,1,1,1,1}, // 8 er jonno
  {1,1,1,1,0,1,1}  // 9 er jonno
};

void setup() {
  Serial.begin(9600); // serial start korlam
  for(int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT); // sob pin output dilam
  }
}

void loop() {
  if(Serial.available() > 0) { // data ashle
    char received = Serial.read(); // data nilam
    if(received >= '0' && received <= '9') { // number hole
      int number = received - '0'; // char theke number
      displayNumber(number); // display te dekhaisi
    }
  }
}

void displayNumber(int num) {
  for(int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], numberPatterns[num][i]); // segment on/off korlam
  }
}
