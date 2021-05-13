#include"UI.h"
#include<LiquidCrystal.h>

LiquidCrystal lcd(10,9,5,4,3,2);

void uiBegin(){
  lcd.begin(16,2);
  lcd.setCursor(0,0);  
  lcd.print("AlphaHAWK");
  lcd.setCursor(5,1);
  lcd.print("FalconFire");
  delay(2000);
    
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Version 1.0b");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(1,5); 
  lcd.print("Start→");
  
  while(true){
    if (switchVal == 1) {
      lcd.clear(); 
      lcd.setCursor(0,0);
      lcd.print("DroneSys");  
      lcd.setCursor(1,1);
      lcd.print("testing...");
      break; 
    }
    else {
      lcd.setCursor(0,0);
      lcd.print("Falcon Fire");
    }
  }
  //the receiver signal part goes over here
  lcd.clear();
}
