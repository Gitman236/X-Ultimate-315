#include "joystick.h"
#include "controls.h"
using namespace vex;
using string = std::string;


///////////////遥控手控函数////////////
void Joystick() {
    // 设置百分比转换为电压的系数
    float percent_to_voltage_index = 0.12;

    // 定义并初始化按键状态变量
    bool Wing_Hang_extended = false;
    bool PTO_Lock_active = false;
    bool R1_pressed_prev = false;
    bool Catapult_running = false; // 用于跟踪 Catapult 是否正在运行

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
        if (PTO_Lock_active) {
            Controller1.Screen.print("PTO Active, hang unlocked"); // PTO 激活，吊物气缸解锁
        } else {
            Controller1.Screen.print("PTO Inactive, hang locked"); // PTO 未激活，吊物气缸锁定
        }

        // 检测并执行其他操作（例如气缸控制）
        // 按下 R2 键伸出名为 Wing_Hang 的气缸，松开收回
        if (Controller1.ButtonR2.pressing()) {
            Piston(Wing_Hang, true); // 伸出
        } else {
            Piston(Wing_Hang, false); // 收回
        }

        // 按下 → 键伸出名为 Wing_Hang 的气缸，再按一下收回
        if (Controller1.ButtonRight.pressing()) {
            Piston(Wing_Hang, !Wing_Hang_extended); // 切换状态
        }

        // 按下 X 键进行 PTO 伸出名为 PTO_Lock 的气缸，再按一下取消 PTO
        if (Controller1.ButtonX.pressing()) {
            PTO_Lock_active = !PTO_Lock_active; // 切换状态
            Piston(PTO_Lock, PTO_Lock_active);
        }

        // 未进行 PTO 时，按下 L1 键时 intake 吸入，按下 L2 键时 intake 吐出,按下 R1 键 Catapult 开始一直转，再次按下停止,1s后下降直到碰到纤维开关
        if (!PTO_Lock_active) {
            if (Controller1.ButtonL1.pressing()) {
                Intake.spin(forward, 12, volt); // 吸入
            } else if (Controller1.ButtonL2.pressing()) {
                Intake.spin(reverse, 12, volt); // 吐出
            } else {
                Intake.stop(); // 停止
            }

            if (Controller1.ButtonR1.pressing() && !R1_pressed_prev) {
                if (!Catapult_running) {
                    Catapult.spin(forward, 100, pct); // 启动
                    Catapult_running = true;
                } else {
                    Catapult.stop(); // 停止
                    Catapult_running = false;
                }
                R1_pressed_prev = true;
                wait(1000, msec); // 等待1秒
            } else if (Controller1.ButtonR1.pressing() && R1_pressed_prev && !Catapult_running) {
                Catapult.spin(forward, 20, pct); // 缓慢旋转
            } else {
                R1_pressed_prev = false;
                if (PuncherSensor.pressing()) {
                    Catapult.stop(); // 触发 PuncherSensor 限位开关，停止旋转
                }
            }
        }

        // PTO 后，按下 L1 键驱动 Catapult 电机正转，同时 intake 吐
        // 按下 L2 键驱动 Catapult 电机反转，同时 intake 吸
        if (PTO_Lock_active) {
            Catapult.setMaxTorque(100, pct);
            if (Controller1.ButtonL1.pressing()) {
                Catapult.spin(forward, 100, rpm); // 正转
                Intake.spin(reverse, 8, volt); // 吐
            } else if (Controller1.ButtonL2.pressing()) {
                Catapult.spin(reverse, 100, rpm); // 反转
                Intake.spin(forward, 5, volt); // 吸
            } else {
                Catapult.stop(); // 停止
                Intake.stop(); // 停止
            }
        }

        // 休眠一小段时间，降低CPU负载
        wait(20, msec);
    }
}
