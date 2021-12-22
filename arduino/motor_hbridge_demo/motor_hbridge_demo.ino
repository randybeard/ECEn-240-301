#define MOTOR_EN 3
#define MOTOR_INA 4
#define MOTOR_INB 5

void setup() {
  // set up serial connection at 9600 Baud
  Serial.begin(9600);
  
  pinMode(MOTOR_EN, OUTPUT);
  pinMode(MOTOR_INA, OUTPUT);
  pinMode(MOTOR_INB, OUTPUT);
  pinMode(POT_PIN, INPUT);
}

void loop() {
  float time = currentTime();  
  float omega = 2 * PI * 0.1; //frequency for sin is in rad/sec
  float motorSpeed = 1 * sin(omega * time);
  spinMotor(motorSpeed, MOTOR_EN, MOTOR_INA, MOTOR_INB);
}

void spinMotor(float speed, int en, int inA, int inB) {
  if (speed > 0){
    digitalWrite(inA, HIGH);
    digitalWrite(inB, LOW);
    int pwmSpeed = (int)(255 * speed); 
    analogWrite(en, pwmSpeed);
  } 
  else if (speed < 0){
    digitalWrite(inA, LOW);
    digitalWrite(inB, HIGH);
    int pwmSpeed = (int)(255 * (-speed));        
    analogWrite(en, pwmSpeed);    
  }
  else {
    digitalWrite(inA, HIGH);
    digitalWrite(inB, HIGH);    
    analogWrite(en, 0);
  }
}

float currentTime() {
  // t=0 is the first time function is called
  static unsigned int startTime = millis();  
  float time = (float)(millis() - startTime)/1000; 
    // divide by 1000 to convert milliseconds to seconds
  return(time);
}
