int buzzerPin = 9;  // Buzzer pin 9

void setup() {
  pinMode(buzzerPin, OUTPUT); // buzzer output set korlam
  Serial.begin(9600);         // serial start korlam
}

void loop() {
  if (Serial.available() > 0) { // serial e kichu ashle
    char command = Serial.read(); // command read korlam
    
    if (command == '1') {
      tone(buzzerPin, 1000);  // buzzer on korlam (1kHz)
    }
    else if (command == '0') {
      noTone(buzzerPin);       // buzzer off korlam
    }
  }
}