#ifndef PREAUTON_H
#define PREAUTON_H

#include "vex.h"
#include "TrueAuton.h"


extern float Start ;

extern color AllianceSet;
extern bool SkillsSet;
extern int RouteSet;






void MotorInitialization();
void InertialInitialization();
// void Selector();
void Joystick_Selector();
#endif