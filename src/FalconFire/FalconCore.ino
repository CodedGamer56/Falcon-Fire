#include"FalconCore.h"
#include<Servo.h>

void beginSession(){
  //11 - red led
  //12 - green led
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  Servo servoR;
  Servo servoL;
  Servo motorR;
  Servo motorL;
  servoR.attach(9);
  servoL.attach(8);
  motorR.attach(6);
  motorL.attach(7);
  servoR.write(0);
  servoL.write(0);
  
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

  //MPU 6050 Calibration

  
  //end of tests
  lcdClear();
  lcdPrint("Ready for flight");
  testClear = true;
}

void endSession(){

}
