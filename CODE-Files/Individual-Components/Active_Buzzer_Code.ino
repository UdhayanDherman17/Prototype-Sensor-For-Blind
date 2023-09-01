/*The following code beeps twice when an anaolg signal is sent to the buzzer pin*/

//the header file needed to be able to sue differnet frequencies
#include "pitches.h"
int b_pin = 4;
//Function that beeps at 2 differnt frequncies for 200ms and with a 800ms delay interval
void dead_battery(){
  tone(b_pin, NOTE_DS8, 200);
  delay(800);
  tone(b_pin, NOTE_CS8, 200); 
}

//pin setup and function call
void setup() {
  pinMode(b_pin,OUTPUT);
  dead_battery();
}

void loop() {
  //NULL
}
