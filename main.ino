//----- Variablendefinition -----//
const uint16_t stepspruefung = 10; //nicht dokumentierte Fall
extern bool distance;   //Roboter zu nah an Hindernis
extern int blinkerRechts;   
extern int blinkerLinks;    

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
extern void blink(int pin, bool anaus);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  StepperInit();
}


// ----------------------------------------------- Main loop ----------------------------------------------- //
void loop() { 
  while(true)  {
    
    LineUpdate(); //laesst den Sensor "sensor" die Daten in den Variablen Typ (siehe oben) aktualisieren

    //------- weiss-schwarz-weiss -------//
    if(leftBool && !midBool && rightBool)  {
        Serial.println("wsw");
        Vorwaertsfahren(1);
        LineUpdate();
    }
    
    //------- weiss-weiss-schwarz -------//
    else if(leftBool && midBool && !rightBool) {
        Serial.println("wws");
        turnright();       //dreht solang nach rechts bis wieder auf schwarz
      	LineUpdate();
    }

    //------- schwarz-weiss-weiss -------//
    else if(!leftBool && midBool && rightBool) {
        Serial.println("sww");
        turnleft();     //dreht solang nach links bis wieder auf schwarz
      	LineUpdate();
    }
    
    //------- Hindernis erkannt -------//
    else if(!distance) 
    {
      blink(pinLinks, true);
      blink
    }
    
    //------- nicht dokumentierter Fall -------//
    else {
       Serial.println("----");
       Vorwaertsfahren(stepspruefung);
       LineUpdate();
    }
  }
}
