/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved.
 + 文件名  ：device_led.c
 + 描述    ：led设备
代码尽量做到逐行注释 代码有问题，及时加群交流 作者有偿支持对开源代码的完善 */
#include "device_led.h"
#include "stm32f10x.h"

/*----------------------------------------------------------
 + 实现功能：控制LED初始化
----------------------------------------------------------*/
void LED_Init()
{
    GPIO_InitTypeDef GPIO_InitStructure;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能或者失能APB2外设时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//最高输出速率50MHz
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
		GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化外设GPIOx寄存器

		GPIO_SetBits(GPIOB, GPIO_Pin_10);//设置指定的数据端口位
		GPIO_SetBits(GPIOB, GPIO_Pin_11);//设置指定的数据端口位
}

/*----------------------------------------------------------
 + 实现功能：控制LED发光亮度 由任务调度调用周期1ms
 + 调用参数功能：发光亮度数组 0-20
----------------------------------------------------------*/
void Call_LED_show( u8 duty[2] )
{
    /* 计时值 */
    static u8 LED_cnt[2];
		u8 i;
	
    /* 依次控制2个LED */
    for(i=0; i<2; i++)
    {
        /* 计时器用于比较 */
        if( LED_cnt[i] < 19 )
            LED_cnt[i]++;
        else
            LED_cnt[i] = 0;

        /* LED开启状态控制 */
        if( LED_cnt[i] < duty[i] )
        {
            /* 依次控制2个LED */
            switch(i)
            {
            case 0:
                LED1_ON;
                break;
            case 1:
                LED2_ON;
                break;
            }
        }
        /* LED关断状态控制 */
        else
        {
            /* 依次控制2个LED */
            switch(i)
            {
            case 0:
                LED1_OFF;
                break;
            case 1:
                LED2_OFF;
                break;
            }
        }
    }
}

///* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved. */
