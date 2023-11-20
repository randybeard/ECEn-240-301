// defines pins numbers
#define FLEX_SENSOR_PIN A7

void setup(void) {
  Serial.begin(9600);
}

void loop() {
  static float bias = 0;
  float angle;
//  angle = getAngleRaw();
//  Serial.println(angle);    
  static int state = 0;
  switch (state) {
    case 0:
      bias = getBias();
      state = 1;
      break;
    case 1:
      //angle = getAngleRaw();
      //angle = getAngleCalibrated(bias);
      angle = getAngleSmoothed(bias);
      Serial.println(angle);
      break;
  }
}

// raw sensor measurement in range 0-1024
float getAngleRaw() {
  int flex_raw;
  flex_raw = analogRead(FLEX_SENSOR_PIN);
  return ((float)flex_raw);
}

// calibrate the raw sensor to units of degrees
float getAngleCalibrated(float bias) {
  float angle;
  angle = getAngleRaw();
  angle = angle - bias; // subtract off bias
  angle = (angle * 90) / 57;  // units of degrees
  return (angle);
}

// use an alpha-filter to smooth the data
float getAngleSmoothed(float bias) {
  float alpha = 0.9;
  static float angle = 0;
  angle = alpha * angle + (1 - alpha) * getAngleCalibrated(bias);
  return (angle);
}

float getBias() {
  float bias = 0;
  int N = 100;
  for (int i = 0; i < N; i++) {
    bias += analogRead(FLEX_SENSOR_PIN);
  }
  bias = bias / N;
  return (bias);
}
