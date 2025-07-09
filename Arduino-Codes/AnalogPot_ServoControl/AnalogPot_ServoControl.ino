#include <Servo.h>

Servo servo1;
const int potPin = A0;  // analog pin for potentiometer

void setup() {
  servo1.attach(9);    // Setting up the pin for servo
  Serial.begin(9600);  // No need to set potPin as input, analogRead() does this automatically
}

void loop() {
  int potValue = analogRead(potPin);
  Serial.println(potValue);

  float angle = map(potValue, 0, 1023, 0, 180);  // map() function handles the conversion from 0-1023 to 0-255(PWM range)
  servo1.write(angle);
  delay(10);
  
}