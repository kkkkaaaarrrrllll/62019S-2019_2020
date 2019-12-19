#include "main.h"

Controller master (E_CONTROLLER_MASTER); //initializing main and only controller as the master controller

ADIEncoder leftEnc (1, 2, 0); //legacy ports A and B, not reversed
ADIEncoder rightEnc (3, 4, 1); //legacy ports C and D, reversed
ADIAnalogIn trayPot (5); //legacy port E
ADIAnalogIn liftPot (6); //legacy port F

Motor leftBase1 (1, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS); //v5 port 1, 200 rpm, not reversed, returns its encoder value in raw untis
Motor leftBase2 (2, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS); //v5 port 2, 200 rpm, not reversed, returns its encoder value in raw untis
Motor rightBase1 (3, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_COUNTS); //v5 port 3, 200 rpm, reversed, returns its encoder value in raw untis
Motor rightBase2 (4, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_COUNTS); //v5 port 4, 200 rpm, reversed, returns its encoder value in raw untis
Motor leftRoller (5, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS); //v5 port 5, 200 rpm, not reversed, returns its encoder value in raw untis
Motor rightRoller (6, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_COUNTS); //v5 port 6, 200 rpm, reversed, returns its encoder value in raw untis
Motor trayMtr (7, E_MOTOR_GEARSET_36, 0, E_MOTOR_ENCODER_COUNTS); //v5 port 7, 100 rpm, not reversed, returns its encoder value in raw untis
Motor liftMtr (8, E_MOTOR_GEARSET_36, 0, E_MOTOR_ENCODER_COUNTS); //v5 port 8, 100 rpm, not reversed, returns its encoder value in raw untis