#include <REGX52.H>
#include <intrins.h>
void Latch(unsigned char x)
{
	switch (x)
	{
		/*case 0:c=0;b=0;a=0;break;
		case 1:c=0;b=0;a=1;break;
		case 2:c=0;b=1;a=0;break;
		case 3:c=0;b=1;a=1;break;
		case 4:c=1;b=0;a=0;break;
		case 5:c=1;b=0;a=1;break;
		case 6:c=1;b=1;a=0;break;
		case 7:c=1;b=1;a=1;break;*/
		case 0:P2=0x00;break;
		case 1:P2=0x20;break;
		case 2:P2=0x40;break;
		case 3:P2=0x60;break;
		case 4:P2=0x80;break;
		case 5:P2=0xA0;break;
		case 6:P2=0xC0;break;
		case 7:P2=0xE0;break;
	}
	
}
void Latchoff()
{
	P2=0x00;
}
void LockLatch(unsigned char x)
{
	Latch(x);
	Latchoff();
}