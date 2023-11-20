// defines pins numbers
#define MICROPHONE_PIN A3

void setup(void) {
  Serial.begin(9600);
}

void loop() {
//  float sound = getSoundRaw();
//  Serial.println(sound);

  static float bias = 0;
  float angle;
  static int state = 0;
  switch (state) {
    case 0:
      bias = getBias();
      state = 1;
      break;
    case 1:
      float sound = getSoundRaw()-bias;
      float sound_smoothed = getSoundSmoothed(sound);
//      Serial.println(sound);
      Serial.println(sound_smoothed);
      break;
  }
}

// raw sensor measurement in range 0-1024
float getSoundRaw() {
  int sound_raw;
  sound_raw = analogRead(MICROPHONE_PIN);
  return ((float)sound_raw);
}

// use an alpha-filter to smooth the data
float getSoundSmoothed(float sound) {
  float alpha = 0.5;
  static float sound_smoothed = 0;
  sound_smoothed = alpha * sound_smoothed + (1 - alpha) * sound;
  return (sound_smoothed);
}

float getBias() {
  float bias = 0;
  int N = 100;
  for (int i = 0; i < N; i++) {
    bias += analogRead(MICROPHONE_PIN);
  }
  bias = bias / N;
  return (bias);
}
