#define MOTOR_PIN 3
#define POT_PIN A0

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(POT_PIN, INPUT);
}

void loop() {
  int potValue = analogRead(POT_PIN);
  int motorSpeed = map(potValue, 0, 1023, 0, 255);
  spinMotor(motorSpeed, MOTOR_PIN);
}

void spinMotor(int speed, int pin) {
  analogWrite(pin, speed);
}
