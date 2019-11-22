#ifndef _INTAKE_TRAY_H_
#define _INTAKE_TRAY_H_

void runRollers(double percVolt);
void runTray(double percVolt);
void runArms(double percVolt);
void trayTask(void* param);
void armsTask(void* param);

#endif