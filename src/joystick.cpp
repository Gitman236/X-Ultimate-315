#include "joystick.h"
#include "controls.h"
using namespace vex;
using string = std::string;


///////////////遥控手控函数////////////
void Joystick() {
    // 设置百分比转换为电压的系数
    float percent_to_voltage_index = 0.12;

    // 定义并初始化按键状态变量
    bool PTO_Engaged = false;
    bool Lock_Engaged = false;

    // 主循环
    while (true) {
        // 双摇杆控制底盘运动
        float axis1 = Controller1.Axis1.position(); // 获取右摇杆位置
        float axis3 = Controller1.Axis3.position(); // 获取左摇杆位置

        // 计算左右电机的控制电压
        double leftvol = percent_to_voltage_index * (axis3 + axis1);
        double rightvol = percent_to_voltage_index * (axis3 - axis1);

        // 控制底盘电机
        ChasisSpinVol('L', leftvol);
        ChasisSpinVol('R', rightvol);

        // 打印 PTO 状态到手柄屏幕
        if (AutonSelected && (Brain.Timer.time()% 2 == 0)) {
            Brain.Screen.clearScreen();

            Brain.Screen.setCursor(1,2);
            Brain.Screen.print("PTO:%d",PTO.value()); 

            Brain.Screen.setCursor(1,8);
            Brain.Screen.print("PTO_Engaged:%d",int(PTO_Engaged)); 


            Brain.Screen.setCursor(2,2);
            Brain.Screen.print("Lock:%d",Lock.value()); 

            Brain.Screen.setCursor(2,8);
            Brain.Screen.print("Lock_Engaged:%d",int(Lock_Engaged)); 


            Brain.Screen.setCursor(3,2);
            Brain.Screen.print("Wing_Hang:%d",Wing_Hang.value()); 

        }

        // 检测并执行其他操作（例如气缸控制）
        // 按下 R2 键伸出名为 Wing_Hang 的气缸，再按一下收回
        if (Controller1.ButtonR2.pressing()) 
        {
          Piston(Wing_Hang, 1);
        }
        else {
            Piston(Wing_Hang, 0);
        }
        

        // 按下 X 键进行 PTO 伸出名为 PTO 的气缸，再按一下取消 PTO
        if (Controller1.ButtonX.pressing()) {
            PTO_Engaged = !PTO_Engaged; // 切换状态
            Piston(PTO, PTO_Engaged);
        }
        if (Controller1.ButtonY.pressing()) {
            Lock_Engaged = !Lock_Engaged; // 切换状态
            Piston(Lock, Lock_Engaged);
        }

        // 未进行 PTO 时，按下 L1 键时 intake 吸入，按下 L2 键时 intake 吐出,按下 R1 键 Catapult 转，松手停止
        if (!PTO_Engaged) {
            
            if (Controller1.ButtonL1.pressing()) {
                Intake.spin(forward, 12, volt); // 吸入
            } else if (Controller1.ButtonL2.pressing()) {
                Intake.spin(reverse, 12, volt); // 吐出
            } else {
                Intake.stop(); // 停止
            }

            if (Controller1.ButtonR1.pressing() ) 
            {
                Catapult.spin(forward, 100, pct); // 启动
            } 
            else{
                Catapult.stop(); // 停止
             }
        }

        // PTO 后，按下 L1 键驱动 Catapult 电机正转，同时 intake 吐
        // 按下 L2 键驱动 Catapult 电机反转，同时 intake 吐
        if (PTO_Engaged) {
            Catapult.setStopping(hold);//设置默认停止模式
            if (Controller1.ButtonL1.pressing()) {
                Catapult.spin(forward, 12, volt); // 正转
                Intake.spin(reverse, 3, volt); // 吐
            } else if (Controller1.ButtonL2.pressing()) {
                Catapult.spin(reverse, 12, volt); // 反转
                Intake.spin(reverse, 3, volt); // 吐
            } else {
                Catapult.stop(); // 停止
                Intake.stop(); // 停止
            }
        }

        // 休眠一小段时间，降低CPU负载
        wait(25, msec);
    }
}
