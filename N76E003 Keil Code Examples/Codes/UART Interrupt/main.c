#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "soft_delay.h"
#include "LCD_2_Wire.h"


unsigned char received = 0;
unsigned char count = 0;
unsigned char buffer[5] = {0x00, 0x00, 0x00, 0x00, 0x00};


void setup(void);


void UART0_ISR(void)     
interrupt 4	
{
	if(RI == 1) 
	{                                                                
		buffer[count] = SBUF;
		count++;
		
		if(count >= 4)
		{
			clr_ES;
			received = 1;
		}
		
		clr_RI; 
	}
	
	P15 = ~P15;
}


void main(void)
{
	unsigned char i = 0;
	
	setup();
	
	while(1)
	{
		Send_Data_To_UART0('S');
		delay_ms(40);
		set_ES;		
		
		if(received)
		{
			
			for(i = 1; i < 4; i++)
			{
				LCD_goto((12 + i), 1);
			  LCD_putchar(buffer[i]);
			}
			
			count = 0;
			received  = 0;
			set_ES;
		}
		
		delay_ms(40);
	}
}


void setup(void)
{
	P15_PushPull_Mode;
	
	LCD_init();
	LCD_clear_home();
	
	LCD_goto(1, 0);
	LCD_putstr("UART Interrupt");
	LCD_goto(0, 1);
	LCD_putstr("Range/Inch:");
	
	InitialUART0_Timer3(9600);
	set_EA;
}

