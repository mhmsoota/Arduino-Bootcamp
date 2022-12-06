#include <Arduino.h>
int codeArray[10][7] = {{1,1,1,1,1,0,1},        //0
                        {0,1,1,0,0,0,0},        //1
                        {1,1,0,1,1,1,0},        //2
                        {1,1,1,1,0,1,0},        //3
                        {0,1,1,0,0,1,1},        //4
                        {1,0,1,1,0,1,1},        //5
                        {1,0,1,1,1,1,1},        //6
                        {1,1,1,0,0,0,0},        //7
                        {1,1,1,1,1,1,1},        //8
                        {1,1,1,0,0,1,1}};       //9

void Num_Write (int number)
{
  int pin=2;
  for (int j=0; j<7; j++)
  {
     digitalWrite(pin,codeArray[number][j]);
     pin++;
  } 
  delay(40);
}

void setup() 
{
  for (int i=2;i<9;i++)
    pinMode(i,OUTPUT) ;
}

void loop() 
{
  for (int counter=10;counter>0;--counter)
  {
    delay(1000);
    Num_Write(counter-1);
  }
  delay(3000);
}