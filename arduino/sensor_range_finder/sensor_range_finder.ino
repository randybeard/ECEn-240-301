#define TRIGGER_PIN 2
#define ECHO_PIN 3

void setup(void) {
  pinMode(TRIGGER_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
}

void loop() {
  //long duration = getDurationRaw();
  //Serial.println(duration);
  //;float distance = getDistanceRaw();
  //Serial.println(distance);
  float distance = getDistanceSmoothed();
  Serial.println(distance);  
}

float getDistanceSmoothed() {
  static float distanceSmoothed = getDistanceRaw();
  float distance = getDistanceRaw();
  float alpha = 0.9;
  // only update if measurement is close to current estimate
  // this is called a measurement gate
  if (abs(distance-distanceSmoothed)<10) {
    distanceSmoothed = alpha*distanceSmoothed
          + (1-alpha)*distance;
  }
  return(distanceSmoothed);
}

float getDistanceRaw() {
  float duration = (float)getDurationRaw();
  // duration is time for sonar to travel to object and back
  // divide by 2 for travel time to object (in microseconds)
  duration = duration / 2;  
  // need speed of sound in cm/microseconds
  float c = 343;  // speed of sound in m/s
  c = c * 100 / 1e6;  // speed of sound in cm/s
  // Calculate the distance in centimeters
  float distance= duration * c;
  return(distance);
}

long getDurationRaw() {
  long duration;
  // Clear the TRIGGER_PIN
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);

  // Set the TRIGGER_PIN on HIGH state for 10 micro seconds
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Reads the ECHO_PIN, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH, 10000);
  return(duration);
}
