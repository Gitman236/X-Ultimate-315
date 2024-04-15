#ifndef CONTROLS_H
#define CONTROLS_H

#include "vex.h"


void PistonLegacy(motor29 name,bool status);
void Piston(digital_out name,bool status);
void ChasisSpinSpd(char side, int spd);//1 for left side,0 for right side. spd 0-100
void ChasisSpinVol(char side, float vol);//1 for left side,0 for right side. vol -12----0-----12
void ChasisStopSlow();

void ChasisStop(brakeType brakeTypee);
void intake(int speed,std::string dir);

// void wing(bool status);
// void hang(bool status);



#endif