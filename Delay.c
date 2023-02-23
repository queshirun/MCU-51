#include <REGX52.H>
#include <intrins.h>
void Delayus(unsigned int x)
{
	while(x--)
	{
			_nop_();
	_nop_();
	_nop_();
	}
}
void Delayms(unsigned int x)		//@11.0592MHz
{
	while(x--)
	{
	unsigned char i, j;

	_nop_();
	_nop_();
	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}
}
