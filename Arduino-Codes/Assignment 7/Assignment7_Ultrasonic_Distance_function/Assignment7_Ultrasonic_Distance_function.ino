const int trigPin = 5;
const int echoPin = 6;
long duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
float dis_func(long dur) {
  distance = duration * 0.0343 / 2;
  // Assignment 7.2
  // speed of sound in 20 deg celcius 343 m/s => 0.0343 cm/micro seconds
  // as our ultrasonic sensor works in cm and micro second unit 
}
void loop() {
  digitalWrite(trigPin, LOW);  //clean signal pawar jonno
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  //trigger on for 10 microseconds
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  //pulseIn => calcs how much time a pin stayed HIGH
  //echo pin high thake until n unless sound is still travelling
  //problem with pulseIn() hoitese => it makes the whole code wait until it completes the echo pulse measurement
  //tarmane object besi dure hoile basically timeout porjonto halt kore rakhbe
  // solve hoitese => using hardwire Interrupts(attachInterrupt()) to detech echo without blocking
  //alternate is =>NewPing Library can handle timeouts and nonBlocking behaviors
  distance = dis_func(duration);
  //Arduino-Uno's default Timeout is 1 second thats why i'm getting 83 cm ig
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);  //miliseconds
}
