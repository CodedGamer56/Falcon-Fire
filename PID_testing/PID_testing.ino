#include<Servo.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

int pinServo=9;
Adafruit_MPU6050 mpu;
Servo servo;

//PID constants (arbitrary)
float kp = 1;
float ki = 5;
float kd = 3;

void setup(){
  Serial.begin(115200);
  servo.attach(pinServo);
  mpu.begin();
  Serial.println("MPU6050 Found!");
  startMpu6050();
}

void loop(){
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  float accx = a.acceleration.x;
  float accy = a.acceleration.y;
  float gyrox = g.gyro.x;
  float gyroy = g.gyro.y;
  
}

void startMpu6050(){
   mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
 }
}

void PID(float cAccelX, float cGyroX){
  float requiredAX = 20.9; //random number
  float requiredGX = 56.0; //random number
  float errorA = requiredAX - cAccelX; //accelerometer error
  float errorG = requiredGX - cGyroX; //gyro error
  float iFinal;
  float dFinal;
  
  float pFinal = kp*error*10; //limiting the P value between 0 and 10 for some reason
  iFinal += ki*error*timeChange/10;
  
  //I have not figured out the derivative part
}
