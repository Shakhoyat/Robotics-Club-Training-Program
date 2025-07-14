int buzzerPin = 9;  // Buzzer on pin 9

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    if (command == '1') {
      tone(buzzerPin, 1000);  // Turn buzzer ON (1kHz tone)
    }
    else if (command == '0') {
      noTone(buzzerPin);       // Turn buzzer OFF
    }
  }
}