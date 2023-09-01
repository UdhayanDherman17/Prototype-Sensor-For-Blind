/*The following code sequentially lights up the 2 LED's in 200ms intervals*/


//Setting up pinmodes as outputs
void setup() {
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
}

//Turning ON all LEDS with 200ms intervals and then truning them all OFF with 200ms intervals
void loop() {
  digitalWrite(12,LOW);
  delay(200);
  digitalWrite(11,LOW);
  delay(200);
  digitalWrite(12,HIGH);
  delay(200);
  digitalWrite(11,HIGH);
  delay(200); 
}
