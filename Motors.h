#ifndef motors_h
#define motors_h
#include <AFMotor.h>

AF_DCMotor motorLinks(1);
AF_DCMotor motorRechts(2);

int pinRechts = 8;
int pinLinks = 9;

void StepperInit()  {
    Shield.begin();
    motorLinks.setSpeed(110);
    motorRechts.setSpeed(110);
}

void Vorwaertsfahren(int steps = 10) {
    for(int count = 0; count <= steps; count++)
    {
        motorLinks.run(FORWARD);
        motorRechts.run(FORWARD);
    }
}

void Linksfahren(int steps = 10) {
    blink(pinLinks, true);
    for(int count = 0; count <= steps; count++)
    {
        motorLinks.run(BACKWARD);
        motorRechts.run(FORWARD);
    }
    blink(pinLinks, false);
}

void Rechtsfahren(int steps = 10) {
    blink(pinRechts, true);
    for(int count = 0; count <= steps; count++)
    {
        motorLinks.run(FORWARD);
        motorRechts.run(BACKWARD);
    }
    blink(pinLinks, false);
}

void Zurueckfahren(int steps = 10) {
    blink(pinLinks, true);
    blink(pinRechts, true);
    for(int count = 0; count <= steps; count++)
    {
        motorLinks.run(BACKWARD);
        motorRechts.run(BACKWARD);
    }
    blink(pinLinks, false);
    blink(pinRechts, false);
}

void MotorStop() {
   motorLinks.run(RELEASE);
   motorRechts.run(RELEASE);
}

void setSpeedLeft(uint16_t speed = 200)  {
    motorLinks.setSpeed(speed);
}

void setSpeedRight(uint16_t speed = 200)    {
    motorRechts.setSpeed(speed);
}

void blink(int pin, bool anaus)
{
   pinMode(pin, OUTPUT);
   
   if(anaus)
   {
     digitalWrite(pin, HIGH);
   }
    
   else if(anaus == false)
   {
     digitalWrite(pin, LOW);
   } 
}


#endif
