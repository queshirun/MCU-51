#include <REGX52.H>
#include "Delay.h"
#include "Latch.h"
#include "Timer.h"
#include "Nixietube.h"
#include "Keynumber.h"
#define SPEED1 75
#define SPEED2 75
#define SPEED3 75
#define STOP 0
#define L1   1
#define L1_  2
#define L2   3
#define L2_  4
#define L3   5
#define L4   6
#define L4_  7
#define L5   8
#define L5_  9
#define L6   10
#define L6_  11
#define L7   12
#define M1   13
#define M1_  14
#define M2   15
#define M2_  16
#define M3   17
#define M4   18
#define M4_  19
#define M5   20
#define M5_  21
#define M6   22
#define M6_  23
#define M7   24
#define H1   25
#define H1_  26
#define H2   27
#define H2_  28
#define H3   29
#define H4   30
#define H4_  31
#define H5   32
#define H5_  33
#define H6   34
#define H6_  35
#define H7   36

sbit Buzzer=P1^0;
unsigned char mode=1;
unsigned char MusicSelect,FreqSelect;
unsigned int FreqTable[]={0,//空拍
													 63778,63873,63968,64054,64140,64215,64291,64360,64425,64489,64547,64603,  //低音
													 64655,64704,64751,64795,64837,64876,64913,64948,64981,65013,65042,65070,  //中音
													 65095,65120,65143,65166,65187,65206,65224,65242,65259,65274,65289,65303   //高音
};
unsigned char code Music1[]={             //天空之城
	//1
	STOP,4,
	STOP,4,
	STOP,4,
	M6,2,
	M7,2,
	
	H1,4+2,
	M7,2,
	H1,4,
	H3,4,
	
	M7,4+4+4,
	M3,2,
	M3,2,
	//2
	M6,4+2,
	M5,2,
	M6,4,
	H1,4,
	
	M5,4+4+4,
	M3,4,
	
	M4,4+2,
	M3,2,
	M4,4,
	H1,4,
	//3
	M3,4+4,
	STOP,2,
	H1,2,
	H1,2,
	H1,2,
	
	M7,4+2,
	M4_,2,
	M4,4,
	M7,4,
	
	M7,4+4,
	STOP,4,
	M6,2,
	M7,2,
	//4
	H1,4+2,
	M7,2,
	H1,4,
	H3,4,
	
	M7,4+4+4,
	M3,2,
	M3,2,
	
	M6,4+2,
	M5,2,
	M6,4,
	H1,4,
	//5
	M5,4+4+4,
	M2,2,
	M3,2,
	
	M4,4,
	H1,2,
	M7,2+2,
	H1,2+4,
	
	H2,2,
	H2,2,
	H3,2,
	H1,2+4+4,
	//6
	H1,2,
	M7,2,
	M6,2,
	M6,2,
	M7,4,
	M5_,4,
	
	M6,4+4+4,
	H1,2,
	H2,2,
	
	H3,4+2,
	H2,2,
	H3,4,
	H5,4,
	//7
	H2,4+4+4,
	M5,2,
	M5,2,
	
	H1,4+2,
	M7,2,
	H1,4,
	H3,4,
	
	H3,4+4+4+4,
	//8
	M6,2,
	M7,2,
	H1,4,
	M7,4,
	H2,2,
	H2,2,
	
	H1,4+2,
	M5,2+4+4,
	
	H4,4,
	H3,4,
	H2,4,
	H1,4,
	//9
	H3,4+4+4,
	H3,4,
	
	H6,4+4,
	H5,4,
	H5,4,
	
	H3,2,
	H2,2,
	H1,4+4,
	STOP,2,
	H1,2,
	//10
	H2,4,
	H1,2,
	H2,2,
	H2,4,
	H5,4,
	
	H3,4+4+4,
	H3,4,
	
	H6,4+4,
	H5,4+4,
	//11
	H3,2,
	H2,2,
	H1,4+4,
	STOP,2,
	H1,2,
	
	H2,4,
	H1,2,
	H2,2+4,
	M7,4,
	
	M6,4+4+4,
	M6,2,
	M7,2,
	
	
	
	
	
	0xFF
}; //格式为：音符，时长；以0xFF终止
unsigned char code Music2[]={           
	//0
	M3,4,
	M3,2,
	M3,2,
	M4,4,
	M5,4,
	
	M3,4+2,
	M2,2,
	M2,4+4,
	
	M1,4,
	M1,2,
	M1,2,
	M2,4,
	M3,4,
	
	M3,4+2,
	L7,2,
	L7,4+4,
	
	L6,4,
	M3,4,
	M2,4+4,
	//2
	L6,4,
	M3,4,
	M2,4+4,
	
	L6,4,
	M3,4,
	M2,4+2,
	M1,2,
	
	M1,4+4+4+4,
	//
		//0
	M3,4,
	M3,2,
	M3,2,
	M4,4,
	M5,4,
	
	M3,4+2,
	M2,2,
	M2,4+4,
	
	M1,4,
	M1,2,
	M1,2,
	M2,4,
	M3,4,
	
	M3,4+2,
	L7,2,
	L7,4+4,
	
	L6,4,
	M3,4,
	M2,4+4,
	//2
	L6,4,
	M3,4,
	M2,4+4,
	
	L6,4,
	M3,4,
	M2,4+2,
	M1,2,
	
	M1,4+4,
	STOP,4,
	M3,2,
	M2,2,
	
	M5,4+4+4,
	M4,2,
	M3,2+2,
	//3
	M2,2+4+4,
	M5,2,
	M4,2,
	
	M3,4,
	M4,2,
	M5,4+2,
	M3,4,
	
	M2,4+4+4,
	STOP,2,
	M1,2,
	
	L6,4,
	M3,4,
	M2,4+2,
	M1,2,
	//4
	L5,4,
	M2,2,
	M1,2,
	M1,4+4,
	
	M4,2,
	M3,2,
	M4,2,
	M3,2,
	M1,4+2,
	M2,2,
	
	M1,4+4+4+4,
	0XFF
	

	
	
	
}	;
unsigned char code Music3[]={
	STOP,4+2,
	L6,2,
	M3,1,
	M4,1,
	M3,1,
	M4,1,
	M3,2,
	L6,2,
	//2
	STOP,2+4,
	L6,2,
	L5,1,
	L6,1,
	L6,1,
	L5,1,
	L6,2,
	L6,2,
	
	STOP,4+2,
	L6,1,
	L6,1,
	M3,1,
	M4,1,
	M3,1,
	M4,1,
	M3,2,
	L6,2,
	//3
	STOP,2+4,
	L6,2,
	L5,1,
	L6,1,
	L6,1,
	L5,1,
	L6,2,
	L6,2,
	
	L6,4,
	STOP,2,
	L6,2,
	L5,1,
	L6,1,
	L6,1,
	L5,1,
	L6,2,
	L6,2,
	
	M1,4,
	H1,4,
	M7,2,
	M5,2,
	M5,2,
	M3,2,
	
	M3,2,
	M3,2,
	H1,4,
	M7,2,
	M5,2,
	M5,2,
	M3,2+2,
	M5,4+2,
	STOP,2,
	M3,2,
	M3,2,
	M3,2,
	
	M5_,2,
	M5,2,
	M5,2,
	M6,2,
	M7,2,
	L6,1,
	L6,1,
	M3,2,
	M3,2,
	//4
	L6,4,
	STOP,4+4+2,
	L6,1,
	L6,1+2,
	STOP,2+4+2,
	L6,1,
	L6,1,
	M3,2,
	M3,2,
	
	L6,4,
	STOP,4+4+2,
	L6,1,
	L6,1+2,
	STOP,2+2,
	L6,1,
	L6,1,
	L6,2,
	L6,1,
	L6,1,
	M3,2,
	M3,2,
	
	L6,4,
	STOP,4+4+2,
	L6,1,
	L6,1+2,
	STOP,2+4+2,
	L6,1,
	L6,1,
	M3,2,
	M3,2,
	
	L6,4,
	STOP,4+4+2,
	L6,1,
	L6,1+2,
	STOP,2+4,
	L6,4,
	M4,4,
	
	M3,4,
	0XFF
};
void main()
{
	unsigned char Value=0;
	Latch(5);
	P0=0x00;
	Latchoff();
	while(1)
	{
	
  Nixietube(1,10);
	while (1)
	{
		P3=0xff;
		while (1)
		{
		if(Value==0)
		{
			Value=Key(mode);
			if(Value==8)
			{mode=1;}
		}
		else {break;}
		
		}
		if(mode==0)
		{
	switch (Value)//根据键值选择乐曲
	{
		case 1:
			Nixietube(1,1);
		InitTimer(0,0);
			while(1)
			{
				
				
				if(Music1[MusicSelect]!=0xFF)
				{
					FreqSelect=Music1[MusicSelect];
					MusicSelect++;
					Delayms(SPEED1/4*Music1[MusicSelect]);
					MusicSelect++;
					TR0=0;
					Delayms(5);
					TR0=1;
				}
				else
				{
					TR0=0;
					MusicSelect=0;//音符选择数组清零
					break;	//音乐结束，跳出此case循环
				}
			}
		Delayus(5000);
		Value=0;//键值清零
		break;//音乐一演奏程序到此结束
		case 2:
			Nixietube(1,2);
		InitTimer(0,0);
			while(1)
			{
				
				
				if(Music2[MusicSelect]!=0xFF)
				{
					FreqSelect=Music2[MusicSelect];
					MusicSelect++;
					Delayms(SPEED2/4*Music2[MusicSelect]);
					MusicSelect++;
					TR0=0;
					Delayms(5);
					TR0=1;
				}
				else
				{
					TR0=0;
					MusicSelect=0;//音符选择数组清零
					break;	//音乐结束，跳出此case循环
				}
			}
		Delayus(5000);
		Value=0;
		break;
		case 3:
			Nixietube(1,3);
		InitTimer(0,0);
			while(1)
			{
				
				
				if(Music3[MusicSelect]!=0xFF)
				{
					FreqSelect=Music3[MusicSelect];
					MusicSelect++;
					Delayms(SPEED3/4*Music3[MusicSelect]);
					MusicSelect++;
					TR0=0;
					Delayms(5);
					TR0=1;
				}
				else
				{
					TR0=0;
					MusicSelect=0;//音符选择数组清零
					break;	//音乐结束，跳出此case循环
				}
			}
		Delayus(5000);
		Value=0;
		break;
		default:P0=0x00;Delayus(20);	Value=0;break;
	}
	break;//跳出至最外层循环

}
	if(mode==1)
	{
		FreqSelect=0;
		InitTimer(0,0);
		while (mode==1)
		{
			
			Value=Key(mode);
			switch (Value)
			{
				case 1:
					Nixietube(1,1);
					while (P3!=0x0f)
					{
						FreqSelect=M1;
					}
					FreqSelect=0;
					break;
						case 2:
							Nixietube(1,2);
					while (P3!=0x0f)
					{
						FreqSelect=M2;
					}
					FreqSelect=0;
					break;
						case 3:
							Nixietube(1,3);
					while (P3!=0x0f)
					{
						FreqSelect=M3;
					}
					FreqSelect=0;
					break;
						case 4:
							Nixietube(1,4);
					while (P3!=0x0f)
					{
						FreqSelect=M4;
					}
					FreqSelect=0;
					break;
						case 5:
							Nixietube(1,5);
					while (P3!=0x0f)
					{
						FreqSelect=M5;
					}
					FreqSelect=0;
					break;
						case 6:
							Nixietube(1,6);
					while (P3!=0x0f)
					{
						FreqSelect=M6;
					}
					FreqSelect=0;
					break;
						case 7:
							Nixietube(1,7);
					while (P3!=0x0f)
					{
						FreqSelect=M7;
					}
					FreqSelect=0;
					break;
						case 8:mode=0;break;
						default:break;
			}
			Nixietube(1,10);
		}
		TR0=0;
	}
		
	}
	}
}
void Timer0() interrupt 1
{
	if(FreqTable[FreqSelect]!=0)
	{
		TH0=FreqTable[FreqSelect]/256;
		TL0=FreqTable[FreqSelect]%256;
		Buzzer=~Buzzer;
	}
}
