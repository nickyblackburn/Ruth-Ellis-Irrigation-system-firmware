#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// webserver on port 80
WebServer server(80);

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
  Serial.println("Reading soil moisture levels...");
  int moisture1 = analogRead(SOIL_SENSOR_1);
  int moisture2 = analogRead(SOIL_SENSOR_2);
  int moisture3 = analogRead(SOIL_SENSOR_3);
  int moisture4 = analogRead(SOIL_SENSOR_4);
Serial.println("Red soil moisture levels...");
}

// Base json object to hold all the data

void dataJson(int sensor_name, int sensor_data_raw,int sensor_data_avg, bool valve_state) {
   StaticJsonDocument<200> doc;

  doc["timestamp"] = millis();
  doc["sensor"] = sensor_name;
  doc["moisture_raw"] = sensor_data_raw;
  doc["moisture_avg"] = sensor_data_avg;
  doc["valve_state"] = valve_state;

  String output;
  serializeJson(doc, output);

  server.send(200, "application/json", output);
}
/*
Endpoints for the web server will be defined here, such as handling requests to read soil moisture levels or control the water pump.
*/



void handleSensorData() { dataJson(1,1,1,1); }


void setup() {
hardwareSetup();
}

void loop() {


  delay(1000);
}
