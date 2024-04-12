#include "TrueAuton.h"


using namespace vex;
using string = std::string;
// extern bool SkillsSet;


void StartAuton()
{
    Brain.resetTimer();

    if (SkillsSet ==1)
    {  SkillsAuton();  }

    else{
    switch (RouteSet)
    {
    case 0:
        SkillsAuton();
        break;
    case 1:
        auton1();
        break;
    case 2:
        auton2();
        break;
    case 3:
        auton3();
        break;
    case 4:
        auton4();
        break;
    default:
        break;
    }
  }

  
  
}




//线路一：
void auton1(){

  autodone=1;


}
//线路二
void auton2(){
 
  autodone=1;

}
//线路三
void auton3(){


  autodone=1;


}
void auton4(){


}



void SkillsAuton()
{
  /*
  Run_gyro(390,80,0);
  wait(100,msec);
  Turn_Gyro(-106);
  wait(100,msec);
  Run_gyro(645,70,-108);
  Run_gyro(130,11,-107);
  wait(150,msec);

  
  int times = 48;//42
  Catapult.spinFor(1080*times,degrees,true);
  // Catapult.setVelocity(50,percent);
  // Catapult.spinFor(385,degrees,false);
  // Catapult.setVelocity(100,percent);
  // wait(500,msec);
  
  Run_gyro(-780,85,-110);
  wait(150,msec);
  Turn_Gyro(4);
  wait(150,msec);
  Run_gyro(1230,95,3);
  wait(150,msec);
  Turn_Gyro(90);
  Piston(Wing,1);
  // // wait(150,msec);
  Run_gyro(3201,100,86);
  Run_gyro(1001,95,83);
  wait(200,msec);
  Piston(Wing,0);
  Run_gyro(-1000,-60,65);
  Piston(Wing,1);
  
  wait(150,msec);
  Turn_Gyro(0);
  // Piston(Wing,1);
  wait(150,msec);
  Run_gyro(970,30,20);
  wait(150,msec);
  Turn_Gyro(96);
  wait(200,msec);
  Run_gyro(1700,100,96);
  Run_gyro(-900,50,96);
  Piston(Wing,0);





  
    */
autodone=1;
}
