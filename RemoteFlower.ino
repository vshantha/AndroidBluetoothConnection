#include <LiquidCrystal.h>
//#include <Servo.h> 
#include <VarSpeedServo.h>
 
int led1 = 4 ;//Blue
int led2 = 5 ;
int led3 = 6;

 
int servoPin = 9;
 
VarSpeedServo servo;  
 
int angle = 0;   // servo position in degrees 

 

//Char used for reading in Serial characters
char inbyte = 0;
//*******************************************************************************************
 
void setup() {
  // initialise serial communications at 9600 bps:
  Serial.begin(9600);
  servo.attach(servoPin);
 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  
  servo.slowmove(90,30);
}
 
void loop() {
 
  //when serial values have been received this will be true
  if (Serial.available() > 0)
  {
    inbyte = Serial.read();
    if (inbyte == '0')
    {
      //LED off
      //digitalWrite(led1, HIGH);
      //digitalWrite(led2, LOW);
      setColor(255, 0, 0);  // red
      delay(5000);
      setColor(0, 255, 0);  // green
      delay(5000);
      setColor(0, 0, 255);  // blue
      delay(5000);
      setColor(255, 255, 0);  // YELLOW
      delay(5000);
      servo.slowmove(10,30);
      
    }
    if (inbyte == '1')
    {
      //LED on
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      servo.slowmove(220,30);
      setColor(255, 0, 0);  // red
      delay(5000);
      setColor(0, 255, 0);  // green
      delay(5000);
      setColor(0, 0, 255);  // blue
      delay(5000);
      setColor(255, 255, 0);  // YELLOW
      delay(5000);
      blink(led2);
      
      
      
      
    }

     if (inbyte == '2')
    {
      //LED on
     if(servo.read()>0){
      servo.slowmove(10,30);
      
     }

     setColor(255, 255, 0);  // Yellow
      delay(5000);
      setColor(0, 255, 0);  // green
      delay(5000);
      setColor(0, 0, 255);  // blue
      delay(5000);
      
      blink(led2);
      
      
      
      
    }

    if (inbyte == '3')
    {
      //LED on
     if(servo.read()>0){
      servo.slowmove(135,30); 
     }
     setColor(255, 15, 150);  // red
      delay(1000);
      setColor(0, 255, 0);  // green
      delay(1000);
      setColor(0, 0, 255);  // blue
      blink(led2);
   }

   if (inbyte == '4')
    {
     for(int i=0;i<130;i++){
      servo.slowmove(i,200);
     }
   }
  }
  //delay by 2s. Meaning we will be sent values every 2s approx
  //also means that it can take up to 2 seconds to change LED state
  delay(500);
}
 


void blink(int ledNumber)
{
  for(int i=0;i<6;i++){
    
 
  digitalWrite(ledNumber, HIGH);
  delay(200);
  digitalWrite(ledNumber, LOW);
  delay(200);
  digitalWrite(ledNumber, HIGH);
  setColor(255, 0, 0);  // red
      delay(1000);
      setColor(0, 255, 0);  // green
      delay(1000);
      setColor(0, 0, 255);  // blue
      delay(1000);
      setColor(255, 255, 0);  // Yellow
}



}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(led1, red);
  analogWrite(led2, green);
  analogWrite(led3, blue);  
}




