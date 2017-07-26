#ifndef _BITDEFINE_H
#define _BITDEFINE_H

#define clrsomeonebit(a,b)  ((a) &= ~(1<<(b)))   // ��a�е�bλд0
#define setsomeonebit(a,b)  ((a) |=  (1<<(b)))   // ��a�е�bλд1
#define getsomeonebit(a,b)	(((a)>>(b))&(0x01))	 // ��a�е�bλ��

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
//uchar   bdata   	TIME_Flagb;			��ʱ��־λ�Ĵ���
/**************************************************************************/
#define		f_Time_4ms				TIME_Flagb.bit.Bit0
#define		f_Time_20ms				TIME_Flagb.bit.Bit1
#define		f_Time_100ms			TIME_Flagb.bit.Bit2
#define		f_Time_500ms			TIME_Flagb.bit.Bit3
#define		f_Time_1s				  TIME_Flagb.bit.Bit5
#define		f_Time_1s1				TIME_Flagb.bit.Bit6
/**************************************************************************/

/**************************************************************************/
//uchar		bdata			UART_Flag;		���ڱ�־λ�Ĵ���
/**************************************************************************/
#define		f_UART_Send						UART_Flag.bit.Bit0			// ���ڷ��ͱ�־λ
#define		f_UART_Receive				UART_Flag.bit.Bit1			// ���ڽ��ձ�־λ	
#define		Drive_By_Wire_Data		UART_Flag.bit.Bit3   // �����߿����ݱ�־λ
/**************************************************************************/

/**************************************************************************/
//uchar   bdata     _Flagb1��   ϵͳ���Ʊ�־λ
/**************************************************************************/
#define		f_Open_Fan					_Flagb1.bit.Bit0   // ���ȱ���ˮ��־λ
#define		f_Open_Heater				_Flagb1.bit.Bit1   // ������ȱ�־λ
#define		f_System_Close			_Flagb1.bit.Bit2   // �ػ���־λ
#define		f_EValue_Hot				_Flagb1.bit.Bit3   // �������ͷ��ȶȿ���
//#define		f_Heater_Close			_Flagb1.bit.Bit4   // ��ˮ����ͣ����־λ
#define		f_Time_fan					_Flagb1.bit.Bit5   // �����ʱ��־λ
#define		f_Open_YJ						_Flagb1.bit.Bit6   // ��ѹ������־λ
#define		f_Open_Air_Con			_Flagb1.bit.Bit7   // �յ�����
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
//uchar		bdata			_System_State1;			�����ϵͳ״̬�Ĵ���1
/**************************************************************************/
#define		f_System_WFan			_System_State1.bit.Bit0   // ����
#define		f_System_YJ				_System_State1.bit.Bit1   // ѹ����
#define		f_System_HXF_1		_System_State1.bit.Bit2   // ��ͨ��1
#define		f_System_HXF_2		_System_State1.bit.Bit3   // ��ͨ��2
#define		f_System_Hot			_System_State1.bit.Bit4   // �����
#define		f_System_RW				_System_State1.bit.Bit5   // ��ˮ��
#define		f_System_LHot			_System_State1.bit.Bit6   // �̹ܼ���
/**************************************************************************/

/**************************************************************************/
//uchar		bdata			_System_State2;			�����ϵͳ״̬�Ĵ���2
/**************************************************************************/
#define		f_System_HVS			_System_State2.bit.Bit0   // ��ѹ����
#define		f_System_LVS			_System_State2.bit.Bit1   // ��ѹ����
#define		f_System_WS				_System_State2.bit.Bit2   // ˮλ����
/**************************************************************************/

/**************************************************************************/
//uchar		bdata			_Protect_State;			������־λ�Ĵ���
/**************************************************************************/
#define		f_Protect_High_Voltage	 _Protect_State.bit.Bit0   // ��ѹ�쳣������־λ 
#define		f_Protect_Low_Voltage		 _Protect_State.bit.Bit1   // ��ѹ�쳣������־λ 
#define		f_Protect_Exhaust_Over	 _Protect_State.bit.Bit2   // �����¶ȹ��߱�����־λ
#define		f_Protect_CSS						 _Protect_State.bit.Bit3   // �����ᱣ����־λ
#define		f_Protect_YJ						 _Protect_State.bit.Bit4   // ѹ��������������־λ
/**************************************************************************/

/**************************************************************************/
//uint		bdata			_Error_State1;					���ϴ���Ĵ���1
/**************************************************************************/
#define		f_E0			_Error_State1.bit.Bit0			// ˮ�´���������
#define		f_E7			_Error_State1.bit.Bit1			// ��������������
#define		f_E2			_Error_State1.bit.Bit2			// �̹ܴ���������
#define		f_E9			_Error_State1.bit.Bit3			// ��������������
//#define		f_E12			_Error_State1.bit.Bit4			// ��ˮ����������
#define		f_E6			_Error_State1.bit.Bit5			// ��������������
#define		f_E1			_Error_State1.bit.Bit6			// �߿�ͨѶ����
//#define		f_E11			_Error_State1.bit.Bit7			// ���ڰ�ͨѶ����
/**************************************************************************/

/**************************************************************************/
//uint		bdata			_Error_State2;					���ϴ���Ĵ���2
/**************************************************************************/
#define		f_E3			_Error_State2.bit.Bit0			// ϵͳ��ѹ��������
#define		f_E4			_Error_State2.bit.Bit1			// ϵͳ��ѹ��������
#define		f_E5			_Error_State2.bit.Bit2			// �����¶ȹ��߱�������
/**************************************************************************/

/**************************************************************************/
//uchar   bdata     f_System_Mode��   ���������ģʽ��־λ�Ĵ���
/**************************************************************************/
#define		f_Heat_Recovery				f_System_Mode.bit.Bit1   // �Ȼ���ģʽ
#define		f_Refrigeration				f_System_Mode.bit.Bit2   // ������ģʽ
#define		f_Heating_Calorifier	f_System_Mode.bit.Bit3   // �յ����ȼ�����ˮ
#define		f_Heating							f_System_Mode.bit.Bit4   // ������ģʽ
#define		f_Calorifier					f_System_Mode.bit.Bit5   // �ȱ���ˮģʽ
#define		f_System_CSS_Mode			f_System_Mode.bit.Bit6   // ��˪ģʽ
#define		f_System_SFS_Mode			f_System_Mode.bit.Bit7   // �����շ���־λ
/**************************************************************************/

/**************************************************************************/
//uchar   bdata     _System_Mode��   ���������ģʽ�Ĵ���
/**************************************************************************/
#define		f_System_Run				 			_System_Mode.bit.Bit0   // ϵͳ����
#define		f_Mode_Heat_Recovery			_System_Mode.bit.Bit1   // �Ȼ���ģʽ
#define		f_Mode_Refrigeration			_System_Mode.bit.Bit2   // ������ģʽ
#define		f_Mode_Heating_Calorifier	_System_Mode.bit.Bit3   // �յ����ȼ�����ˮ
#define		f_Mode_Heating						_System_Mode.bit.Bit4   // ������ģʽ
#define		f_Mode_Calorifier					_System_Mode.bit.Bit5   // �ȱ���ˮģʽ
#define		f_Mode_System_CSS					_System_Mode.bit.Bit6   // ��˪ģʽ
#define		f_Mode_System_SFS					_System_Mode.bit.Bit7   // �շ�ģʽ
/**************************************************************************/

/**************************************************************************/
//uchar   bdata     _System_Ctrl��  ϵͳ���ƼĴ���
/**************************************************************************/
//#define		f_System_Run					_System_Ctrl.bit.Bit0   // ϵͳ����
#define		f_Manual_Heater		  	_System_Ctrl.bit.Bit1   // �����
#define		f_Sys_Refrigeration		_System_Ctrl.bit.Bit2   // �յ�����
#define		f_Sys_Heating					_System_Ctrl.bit.Bit3   // �յ�����
#define		f_Sys_Calorifier			_System_Ctrl.bit.Bit4   // ����ˮ
#define		f_System_SFS					_System_Ctrl.bit.Bit5   // ǿ���շ�
#define		f_System_CSS					_System_Ctrl.bit.Bit6   // ǿ�Ƴ�˪
/**************************************************************************/

//--------------------------------------------------

#endif

//---------------------------------






