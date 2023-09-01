#include <NewTone.h>
/*Initializing pin*/
int echo = 9;
int trig = 8;
int b_pin = 4;
int motorPin3  = 5; 
int motorPin4  = 6;  
int enA = 3; 

/*define variables*/
long duration; 
int distance;

/*Initializing pin modes*/
void setup() {
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT); 
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(b_pin,OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(9600);    
}

/*"danger" function signals buzzer pin at frequency of 800 for 100 micro-seconds
and then turn off the buzzer for 100 micro-seconds*/
void danger(){
  NewTone(b_pin, 800);
  delay(100);
  noNewTone(b_pin);
  delay(100);
}

/*"beware" function signals buzzer pin at frequency of 600 for 300 micro-seconds
and then turn off the buzzer for 300 micro-seconds*/
void beware(){
  NewTone(b_pin, 600);
  delay(300);
  noNewTone(b_pin);
  delay(300);
}

/*"careful" function signals buzzer pin at frequency of 500 for 300 micro-seconds
and then turn off the buzzer for 500 micro-seconds*/
void careful(){
  NewTone(b_pin, 300);
  delay(500);
  noNewTone(b_pin);
  delay(500);
}

/*"UltraSonic" function will active the trig pin to send out a sonic burst 
 * and the echo pin will wait for an input of the sonic burst, we gives 
 * the time of travel to an obstruction and back. We can then use the 
 * formula: "distance = (time)(speed)" to find the distance between the user 
 and a obstruction*/
int UltraSonic(){
  /*Clears the trigPin condition*/
  digitalWrite(trig, LOW);
  delay(0.002); 
  
  /*Activate TRIGPIN for 10 microseconds*/
  digitalWrite(trig, HIGH);
  delay(0.01);
  digitalWrite(trig, LOW);
  
  /*Reads ECHOPIN, returns the time the waves travelled forward and back*/
  duration = pulseIn(echo, HIGH);
  
  /*We only want the time it takes to go forward so we can correspomd that 
   * time with the distance 
    it travells forward */
  distance = duration * 0.034 / 2;
  return distance;  
}
  
/*"Motor_20_60" function sends a signal to motorPin3 and motorPin4 acts as GND  
 * allowing the DC motor to rotate at default frequency of 500Hz 
 * and at 180 duty cycle 
 */
void motorClose(){  
    analogWrite(enA, 200);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);  
}
/*"Motor_60_80" function sends a signal to motorPin3 and motorPin4 acts as GND  
 * allowing the DC motor to rotate at default frequency of 500Hz 
 * and at 120 duty cycle 
 */
void motorFar(){  
    analogWrite(enA, 150);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);  
}

/*"motorOFF" function sets both pins to low as they now they both act as GND*/ 
void motorOFF(){
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}


/*This fucntion use the Volatge Divider circuit to then read values at pin A0, which is between 0 and 1023.Then calculating the 
true value using the "true volatage" formula. */
float B_Life(){
  int sensorValue = analogRead(A0); //read the A0 pin value
  float voltage = sensorValue * (5.00 / 1023.00) * 2; //convert the value to a true voltage.
  return voltage;
}



/*The following code captures the distance from the "Ultrasonic" function which
is then used to activate different functions relative to the distance value*/
void loop() {
  int dist = UltraSonic();
  Serial.println(dist);
  motorOFF();
  
  /*The statement triggers if the variable "dist" outputs a value larger than 
  60 but less than 80, which then calls function  "carful()*/
  if (dist > 100 && dist < 150 ){ 
    careful();
  }
  /*The statement triggers if the variable "dist" outputs a value larger than 
  30 but less than 60, which then calls function "motorFar()" and "beware()*/
  if (dist > 50 && dist < 100 ){ 
    motorFar();
    beware();
  }
  
   /*The statement triggers if the variable "dist" outputs a value larger than 
  0 but less than 30, which then calls function "motorClose()" and "danger()*/
  if (dist > 0 && dist < 50 ){
    motorClose(); 
    danger();
  }
  delay(250);
}
/*END*/
