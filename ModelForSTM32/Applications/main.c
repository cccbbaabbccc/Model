/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved.
 + 文件名  ：main.c
 + 描述    ：主循环
 */
#include "init.h"
#include "scheduler.h"

/*----------------------------------------------------------
 + 实现功能：主函数
----------------------------------------------------------*/
int main(void)
{
    /* 总初始化 */
    Light_Init();
    /* 主循环 */
    while(1)Main_Loop();
}
/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved. */
