#include <Arduino.h>
#include "lcd.h"

/*
LCD::LCD(uint8_t address, uint8_t cols,uint8_t rows)
    : lcd(address,cols,rows){
      lcd.init();
    }
*/

LCD::LCD(uint8_t address,uint8_t cols, uint8_t rows,uint8_t sda, uint8_t scl)
    : lcd(address,cols,rows,sda,scl){
    lcd.init();
}

void LCD::printStandby(){
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Operational");
}

void LCD::printDate(String _date, String _time){
  lcd.setCursor(0, 1);
  lcd.print(_date);
  lcd.print(" ");
  lcd.print(_time);
}

void LCD::printKeyData(uint8_t user, uint8_t amount){

}

void LCD::printError(int errorCode){

}

void LCD::off(){
  lcd.clear();
  lcd.noBacklight();
}

bool LCD::testLcd(){
  return 0;
}