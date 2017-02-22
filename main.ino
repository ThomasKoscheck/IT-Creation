//----- Libraries -----//
#include "Motors.h"

//----- Initialisierungen -----//
extern void Vorwaertsfahren(int steps);
extern void Zurueckfahren(int steps);
extern void Linksfahren(int steps);
extern void Rechtsfahren(int steps);
extern void MotorStop();
extern void setSpeedRight(uint16_t speed);
extern void setSpeedLeft(uint16_t speed);


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  // turn on motor
  motorlinks.setSpeed(200);
  motorrechts.setSpeed(200);
  motorlinks.run(RELEASE);
  motorrechts.run(RELEASE);
}

void loop() {  
  motor.run(FORWARD);
  motor.run(BACKWARD);
  motor.setSpeed(i);  
  motor.run(RELEASE);
  delay(1000);
}
