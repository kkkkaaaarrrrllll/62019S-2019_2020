#include "main.h"

int autonCount = 0;

void disabled() {



}

void initialize() {

    leftBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);
    leftBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);
    rightBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);
    rightBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);
    intake1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    intake2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    tray.set_brake_mode(E_MOTOR_BRAKE_COAST);
    arms.set_brake_mode(E_MOTOR_BRAKE_COAST);

    //Task trayControl (trayTask, (void*)"PROS", "PID Controlled Tray");
    //Task armsControl (armsTask, (void*)"PROS", "PID Controlled Arms");

}

void competition_initialize() {



}

void autonomous() {



}

void opcontrol() {

	std::uint_least32_t now = millis();

    while(true) {

        runLeftBase(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) * 100 / 127);
        runRightBase(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) * 100 / 127);

        if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
            runRollers(100);

        else if(master.get_digital(E_CONTROLLER_DIGITAL_R2))
            runRollers(-100);

        else
            runRollers(0);

        if(master.get_digital(E_CONTROLLER_DIGITAL_L1))
            runTray(60);

        else if(master.get_digital(E_CONTROLLER_DIGITAL_L2))
            runTray(-100);

        else
            runTray(0);

        Task::delay_until(&now, 20);

    }

}
