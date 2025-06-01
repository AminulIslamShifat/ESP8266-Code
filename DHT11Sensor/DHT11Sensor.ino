#define BLYNK_TEMPLATE_ID "TMPL6kGsXKNxE"
#define BLYNK_TEMPLATE_NAME "ESP8266"
#define BLYNK_AUTH_TOKEN "XW0wHD2kI5aPXepVegdMnIr1Y0tXQQMC" 

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"

char ssid[] = "Shohan";      
char pass[] = "shn12345";  

#define DHTPIN 14  // Corrected: D5 = GPIO14
#define DHTTYPE DHT11    

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;  // Use BlynkTimer instead of SimpleTimer

void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: "); Serial.print(h); Serial.println("%");
  Serial.print("Temperature: "); Serial.print(t); Serial.println("°C");

  Blynk.virtualWrite(V1, h);  
  Blynk.virtualWrite(V2, t);  
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, sendSensor);  // Corrected: Using BlynkTimer
}

void loop() {
  Blynk.run();
  timer.run();
}
