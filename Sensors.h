short leftPin=9;      
short midPin=2;       
short rightPin=8;
short distancePin=10;

bool leftBool;
bool midBool;
bool rightBool;
bool distance;

const short farbBorder = 68;
//const short midBorderIR = 180;
//const short rightBorderIR = 140

void SensorUpdate(){
  leftBool =  analogRead(leftPin) >= farbBorder ? true : false;
  midBool =   analogRead(leftPin) >= farbBorder ? true : false;
  rightBool =  analogRead(leftPin) >= farbBorder ? true : false;
  distance = analogRead(distancePin) == HIGH ? true : false;
}
