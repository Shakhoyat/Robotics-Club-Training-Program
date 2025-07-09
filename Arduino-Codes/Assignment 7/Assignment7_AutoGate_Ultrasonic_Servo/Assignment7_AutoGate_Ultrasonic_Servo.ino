#include <Servo.h>

const int trigPin = 5;    // Ultrasonic sensor pins
const int echoPin = 6;
const int servoPin = 9;   // Servo control pin

Servo gate1;          // Creat servo object
int gateOpenAngle = 90;   // Angle when gate is open
int gateCloseAngle = 0;   // Angle when gate is closed
int detectionRange = 25;  // Detection range in cm

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  gate1.attach(servoPin); // connecting servo signal pin to 9

  gate1.write(gateCloseAngle); // Start with closed gate
  Serial.begin(9600);
}

float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.0343 / 2; // Converted in cm
}

void loop() {
  float distance = getDistance();
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= detectionRange) {
    gate1.write(gateOpenAngle); // Open gate
    Serial.println("Gate OPENED");
    delay(3000); // Keep gate open for 3 seconds
  } 
  else {
    gate1.write(gateCloseAngle); // Close gate
    Serial.println("Gate CLOSED");
  }
  
  delay(100); // Short delay between readings
}