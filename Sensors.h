short leftPin=9;      
short midPin=2;       
short rightPin=8;    

bool leftBool;
bool midBool;
bool rightBool;
bool distance;

const short leftBorderIR = 68;
const short midBorderIR = 180;
const short rightBorderIR = 140

void SensorUpdate(){
  leftBool =  pulseIn(leftPin, digitalRead(leftPin) == HIGH ? LOW : HIGH) <= borderFarb ? true : false;
  midBool = analogRead(midPin) >= midBorderIR ? true : false;
  rightBool =  pulseIn(rightPin, digitalRead(rightPin) == HIGH ? LOW : HIGH) <= borderFarb ? true : false;
  //IR + Ultraschall
}
