#include"FalconCore.h"

void beginSession(){
  //11 - red led
  //12 - green led
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  
  fromFalconCore("Falcon Fire has started");

  digitalWrite(11,HIGH);
  delay(1000);
  digitalWrite(11,LOW);
  delay(1000);
}

void endSession(){
  
}
