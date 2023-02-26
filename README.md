# Control_DC_Motor
Arduino program to control the speed and direction of a DC Motor using a potentiometer.

# Description

This code controls the speed and direction of a DC motor using an Arduino board and a potentiometer.
The potentiometer is connected to an analog input pin of the Arduino board, and the motor is connected to two digital output pins through a motor driver chip. 
The code reads the value of the potentiometer and maps it to a range of 0 to 255, which corresponds to the range of PWM duty cycle that can be applied to the motor to control its speed. 
The direction of the motor can be changed by pressing a switch connected to a digital input pin of the Arduino board.
The code uses a variable called "direction" to keep track of the current direction of the motor and toggles it between forward and backward when the switch is pressed. 
The code runs in an infinite loop and constantly updates the motor speed and direction based on the potentiometer value and switch state. 
A small delay is added at the end of each loop iteration to ensure stability.

This was created for a lesson. The code 'Control_DC_Motor.ino' has a lot of comments to help explain the process and reasons.
