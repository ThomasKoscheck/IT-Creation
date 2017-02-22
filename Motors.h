#ifndef motors_h
#define motors_h
#include <AFMotor.h>

AF_DCMotor motorLinks(1);
AF_DCMotor motorRechts(2);

void Vorwaertsfahren(int steps = 10) {
    motorLinks.run(FORWARD);
    motorRechts.run(FORWARD);
}

void Linksfahren(int steps = 10) {
    motorLinks.run(BACKWARD);
    motorRechts.run(FORWARD);
}

void Rechtsfahren(int steps = 10) {
    motorLinks.run(FORWARD);
    motorRechts.run(BACKWARD);
}

void Zurueckfahren(int steps = 10) {
    motorLinks.run(BACKWARD);
    motorRechts.run(BACKWARD)
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

#endif
