#include"FalconCore.h"
#include"Servo.h"

void beginSession(){
  //11 - red led
  //12 - green led
  pinMode(11,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);

  Servo servoR;
  Servo servoL;
  
  servoR.attach(9);
  servoL.attach(8);

  if(digitalRead(9) == 0 || digitalRead(8) == 0){
    Serial.println("Falcon Fire has detected an error with the servos");
    return;  
  }
  
  int ledSignal;
  
  fromFalconCore("Falcon Fire has started");
  
   for(int i=0; i<5; i++)
   {
    digitalWrite(11,HIGH);;
    delay(1000);
    digitalWrite(11,LOW);
    delay(1000);
   }

   fromFalconCore("Falcon Fire has started servos");

   //Servo tests
   for(int i=50; i<130; i++)
   {
    servoR.write(i);
   }
   for(int i=130; i<50; i--)
   {
    servoR.write(i);
   }
   
   for(int i=50; i<130; i++)
   {
    servoL.write(i);
   }
   for(int i=130; i<50; i--)
   {
    servoL.write(i);
   }

   //default servo position
   servoR.write(90);
   servoL.write(90);
    
   for(int i=0; i<2; i++)
   {
    digitalWrite(LED_BUILTIN,HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN,LOW);
    delay(1000);
   }
}

void endSession(){
  
}
