#include "main.h"

int autonCount = 0;

double sgn(double x) {         // returns sign (-1 or 1) of a number, and 0 for 0
    return (x > 0) - (x < 0);  // really cool way of finding sign of a number
}

void betterDelay(int ms) {  // delays for a certain number for milliseconds
    std::uint_least32_t now = millis();

    for (int i = 0; i < ms; i++) {  // loop for how many milliseconds passed through

        Task::delay_until(&now, 1);  // iterate 1000 times per second
    }
}

void disabled() {  // disable all subsystems
}

void initialize() {                                  // set motor break modes and start subsystem tasks
    leftBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);   //set break mode to coast, a.k.a. no background motor control
    leftBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);   //set break mode to coast, a.k.a. no background motor control
    rightBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);  //set break mode to coast, a.k.a. no background motor control
    rightBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);  //set break mode to coast, a.k.a. no background motor control
    leftRoller.set_brake_mode(E_MOTOR_BRAKE_HOLD);   //set break mode to hold, a.k.a. background motor control holds motor's current position
    rightRoller.set_brake_mode(E_MOTOR_BRAKE_HOLD);  //set break mode to hold, a.k.a. background motor control holds motor's current position
    liftMtr.set_brake_mode(E_MOTOR_BRAKE_HOLD);      //set break mode to coast, a.k.a. no background motor control
    trayMtr.set_brake_mode(E_MOTOR_BRAKE_COAST);     //set break mode to coast, a.k.a. no background motor control

    Task trayControl(trayTask, (void *)"PROS", "PID Controlled Tray");  //allocate memory to run tray PID control in background
    Task liftControl(liftTask, (void *)"PROS", "PID Controlled Lift");  //allocate memory to run lift PID control in background

    liftMtr.tare_position();
}

void competition_initialize() {  //display auton selector
    lv_obj_t *label = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_recolor(label, true);

    while (competition::is_disabled()) {
        autonCount = (int)floor(5 * randoPot.get_value() / 4095.0);

        switch (autonCount) {
            case 0:
                lv_label_set_text(label, "#ffff00 Do Nothing#");
                break;

            case 1:
                lv_label_set_text(label, "#0000ff blue small zone#");
                break;

            case 2:
                lv_label_set_text(label, "#0000ff BLUE BIG ZONE#");
                break;

            case 3:
                lv_label_set_text(label, "#ff0000 red small zone#");
                break;

            case 4:
                lv_label_set_text(label, "#ff0000 RED BIG ZONE#");
                break;

            default:
                lv_label_set_text(label, "#ffffff Error#");
                break;
        }

        lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);

        betterDelay(100);  //iterate 10 times a second
    }
}

void autonomous() {  //run auton that was selector from auton selector
    switch (autonCount) {
        case 0:
            //do nothing
            break;

        case 1:
            blueSmallZone();
            break;

        case 2:
            blueBigZone();
            break;

        case 3:
            redSmallZone();
            break;

        case 4:
            redBigZone();
            break;

        default:
            //do nothing
            break;
    }
}

void opcontrol() {  //run driver controls
    std::uint_least32_t now = millis();

    liftTaskActive = false;

    while (true) {  //loop indefinitely

        pwrLeftBase(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) * 100 / 127);
        pwrRightBase(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) * 100 / 127);

        if (master.get_digital(E_CONTROLLER_DIGITAL_R1))
            pwrRollers(100);

        else if (master.get_digital(E_CONTROLLER_DIGITAL_R2))
            pwrRollers(-100);

        else
            pwrRollers(0);

        if (master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
            trayTaskActive = true;
            trayTarget = TRAY_FULL_UP;

            leftRoller.set_brake_mode(E_MOTOR_BRAKE_COAST);
            rightRoller.set_brake_mode(E_MOTOR_BRAKE_COAST);
        }

        else if (master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
            trayTaskActive = false;
            pwrTray(-100);
        }

        else {
            trayTaskActive = false;
            pwrTray(0);
        }

        if (master.get_digital(E_CONTROLLER_DIGITAL_DOWN)) {
            liftMtr.set_brake_mode(E_MOTOR_BRAKE_HOLD);
            pwrLift(100);
        }

        else if (master.get_digital(E_CONTROLLER_DIGITAL_B)) {
            liftMtr.set_brake_mode(E_MOTOR_BRAKE_HOLD);
            pwrLift(-100);
        }

        else if (liftMtr.get_position() < 100) {
            liftMtr.set_brake_mode(E_MOTOR_BRAKE_COAST);
            pwrLift(0);
        }

        else {
            liftMtr.set_brake_mode(E_MOTOR_BRAKE_HOLD);
            pwrLift(0);
        }

        Task::delay_until(&now, 10);  //iterate 100 times per second
    }
}
