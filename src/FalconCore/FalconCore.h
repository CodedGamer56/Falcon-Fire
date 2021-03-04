#include"..\\Motors\\Motors.h"
#include"..\\PID\\PID.h"
#include"..\\RadioControl\\radio.h"

class FalconCore{
public:
  void beginSession();
  void endSession();
  void readyComponents();
private:
  int ledGreen = 10;
  int ledRed = 11;
  int ledDelays = 1000;
  bool readyState = false;
  
};
