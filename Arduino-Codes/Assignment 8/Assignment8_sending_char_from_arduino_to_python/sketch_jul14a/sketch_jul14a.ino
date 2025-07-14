void setup() {
  Serial.begin(9600); // Serial suru korlam, 9600 speed e
}
void loop() {
  for (char c = 'a'; c <= 'z';c++) // a theke z porjonto loop cholbe
  {
     Serial.println(c); // prottek letter serial e pathacchi
  }
  delay(1000); // 1 second wait korchi
}