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
extern digital_out Hang;
// extern motor29 HangR;
extern digital_out Wing;
// extern motor29 WingR;
extern controller Controller1;
extern motor Intake;
extern motor Puncher;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
// void  vexcodeInit( void );