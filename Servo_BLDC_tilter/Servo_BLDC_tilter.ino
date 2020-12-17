#include<Servo.h>
Servo servo;
int def=119;
int angle=95;
int angle2=130;
int counter=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Testing the working of servo tilt bldc motor for bicopter project");
  servo.attach(9);
  servo.write(def);
   
}

void loop() {
  Serial.println("Enter 2 to stop");
  while(Serial.available()==0){}
  int st = Serial.parseInt();
  if(st == 2){
    servo.write(def);
  }
  else{
   while(counter != 20){
    for(int i=angle; i<=angle2; i+=1){
      servo.write(i);
      delay(20);
    }
    for(int i=angle2; i>angle; i-=1){
      servo.write(i);
      delay(20);
    }
    servo.write(def);
    counter++;
  }
 }
}
