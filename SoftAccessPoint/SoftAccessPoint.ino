#include<ESP8266WiFi.h>
#include<DNSServer.h>
#include<WiFiManager.h>

WiFiManager wifi;

void setup() {
  
  Serial.begin(115200);
  wifi.autoConnect("Sifat");
Serial.println("connect to Sifat");
}

void loop() {
 

}
