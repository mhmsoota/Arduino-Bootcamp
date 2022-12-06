#include <Arduino.h>

//Using pulse width modulation and analogWrite
//No need to do this much, can just dopower on for certain value

int minLights, maxLights;
void setup()
{
  pinMode(11,OUTPUT);                                                  //Our streetlight Pin
  Serial.begin(9600);                                                  //For taking minimum and maximum
  Serial.println("Set the light as the darkest it can be");            //values of photoresistor
  Serial.println("Waiting for just 4 seconds");
  delay(4000);
  minLights = analogRead(A0);
  Serial.println("Set the light as the brightest it can be");
  Serial.println("Waiting for just 4 seconds");
  delay(4000);
  maxLights = analogRead(A0);
  Serial.print("All the readings done!");
  Serial.end();
}

void loop()
{
  int currentLights = analogRead(A0);
  currentLights= 255*(1-(float(currentLights-minLights)/(maxLights-minLights)));     //Converts the lights to 
  if (currentLights>150)                                                        //scale of 1-255 according 
   analogWrite(11,currentLights);                                               //to analogWrite
  else
    digitalWrite(11,LOW);
}