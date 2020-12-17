#include<Servo.h>
Servo motor1;

void setup(){
  motor1.attach(9);
  Serial.begin(9600);
}

void loop(){
  Serial.println("BLDC test workspace");
  
}
