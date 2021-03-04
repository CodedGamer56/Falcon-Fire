#include"FalconCore.h"

void FalconCore::beginSession(){
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  readyComponents();
  
  while(true){
    if(readyState == true){
      digitalWrite(ledGreen, HIGH);
      break;
    }
    digitalWrite(ledRed, HIGH);
    delay(ledDelays);
    digitalWrite(ledRed, LOW);
    delay(ledDelays);
  }
}

void FalconCore::endSession(){
  
}

void FalconCore::readyComponents(){
  readyState = false;
}
