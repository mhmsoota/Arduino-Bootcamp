#include <Arduino.h>
#include <Servo.h>
#include <NewPing.h>

//Our L298 control pins(motor driver)
#define LeftMotorForward 7
#define LeftMotorBackward 6
#define RightMotorForward 4
#define RightMotorBackward 5
#define Enable1n2 8
#define Enable3n4 9

//Sonar Sensor Pins
#define trig_pin A1
#define echo_pin A2

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance);
Servo servo_motor;

boolean fire = false;
/*#define pump 8
  #define f_sensors 9
*/

int readPing()
{
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0) cm = 250;
  return cm;
}
int lookRight()
{
  servo_motor.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}
int lookLeft()
{
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}
void moveStop()
{
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}
void moveForward()
{
  if (!goesForward)
  {
    goesForward = true;

    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);

    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
  }
}
void moveBackward()
{
  goesForward = false;
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
}
void turnRight()
{
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  delay(500);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward,LOW);
  digitalWrite(RightMotorBackward, LOW);
}
void turnLeft()
{
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  delay(500);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void setup()
{
  pinMode(RightMotorForward,OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
//pinMode(pump, OUTPUT);
//pinMode(f_sensors, INPUT);
/* ----Required for L293 enable pins----
  pinMode(Enable1n2,OUTPUT);
  pinMode(Enable3n4, OUTPUT);

  digitalWrite(Enable1n2, HIGH);
  digitalWrite(Enable3n4, OUTPUT);
*/

  servo_motor.attach(10);     //Servo Pin only allowed on 9 and 10 pins

  servo_motor.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop()
{
  /* int fire = digitalRead(f_sensors);
     if (fire==HIGH)
     {
       digitalWrite(pump,HIGH);
       fire = true;
       moveStop();
     }
     else
     {
       digitalWrite(pump,LOW);
       fire = false;
     }
  */
  int distanceRight = 0, distanceLeft = 0;
  delay(50);
  if (distance<=20)
  {
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);
    if (distanceRight >= distanceLeft)
    {
      turnRight();
      moveStop();
    }
    else
    {
      turnLeft();
      moveStop();
    }
  }
  else 
    moveForward();
  distance = readPing();
}