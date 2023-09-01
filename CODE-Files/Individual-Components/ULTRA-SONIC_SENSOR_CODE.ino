/*The following code obtains electrical signals from the ardinuo to send out a sonic burst of waves
for a finite time and then recive those waves. Thus the time from the initial send of waves to the time of 
reiceve those waves, when have the change in time. We multiply the delta time by the speed of sound and find the distance 
the waves travels foward and back, so which half the time so we only get the distnace on way*/

//define pins
#define echo 9 
#define trig 8 

//define variables
long duration; 
int distance;

//Initializing pin modes
void setup() {
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT); 
  Serial.begin(9600);   
}

void loop() {

  //Clears the trigPin condition
  digitalWrite(trig, LOW);
  delay(0.002); 
  
  //Activate TRIGPIN for 10 microseconds
  digitalWrite(trig, HIGH);
  delay(0.01);
  digitalWrite(trig, LOW);
  
  //Reads ECHOPIN, returns the time the waves travelled forward and back
  duration = pulseIn(echo, HIGH);
  
  //Calculating the distance
  /*We only want the time it takes to go forward so we can correspomd that time with the distance 
    it travells forward */
  distance = duration * 0.034 / 2;
  Serial.print(distance);
  Serial.println("cm");
  delay(500);
}
//END
