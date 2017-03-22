//----- Variablendefinition -----//
const uint16_t stepspruefung = 10; //nicht dokumentierte Fall
  //-----Sensorwerte der Farbsensoren -----//
  extern bool leftBool;
  extern bool midBool;
  extern bool rightBool;

//----- Libraries -----//
#include "Motors.h"
#include "Sensors.h"

//----- Initialisierungen -----//
extern void Vorwaertsfahren(int steps);
extern void Zurueckfahren(int steps);
extern void Linksfahren(int steps);
extern void Rechtsfahren(int steps);
extern void MotorStop();
extern void setSpeedRight(uint16_t speed);
extern void setSpeedLeft(uint16_t speed);
extern void StepperInit();

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  StepperInit();
}

void loop() { 
  while(true)
  {
    //------- weiss-schwarz-weiss -------//
    if(leftBool && !midBool && rightBool)  {
        Serial.println("wsw");
        Vorwaertsfahren(1);
        LineUpdate();
    }
    
    //------- nicht dokumentierter Fall -------//
    else {
       Serial.println("----");
       Vorwaertsfahren(stepspruefung);
       LineUpdate();
    }
  }
}
