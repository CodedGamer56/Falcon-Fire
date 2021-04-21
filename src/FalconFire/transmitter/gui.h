#include<LiquidCrystal.h>

int rs=10;
int en=9;
int d4=5;
int d5=4;
int d6=3;
int d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void lcdBegin();
void lcdPrint();
void lcdClear();
