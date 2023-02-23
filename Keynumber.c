#include <REGX52.H>
#include <intrins.h>
#include "Delay.h"
unsigned char Key(unsigned char mode)    //乐曲演奏键盘扫描
{
	
	unsigned char Keynumber=0;
	P3=0XF0;
	if(P3!=0xF0)
	{
		Delayms(1);
		if(P3!=0xF0)
		{
			switch(P3)
			{
				case 0xE0:Keynumber=4;break;
				case 0xD0:Keynumber=3;break;
				case 0xB0:Keynumber=2;break;
				case 0x70:Keynumber=1;break;
			}
			P3=0x0f;
			switch (P3)
			{
				case 0x0E:Keynumber=Keynumber;break;
				case 0x0D:Keynumber=Keynumber+4;break;
				case 0x0B:Keynumber=Keynumber+8;break;
				case 0x07:Keynumber=Keynumber+12;break;
				
			}
			if(mode==0||Keynumber==8)
			{
			while(P3!=0x0f);  //等待按键抬起
			}
			}
	}
	return Keynumber;
}
