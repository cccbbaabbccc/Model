/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved.
 + 文件名  ：device_pwm_out.c
 + 描述    ：PWM输出设备
代码尽量做到逐行注释 代码有问题，及时加群交流 作者有偿支持对开源代码的完善 */
#include "stm32f10x.h"
#include "device_pwm_out.h"

/* 占空比精度 */
#define ACCURACY 10000 //u16(2500/0.25)
///* 初始占空比 */
//#define INIT_DUTY 4000 //u16(1000/0.25)
/* 数据限幅 */
//#define LIMIT( x,min,max ) ( (x) < (min)  ? (min) : ( (x) > (max) ? (max) : (x) ) )

void TIM3_PWM_Init(uint16_t hz);

/*----------------------------------------------------------
 + 实现功能：PWM输出初始化
----------------------------------------------------------*/
void PWM_Out_Init(void)
{  
	TIM3_PWM_Init(50);
}
/*----------------------------------------------------------
 + 实现功能：TIM3_PWM输出初始化
 + 管脚配置：GPIOA_Pin_7，TIM3_CH2
 + 调用参数功能：uint16_t hz：PWM输出的频率    
----------------------------------------------------------*/
void TIM3_PWM_Init(uint16_t hz)
{
	uint16_t PrescalerValue = 0;
	u32 hz_set = ACCURACY*hz;	
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	TIM_OCStructInit(&TIM_OCInitStructure);
	
	hz_set = LIMIT(hz_set,1,84000000);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);		// 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);  //使能GPIO外设时钟使能
	                                                                     	
   //设置该引脚为复用输出功能,输出TIM3 CH2的PWM脉冲波形
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; //TIM_CH2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/*  Compute the prescaler value */
	PrescalerValue = (uint16_t) ( ( SystemCoreClock  ) / hz_set ) - 1;

	TIM_TimeBaseStructure.TIM_Period = ACCURACY;     //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 
	TIM_TimeBaseStructure.TIM_Prescaler =PrescalerValue; //设置用来作为TIMx时钟频率除数的预分频值  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx

  TIM_CtrlPWMOutputs(TIM3,ENABLE);	//MOE 主输出使能	

	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //CH3预装载使能	 

	TIM_ARRPreloadConfig(TIM3, ENABLE); //使能TIMx在ARR上的预装载寄存器
	
	TIM_Cmd(TIM3, ENABLE);  //使能TIM3
}

/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved. */
