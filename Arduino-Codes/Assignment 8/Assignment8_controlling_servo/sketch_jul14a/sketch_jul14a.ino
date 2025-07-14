#include <Servo.h> // Servo library

Servo myServo; // Servo object
int servoPin = 9; // Servo pin

void setup() {
  myServo.attach(servoPin); // Servo pin set
  Serial.begin(9600); // Serial start
}

void loop() {
  if (Serial.available() > 0) { // Serial data ase kina
    int angle = Serial.parseInt(); // Serial theke number pora
    if (angle >= 0 && angle <= 180) { // Angle thik ase kina
      myServo.write(angle); // Servo ghurao
    }
  }
}