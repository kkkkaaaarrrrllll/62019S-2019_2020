#include "main.h"

void blueSmallZone() 
{
    runIntk(80);
    delay(500);
    runIntk(0);
    moveBase(1000, 1000, 2000, 100);
    runIntk(40);
    moveBase(2000, 2000, 7000, 100);
    runIntk(0);
    moveBase(500, -100, 1000, 100);
    moveBase(100, -500, 1000, 100);
    moveBase(1000, 1000, 1000, 100);
    runTray(-50);
    delay(200);
    runIntk(20);
    moveBase(-100, -100, 2000, 100);

}