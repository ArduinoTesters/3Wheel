#include <Servo.h>

Servo lServo; //left motor
Servo rServo; //right motor

bool executed = true;

int yellowPin = 8;
int whitePin = 9;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  lServo.attach(8); // attach to pin 8
  rServo.attach(9); // attach to pin 9



}

void loop() {

  while (executed == true){

    Serial.println("Executing Test!");
    test();
    executed = false;
  }

  Serial.println("Still running loop");

}

void test(){

   // put your main code here, to run repeatedly:

  // instructions are numbered from 1-180

  //  THIS IS HOW TO: STOP
  lServo.write(90); // 90 means stop; left motor stop
  rServo.write(90); // right motor stop
 
  delay(1000); // delay for 1s

  
   // any number between 1-89 tells the motor to go forward at a  speed
   // the lower the nubmer the faster the motor, i.e 10 is fast, 80 is slow
  lServo.write(80); // go forward 80; left motor go slow
  rServo.write(80); // right motor go slow

  delay(1000); // delay for 1s

  
  // So if we did 170 it would go backwards relatively fast
  lServo.write(100); //go backwards slowly; left motor go back slowly
  rServo.write(100); // right motor go back slowly

  delay(1000);

  // THIS IS TURNING RIGHT
  lServo.write(80); // left motor go forward slowly
  rServo.write(100); // right motor go backward slowly

  delay(1000);

  // THIS IS TURNING LEFT
  lServo.write(100); // left motor go backwards slowly
  rServo.write(80); // right motor go forward slowly

  delay(1000);

  lServo.write(90);
  rServo.write(90);


  
}
