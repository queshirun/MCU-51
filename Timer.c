#include <REGX52.H>
void InitTimer(unsigned char x,unsigned char y)
{
	if(x==0)
	{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0xF5;		//设置定时初始值
	TH0 = 0xFF;		//设置定时初始值
		EA=1;//开启所有中断
		ET0=1;  //开启T0计时器
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
		PT0=y;//优先级设为y
		
	}
	if(x==1)//1微秒@11.0592MHz
{
	TMOD &= 0x0F;		//设置定时器模式
	TL0 = 0xCD;		//设置定时初始值
	TH0 = 0xD4;		//设置定时初始值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	ET1=1; //开启T0开启
	EA=1;//开启所有中断
	TR1=y;//开启所有中断
}



	
}
void InitExter(unsigned char x,unsigned char y,unsigned z)
{
	if(x==0)
	{
		EX0=1;
		IT0=y;//触发方式：0为低电平出发，1为下降沿触发
		EA=1;
		PX0=z;//优先级设定
	}
	if(x==1)
	{
		EX1=1;
		IT1=y;
		EA=1;
		PX1=z;
	}
}

	

