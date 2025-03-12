#define BLYNK_TEMPLATE_ID "TMPL6kGsXKNxE"
#define BLYNK_TEMPLATE_NAME "ESP8266"
#define BLYNK_AUTH_TOKEN "XW0wHD2kI5aPXepVegdMnIr1Y0tXQQMC" // Keep this secret

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi Credentials
char ssid[] = "Shohan";       // Your WiFi SSID
char pass[] = "shn12345";     // Your WiFi Password

// Define a pin for controlling an LED (example: GPIO2 - D4 on ESP8266)
#define LED_PIN D0

BLYNK_WRITE(V0) {
  int pinValue = param.asInt(); // Get value from Blynk Slider
  digitalWrite(LED_PIN, pinValue); // Control LED with slider
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT); // Set LED pin as output

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi Disconnected! Reconnecting...");
    WiFi.begin(ssid, pass);
    delay(5000); // Wait before retrying
  }
  
  Blynk.run();
}
