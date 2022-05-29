#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"


void set_PWM_period(unsigned int value);
void set_PWM0(unsigned int value);
void set_PWM1(unsigned int value);
void set_PWM2(unsigned int value);
void set_PWM3(unsigned int value);
void set_PWM4(unsigned int value);
void set_PWM5(unsigned int value);
void set_PWM_dead_time(unsigned int	value);


void main(void)
{
  signed int i = 0;
  
  P11_PushPull_Mode;
  P12_PushPull_Mode;
    
  PWM0_P12_OUTPUT_ENABLE;  
	PWM1_P11_OUTPUT_ENABLE;

	PWM_COMPLEMENTARY_MODE;
	PWM_CENTER_TYPE;
	set_CLRPWM;
	PWM_CLOCK_FSYS;
	PWM_CLOCK_DIV_64;
	PWM0_OUTPUT_INVERSE;
	PWM1_OUTPUT_INVERSE;
	set_PWM_period(600);
	set_PWM_dead_time(40);
	PWM01_DEADTIME_ENABLE;
	set_PWMRUN;

	while(1)
	{
		for(i = 0; i < 600; i++)
		{
			set_PWM0(i);
			Timer0_Delay1ms(5);
		}
		for(i = 600; i > 0; i--)
		{
			set_PWM0(i);
			Timer0_Delay1ms(5);
		}
	};
}


void set_PWM_period(unsigned int value)
{
  PWMPL = (value & 0x00FF);
  PWMPH = ((value & 0xFF00) >> 8);  
}


void set_PWM0(unsigned int value)
{
  PWM0L = (value & 0x00FF);
  PWM0H = ((value & 0xFF00) >> 8);
  set_LOAD;
}


void set_PWM1(unsigned int value)
{
  PWM1L = (value & 0x00FF);
  PWM1H = ((value & 0xFF00) >> 8);
  set_LOAD;
}


void set_PWM2(unsigned int value)
{
  PWM2L = (value & 0x00FF);
  PWM2H = ((value & 0xFF00) >> 8);
  set_LOAD;
}


void set_PWM3(unsigned int value)
{
  PWM3L = (value & 0x00FF);
  PWM3H = ((value & 0xFF00) >> 8);
  set_LOAD;
}


void set_PWM4(unsigned int value)
{
  set_SFRPAGE;
  PWM4L = (value & 0x00FF);
  PWM4H = ((value & 0xFF00) >> 8);
  clr_SFRPAGE;
  set_LOAD;
}


void set_PWM5(unsigned int value)
{
  set_SFRPAGE;
  PWM5L = (value & 0x00FF);
  PWM5H = ((value & 0xFF00) >> 8);
  clr_SFRPAGE;
  set_LOAD;
}


void set_PWM_dead_time(unsigned int	value)
{
	unsigned char hb = 0;
	unsigned char lb = 0;
	
	lb = (value & 0x00FF);
	hb = ((value & 0x0100) >> 8);
	BIT_TMP = EA;
	
	EA = 0;
	TA = 0xAA;
	TA = 0x55;
	PDTEN &= 0xEF;
  PDTEN |= hb;
  PDTCNT = lb;
	EA = BIT_TMP;
	
}