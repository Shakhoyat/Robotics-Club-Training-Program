char value = 'p';

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(value);
  delay(1000);
}
