#include <Servo.h>

Servo lServo;
Servo rServo;

bool execute = true;

void setup() {

  lServo.attach(8);
  rServo.attach(9);
}
 
void loop() {

  if(execute == true){
    
    // stop
    lServo.write(90);
    lServo.write(90);
  
    delay(1000);
  
    // move forward
    lServo.write(80);
    rServo.write(80);
  
    delay(1000);
  
    // move backward
    lServo.write(100);
    rServo.write(100);
  
    delay(1000);
  
    // turn right
    lServo.write(80);
    rServo.write(100);
  
    delay(1000);
  
    // turn left
    lServo.write(100);
    rServo.write(80);
  
    delay(1000);
  
    lServo.write(90);
    rServo.write(90);
  }
  execute = false;
}
