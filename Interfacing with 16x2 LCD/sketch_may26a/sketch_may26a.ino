#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8,7,6,5,4,3);     //For 8-bit mode
//LiquidCrystal lcd(13,12,11,6,5,4,3);            //For 4 bit mode

//any custom characters for callibration
unsigned char Character1[8]={0x04,0x19,0x01,0x09,0x1F,0x04,0x19,0x01};
unsigned char Character2[8]={0x01,0x03,0x07,0x1F,0x01,0x08,0x1A,0x0C};

void setup() {
  lcd.begin(16,2);                    //Initialise 16x2 LCD
  lcd.clear();                        //Clear the LCD
  lcd.createChar(0, Character1);      //Generate custom characters
  lcd.createChar(0, Character2);
}

void loop() {
  lcd.setCursor(0,0);                 //Set cursor to column 0 row 0
  lcd.print("Hello!!!!");             //Print data on display
  lcd.setCursor(0,1);
  lcd.write(byte(0));                 //Write a character to display
  lcd.write(1);
}
