#include "PID.h"
#include "controls.h"
#include "PreAuton.h"

using namespace vex;
using string = std::string;
//11
int sgn(double d)
{
  if (d<0) return -1;
  else if (d==0) return 0;
  else return 1;
}



void Run_gyro(double enc , double power, float g)//距离 功率，方向
{
  
  g=Side*g+ Start;
  LRM.resetPosition();
  RRM.resetPosition();

  
  float gyro_kp = 0.8;//0.8  1
  float gyro_kd = 10;

  float move_kp = 0.5;//0.47
  float move_kd = 4;//3.2

  // bool finish;//跳出
  float menc=0;//左右轮平均值
  float vg = 0;//角速度差
  float vm = 0;//线速度差
  float turnpower;//角速度补偿
  float movepower;//线速度补偿
  float gyro_lasterror;//角变量上一次变化
  float move_lasterror;//直线上一次变量变化
  float move_err = fabs(enc) - fabs(menc);//编码器当前与目标差值
  float gyro_err = g - Inertial.rotation(degrees);//陀螺仪当前与目标差值

  gyro_lasterror = gyro_err;//
  move_lasterror = move_err;//
  //int timeout =  enc < 300 ? 500 : enc * 1.5;
  while(1)
  {
    menc = (fabs(LRM.position(deg))+ fabs(RRM.position(deg)))/2;
    move_err = fabs(enc) - fabs(menc);
    gyro_err = g - Inertial.rotation(degrees);
    vg = gyro_err - gyro_lasterror;
    gyro_lasterror = gyro_err;
    vm = move_err - move_lasterror;
    move_lasterror = move_err;
    //time += 1;
    turnpower = gyro_kp*gyro_err + gyro_kd * vg;
    movepower = move_kp*move_err + move_kd * vm;
    //if (time>timeout){break;}
    if (fabs(enc)-fabs(menc)<5 )//&& fabs(vm) < 1)//0.1
    {
      break;
    }
    else
    {
    ChasisSpinSpd('L',(sgn(enc)*power) + turnpower);
    ChasisSpinSpd('R',(sgn(enc)*power) - turnpower);
    wait(10,msec);
    }/* 
    
      if ((fabs(enc) - fabs(move_err)) > 0.1*fabs(enc) )
      {
        Run_Ctrl(100,power + turnpower,-power +turnpower);
        ChasisSpinSpd('L',(sgn(enc)*power) + turnpower);
        ChasisSpinSpd('R,(-sgn(enc)*power) + turnpower);
      }
      else
      {
        Run_Ctrl(100,0.7*power+turnpower,-0.7*power+turnpower);
        ChasisSpinSpd('L,0.7*(sgn(enc)*power) + turnpower);
        ChasisSpinSpd('R,0.7*(-sgn(enc)*power) + turnpower);
      }*/
    
    
    
      
    
  }
  // ChasisStop(hold);
  ChasisStopSlow();
}

void Turn_Gyro(float target)
{
   target=Side*target+Start;

  float kp =1.8;//1.2   2  yuan 2           1.9
  float ki =1.15;//1  1.5       1.4      1.21
  float kd =5.9;//10            5       5.5
  float istart = 10;//启动速度累加阈值
  float dtol = 0.1;//停止速度阀
  float errortolerance = 2;//角度误差区间
  float lim =100;
  float error = target - Inertial.rotation(degrees);//与目标角度距离
  float lasterror;//上一次与目标角度距离
  float V= 0;//瞬时速度，负值
  float integral = 0;//i累加瞬时速度积分
  bool arrived;//跳出判断函数
  float Time=Brain.timer(timeUnits::sec);
  float timeout=error/50;
  float pow;//实际输出功率
  float pow1;//++

  extern float turnspeed;
  lasterror = error;
  arrived = error == 0;//
  while (!arrived)
  {
    error = target - Inertial.rotation(degrees);
    V = error - lasterror;

    if ((fabs(error) <= errortolerance && fabs(V) <= dtol) || (Brain.timer(timeUnits::sec)-Time)>=timeout+10)
    {arrived = true;}

    if (fabs(integral) < 10 && fabs(error) < istart)
      integral += sgn(error) ;
    if (error * lasterror <= 0)
      integral = 0;
    pow = kp * error + kd * V + ki*integral;
    pow = fabs(pow) > lim ? sgn(pow) * lim : pow;
    pow1=turnspeed*pow;

    ChasisSpinSpd('L',pow1);
    ChasisSpinSpd('R',-pow1);


    lasterror = error;
    wait(10,msec);

  }
   ChasisStop(hold);

}