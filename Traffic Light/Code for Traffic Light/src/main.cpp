#include <Arduino.h>
int redLight=13, yellowLight=12, greenLight=11;
int redWait=20, yellowWait=2, greenWait=15;

void setup() {
  pinMode(redLight,OUTPUT)  ;
  pinMode(yellowLight,OUTPUT);
  pinMode(greenLight,OUTPUT);
}

void loop() 
{
  digitalWrite(redLight, HIGH);
  delay(redWait*1000);
  digitalWrite(redLight, LOW);
  digitalWrite(yellowLight, HIGH);
  delay(yellowWait*1000);
  digitalWrite(yellowLight, LOW);
  digitalWrite(greenLight, HIGH);
  delay(greenWait*1000);
  digitalWrite(greenLight, LOW);
}  