#include <Arduino.h>

int l,r;
void setup()
{
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
}
void loop()
{
  r=digitalRead(2);
  l=digitalRead(3);
  Serial.begin(9600);
  Serial.println(r);
  Serial.println(l);
  if(r==HIGH && l==HIGH)
  {
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }
  else if(r==HIGH && l==LOW)
  {
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
  }
  else if(r==LOW && l==HIGH)
  {
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
   }
  else if(r==LOW && l==LOW)
  {
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
  }
    
 delay(100);
}
    