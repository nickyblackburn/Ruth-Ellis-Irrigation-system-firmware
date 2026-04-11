#include <Arduino.h>

// Analog soil sensor pins (A1 - A4)
const int SOIL_SENSOR_1 = 1;
const int SOIL_SENSOR_2 = 2;
const int SOIL_SENSOR_3 = 3;
const int SOIL_SENSOR_4 = 4;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }
  Serial.println("Soil sensor reader starting");
}

void loop() {
  int v1 = analogRead(SOIL_SENSOR_1);
  int v2 = analogRead(SOIL_SENSOR_2);
  int v3 = analogRead(SOIL_SENSOR_3);
  int v4 = analogRead(SOIL_SENSOR_4);

  Serial.print("Sensor 1 (A1): "); Serial.println(v1);
  Serial.print("Sensor 2 (A2): "); Serial.println(v2);
  Serial.print("Sensor 3 (A3): "); Serial.println(v3);
  Serial.print("Sensor 4 (A4): "); Serial.println(v4);
  Serial.println("---");

  delay(1000);
}
