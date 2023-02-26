/* This is an Arduino program that controls the speed and direction of a DC motor
using a potentiometer, push button, and a L293D motor driver. 
The program defines the pin numbers for the potentiometer, motor outputs 1 and 2, 
motor enable, and direction switch.
It also initializes the potentiometer value, motor speed value, and motor direction. */

// Define the input/output pin numbers and initial variable values
const int potPin = A0;         // pin number for the potentiometer
const int motorPin1 = 2;       // pin number for motor output 1
const int motorPin2 = 3;       // pin number for motor output 2
const int enablePin = 9;       // pin number for motor enable
const int directionPin = 4;    // pin number for the direction switch
int potValue = 0;              // initial potentiometer value
int motorSpeed = 0;            // initial motor speed value
int direction = 1;             // initial motor direction (1 = forward, -1 = backward)


/* The setup function configures the potentiometer pin as an input and the motor outputs and enable as outputs.
The direction switch is also set as an input with a pull-up resistor, 
so that it reads HIGH when the switch is not pressed. */

// Configure the input/output pins in the setup function
void setup() {
  pinMode(potPin, INPUT);      // set the potentiometer pin as an input
  pinMode(motorPin1, OUTPUT);  // set motor output 1 as an output
  pinMode(motorPin2, OUTPUT);  // set motor output 2 as an output
  pinMode(enablePin, OUTPUT);  // set motor enable as an output
  pinMode(directionPin, INPUT_PULLUP); // set direction switch as an input with pull-up
}

/* The program reads the potentiometer value using the analogRead function, which returns a value between 0 and 1023.
This value is then mapped to a range of 0 to 255, which corresponds to the PWM duty cycle that controls the motor speed. */

// Read the potentiometer value and map it to the motor speed range:
void loop() {
  potValue = analogRead(potPin); // read the potentiometer value
  
  // map the potentiometer value to a motor speed range of 0 to 255
  motorSpeed = map(potValue, 0, 1023, 0, 255);

/* The program checks if the direction switch is pressed by reading its state using digitalRead.
 If the switch is pressed (reads LOW),
 the program toggles the motor direction between forward and backward by multiplying the direction variable by -1. */
// Read the direction switch and change direction if pressed
  if (digitalRead(directionPin) == LOW) {
    direction *= -1;  // toggle direction between forward and backward
  }

/* The program drives the motor in the current direction by setting the motor outputs 1 */
  // drive the motor in the current direction
  if (direction == 1) {
    digitalWrite(motorPin1, HIGH);   // set output 1 high
    digitalWrite(motorPin2, LOW);    // set output 2 low
  } else {
    digitalWrite(motorPin1, LOW);    // set output 1 low
    digitalWrite(motorPin2, HIGH);   // set output 2 high
  }
  analogWrite(enablePin, motorSpeed); // set PWM duty cycle
  
  delay(10); // small delay for stability
}

/* Note that you will need a power supply capable of providing sufficient voltage and current to the motor. 
The power supply should be connected to the L293D IC and the motor, 
and the GND pin of the Arduino should be connected to the GND pin of the power supply.
/*

/*************** Extention ************************
Play with the program and figures to make the motor: 
- more responsive
- the range accurate to the input
- the pushbutton into a transitioned reverse in direction
***************************************************/
