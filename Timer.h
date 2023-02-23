#ifndef __Timer_H__
#define __Timer_H__
/**
*@简介：初始化定时器
*@输入：初始化定时器数值，优先级（0=低优先级1=高优先级）
*@返回值：无
*/

void InitTimer(unsigned char x,unsigned char y);
/**
*@简介：初始化外部中断
*@输入：初始化定时器数值，低电平出发或低跳电触发（0=低电平1=低跳电），优先级（0=低优先级1=高优先级）
int0 P3.2 S5  int1 P3.3 S4
*@返回值：无
*/
void InitExter(unsigned char x,unsigned char y,unsigned z);
#endif