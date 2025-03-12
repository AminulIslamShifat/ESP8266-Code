int buttonstate;
void setup() {
pinMode (D1, OUTPUT); 
pinMode (D2, INPUT); 
}
void loop() {
buttonstate = digitalRead (D2); 
if (buttonstate == HIGH) 
{
digitalWrite(D1, LOW); // led on 
}
else {
digitalWrite(D1, HIGH);
}
}