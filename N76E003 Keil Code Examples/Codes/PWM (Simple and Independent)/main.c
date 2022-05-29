#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "soft_delay.h"


unsigned int R_value[10] = {20, 150, 250, 360, 440, 560, 680, 820, 900, 1020};
unsigned int G_value[10] = {440, 560, 680, 820, 900, 1020, 20, 150, 250, 360};
unsigned int B_value[10] = {900, 1020, 20, 150, 250, 360, 440, 560, 680, 820};


void set_PWM_period(unsigned int value);
void set_PWM0(unsigned int value);
void set_PWM1(unsigned int value);
void set_PWM2(unsigned int value);
void set_PWM3(unsigned int value);
void set_PWM4(unsigned int value);
void set_PWM5(unsigned int value);


void main(void)
{
	signed int i = 0;
	signed char j = 0;

	P01_PushPull_Mode;
	P10_PushPull_Mode;
	P11_PushPull_Mode;

	PWM1_P11_OUTPUT_ENABLE;
	PWM2_P10_OUTPUT_ENABLE;
	PWM4_P01_OUTPUT_ENABLE;

	PWM_IMDEPENDENT_MODE;
	PWM_EDGE_TYPE;
	set_CLRPWM;
	PWM_CLOCK_FSYS;
	PWM_CLOCK_DIV_64;
	PWM_OUTPUT_ALL_NORMAL;
	set_PWM_period(1023);
	set_PWMRUN;

	while(1)
	{
		for(i = 0; i < 1024; i += 10)
		{
			set_PWM1(i);
			delay_ms(20);
		}
		for(i = 1023; i > 0; i -= 10)
		{
			set_PWM1(i);
			delay_ms(20);
		}              
		
		for(i = 0; i < 1024; i += 10)
		{
			set_PWM2(i);
			delay_ms(20);
		}
		for(i = 1023; i > 0; i -= 10)
		{
			set_PWM2(i);
			delay_ms(20);
		}
		
		for(i = 0; i < 1024; i += 10)
		{
			set_PWM4(i);
			delay_ms(20);
		}
		for(i = 1023; i > 0; i -= 10)
		{
			set_PWM4(i);
			delay_ms(20);
		}
		
		delay_ms(600);
		
		for(i = 0; i <=9; i++)
		{
			for(j = 0; j <= 9; j++)
			{
				set_PWM4(R_value[j]);
				set_PWM1(G_value[j]);
				set_PWM2(B_value[j]);
				delay_ms(200);
			} 
			for(j = 9; j >= 0; j--)
			{
				set_PWM4(R_value[j]);
				set_PWM1(G_value[j]);
				set_PWM2(B_value[j]);
				delay_ms(200);
			} 
		}
		
		delay_ms(600);
	}
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