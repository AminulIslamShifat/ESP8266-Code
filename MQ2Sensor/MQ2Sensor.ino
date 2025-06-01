#define BLYNK_TEMPLATE_ID "TMPL6kGsXKNxE"
#define BLYNK_TEMPLATE_NAME "ESP8266"
#define BLYNK_AUTH_TOKEN "XW0wHD2kI5aPXepVegdMnIr1Y0tXQQMC"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Shohan";      
char pass[] = "shn12345";  

#define MQ_SENSOR A0  

BlynkTimer timer;

void sendSensor() {
  int Gaslevel = analogRead(MQ_SENSOR);
  int gasPercentage = map(Gaslevel, 0, 1023, 0, 100);

  Blynk.virtualWrite(V3, gasPercentage);
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(MQ_SENSOR, INPUT);
  
  timer.setInterval(2000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
