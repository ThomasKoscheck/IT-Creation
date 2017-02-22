#include <AFMotor.h>
AF_DCMotor motorlinks(1);
AF_DCMotor motorrechts(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  // turn on motor
  motorlinks.setSpeed(200);
  motorrechts.setSpeed(200);
  motorlinks.run(RELEASE);
  motorrechts.run(RELEASE);
}

void loop() {
  uint8_t i;
  
  
  motor.run(FORWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(10);
 }
  
  Serial.print("tock");

  motor.run(BACKWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(10);
 }
  

  Serial.print("tech");
  motor.run(RELEASE);
  delay(1000);
}
