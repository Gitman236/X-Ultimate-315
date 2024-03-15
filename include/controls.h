#ifndef CONTROLS_H
#define CONTROLS_H

#include "vex.h"

void Piston(digital_out name,bool status);
void ChasisSpinSpd(char side, int spd);//1 for left side,0 for right side. spd 0-100
void ChasisSpinVol(char side, float vol);//1 for left side,0 for right side. vol -12----0-----12
void ChasisStopSlow();

void ChasisStop(brakeType brakeTypee);
void intake_spin(int time);
void RunIntake(bool dir,int time, int speed );
// void wing(bool status);
// void hang(bool status);



#endif