#ifndef TRUEAUTON_H
#define TRUEAUTON_H

#include "vex.h"
#include "PID.h"
#include "PreAuton.h"
#include "controls.h"
extern bool SkillsSet;
extern int RouteSet;
extern bool autodone;
extern float turnspeed;
void StartAuton();
void SkillsAuton();

void auton1();
void auton2();
void auton3();
void auton4();



#endif