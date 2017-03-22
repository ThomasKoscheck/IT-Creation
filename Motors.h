#ifndef motors_h
#define motors_h
#include <AFMotor.h>

AF_DCMotor motorLinks(1);
AF_DCMotor motorRechts(2);

int blinkerRechts = 8;
int blinkerLinks = 9;

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
    blink(blinkerLinks, true);
    for(int count = 0; count <= steps; count++)
    {
        motorLinks.run(BACKWARD);
        motorRechts.run(FORWARD);
    }
    blink(blinkerLinks, false);
}

void Rechtsfahren(int steps = 10) {
    blink(blinkerRechts, true);
    for(int count = 0; count <= steps; count++)
    {
        motorLinks.run(FORWARD);
        motorRechts.run(BACKWARD);
    }
    blink(blinkerRechts, false);
}

void Zurueckfahren(int steps = 10) {
    blink(blinkerLinks, true);
    blink(blinkerRechts, true);
    for(int count = 0; count <= steps; count++)
    {
        motorLinks.run(BACKWARD);
        motorRechts.run(BACKWARD);
    }
    blink(blinkerLinks, false);
    blink(blinkerRechts, false);
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
