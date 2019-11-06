#include "main.h"

Controller master (E_CONTROLLER_MASTER);

ADIAnalogIn trayPot(8);

Motor leftBase1 (8, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS);
Motor leftBase2 (11, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS);
Motor rightBase1 (10, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_COUNTS);
Motor rightBase2 (16, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_COUNTS);
Motor intake1 (4, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_COUNTS);
Motor intake2 (2, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_COUNTS);
Motor tray1 (20, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_COUNTS);
Motor tray2 (21, E_MOTOR_GEARSET_06, 0, E_MOTOR_ENCODER_COUNTS);