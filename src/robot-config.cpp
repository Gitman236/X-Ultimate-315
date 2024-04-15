#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors

//手动配置说明：
//1. 类型 motor/motor29（气缸）/inertial（惯性传感器）/controller/。。。。。
//2. 名称
//3. 端口
//4. V5电机 齿轮比
//5. 旋转运动方向（true/false） 
motor LRF = motor(PORT16, ratio6_1, true);//16
motor LRM = motor(PORT17, ratio6_1, false);//17
motor LRB = motor(PORT18, ratio6_1, false);//18
motor RRF = motor(PORT6, ratio6_1, false);//6
motor RRM = motor(PORT8, ratio6_1, true);//8
motor RRB = motor(PORT9, ratio6_1, true);//9

inertial Inertial = inertial(PORT21);

controller Controller1 = controller(primary);
motor Intake = motor(PORT5, ratio18_1, false);
motor Catapult = motor(PORT14, ratio18_1, false);

limit PuncherSensor = limit(Brain.ThreeWirePort.H);
limit ClimbPosSensor = limit(Brain.ThreeWirePort.B);

digital_out Wing_Hang = digital_out(Brain.ThreeWirePort.C);
digital_out PTO_Lock = digital_out(Brain.ThreeWirePort.D);

