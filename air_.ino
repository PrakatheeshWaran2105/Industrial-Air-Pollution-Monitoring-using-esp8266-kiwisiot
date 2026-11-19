#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// WiFi Credentials
const char* ssid = "wifi name ";
const char* pass = "wifi password";

// KiwisIoT Topic ID
const char* topic = "dash_1791367866871";

// MQ-135 Sensor Pin
#define MQ135_PIN A0

// Example threshold only
const int AIR_THRESHOLD = 500;

// KiwisIoT Object
KiwisIoT kiwisiot(ssid, pass, topic);

// Timer
unsigned long previousMillis = 0;
const unsigned long interval = 2000;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("================================");
  Serial.println("Industrial Air Pollution Monitoring");
  Serial.println("================================");

  pinMode(MQ135_PIN, INPUT);

  Serial.println("MQ-135 Sensor Initialized");
  Serial.println("Starting KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialization returned");
}

void loop() {

  // Maintain KiwisIoT connection
  kiwisiot.run();

  // Read sensor every 2 seconds
  if (millis() - previousMillis >= interval)