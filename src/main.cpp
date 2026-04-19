#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

const int sensorPins[] = {34, 35, 32, 33}; // REAL analog pins

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {
  int total = 0;

  for (int i = 0; i < 4; i++) {
    total += analogRead(sensorPins[i]);
  }

  float avg = total / 4.0;

  HTTPClient http;
  http.begin("http://YOUR_SERVER_IP:8000/api/bed-data");
  http.addHeader("Content-Type", "application/json");

  String json = "{";
  json += "\"bed_id\":\"bed_1\",";
  json += "\"average\":" + String(avg) + ",";
  json += "\"sensors\":[";

  for (int i = 0; i < 4; i++) {
    json += String(analogRead(sensorPins[i]));
    if (i < 3) json += ",";
  }

  json += "],\"valve_state\":\"OFF\"}";

  http.POST(json);
  http.end();

  delay(3000);