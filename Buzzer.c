#include <REGX52.H>
#include "Delay.h"
sbit Buzzer=P1^0;
void Buzzer_Time(unsigned int us)
{
	while(us--)
	{
		Buzzer=~Buzzer;
		Delay(50);
	}
}