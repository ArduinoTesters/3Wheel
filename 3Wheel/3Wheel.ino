#include <Servo.h>

#define trigPin 3
#define echoPin 2

float duration, distance;

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

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);



}

void loop() {

/*
  while (executed == true){
    Serial.println("Executing Test!");
    final();
    executed = false;
  }
*/

  final();
  Serial.println("Still running loop");
  
  //echo();

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

void echo() {

  // Write a pulse to the HC-SR04 Trigger Pin

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the response from the HC-SR04 Echo Pin

  duration = pulseIn(echoPin, HIGH);

  // Determine distance from duration
  // Use 343 metres per second as speed of sound

  distance = (duration/2)*0.0343;

  // Send results to Serial Monitor

  Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2) {
    Serial.println("Out of range");
  }

  else{
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }

  delay(500);


  
}


void detectWall() {

  // Write a pulse to the HC-SR04 Trigger Pin

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the response from the HC-SR04 Echo Pin

  duration = pulseIn(echoPin, HIGH);

  // Determine distance from duration
  // Use 343 metres per second as speed of sound

  distance = (duration/2)*0.0343;

  // Send results to Serial Monitor
  
   // Closing in on Wall
  while (distance <= 15) {

    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");


    Serial.print("Going Backwards!");
    lServo.write(100); //go backwards slowly; left motor go back slowly
    rServo.write(100); // right motor go back slowly
    
    delay(500);

    // STOP
    lServo.write(90); // 90 means stop; left motor stop
    rServo.write(90); // right motor stop

    delay(500);
    
    // THIS IS TURNING LEFT
    Serial.print("Turning Left");
    lServo.write(100); // left motor go backwards slowly
    rServo.write(80); // right motor go forward slowly

    delay(1000);

    // STOP
    lServo.write(90); // 90 means stop; left motor stop
    rServo.write(90); // right motor stop

    delay(500);

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distance = (duration/2)*0.0343;

    delay(1000);

  }
  
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);


  
}


void final() {

  detectWall();

  // go forward slowly
  Serial.print("Going forward!"); 
  lServo.write(80); 
  rServo.write(80);

  delay(500); // delay for 1s
  
  // STOP
  lServo.write(90); // 90 means stop; left motor stop
  rServo.write(90); // right motor stop
  
  delay(500); // delay for 1s

  detectWall();

 

}
