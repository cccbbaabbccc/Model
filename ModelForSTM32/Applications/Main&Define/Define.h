#ifndef	_DEFINE_H
#define	_DEFINE_H

#include  "SWM1000S.h"



#define	HIBYTE_REF(addr)	(*((Byte*)&addr))
#define	LOBYTE_REF(addr)	(*((Byte*)&addr+1))
#define	MAKEWORD(v1,v2)		(((Word)(v1)<<8) + (Word)(v2))
#define	HIBYTE(v1)		((uchar)((v1)>>8))
#define	LOBYTE(v1)		((uchar)((v1)&0xff))
#define SetB(d,b)       (d |= (1<<b))
#define ClrB(d,b)       (d &= (~(1<<b)))
#define XorB(d,b)       (d ^= (1<<b)) 
#define	SUCCESS		0
#define	FAILURE		1
#define	Enable		1
#define Disable		0
#define	ON				1
#define	OFF				0
#define FALSE     (0!=0)
#define TRUE      (0==0)

#define T16_125US	    0x01F4*2			// 125us*Fx/2
#define	Baud1200	0x0D05*2

#define IntToBin(n) \
(                    \
((n >> 21) & 0x80) | \
((n >> 18) & 0x40) | \
((n >> 15) & 0x20) | \
((n >> 12) & 0x10) | \
((n >>  9) & 0x08) | \
((n >>  6) & 0x04) | \
((n >>  3) & 0x02) | \
((n      ) & 0x01)   \
)
#define Bin(n) IntToBin(0x##n##l)	//write binary charactor set,exsample : Bin(11111111) = 0xff

#endif

