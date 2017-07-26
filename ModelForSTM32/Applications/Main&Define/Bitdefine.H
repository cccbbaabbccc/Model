#ifndef _BITDEFINE_H
#define _BITDEFINE_H

#define clrsomeonebit(a,b)  ((a) &= ~(1<<(b)))   // 对a中的b位写0
#define setsomeonebit(a,b)  ((a) |=  (1<<(b)))   // 对a中的b位写1
#define getsomeonebit(a,b)	(((a)>>(b))&(0x01))	 // 对a中的b位读

typedef union _Flag08{
	uchar	byte;
	struct {
			uchar	bit0:1;
			uchar	bit1:1;
			uchar	bit2:1;
			uchar	bit3:1;
			uchar	bit4:1;
			uchar	bit5:1;
			uchar	bit6:1;
			uchar	bit7:1;
	} Bit;
}Flag08;

typedef union _Flag16{
	uint	byte;
	struct {
			uint	bit0:1;
			uint	bit1:1;
			uint	bit2:1;
			uint	bit3:1;
			uint	bit4:1;
			uint	bit5:1;
			uint	bit6:1;
			uint	bit7:1;
			uint	bit8:1;
			uint	bit9:1;
			uint	bit10:1;
			uint	bit11:1;
			uint	bit12:1;
			uint	bit13:1;
			uint	bit14:1;
			uint	bit15:1;
		  uint	RESERVE:16;
	} Bit;
}Flag16;


Flag08 TIME_Flagb,UART_Flag,_Flagb1,_Flagb2,_System_State1,_System_State2,_Protect_State,_Error_State1,_Error_State2,_System_Mode,_System_Ctrl,f_System_Mode;
 


/**************************************************************************/
//uchar   bdata   	TIME_Flagb;			定时标志位寄存器
/**************************************************************************/
#define		f_Time_4ms				TIME_Flagb.bit.Bit0
#define		f_Time_20ms				TIME_Flagb.bit.Bit1
#define		f_Time_100ms			TIME_Flagb.bit.Bit2
#define		f_Time_500ms			TIME_Flagb.bit.Bit3
#define		f_Time_1s				  TIME_Flagb.bit.Bit5
#define		f_Time_1s1				TIME_Flagb.bit.Bit6
/**************************************************************************/

/**************************************************************************/
//uchar		bdata			UART_Flag;		串口标志位寄存器
/**************************************************************************/
#define		f_UART_Send						UART_Flag.bit.Bit0			// 串口发送标志位
#define		f_UART_Receive				UART_Flag.bit.Bit1			// 串口接收标志位	
#define		Drive_By_Wire_Data		UART_Flag.bit.Bit3   // 接收线控数据标志位
/**************************************************************************/

/**************************************************************************/
//uchar   bdata     _Flagb1；   系统控制标志位
/**************************************************************************/
#define		f_Open_Fan					_Flagb1.bit.Bit0   // 开热泵热水标志位
#define		f_Open_Heater				_Flagb1.bit.Bit1   // 开电加热标志位
#define		f_System_Close			_Flagb1.bit.Bit2   // 关机标志位
#define		f_EValue_Hot				_Flagb1.bit.Bit3   // 电子膨胀阀热度开关
//#define		f_Heater_Close			_Flagb1.bit.Bit4   // 热水恒温停机标志位
#define		f_Time_fan					_Flagb1.bit.Bit5   // 风机计时标志位
#define		f_Open_YJ						_Flagb1.bit.Bit6   // 开压缩机标志位
#define		f_Open_Air_Con			_Flagb1.bit.Bit7   // 空调开机
/**************************************************************************/

/**************************************************************************/
//uchar		bdata			_Flagb2;
/**************************************************************************/
#define		f_Over_Pipe_Fan		_Flagb2.bit.Bit0
#define		f_Remote					_Flagb2.bit.Bit1
#define		f_YSJ_OFF3m				_Flagb2.bit.Bit2
#define		f_YSJ_ON3m				_Flagb2.bit.Bit3
#define		f_Test						_Flagb2.bit.Bit4
#define		f_EValue_First		_Flagb2.bit.Bit5
#define		f_EValue_First1		_Flagb2.bit.Bit6
#define		f_KeySelf					_Flagb2.bit.Bit7
/**************************************************************************/

/**************************************************************************/
//uchar		bdata			_System_State1;			室外板系统状态寄存器1
/**************************************************************************/
#define		f_System_WFan			_System_State1.bit.Bit0   // 外风机
#define		f_System_YJ				_System_State1.bit.Bit1   // 压缩机
#define		f_System_HXF_1		_System_State1.bit.Bit2   // 四通阀1
#define		f_System_HXF_2		_System_State1.bit.Bit3   // 四通阀2
#define		f_System_Hot			_System_State1.bit.Bit4   // 电加热
#define		f_System_RW				_System_State1.bit.Bit5   // 回水阀
#define		f_System_LHot			_System_State1.bit.Bit6   // 盘管加热
/**************************************************************************/

/**************************************************************************/
//uchar		bdata			_System_State2;			室外板系统状态寄存器2
/**************************************************************************/
#define		f_System_HVS			_System_State2.bit.Bit0   // 高压开关
#define		f_System_LVS			_System_State2.bit.Bit1   // 低压开关
#define		f_System_WS				_System_State2.bit.Bit2   // 水位开关
/**************************************************************************/

/**************************************************************************/
//uchar		bdata			_Protect_State;			保护标志位寄存器
/**************************************************************************/
#define		f_Protect_High_Voltage	 _Protect_State.bit.Bit0   // 高压异常保护标志位 
#define		f_Protect_Low_Voltage		 _Protect_State.bit.Bit1   // 低压异常保护标志位 
#define		f_Protect_Exhaust_Over	 _Protect_State.bit.Bit2   // 排气温度过高保护标志位
#define		f_Protect_CSS						 _Protect_State.bit.Bit3   // 防冻结保护标志位
#define		f_Protect_YJ						 _Protect_State.bit.Bit4   // 压缩机过流保护标志位
/**************************************************************************/

/**************************************************************************/
//uint		bdata			_Error_State1;					故障代码寄存器1
/**************************************************************************/
#define		f_E0			_Error_State1.bit.Bit0			// 水温传感器故障
#define		f_E7			_Error_State1.bit.Bit1			// 环境传感器故障
#define		f_E2			_Error_State1.bit.Bit2			// 盘管传感器故障
#define		f_E9			_Error_State1.bit.Bit3			// 回气传感器故障
//#define		f_E12			_Error_State1.bit.Bit4			// 回水传感器故障
#define		f_E6			_Error_State1.bit.Bit5			// 排气传感器故障
#define		f_E1			_Error_State1.bit.Bit6			// 线控通讯故障
//#define		f_E11			_Error_State1.bit.Bit7			// 室内板通讯故障
/**************************************************************************/

/**************************************************************************/
//uint		bdata			_Error_State2;					故障代码寄存器2
/**************************************************************************/
#define		f_E3			_Error_State2.bit.Bit0			// 系统高压保护故障
#define		f_E4			_Error_State2.bit.Bit1			// 系统低压保护故障
#define		f_E5			_Error_State2.bit.Bit2			// 排气温度过高保护故障
/**************************************************************************/

/**************************************************************************/
//uchar   bdata     f_System_Mode；   室外机工作模式标志位寄存器
/**************************************************************************/
#define		f_Heat_Recovery				f_System_Mode.bit.Bit1   // 热回收模式
#define		f_Refrigeration				f_System_Mode.bit.Bit2   // 单制冷模式
#define		f_Heating_Calorifier	f_System_Mode.bit.Bit3   // 空调制热加制热水
#define		f_Heating							f_System_Mode.bit.Bit4   // 单制热模式
#define		f_Calorifier					f_System_Mode.bit.Bit5   // 热泵热水模式
#define		f_System_CSS_Mode			f_System_Mode.bit.Bit6   // 除霜模式
#define		f_System_SFS_Mode			f_System_Mode.bit.Bit7   // 按键收氟标志位
/**************************************************************************/

/**************************************************************************/
//uchar   bdata     _System_Mode；   室外机工作模式寄存器
/**************************************************************************/
#define		f_System_Run				 			_System_Mode.bit.Bit0   // 系统开机
#define		f_Mode_Heat_Recovery			_System_Mode.bit.Bit1   // 热回收模式
#define		f_Mode_Refrigeration			_System_Mode.bit.Bit2   // 单制冷模式
#define		f_Mode_Heating_Calorifier	_System_Mode.bit.Bit3   // 空调制热加制热水
#define		f_Mode_Heating						_System_Mode.bit.Bit4   // 单制热模式
#define		f_Mode_Calorifier					_System_Mode.bit.Bit5   // 热泵热水模式
#define		f_Mode_System_CSS					_System_Mode.bit.Bit6   // 除霜模式
#define		f_Mode_System_SFS					_System_Mode.bit.Bit7   // 收氟模式
/**************************************************************************/

/**************************************************************************/
//uchar   bdata     _System_Ctrl；  系统控制寄存器
/**************************************************************************/
//#define		f_System_Run					_System_Ctrl.bit.Bit0   // 系统开机
#define		f_Manual_Heater		  	_System_Ctrl.bit.Bit1   // 电加热
#define		f_Sys_Refrigeration		_System_Ctrl.bit.Bit2   // 空调制冷
#define		f_Sys_Heating					_System_Ctrl.bit.Bit3   // 空调制热
#define		f_Sys_Calorifier			_System_Ctrl.bit.Bit4   // 制热水
#define		f_System_SFS					_System_Ctrl.bit.Bit5   // 强制收氟
#define		f_System_CSS					_System_Ctrl.bit.Bit6   // 强制除霜
/**************************************************************************/

//--------------------------------------------------

#endif

//---------------------------------







