/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved.
 + 文件名  ：init.c
 + 描述    ：飞控初始化
代码尽量做到逐行注释 代码有问题，及时加群交流 作者有偿支持对开源代码的完善 */
#include "stm32f10x.h"
//#include "device_iic.h"
//#include "device_pwm_in.h"
#include "driver_pwm_out.h"
//#include "driver_ms5611.h"
//#include "driver_mpu6050.h"
//#include "driver_ak8975.h"
//#include "driver_led.h"
//#include "data_transfer.h"
//#include "driver_ultrasonic.h"
//#include "driver_GPS.h"
#include "driver_time.h"
//#include "ctrl.h"

/* 初始化结束标识 */
u8 Init_Finish;

/*----------------------------------------------------------
 + 实现功能：总初始化
----------------------------------------------------------*/
void Light_Init()
{
    /* 中断优先级组别设置 */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);
    /* 开启定时器 */
    SysTick_Configuration();
	
    /* LED功能初始化 */
//    LED_Init();
//    /* 接收机信号采集初始化 */
//    PWM_IN_Init();
    /* 初始化信号输出功能400HZ */
    PWM_Out_Init();
		SetPwm(400);
//    /* I2C初始化 */
//    I2c_Device_Init();
//    /* 气压计初始化 */
//    MS5611_Init();
//    /* 加速度计、陀螺仪初始化，配置20hz低通 */
//    MPU6050_Init(20);
//    /* 磁力计初始化 */
//    hard_error_ak8975 = AK8975_IS_EXIST();
//    /* 数传初始化 */
//    Data_transfer_init();
//    /* 超声波初始化 */
//    Ultrasonic_Init();
//    /* GPS模块初始化 */
//    GPS_Init();
//    /* 参数初始化 */
//    Para_Init();
//    /* 时间统计初始化 */
//    Cycle_Time_Init();
    /* 初始化结束标识 */
    Init_Finish = 1;
}

/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved. */
