#include "joystick.h"
#include "controls.h"
using namespace vex;
using string = std::string;


///////////////遥控手控函数////////////
void Joystick()
{
  double leftvol;
  double rightvol;
  float axis3;
  float axis1;
  // long int axis2;
  // float turn_slow_index =0.95;
  float percent_to_voltage_index=0.12;///0.097 by YUE
  // LRM.setStopping(coast);
  // RRM.setStopping(coast);
  // Intake.setStopping(coast);


  while (1)
  {
  ///////////////////双摇杆控制底盘运动//////////////////
  axis1 =  Controller1.Axis1.position();//input to percent
  axis3 = Controller1.Axis3.position();//input to percent

  Brain.Screen.printAt(20,20,"axis1:%f",axis1);
  Brain.Screen.printAt(20,40,"axis3:%f",axis3);
  leftvol = percent_to_voltage_index*(axis3 + axis1);//3-4 
  rightvol = percent_to_voltage_index*(axis3 - axis1);//3+4
  Brain.Screen.printAt(20,60,"leftvol:%f",leftvol);
  Brain.Screen.printAt(20,80,"rightvol:%f",rightvol);
  
  ChasisSpinVol('L',leftvol);
  ChasisSpinVol('R',rightvol);

  ///////////R1（R2）控制撞针运动////////////////
  if (Controller1.ButtonR1.pressing())
  {    
    CataStatus = "shoot";
  }
  else if (Controller1.ButtonR2.pressing())
  {
    CataStatus = "stop";
    wait(350,msec);
    CataStatus = "down";
  }

/////AB键 以下测试 和上边互斥
  // if (Controller1.ButtonA.pressing())
  // {    
  //   Catapult.spin(forward,9,volt);
  // }
  // else if (Controller1.ButtonB.pressing())
  // {
  //   Catapult.spin(reverse,5,volt);
  // }
  // else   {    Catapult.stop();  }
// //////end
  

  ////////////L1 L2 控制intake吸入吐出///////////
  if ( ptoToClimb==1)
  {
    if (Controller1.ButtonL1.pressing())//in
    {    Intake.spin(reverse, 5, volt);  
         Catapult.setMaxTorque(100,pct);
         Catapult.setVelocity(200,rpm);
         Catapult.spin(forward);
    }
    else if (Controller1.ButtonL2.pressing())
    {    Intake.spin(forward, 6, volt);
          Catapult.setMaxTorque(100,pct);
          Catapult.setVelocity(150,rpm);
          Catapult.spin(reverse);  }//.out
    else   {    Intake.stop();  
            Catapult.stop(hold);    } 
  }
  else  {
    if (Controller1.ButtonL1.pressing())//in
    {    Intake.spin(forward, 12, volt);  }
    else if (Controller1.ButtonL2.pressing())
    {    Intake.spin(reverse, 10, volt);  }//.out
    else   {    Intake.stop();  }
  }
  

////////////// X Y 控制Wing 侧挂展开//////////////
  if (Controller1.ButtonX.pressing())
  {    Piston(Wing_Hang,1);    } 
  else if (Controller1.ButtonY.pressing())
  {    Piston(Wing_Hang,0);  }
  // else
  // {    //Piston(Wing,0);  
  // }

//////////////Up Down 控制pto 高挂 展开//////////////
  if (Controller1.ButtonA.pressing())  //up to A gua
  {    Piston(PTO_Lock,1);
       CataStatus = "pto_ing";  
  } 
  else if (Controller1.ButtonB.pressing())
  {    Piston(PTO_Lock,0);  
  }
  }
}
