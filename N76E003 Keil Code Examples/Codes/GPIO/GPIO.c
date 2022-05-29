#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"


void setup(void);


void main(void)
{	
	setup();
	
	while(1)
	{
		if(P05 != 0x00)
		{
			Timer0_Delay1ms(900);
		}
		
		set_P15;
		Timer0_Delay1ms(100);
		clr_P15;
		Timer0_Delay1ms(100);
	};
}


void setup(void)
{	
	P15_PushPull_Mode;
	P05_Input_Mode;
}