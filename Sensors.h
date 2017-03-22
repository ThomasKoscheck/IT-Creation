short farLeftPin=3;   //analog Pin 
short leftPin=9;      //digital Pin 
short midPin=2;       //analog Pin 
short rightPin=8;     //digital Pin 
short farRightPin=1;  //analog Pin 

bool leftBool;
bool midBool;
bool rightBool;

const short leftBorderIR = 68;
const short midBorderIR = 180;
const short rightBorderIR = 140;
const short borderFarb = 8;

void LineUpdate(){
  farLeftBool = analogRead(farLeftPin) >= leftBorderIR ? true : false;
  leftBool =  pulseIn(leftPin, digitalRead(leftPin) == HIGH ? LOW : HIGH) <= borderFarb ? true : false;
  midBool = analogRead(midPin) >= midBorderIR ? true : false;
  rightBool =  pulseIn(rightPin, digitalRead(rightPin) == HIGH ? LOW : HIGH) <= borderFarb ? true : false;
  farRightBool = analogRead(farRightPin) >= rightBorderIR ? true : false;
}
