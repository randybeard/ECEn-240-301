#include<Servo.h>  // this includes the servo library
#define SERVO_PIN 3
#define CONTINUOUS_SERVO_PIN 5

Servo servo;  // global variable of type Servo (defined in Servo.h)
Servo continuousServo;
void setup() {
  servo.attach(SERVO_PIN);  // tells library where servo is attached
  continuousServo.attach(CONTINUOUS_SERVO_PIN);
}

void loop() {
  float time = currentTime();
  float omega = 2 * PI * 0.1;
  float servoAngle = 90 + 60 * sin(omega * time);
  servo.write(servoAngle);
  continuousServo.write(servoAngle);
}

float currentTime() {
  // t=0 is the first time function is called
  static unsigned int startTime = millis();  
  float time = (float)(millis() - startTime)/1000; 
    // divide by 1000 to convert milliseconds to seconds
  return(time);
}
