#include <ESP8266WiFi.h>
#include "DHT.h"

#define DHTPIN 14  
#define DHTTYPE DHT11    

DHT dht(DHTPIN, DHTTYPE);

void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: "); Serial.print(h); Serial.println("%");
  Serial.print("Temperature: "); Serial.print(t); Serial.println("°C");
}

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  sendSensor();
  delay(2000); 
  }