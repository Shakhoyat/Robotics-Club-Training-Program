const int trigPin = 5;
const int echoPin = 6;
const int ledPin = 9;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  // Serial.begin(9600);
}

float get_dis() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.0343 / 2;  // Distance in cm & 343 m/s => 0.0343 cm/micro second
}

void blinkLED(float distance) {
  int blinkDelay = map(distance, 2, 200, 50, 1000);  // amra Mapping kortesi from distance (2-200cm) to delay (50-1000ms)
  blinkDelay = constrain(blinkDelay, 50, 1000);      // Ensure kortesi  bounds er vitor blink korbe

  digitalWrite(ledPin, HIGH);
  delay(blinkDelay / 2);
  digitalWrite(ledPin, LOW);
  delay(blinkDelay / 2);

  // Serial.print("Distance: ");
  // Serial.print(distance);
  // Serial.print("cm | Blink delay: ");
  // Serial.println(blinkDelay);
}

void loop() {
  float distance = getDistance();
  blinkLED(distance);
}