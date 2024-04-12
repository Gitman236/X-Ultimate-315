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
motor LRF = motor(PORT15, ratio6_1, false);
motor LRM = motor(PORT16, ratio6_1, true);
motor LRB = motor(PORT12, ratio6_1, true);
motor RRF = motor(PORT5, ratio6_1, false);
motor RRM = motor(PORT2, ratio6_1, true);
motor RRB = motor(PORT10, ratio6_1, true);

inertial Inertial = inertial(PORT16);

// digital_out Hang = digital_out(Brain.ThreeWirePort.C);
// digital_out Wing = digital_out(Brain.ThreeWirePort.F);

controller Controller1 = controller(primary);
motor Intake = motor(PORT1, ratio18_1, true);
motor Catapult = motor(PORT9, ratio18_1, false);

limit PuncherSensor = limit(Brain.ThreeWirePort.A);
limit ClimbPosSensor = limit(Brain.ThreeWirePort.B);
digital_out Wing_Hang = digital_out(Brain.ThreeWirePort.C);
digital_out PTO_Lock = digital_out(Brain.ThreeWirePort.D);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
// void vexcodeInit( void ) {
// }