#include"gui.h"

void lcdBegin(){
  lcd.begin(16,2);
  lcd.setCursor(0,0);
}

void lcdPrint(String toPrint){
  lcd.print(toPrint);
}

void lcdClear(){
  lcd.clear();
}
