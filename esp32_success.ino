#include <WiFi.h>

const char* ssid = "ESP32-Access-Point";
const char* password = "your_PASSWORD";

void setup() {
  Serial.begin(9600);

  // Set up ESP32 as an access point
  WiFi.softAP(ssid, password);

  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // Your code here
}