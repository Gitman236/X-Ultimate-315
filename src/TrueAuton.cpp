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


void SkillsAuton()
{
  
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





  
    
autodone=1;
}


//远场自动 拿分线路
void auton1(){

    /*fei
  Run_gyro(2400,90,0);
  wait(100,msec);
  Turn_Gyro(88);
  intake_spin(0);
  wait(720,msec);
  Run_gyro(350,50,87);
  Intake.stop();
  Run_gyro(-300,45,87);
  wait(100,msec);
  Turn_Gyro(244);
  wait(50,msec);
  Run_gyro(823,90,245);
  Run_gyro(480,25,246);
  intake_spin(1);
  wait(950,msec);
  Intake.stop();
  Turn_Gyro(350);
  // Run_gyro(300,20,370);
  Run_gyro(420,17,351);//clode to pos for wing
  Piston(Wing,1);//开wing
  Run_gyro(170,10,380);
  wait(200,msec);
  Run_gyro(280,1,535);
  // Turn_Gyro(450);
  wait(100,msec);
  intake_spin(0);
  wait(720,msec);
  Intake.stop();
  Run_gyro(1600,100,470);
  // // Piston(Wing,1);
  wait(200,msec);
  Piston(Wing,0);//
*/

  Run_gyro(2435,90,2);
  wait(150,msec);
  Turn_Gyro(88);
  intake_spin(0);
  wait(950,msec);
  Intake.stop();
  Run_gyro(430,60,87);
  wait(100,msec);
  Run_gyro(-425,35,85);
  wait(100,msec);
  Turn_Gyro(248);
  wait(150,msec);
  Run_gyro(846,80,248);
  intake_spin(1);
  wait(1000,msec);
  Intake.stop();
  Turn_Gyro(0);
  Run_gyro(275,30,1);//clode to pos for wing 230,35,0
  wait(100,msec);
  Turn_Gyro(84);
  wait(220,msec);
  Piston(Wing,1);//开wing
  intake_spin(0);
  wait(790,msec);
  Intake.stop();
  Run_gyro(1600,100,85);
  // Piston(Wing,1);
  wait(300,msec);
  Run_gyro(-610,50 ,85);
  wait(150,msec);
  Run_gyro(750,100,84);

  /*
  Piston(Wing,0);//
  wait(300,msec);


  Run_gyro(-330,50,88);
  wait(100,msec);

  
  Turn_Gyro(-73);
  // wait(100,msec);
  Run_gyro(989,80,-74);
  Run_gyro(75,10,-69);
  intake_spin(1);
  wait(950,msec);
  Intake.stop();

  //fron
  Turn_Gyro(88);
  Run_gyro(1100,100,87);
  // Run_gyro(250,90,85);
  intake_spin(0);
  wait(650,msec);
  Intake.stop();
  Piston(Wing,1);
  Run_gyro(720,100,86);
  Run_gyro(-200,100,86);
//to
*/

  // Turn_Gyro(-80);
  autodone=1;


}
//近场自动 一个棕球入球门 wing移除导入 碰杆
void auton2(){
  Run_gyro(-1299,55,0);//后退
  wait(250,msec);
  Run_gyro(-520,45,54);//转弯
  wait(150,msec);
  Run_gyro(-310,100,52);//全力后顶，推入-530
  wait(200,msec);
  Run_gyro(290,30,40);//向前走一点
  wait(150,msec);
  Run_gyro(806,35,13);//zhuan 准备拿导入
  Piston(Wing,1);//开wing
  wait(150,msec);
  Turn_Gyro(-34);//弹出dao棕球
  Piston(Wing,0);//关wing
  Run_gyro(570,60,0);
  Run_gyro(750,60,-30);
  wait(200,msec);
  Run_gyro(135,20,-40);//往前走+转
  Turn_Gyro(-46);//
  wait(200,msec);
  Run_gyro(770,90,-46);//向前推球700
  Run_gyro(220,50,-44);//推杆下球190
  wait(200,msec);
  // Run_gyro(-260,17,-46);//稍退一点

  autodone=1;

}
//远场自动 1个预装连队棕球 碰杆 保awp
void auton3(){
  Run_gyro(-1435,60,0);//后退,65,
  wait(250,msec);
  Run_gyro(-540,40,-55);//转弯,50,
  wait(150,msec);
  Run_gyro(-450,100,-50);//全力后顶，推入-530
  wait(200,msec);
  Run_gyro(550,30,-49);//向前走一点
  wait(150,msec);
  Run_gyro(-550,100,-49);//2次后撞
  wait(150,msec);
  Run_gyro(261,30,-49);//向前走一点
  Turn_Gyro(47);//，转弯
  wait(100,msec);
  Run_gyro(1920,75,46);//向中杆走,,45
  Piston(Wing,1);//开wing
  wait(150,msec);
  Run_gyro(765,30,46);//向中杆走760,,45
  Run_gyro(220,10,71);//稍转 使wing碰杆

  autodone=1;


}
void auton4(){
  // Turn_Gyro(360);

}



