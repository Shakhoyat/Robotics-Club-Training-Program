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

  if (receivedVal == 'a') { // a paile LED on
    digitalWrite(ledPin, HIGH);
  } else if (receivedVal == 'b') {// b paile LED off
    digitalWrite(ledPin, LOW);
  }
}
