#include"gui.h"
#include<LiquidCrystal.h>

LiquidCrystal lcd(10,9,5,4,3,2);

void guiBegin(){
  lcd.begin(16,2);
  lcd.setCursor(0,0);  
  lcdPrint("AlphaHAWK");
  lcd.setCursor(5,1);
  lcdPrint("FalconFire");
  delay(2000);  
  lcdClear();
  lcd.setCursor(0,0); 
  lcdPrint("Version 1.0b");
  lcd.setCursor(5,1); 
  lcdPrint("Start→");
  
  lcd.setCursor(0,0); 
  
  while(true){
    if (switchVal == 1) {
      lcdClear(); 
      lcdPrint("DroneSys");  
      lcd.setCursor(0,1);
      lcdPrint("testing...");
      break; 
    }
    else {
      lcdPrint("FalconFire");
    }
  }
  //the receiver signal part goes over here
}

void lcdPrint(String toPrint){
  lcdPrint(toPrint);
}

void lcdClear(){
  lcdClear();
}
