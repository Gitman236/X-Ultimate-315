#include "joystick.h"
#include "controls.h"
using namespace vex;
using string = std::string;


///////////////遥控手控函数////////////

void Joystick()
{
  double leftvol;
  double rightvol;
  long int axis3;
  float axis4;
  // long int axis2;
  float turn_slow_index =0.95;
  float input_to_voltage_index=0.095;///0.097 by YUE
  // LRM.setStopping(coast);
  // RRM.setStopping(coast);
  // Intake.setStopping(coast);

  while (1)
  {
  ///////////////////左摇杆控制底盘运动//////////////////
  axis4 = turn_slow_index * Controller1.Axis4.value();
  // if (Controller1.Axis3.value() > int(128) )
  // {    axis3 = Controller1.Axis3.value() - 4294967296;   }
  // else
  // {
  axis3 = Controller1.Axis3.value();
  // }
  leftvol = input_to_voltage_index*(axis3 + axis4);//3-4 
  rightvol = input_to_voltage_index*(-axis3 + axis4);//3+4
  
  ChasisSpinVol('L',leftvol);
  ChasisSpinVol('R',rightvol);

  // LRF.spin(fwd, leftvol,volt);
  // LRM.spin(fwd, leftvol,volt);//r
  // LRB.spin(fwd, leftvol,volt);
  // RRF.spin(fwd, rightvol,volt);
  // RRM.spin(fwd, rightvol,volt);//l
  // RRB.spin(fwd, rightvol,volt);

  ///////////L1（L2）控制撞针运动////////////////
  if (Controller1.ButtonL1.pressing())
  {    Puncher.spin(forward,12,volt);  }
  else if (Controller1.ButtonL2.pressing())
  {    Puncher.spin(reverse,7,volt);  }
  else   {    Puncher.stop();  }

  ////////////R1 R2 控制intake吸入吐出///////////
  if (Controller1.ButtonR1.pressing())
  {    Intake.spin(forward, 12, volt);  }
  else if (Controller1.ButtonR2.pressing())
  {    Intake.spin(reverse, 12, volt);  }
  else   {    Intake.stop();  }

////////////// X Y 控制Wing展开//////////////
  if (Controller1.ButtonX.pressing())
  {    Piston(Wing,1);  } 
  // else if (Controller1.ButtonY.pressing())
  // {    Piston(Wing,0);  }
  else
  {    Piston(Wing,0);  }

//////////////Up (B) 控制Hang展开//////////////
  if (Controller1.ButtonA.pressing())  //up to A gua
  {    Piston(Hang,1);  } 
  else if (Controller1.ButtonB.pressing())
  {    Piston(Hang,0);  }
}
}