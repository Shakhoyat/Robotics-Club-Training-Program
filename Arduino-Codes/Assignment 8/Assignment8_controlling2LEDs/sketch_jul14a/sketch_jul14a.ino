int led1 = 9;  // LED 1 pin 9
int led2 = 13; // LED 2 pin 13

void setup() {
  pinMode(led1, OUTPUT);   // LED1 output banailam
  pinMode(led2, OUTPUT);   // LED2 output banailam
  Serial.begin(9600);      // Serial suru korlam
}

void loop() {
  if (Serial.available() > 0) { // Jodi kichu ase serial e
    char command = Serial.read(); // Command porlam
    
    switch(command) {
      case 'A': digitalWrite(led1, HIGH); break; // LED1 jalao
      case 'a': digitalWrite(led1, LOW); break;  // LED1 bondho
      case 'B': digitalWrite(led2, HIGH); break; // LED2 jalao
      case 'b': digitalWrite(led2, LOW); break;  // LED2 bondho
    }
  }
}