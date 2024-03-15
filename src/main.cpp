/*----------------------------------------------------*/
/*           12315A Bravo Bot Program                 */
/*        Starting by qinyi at 10/10/2023             */
/*----------------------------------------------------*/
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LRF                  motor         1               
// LRM                  motor         2               
// LRB                  motor         4               
// RRF                  motor         9               
// RRM                  motor         19              
// RRB                  motor         8               
// Inertial             inertial      21              
// Hang                 motor29       A               
// WingL                motor29       B               
// WingR                motor29       C               
// Controller1          controller                    
// Intake               motor         6               
// Catapult             motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

//11
using namespace vex;
using string = std::string;

competition Competition;

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

// define your global instances of motors and other devices here


void pre_auton(void) {
 
  // vexcodeInit(); // Initializing Robot Configuration. DO NOT REMOVE!
  Controller1.Screen.clearScreen();
  MotorInitialization();
  // InertialInitialization();
  // Selector();
  Joystick_Selector();
}

void autonomous(void) {

  StartAuton();
  while(1){
    Brain.Screen.clearLine(1);
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print(Inertial.rotation(degrees));
    if(autodone){
      Brain.Screen.clearLine(2);
      Brain.Screen.setCursor(2,3);
      Brain.Screen.print(Brain.timer(sec));
      autodone = 0;
    }
    wait(10,msec);

  }

 
}


void usercontrol(void) {
  Joystick();
  // while (1) {
  //   wait(20, msec); 
                    
  // }
}

int main() {
  
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  
  pre_auton();

  
  while (true) 
  {
    

    wait(20, msec);
  }
}
