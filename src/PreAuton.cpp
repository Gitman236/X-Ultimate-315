#include "PreAuton.h"
// #include "vex.h"
using namespace vex;
using string = std::string;

////////////////////////初始化电机///////////////////////////
/*扭矩和速度负相关，higher torque means lower speed*/
void MotorInitialization()
{
  motor ChasisMotors[] = {LRF,LRM,LRB,RRF,RRM,RRB};
  for(int i=0;i<6;i++)
  {
  ChasisMotors[i].setMaxTorque(100,percent);//设置扭矩
  ChasisMotors[i].setPosition(0,degrees);//重置编码器值
  ChasisMotors[i].setStopping(hold);//设置默认停止模式
  ChasisMotors[i].setVelocity(100,percent);//设置默认速度
  }
 
  Catapult.setMaxTorque(100,percent);//设置扭矩
  Catapult.setStopping(hold);//设置默认停止模式
  Catapult.setVelocity(100,percent);//设置默认速度30

  Intake.setMaxTorque(100,percent);//设置扭矩
  Intake.setStopping(hold);//设置默认停止模式hold
  Intake.setVelocity(100,percent);//设置默认速度
}


/////////////初始化陀螺仪/////////////
void InertialInitialization()
{
  Inertial.calibrate();

  do {
  wait(5, msec);
  } while (Inertial.isCalibrating());
  
  task::sleep(200);
  Start=Inertial.rotation(degrees);
}



////////自动程序选择器————手柄版本11.19//////////
void Joystick_Selector()
{
  // printf("%s","hello");
  
  int i=0;
  string auton_list[]={"自动技能","远场","2","3","4"};
  int getArrayLength = sizeof(auton_list) / sizeof(auton_list[0]);//5
  while (1)
  {
    
    if (Controller1.ButtonRight.pressing())
    {
      
      if (i > getArrayLength)
      {
        i=0;
        SkillsSet = 1;
      }
      else{
        SkillsSet = 0;
        i += 1;
        RouteSet = i;
      }
      // wait(150,msec);
    }
    

    Controller1.Screen.clearLine(1);
    Controller1.Screen.setCursor(1,2);
    // Controller1.Screen.print("自动选择：%s",auton_list[i].c_str());
    Controller1.Screen.print("自动选择：");
    Controller1.Screen.clearLine(2);
    Controller1.Screen.setCursor(2,2);
    Controller1.Screen.print(auton_list[i].c_str());
    // Controller1.Screen.print(i);

    if (Controller1.ButtonDown.pressing())
    {
    InertialInitialization();
    Controller1.Screen.clearLine(1);
    Controller1.Screen.setCursor(1,2);
    Controller1.Screen.print("Initializing");  
    
    wait(1,sec);
    Controller1.Screen.print("."); 
    wait(1,sec);
    Controller1.Screen.print("."); 
    wait(1,sec);
    Controller1.Screen.print("."); 
    wait(1,sec);
    Controller1.Screen.clearLine(1);
    Controller1.Screen.setCursor(1,2);
    // Controller1.Screen.print("自动选择：%s",auton_list[i].c_str());
    Controller1.Screen.print("Init&OK");     
    break;
    }
    
    wait(150,msec);
    
}
// auton2(); 
}
