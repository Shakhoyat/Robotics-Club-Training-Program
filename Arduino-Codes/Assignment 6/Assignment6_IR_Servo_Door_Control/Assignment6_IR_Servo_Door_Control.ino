#include <Servo.h>

// Pins
const int IR_SENSOR_PIN = 2;  // IR sensor output
const int SERVO_PIN = 9;      // Servo control

// Positions
const int DOOR_CLOSED = 0;    // 0 degrees
const int DOOR_OPEN = 90;     // 90 degrees

Servo doorServo;
bool obstacleDetected = false;

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  doorServo.attach(SERVO_PIN);
  doorServo.write(DOOR_CLOSED); // Start with door closed
  Serial.begin(9600);           // For debugging
}

void loop() {
  int sensorValue = digitalRead(IR_SENSOR_PIN);
  
  // IR sensor typically returns LOW when obstacle detected
  if (sensorValue == LOW && !obstacleDetected) {
    // Obstacle detected - open door
    doorServo.write(DOOR_OPEN);
    obstacleDetected = true;
    Serial.println("Obstacle detected - opening door");
    delay(1500); // Small delay for movement
  } 
  else if (sensorValue == HIGH && obstacleDetected) {
    // Path clear - close door
    doorServo.write(DOOR_CLOSED);
    obstacleDetected = false;
    Serial.println("Path clear - closing door");
    delay(1500); // Small delay for movement
  }
  
  delay(100); // Short delay between readings
}