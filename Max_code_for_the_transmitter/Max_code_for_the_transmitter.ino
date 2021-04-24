//There were a couple mistakes in your code, I have fixed it and left some comments so that you can know about the changes I made
//Compilation passed without errors!
#include <LiquidCrystal.h>
const int buttonPin = 1;

int buttonState = 0;

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

void setup()
{
  /*
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("AlphaHAWK");
  lcd.setCursor(5,1);//counting begins with 0
  lcd.print("FalconFire");
  delay(1000);
  lcd.clear();
  lcd.print("Version 1.0b");
  lcd.setCursor(0,1);
  lcd.print("Start→");
  pinMode(buttonPin, INPUT);
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    // turn nrf on: supposed to happen
    lcd.print("DroneSys");
    lcd.setCursor(0,1);
    lcd.print("testing");
  }
  else {
  lcd.clear();
  }
  */

  //there were a few mistakes in your code
  lcd.begin(16,2);
  lcd.setCursor(0,0);  //make sure you set the cursor position first
  //Over here you had lcd.clear but actually you don't need it as the lcd has just started
  lcd.print("AlphaHAWK");
  lcd.setCursor(5,1);//counting begins with 0, I don't understand this part
  lcd.print("FalconFire");
  delay(2000);  //one second is a bit less
  lcd.clear();
  lcd.setCursor(0,0); //bro you did not set cursor position here, you can change the position later
  lcd.print("Version 1.0b");
  lcd.setCursor(5,1); //I changed it to 5,1
  lcd.print("Start→");
  pinMode(buttonPin, INPUT);
  buttonState = digitalRead(buttonPin);

  //the code below will run only once so, if the pilot doesn't press the button then we can't run the tests, so we are supposed to make a loop in this part and wait for the user to press a button

  lcd.setCursor(0,0); 
  
  while(true){
    if (buttonState == HIGH) {
      // turn nrf on: supposed to happen
      lcd.clear(); //you forgot this part
      lcd.print("DroneSys");  //I suppose you mean system maintainer here
      lcd.setCursor(0,1);
      lcd.print("testing...");
      break; //we break the loop here so that we can move the test function (sessionBegin func in falconfire)
    }
    else {
      lcd.print("Falcon Fire");
    }
  }

  //falconfire function call comes here
}

void loop() {}
