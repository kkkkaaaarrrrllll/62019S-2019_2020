#include "main.h"

void blueSmallZone6() { //6 pts

    runIntk(90);
    moveBase(1000, 1000, 800, 85);
    moveBase(2400, 2400, 2700, 37.5);
    runIntk(20);
    moveBase(675, -675, 910, 45);
    moveBase(500, 500, 660, 52.5);
    moveBase(-675, 675, 910, 45);
    runIntk(71.5);
    moveBase(1250, 1250, 1350, 65);
    runIntk(23.75);
    moveBase(-2100, -2100, 1350, 80);
    moveBase(-1050, 1050, 1100, 50);
    runTray(-30);
    moveBase(2450, 2450, 1900, 55);
    runIntk(40);
    delay(130);
    runIntk(0);
    preciseTray(3990, 1200);
    delay(100);
    runIntk(-7);
    delay(400);
    runIntk(-80);
    delay(150);
    runTray(20);
    delay(250);
    runTray(0);
    delay(300);
    runLeftBase(-55);
    runRightBase(-55);
    delay(2000);
    runLeftBase(0);
    runRightBase(0);

}