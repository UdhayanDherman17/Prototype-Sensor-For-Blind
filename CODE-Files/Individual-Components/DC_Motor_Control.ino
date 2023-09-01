/*The following code Spin a DC motor in one direction at varying speeds using PWM*/

int motorPin = 10;

int Speed = 80; //Variable to store Speed, limits [50 <= speed <= 225]

void setup(){
	pinMode(motorPin, OUTPUT); //Set pin 3 as an OUTPUT
}

/*The looped code has 2 second delay intervals where a signal is sent to pin 3 and depending
on the speed, the width of the pulse form the analog signal increases proportional to that parameter.*/
void loop(){	
  delay(2000);
	analogWrite(motorPin, Speed);
  delay(2000);
	analogWrite(motorPin, Speed + 20);
  delay(2000);
	analogWrite(motorPin, Speed - 40);
}

