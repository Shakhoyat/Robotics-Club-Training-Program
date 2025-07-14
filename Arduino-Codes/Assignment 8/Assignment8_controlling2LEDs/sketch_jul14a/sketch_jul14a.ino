int led1 = 9;  // LED 1 on pin 9
int led2 = 13; // LED 2 on pin 10

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    switch(command) {
      case 'A': digitalWrite(led1, HIGH); break;
      case 'a': digitalWrite(led1, LOW); break;
      case 'B': digitalWrite(led2, HIGH); break;
      case 'b': digitalWrite(led2, LOW); break;
    }
  }
}