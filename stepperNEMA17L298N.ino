
/*
 Connections - L298N

 One coil of the motor is connected to Motor-1 on L298N
 Other coil is connected to Motor-2 on L298N

 The control pins of the L298N are attached to digital pins 8 - 11 of the Arduino.

 */

#include <Stepper.h>

// NEMA17 has 200 steps in one Revolution
// 50 Teeth on Rotor and 4 Pole pairs

const int stepsPerRevolution = 200;  

// change this to fit the number of steps per revolution for your motor

// initialize the stepper library on pins 8 through 11

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // Experiment with rpm. 60, 1, 100, 200, 300, 350 
  // My motor runs smoothly maximum at 300 rpm
  // You can find the limits for your motor
  // Beyond, it misses the steps

  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}

