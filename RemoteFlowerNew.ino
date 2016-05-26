#include <VarSpeedServo.h>

int led3 = 4 ;//Blue
int led1 = 5 ;// RED
int led2 = 6 ;// GREEN

int servoPin = 9;
VarSpeedServo servo;  
int angle = 0;   // servo position in degrees
//Char used for reading in Serial characters
char inbyte = 0;
//*******************************************************************************************

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
// Initialize Pins and switch on the LED
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  
// Reset Servo angle
  servo.slowmove(90,30);

}

void loop() {
  
  
  if (Serial.available() > 0)
  {
    inbyte = Serial.read();
    if (inbyte == '0')
    {
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      servo.slowmove(220,30);
      
      
     }
    if (inbyte == '1')
    {
      
      servo.slowmove(10,30);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      
      
    }
    if (inbyte == '2')
    {
      if(servo.read()>0){
      servo.slowmove(10,30);
      }
      delay(5000);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      
    }

    if (inbyte == '3')
    {
      
      blink(led3);
      
    }
  }

}

void blink(int ledNumber)
{
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
        for(int i=0;i<20;i++){
          digitalWrite(ledNumber, HIGH);
         delay(200);
          digitalWrite(ledNumber, LOW);
          delay(200);
          digitalWrite(ledNumber, HIGH);
      
  }
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
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
