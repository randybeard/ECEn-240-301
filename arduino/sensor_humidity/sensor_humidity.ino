#include "DHT.h"
#define DHT_PIN 5 // Digital pin
#define DHT_TYPE DHT11   // DHT 11

// Initialize DHT sensor.
DHT dht(DHT_PIN, DHT_TYPE);
float temperature_smoothed;
float humidity_smoothed;
float alpha = 0.9;

void setup(void) {
  Serial.begin(9600);
  dht.begin();  //begin the dht sensor
  // initialize the alpha filter at startup
  temperature_smoothed = dht.readTemperature(true);
  humidity_smoothed = dht.readHumidity();
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  delay(2000); // Wait a few seconds between measurements.

  // alpha filter the humidity
  float h = dht.readHumidity();
  humidity_smoothed = alpha*humidity_smoothed + (1-alpha)*h;

  // alpha filter the temperature
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float t = dht.readTemperature(true);
  temperature_smoothed = alpha*temperature_smoothed + (1-alpha)*t;

  Serial.print(h);
  Serial.print(",");
  Serial.print(humidity_smoothed);
  Serial.print(",");
  Serial.print(t);
  Serial.print(",");
  Serial.print(temperature_smoothed);
  Serial.println("");
}
