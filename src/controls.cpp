#include "controls.h"

using namespace vex;
using string = std::string;

void ChasisStop(brakeType brakeTypee)
{
  LRF.stop(brakeTypee);
  LRM.stop(brakeTypee);
  LRB.stop(brakeTypee);
  RRF.stop(brakeTypee);
  RRM.stop(brakeTypee);
  RRB.stop(brakeTypee);
}
void ChasisStopSlow()
{
  LRF.stop(coast);
  LRM.stop(coast);
  LRB.stop(brake);
  RRF.stop(coast);
  RRM.stop(coast);
  RRB.stop(brake);
}

void ChasisSpinSpd(char side, int spd)//spd -100----0----100
{
  if (side =='L')//LEFT
  {
  LRF.spin(fwd, 0.12*spd, volt);
  LRM.spin(fwd, 0.12*spd, volt);
  LRB.spin(fwd, 0.12*spd, volt);
  }
  if (side=='R')//RIGHT
  {
  RRF.spin(fwd, 0.12*spd, volt);
  RRM.spin(fwd, 0.12*spd, volt);
  RRB.spin(fwd, 0.12*spd, volt);
  }
  
}
void ChasisSpinVol(char side, float vol)// vol -12----0-----12
{
  if (side == 'L')
  {
  LRF.spin(fwd, vol, volt);
  LRM.spin(fwd, vol, volt);
  LRB.spin(fwd, vol, volt);
  }
  if (side== 'R')
  {
  RRF.spin(fwd, vol, volt);
  RRM.spin(fwd, vol, volt);
  RRB.spin(fwd, vol, volt);
  }
  
}

void PistonLegacy(motor29 name,bool status)
{
  name.setVelocity(100,percent);
  if (status==1)
  {name.spin(forward);}
  if (status==0)
  {name.stop();}
}

void Piston(digital_out name,bool status)
{
  if (status==1)
  {name.set(1);}
  if (status==0)
  {name.set(0);}
}



void intake_spin(int dir){
  if (dir == 1){Intake.spin(fwd,12,volt);}
  if (dir == 0){Intake.spin(reverse,12,volt);} 
  

}

void RunIntake(bool dir,int time, int speed )
{
Intake.spin(fwd,12,volt);
wait(time,msec);
Intake.stop();
ChasisStopSlow();



}
// void wing(bool status)
// {
//   if (status == 1)//wing open
//   {
//   Piston(WingL,1);
//   Piston(WingR,1);
//   }

//   if  (status == 0)//wing close
//   {
//   Piston(WingL,0);
//   Piston(WingR,0);
//   }
// }

// void hang(bool status)
// {
//   if (status == 1)//hang deploy
//   {
//   Piston(HangL,1);
//   Piston(HangR,1);
//   }

//   if  (status == 0)//hang close
//   {
//   Piston(HangL,0);
//   Piston(HangR,0);
//   }
// }
