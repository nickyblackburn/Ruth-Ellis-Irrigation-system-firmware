#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

// Analog soil sensor pins (A1 - A4)
const int SOIL_SENSOR_1 = 1;
const int SOIL_SENSOR_2 = 2;
const int SOIL_SENSOR_3 = 3;
const int SOIL_SENSOR_4 = 4;

 // Digital pin for water pump control
const int WATER_PUMP_PIN = 5;

/*
Setups the hardware components, such as initializing the soil sensor pins as input.
*/
void hardwareSetup() {
  // Initialize soil sensor pins as input
  pinMode(SOIL_SENSOR_1, INPUT);
  pinMode(SOIL_SENSOR_2, INPUT);
  pinMode(SOIL_SENSOR_3, INPUT);
  pinMode(SOIL_SENSOR_4, INPUT);

  // Initialize water pump control pin as output
  pinMode(WATER_PUMP_PIN, OUTPUT);
}

void readSoilMoisture() {
  int moisture1 = analogRead(SOIL_SENSOR_1);
  int moisture2 = analogRead(SOIL_SENSOR_2);
  int moisture3 = analogRead(SOIL_SENSOR_3);
  int moisture4 = analogRead(SOIL_SENSOR_4);


}

void setup() {
hardwareSetup();
}

void loop() {


  delay(1000);
}
