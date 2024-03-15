#ifndef PID_H
#define PID_H

#include "vex.h"

extern int Side;
void Run_gyro(double enc , double power, float g);
void Turn_Gyro(float target);
#endif