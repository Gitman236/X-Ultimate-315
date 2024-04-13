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
  LRF.stop(coast);
  LRM.stop(coast);
  LRB.stop(brake);
  RRF.stop(coast);
  RRM.stop(coast);
  RRB.stop(brake);
}

void ChasisSpinSpd(char side, int spd)//spd -100----0----100 底盘运动
{
  if (side =='L')//LEFT
  {
  LRF.spin(fwd, 0.12*spd, volt);
  LRM.spin(reverse, 0.12*spd, volt);
  LRB.spin(reverse, 0.12*spd, volt);
  }
  if (side=='R')//RIGHT
  {
  RRF.spin(fwd, 0.12*spd, volt);
  RRM.spin(reverse, 0.12*spd, volt);
  RRB.spin(reverse, 0.12*spd, volt);
  }
  
}
void ChasisSpinVol(char side, float vol)// vol -12----0-----12 底盘运动（用voltage模式控制可以达到最大速度并跳过内置pid，此处两个函数都最终使用voltage实现）
{
  if (side == 'L')
  {
  LRF.spin(fwd, vol, volt);
  LRM.spin(reverse, vol, volt);
  LRB.spin(reverse, vol, volt);
  }
  if (side== 'R')
  {
  RRF.spin(fwd, vol, volt);
  RRM.spin(reverse, vol, volt);
  RRB.spin(reverse, vol, volt);
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
  
void CataMove()
{
  while(1)  {
    if (CataStatus == "stop")
    {
      Catapult.stop();
    }
    else if (CataStatus == "shoot")
    {
      Catapult.spin(forward,9,volt); 
    }
    else if (CataStatus == "down")
    {
      Catapult.setPosition(0,degrees);
      while(!(PuncherSensor.pressing()) && !(CataStatus == "shoot") )//仅当限位开关未被按下且没有手动按下发射的情况下撞针才能下落
      {
        Catapult.setVelocity(30,rpm);
        Catapult.spinFor(2,degrees,true);
      }
      
    }
  //   if (Controller1.ButtonR1.pressing())
  //   {    
  //     CataUp =1;
  //     Catapult.spin(forward,9,volt); 
  //   }
  //   else if (Controller1.ButtonR2.pressing())
  //   {
  //     while (CataUp)
  //     {
  //       Catapult.setVelocity(20,rpm);
  //       Catapult.spinFor(1,degrees);
  //       if (PuncherSensor.pressing())
  //       {
  //         CataUp = 0;
  //         Catapult.spinFor(0.5,degrees);
  //       }
  //       wait(50,msec);
  //     }
      
  //   }
  //   else if (Controller1.ButtonR2.pressing())
  //   {
  //     Catapult.stop();
  //   }
  //   wait(20,msec);
  // }
  // if (spinmode =="shoot")
  // {
  //  CataUp =1;
  //  Catapult.spin(forward,9,volt); 
  // }
  // else if (spinmode =="down")
  // {
  //   while (CataUp)
  //   {
  //     Catapult.setVelocity(20,rpm);
  //     Catapult.spinFor(1,degrees);
  //     if (PuncherSensor.pressing())
  //     {
  //       CataUp = 0;
  //       Catapult.spinFor(0.5,degrees);
  //     }
  //     wait(50,msec);
  //   }
    

  // else if (spinmode =="stop&down")
  // {
  //   Catapult.stop();
  // }
  }
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
