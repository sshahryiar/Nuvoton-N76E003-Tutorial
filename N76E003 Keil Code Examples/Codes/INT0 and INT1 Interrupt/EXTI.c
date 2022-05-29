#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"


void setup(void);


void EXT_INT0(void) 
interrupt 0
{
	set_P00;
}


void EXT_INT1(void) 
interrupt 2
{
	set_P01;
}


void main(void)
{
	setup();
	
	while(1)
	{
		Timer0_Delay1ms(1000);
		clr_P00;
		clr_P01;
	}
}


void setup(void)
{
	P00_PushPull_Mode;
	P01_PushPull_Mode;
	P17_Input_Mode;
	P30_Input_Mode;	
	set_P1S_7;
	set_P3S_0;
	set_IT0;
	set_IT1;
	set_EX0;
	set_EX1;
  set_EA;	
}