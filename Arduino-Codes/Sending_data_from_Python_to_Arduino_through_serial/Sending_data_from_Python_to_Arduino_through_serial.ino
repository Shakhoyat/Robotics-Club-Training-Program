int ledPin = 13;
char receivedVal;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    receivedVal = Serial.read();
  }
  if (receivedVal == 'a') {
    digitalWrite(ledPin, HIGH);
  } else if (receivedVal == 'b') {
    digitalWrite(ledPin, LOW);
  }
}
