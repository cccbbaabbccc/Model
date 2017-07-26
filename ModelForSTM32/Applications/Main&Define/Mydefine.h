/* 
 + �ļ���  ��MyDefine.h
 + ����    ��ʵ�õĶ���
 */
#ifndef _MYDEFINE_H
#define _MYDEFINE_H

#ifdef root											// ����main.c�ж��壬����.c�в��ö���
	#define   ramExtern 	 				// ��main.c�м���"#define root", �� ramExtern ������Ϊ��
#else				
	#define   ramExtern		extern	// ��������.c�ļ���û��"#define root"���� ramExtern������Ϊ"extern��
#endif

typedef	unsigned	char	uchar;
typedef	unsigned	int		uint;
typedef	unsigned 	long	ulong;
typedef	signed 		char	schar;

typedef	signed		char 	si08;
typedef signed		short	si16;
typedef signed		int	 	si32;
typedef unsigned	char 	ui08;
typedef unsigned	short	ui16;
typedef unsigned	int 	ui32;

#define clrsomeonebit(a,b)  ((a) &= ~(1<<(b)))   // ��a�е�bλд0
#define setsomeonebit(a,b)  ((a) |=  (1<<(b)))   // ��a�е�bλд1
#define getsomeonebit(a,b)	(((a)>>(b))&(0x01))	 // ��a�е�bλ��

typedef union _Flag08{	// 8λλ�����
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

typedef union _Flag16{	// 16λλ�����
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


#ifndef	NULL
#define	NULL	((void *)0L)
#endif
  
#define	SetXPage(v1)	(XPAGE = v1)
#define SetWDT(v1)	(RSTSTAT = v1)
#define	WDT_1MS		Bin(00000111)
#define	WDT_4MS		Bin(00000110)
#define	WDT_16MS	Bin(00000101)
#define	WDT_64MS	Bin(00000100)
#define	WDT_128MS	Bin(00000011)
#define	WDT_256MS	Bin(00000010)
#define	WDT_1024MS	Bin(00000001)
#define	WDT_4096MS	Bin(00000000)

#define T0_125US  (unsigned int)(65536-125*12.3)
#define T2_125US  125
#define T2_1200US (65536-1200*8)


#endif





