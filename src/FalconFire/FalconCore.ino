#include"systemMaintainer.h"

void FF_CORE::attachPins(){
  //11 - red led
  //12 - green led
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  
  servoR.attach(9);
  servoL.attach(8);
  
  motorR.attach(6);
  motorL.attach(7);
  
  servoR.write(0);
  servoL.write(0);
}

void FF_CORE::runTests(){
    //start sequence
  for(int i=0; i<3; i++){
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    delay(100);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    delay(100);
  }

  //servo tests
  for(int i=50; i<=130; i++){
    servoR.write(i);
    servoL.write(i);
    delay(10);
  }
  delay(1000);
  for(int i=130; i>=50; i--){
    servoR.write(i);
    servoL.write(i);
    delay(10);
  }

  servoR.write(0);
  servoL.write(0);

  //motor tests
  motorR.write(1000);
  motorL.write(1000);
  motorR.write(2000);
  motorL.write(2000);
  delay(1000);
  motorR.write(1000);
  motorL.write(1000);

  systemPrint("Finished running tests");
  testClear = true;
}
