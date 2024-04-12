/*----------------------------------------------------*/
/*       CPYZ 12315X Ultimate Bot Program             */
/*          Start by qinyi at 31/03/2024              */
/*             OVER UNDER FINAL CODE                  */
/*----------------------------------------------------*/

#include "vex.h"

//1
using namespace vex;
using string = std::string;//引入常用但是vex基本库不含有的string字符串类型

competition Competition;//do not remove

#include "PreAuton.h"
#include "controls.h"
#include "joystick.h"
#include "PID.h"
#include "TrueAuton.h"

bool SkillsSet=0;
int RouteSet=0;
bool AutonSelected = 0;
bool autodone=0;

float Start =0;
int Side =1;
float turnspeed=1;



void pre_auton(void) {
 

  Controller1.Screen.clearScreen();
  MotorInitialization();
  // InertialInitialization();

  Joystick_Selector();
}

void autonomous(void) {

  StartAuton();//运行实际自动程序
  Brain.Timer.clear();//重置大脑计时器，准备自动计时
  while(1){
    Brain.Screen.clearLine(1);
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print("Inertial degrees:  ");
    Brain.Screen.print(Inertial.rotation(degrees));//用于时刻打印自动度数（调自动用，比赛前注释）
    if(autodone){
      Brain.Screen.clearLine(2);
      Brain.Screen.setCursor(2,3);
      Brain.Screen.print("Auto Time:  ");
      Brain.Screen.print(Brain.timer(sec));//自动结束终止计时，最终时间定格（注意误差10msec）
      autodone = 0;
    }
    wait(10,msec);

  }

 
}


void usercontrol(void) {
  Joystick();//手动控制函数，包括按键摇杆映射等
  // while (1) {
  //   wait(20, msec); 
                    
  // }
}

int main() {
  
  Competition.autonomous(autonomous);//场控回调，do not remove
  Competition.drivercontrol(usercontrol);//场控回调，do not remove

  
  pre_auton();//自动前准备函数，包括各种初始化，以及自动选择器等 do not remove

  
  // while (true) 
  // {
    

  //   wait(20, msec);
  // }
}
