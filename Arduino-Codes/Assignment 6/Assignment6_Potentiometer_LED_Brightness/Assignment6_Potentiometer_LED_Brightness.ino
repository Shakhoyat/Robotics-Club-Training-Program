const int potPin = A0;    // Potentiometer  to analog pin 
const int ledPin = 9;     // LED to digital pin 9 (must be PWM-capable)

void setup() {
  pinMode(ledPin, OUTPUT);  // Setting LED pin as output
  Serial.begin(9600);   // No need to set potPin as input, analogRead() does this automatically
}

void loop() {
  int potValue = analogRead(potPin);
  Serial.println(potValue);
  int brightness = map(potValue, 0, 1023, 0, 255); // map() function handles the conversion from 0-1023 to 0-255(PWM range)
  analogWrite(ledPin, brightness);
  delay(10);
}