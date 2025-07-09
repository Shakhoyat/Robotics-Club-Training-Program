#include <Servo.h>

const int btn_clockwise = 2;     // clockwise button pin
const int btn_anti_clockwise = 3;    // anti-clockwise button pin
const int servoPin = 9;     // servo control pin

Servo myServo;
int currentPos = 90;        // fixing 90 degree to be my initial position

void setup() {
  pinMode(btn_clockwise, INPUT_PULLUP);
  pinMode(btn_anti_clockwise, INPUT_PULLUP); // INPUT_PULLUP => by default HIGH/1
  myServo.attach(servoPin);

  myServo.write(currentPos);  // initializing my servo position
}

void loop() {
  // Check clockwise button
  if (digitalRead(btn_clockwise) == LOW) {// if pressed then ...
    currentPos = min(currentPos + 10, 180);  // increase by 10°, max 180
    myServo.write(currentPos);
    delay(200);  // Debounce delay
    while(digitalRead(btn_clockwise) == LOW);  // Wait for button release
  }

  // Check counter-clockwise button
  if (digitalRead(btn_anti_clockwise) == LOW) {
    currentPos = max(currentPos - 10, 0);  // Decrease by 10°, min 0
    myServo.write(currentPos);
    delay(200);  // Debounce delay
    while(digitalRead(btn_anti_clockwise) == LOW);  // Wait for button release
  }
}