#include"falconCore.h"

FF_CORE falcon;

void setup() {
  Serial.begin(9600);
  falcon.attachPins();
  falcon.runTests();
}
 

void loop() {
  
}
