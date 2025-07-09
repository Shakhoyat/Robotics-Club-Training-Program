const int potPin = A0;    // Potentiometer on analog pin A0
const int buzzerPin = 9;  // Buzzer on PWM-capable pin (e.g., 9, ~ symbol)

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);               // Read potentiometer (0-1023)
  int volume = map(potValue, 0, 1023, 0, 255);     // Map to PWM range (0-255)
  analogWrite(buzzerPin, volume);                  // Control buzzer intensity
  delay(10);                                       // Stabilize readings
}