#include<Servo.h>
Servo motor1;
Servo motor2;

class kk2{
  public:
      void define(){
         motor1.attach(9);
         motor2.attach(10);
         motor1.write(0);
         motor2.write(0);
        Serial.begin(9600);
        Serial.println("Connected with kk2.2 flight controller");
      }
      void throttle(int Speed){
         if(Serial.available()){
            while(Speed = Serial.parseInt()){
               Serial.print("Throttle set at: ");
               Serial.println(Speed);
               motor1.writeMicroseconds(Speed);
               delayMicroseconds(10);
                motor2.writeMicroseconds(Speed);
           }
         }
      }
};

kk2 drone;

void setup(){
  drone.define();
}

void loop(){
  int motorSpeed;
  char reply;
  Serial.println("Do you want to run the motors? (Type y for yes or Type n for no)");
  reply = Serial.read();

  switch(reply){
    case 'y':
          Serial.println("Enter your throttle speed");
          motorSpeed = Serial.parseInt();
          drone.throttle(motorSpeed);
          break;
    case 'n':
            Serial.println("Ok");
            Serial.println("Type r if you want to run the motors");
            reply = Serial.read();
            if(reply == 'r'){
              Serial.println("Enter your throttle speed");
               motorSpeed = Serial.parseInt();
              drone.throttle(motorSpeed);
            }
            else{
                Serial.println("Invalid input");
                Serial.println("");
            }
            break;
  } 
  
}
