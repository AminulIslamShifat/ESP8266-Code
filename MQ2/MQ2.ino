int mqSensor = A0;
int Gaslevel;
int gasPercentage;

void sendSensor(){
  Gaslevel = analogRead(mqSensor);
gasPercentage = map(Gaslevel, 0, 1023, 0, 100);
Serial.print(gasPercentage);Serial.println('%');
}

void setup() {
  Serial.begin(115200);
  pinMode(mqSensor, INPUT);

}

void loop() {
sendSensor();
delay(500);
}
