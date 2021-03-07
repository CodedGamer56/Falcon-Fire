#include"FalconCore.h"
#include<Servo.h>

void beginSession(){
  //11 - red led
  //12 - green led
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);

  Servo servoR;
  Servo servoL;
  
  Servo motorR;
  Servo motorL;

  motorR.attach(5, 1000, 2000);
  motorL.attach(4, 1000, 2000);
  
  servoR.attach(9);
  servoL.attach(8);

  fromFalconCore("Falcon Fire has started");
  ledBlinks();
  
  /*
  if(digitalRead(9) == 0 || digitalRead(8) == 0){
    fromFalconCore("Falcon Fire has detected an error with the servos");
    return;  
  }
  else if(digitalRead(5) == 0 || digitalRead(4) == 0){
    fromFalconCore("Falcon Fire has detected an error with the motors");
    return;
  }
  */
  //Servo tests
  fromFalconCore("Falcon Fire has started servos");
  
   for(int i=0; i<2; i++){
    for(int i=0; i<=170; i++)
    {
      servoR.write(i);
      delay(10);
    }
    for(int i=170; i<=0; i--)
    {
      servoR.write(i);
      delay(10);
    }
   
    for(int i=0; i<=170; i++)
    {
      servoL.write(i);
      delay(10);
    }
    for(int i=170; i<=0; i--)
    {  
      servoL.write(i);
      delay(10);
    }
   }
   //default servo position
   servoR.write(90);
   servoL.write(90);
    
   ledBlinks();
   
   //ESC, Motor tests
   fromFalconCore("Falcon has started motors");
   
   motorR.write(1500);
   delay(3000);
   motorR.write(1000);
   delay(1000);
   motorL.write(1500);
   delay(3000);
   motorL.write(1000);

   ledBlinks();

   fromFalconCore("Falcon Fire is ready to fly");
   digitalWrite(11,HIGH);
   return;
}

void endSession(){
  
}

void ledBlinks(){
  
  digitalWrite(11,LOW);
  delay(5);
  for(int i=0; i<3; i++){
   digitalWrite(12,HIGH);
   delay(100);
   digitalWrite(12,LOW);
   delay(100);
  }
  digitalWrite(11,HIGH);

  return;
}
