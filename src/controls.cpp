#include "controls.h"

using namespace vex;
using string = std::string;

void ChasisStop(brakeType brakeTypee)//底盘停止运动（带指定停止类型）
{
  LRF.stop(brakeTypee);
  LRM.stop(brakeTypee);
  LRB.stop(brakeTypee);
  RRF.stop(brakeTypee);
  RRM.stop(brakeTypee);
  RRB.stop(brakeTypee);
}
void ChasisStopSlow()//底盘停止运动（带指定停止类型）
{
  LRF.stop(brake);
  LRM.stop(coast);
  LRB.stop(brake);
  RRF.stop(brake);
  RRM.stop(coast);
  RRB.stop(brake);
}

void ChasisSpinSpd(char side, int spd)//spd -100----0----100 底盘运动
{
  if (side =='L')//LEFT
  {
  LRF.spin(reverse, 0.12*spd, volt);
  LRM.spin(fwd, 0.12*spd, volt);
  LRB.spin(fwd, 0.12*spd, volt);
  }
  if (side=='R')//RIGHT
  {
  RRF.spin(reverse, 0.12*spd, volt);
  RRM.spin(fwd, 0.12*spd, volt);
  RRB.spin(fwd, 0.12*spd, volt);
  }
  
}
void ChasisSpinVol(char side, float vol)// vol -12----0-----12 底盘运动（用voltage模式控制可以达到最大速度并跳过内置pid，此处两个函数都最终使用voltage实现）
{
  if (side == 'L')
  {
  LRF.spin(reverse, vol, volt);
  LRM.spin(fwd, vol, volt);
  LRB.spin(fwd, vol, volt);
  }
  if (side== 'R')
  {
  RRF.spin(reverse, vol, volt);
  RRM.spin(fwd, vol, volt);
  RRB.spin(fwd, vol, volt);
  }
  
}

void PistonLegacy(motor29 name,bool status)//former cable气缸运动 弃用
{
  name.setVelocity(100,percent);
  if (status==1)
  {name.spin(forward);}
  if (status==0)
  {name.stop();}
}

void Piston(digital_out name,bool status)//new cable 气缸控制
{
  if (status==1)
  {name.set(1);}
  if (status==0)
  {name.set(0);}
}



// void intake_spin(int dir){
//   if (dir == 1){Intake.spin(fwd,12,volt);}
//   if (dir == 0){Intake.spin(reverse,12,volt);} 
  

// }

void intake(int speed,std::string dir)//吸球(可与run_gyro 同时运行) 速度0-100；【i】吸入in/【o】吐出out/【s】停止stop
{
  
  if (dir == "in")
  {Intake.spin(forward,12*speed/100,volt);}
  else if (dir == "out")
  {Intake.spin(reverse,12*speed/100,volt);}
  else if (dir == "stop")
  Intake.stop(hold);
  
  

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
