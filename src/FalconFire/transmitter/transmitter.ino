#include"transmitter.h"
#include"gui.h"

int joyx = A0;
int joyy = A1;
int pot = A5;
int joyxval;
int joyyval;
int potval;
int potConverted;

void setup(){
  Serial.begin(9600);
  pinMode(joyx,INPUT);
  pinMode(joyy,INPUT);
   
  lcdBegin();
  lcdPrint("FALCON FIRE");
  lcdPrint("Version 1.0b");
  //lcdPrint("Running tests...");

  //connection to serial monitor (only for tests)
  Serial.println("Falcon Fire");
}

void loop(){
  joyyval = analogRead(joyy);
  joyxval = analogRead(joyx);
  potV = analogRead(pot);
  potConverted = (5/1023)*potval);

  Serial.print("JoyX: ");
  Serial.println(joyxval);
  Serial.print("JoyY: ");
  Serial.println(joyyval);
  Serial.print("Pot: ");
  Serial.println(potConverted);
  delay(100);
}
