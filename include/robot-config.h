using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LRF;
extern motor LRM;
extern motor LRB;
extern motor RRF;
extern motor RRM;
extern motor RRB;
extern inertial Inertial;
extern controller Controller1;
extern motor Intake;
extern motor Catapult;

extern limit PuncherSensor;
extern limit PuncherSensor;
extern digital_out Wing_Hang;
extern digital_out PTO_Lock;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
// void  vexcodeInit( void );