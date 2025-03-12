#include<ESP8266WiFi.h> 
void setup() 
{
// put your setup code here, to run once: 
Serial.begin(115200); 
WiFi.mode(WIFI_STA); // nodemcu as station 
WiFi.begin("SSID", "Password"); 
Serial.print("connecting to wifi"); 
while(WiFi.status() != WL_CONNECTED) ;
{
Serial.print('.'); 
delay (200); 
}
Serial.print("IP Address:"); 
Serial.println(WiFi.localIP()); 
Serial.print("MacAddress:"); 
Serial.println(WiFi.macAddress()); 
} 
void loop() { 
// put your main code here, to run repeatedly;
}