#include <REGX52.H>
#include "Delay.h"
#include <Latch.h>
void Nixietube(unsigned char Location,unsigned char Number)//输入参数：位码，段码
{
	Latch(6);
	
	switch (Location)
	{
		case 1:P0=0x01;break;
		case 2:P0=0x02;break;
		case 3:P0=0x04;break;
		case 4:P0=0x08;break;
		case 5:P0=0x10;break;
		case 6:P0=0x20;break;
		case 7:P0=0x40;break;
		case 8:P0=0x80;break;
	}
	Latchoff();
	P0=0xFF;
	Latch(7);
	switch (Number)
	{
		case 0:P0=0xC0;break;
		case 1:P0=0xF9;break;
		case 2:P0=0xA4;break;
		case 3:P0=0xB0;break;
		case 4:P0=0x99;break;
		case 5:P0=0x92;break;
		case 6:P0=0x82;break;
		case 7:P0=0xF8;break;
		case 8:P0=0x80;break;
		case 9:P0=0x90;break;
		case 10:P0=0xBF;break;
	}
	//P0=0xFF;
	Latchoff();
	P0=0x00;
	//Delay(500);


}
