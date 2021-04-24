#include"gui.h"

int joyx = A0;
int joyy = A1;
int pot = A5;
int switchJoy = 1;

int switchVal;
int joyxval;
int joyyval;
int potval;
int potConverted;

void setup(){
  Serial.begin(9600);
  
  pinMode(joyx,INPUT);
  pinMode(joyy,INPUT);
  pinMode(switchJoy, INPUT);
  
  guiBegin();
  //connection to serial monitor (only for tests)
  Serial.println("FalconFire System");
}

void loop(){
  joyyval = analogRead(joyy);
  joyxval = analogRead(joyx);
  potval = analogRead(pot);
  switchVal = digitalRead(switchJoy);
  potConverted = (5/1023)* potval;//why is this 5/1023 

  Serial.print("JoyX: ");
  Serial.println(joyxval);
  Serial.print("JoyY: ");
  Serial.println(joyyval);
  Serial.print("Pot: ");
  Serial.println(potConverted);
  Serial.print("Switch: ");
  Serial.println(switchVal);
  delay(100);
}
//side note: we should add 3 buttons and one switch
//also switch turns everything on
//the three buttons
//pitch
//yaw
//roll
