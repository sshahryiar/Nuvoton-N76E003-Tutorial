#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "LCD_2_Wire.h"


void show_value(unsigned char value);


void main(void)
{	
	unsigned char s = 0;

	const char txt1[] = {"MICROARENA"};
	const char txt2[] = {"SShahryiar"};
	const char txt3[] = {"Nuvoton 8-bit uC"};
	const char txt4[] = {"N76E003"};
	
	LCD_init();

	LCD_clear_home();

	LCD_goto(3, 0);
	LCD_putstr(txt1);
	LCD_goto(3, 1);
	LCD_putstr(txt2);
	Timer3_Delay100ms(30);

	LCD_clear_home();

	for(s = 0; s < 16; s++)
	{
		LCD_goto(s, 0);
		LCD_putchar(txt3[s]);
		Timer0_Delay1ms(90);
	}
	
	Timer3_Delay100ms(20);
	
	for(s = 0; s < 7; s++)
	{
		LCD_goto((4 + s), 1);
		LCD_putchar(txt4[s]);
		Timer0_Delay1ms(90);
	}
	
	Timer3_Delay100ms(30);
	
	s = 0;
	LCD_clear_home();
	
	LCD_goto(3, 0);
  LCD_putstr(txt1);
	
	while(1)
	{
		show_value(s);
    s++;
		Timer3_Delay100ms(4);
	};
}


void show_value(unsigned char value)
{
   unsigned char ch = 0x00;

   ch = ((value / 100) + 0x30);
   LCD_goto(6, 1);
   LCD_putchar(ch);

   ch = (((value / 10) % 10) + 0x30);
   LCD_goto(7, 1);
   LCD_putchar(ch);

   ch = ((value % 10) + 0x30);
   LCD_goto(8, 1);
   LCD_putchar(ch);
}