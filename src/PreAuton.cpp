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
  ChasisMotors[i].setStopping(brake);//设置默认停止模式
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


// /////////////自动程序选择器（Brain版本）--current /////////////
// void Selector()
// {
// while (1){
// if (Controller1.ButtonUp.pressing())
// { bool SkillsSet=0;
//   int RouteSet=0;
//   string ali ;
//   color AllianceSet;
  
//   Brain.Screen.clearScreen();
//   Controller1.Screen.clearScreen();
//   Controller1.Screen.setCursor(1,1);
//   Controller1.Screen.print( "Auton Not Selected");

//   Brain.Screen.drawRectangle(10, 40, 150, 200, red);//10-160
//   Brain.Screen.drawRectangle(170, 40, 140, 200, green);//170-310
//   Brain.Screen.drawRectangle(320, 40, 150, 200, blue);//320-470
//   Brain.Screen.printAt(20, 20, "Selete Alliance/skills");

//   waitUntil(Brain.Screen.pressing());
//   int xpoint = Brain.Screen.xPosition();
//   int ypoint = Brain.Screen.yPosition();
//   Brain.Screen.drawCircle(xpoint, ypoint, 40, green);
//   task::sleep(200);//
//   Brain.Screen.clearScreen();
//   Brain.Screen.printAt(20, 20, "Selete Route Now");

//   Controller1.Screen.clearLine(1);
//   Controller1.Screen.setCursor(1,1);
//   if (170<xpoint && xpoint<310)//skills
//   {  SkillsSet = 1; 
//     Brain.Screen.clearScreen();  
//     Brain.Screen.print("ok auto skills");
//     Controller1.Screen.print("Auto skills");  }
//   else{ 
//     if (2<xpoint && xpoint<160)//red
//     { AllianceSet = red;
//       ali = "red";
//       Controller1.Screen.print("red");    }
//     else if (xpoint>320 && xpoint<470)//blue
//     { AllianceSet = blue;
//       ali = "blue";
//       Controller1.Screen.print("blue");    }
//                                                           //宽（x坐标范围） 高（y坐标范围）
//     Brain.Screen.drawRectangle(10,40,100,200,AllianceSet);//10-110         40-200
//     Brain.Screen.printAt(60,120,"1%d");// Brain.Screen.printAt(60,120,false,"1%d");
//     Brain.Screen.drawRectangle(130,40,100,200,AllianceSet);//130-230       40-200
//     Brain.Screen.printAt(180,120,"2%d");
//     Brain.Screen.drawRectangle(250,40,100,200,AllianceSet);//250-350       40-200
//     Brain.Screen.printAt(300,120,"3%d");
//     Brain.Screen.drawRectangle(370,40,100,200,AllianceSet);//370-470       40-200
//     Brain.Screen.printAt(420,120,"4%d");
    
//     xpoint = 0;
//     ypoint = 0;
//     waitUntil(Brain.Screen.pressing());
//     xpoint = Brain.Screen.xPosition();
//     ypoint = Brain.Screen.yPosition();
//     Brain.Screen.drawCircle(xpoint, ypoint, 40, green);

//     task::sleep(200);
//     Brain.Screen.clearScreen();
//     Brain.Screen.setCursor(1,1);
//     Brain.Screen.print(ali.c_str());

//     if (10<=xpoint && xpoint<=110)
//     {RouteSet=1;} 
//     else if (130<=xpoint && xpoint<=230)
//     {RouteSet=2;} 
//     else if (250<=xpoint && xpoint<=350)
//     {RouteSet=3;} 
//     else if (370<=xpoint && xpoint<=470)
//     {RouteSet=4;} 

//     Brain.Screen.setCursor(2,1);
//     Brain.Screen.print(RouteSet);
//     Controller1.Screen.print('_');
//     Controller1.Screen.print(RouteSet);
//   }
// }
// }wait(100,msec);
// } 


////////自动程序选择器————手柄版本11.19//////////
void Joystick_Selector()
{
  // printf("%s","hello");
  
  int i=0;
  string auton_list[]={"skills","1","2","3","4"};
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
      wait(150,msec);
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
    wait(500,msec);
    Controller1.Screen.clearLine(1);
    Controller1.Screen.setCursor(1,2);
    // Controller1.Screen.print("自动选择：%s",auton_list[i].c_str());
    Controller1.Screen.print("自动选择：已选定，初始化完成");     
    break;}
    
    wait(150,msec);
    
}
// auton2(); 
}
