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




//线路一：远场冲 6 goal rush
void auton1(){
  intake(100,"in");
  wait(250,msec);
  Run_gyro(210,19,0);
  wait(500,msec);
  intake(100,"stop");
  wait(100,msec);
  Run_gyro(1350,-50,0);
  Run_gyro(595,-15,-47);
  Piston(Wing_Hang,1);
  wait(100,msec);
  Run_gyro(320,-85,-52);
  Piston(Wing_Hang,0);
  Run_gyro(210,-85,-85);
  // turnspeed=0.45;
  // Turn_Gyro(-85);

  // wait(150,msec);
  // Run_gyro(480,-85,-91);


  autodone=1;


}
//线路二：远场保
void auton2(){
  Run_gyro(1965,85,-8);
  wait(200,msec);
  Turn_Gyro(89);
  wait(150,msec);
  Run_gyro(150,40,90);
  intake(100,"out");
  wait(750,msec);
  intake(100,"stop");
  Run_gyro(300,100,89);
  wait(800,msec);
  Run_gyro(-833,30,89);
  wait(150,msec);
  Turn_Gyro(216);
  wait(150,msec);
  // intake(100,"in");
  // Run_gyro(1300,30,220);
  // intake(100,"stop");


 
  autodone=1;

}
//线路三：近场
void auton3(){
Run_gyro(385,60,0);
wait(100,msec);
Piston(Wing_Hang,1);
wait(300,msec);
Run_gyro(-230,70,-20);
wait(300,msec);
Piston(Wing_Hang,0);
Run_gyro(566,40,30);
Run_gyro(222,50,45);
intake(100,"out");
wait(500,msec);
// Run_gyro(480,100,46);
wait(100,msec);
intake(100,"stop");
Run_gyro(-180,40,45);
wait(200,msec);
Turn_Gyro(220);
wait(200,msec);
Run_gyro(-390,100,218);
Run_gyro(450,60,180);
wait(150,msec);
Run_gyro(1000,60,140);
wait(100,msec);
Run_gyro(980,60,124);
wait(150,msec);
Run_gyro(101,20,126);


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
