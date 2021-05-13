#include<Servo.h>

class FF_CORE {
 public:
        void attachPins();
        void runTests();
        
        Servo servoR;
        Servo servoL;
        Servo motorR;
        Servo motorL;

        bool testClear = false;

};
