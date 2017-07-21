/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved.
 + 文件名  time.h
 + 描述    ：系统时间统计头文件
代码尽量做到逐行注释 代码有问题，及时加群交流 作者有偿支持对开源代码的完善 */
#ifndef _TIME_H_
#define _TIME_H_

#include "stm32f10x.h"
#include "device_timer.h"

/*----------------------------------------------------------
 + 实现功能：延时
 + 调用参数：微秒
----------------------------------------------------------*/
extern void Delay_us(uint32_t);

/*----------------------------------------------------------
 + 实现功能：延时
 + 调用参数：毫秒
----------------------------------------------------------*/
extern void Delay_ms(uint32_t);

/*----------------------------------------------------------
 + 实现功能：计算两次点用时间间隔
 + 调用参数：统计时间项数组
 + 返回参数：两次时间间隔 单位：秒
----------------------------------------------------------*/
extern float Call_timer_cycle(u8);

/*----------------------------------------------------------
 + 实现功能：时间统计初始化
----------------------------------------------------------*/
extern void Cycle_Time_Init(void);

#endif
/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved. */