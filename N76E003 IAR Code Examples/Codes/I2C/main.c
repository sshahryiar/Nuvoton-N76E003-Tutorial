#include "N76E003_iar.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "soft_delay.h"
#include "LCD_3_Wire.h"
#include "I2C.h"
#include "DS1307.h"


extern struct
{
   unsigned char s;
   unsigned char m;
   unsigned char h;
   unsigned char dy;
   unsigned char dt;
   unsigned char mt;
   unsigned char yr;
}time;


void show_value(unsigned char x_pos, unsigned char y_pos, unsigned char value);
void display_time(void);


void main(void)
{
	time.s = 30;
  time.m = 58;
  time.h = 23;
	
	P15_PushPull_Mode;
	
	LCD_init();
	LCD_clear_home();

	LCD_goto(0, 0);

	LCD_putstr("N76E003 I2C RTCC");

	DS1307_init();
	set_time();
	
	while(1)
	{
		get_time();
		display_time();
	};
}


void show_value(unsigned char x_pos, unsigned char y_pos, unsigned char value)
{
	unsigned char chr = 0;

	chr = ((value / 10) + 0x30);
	LCD_goto(x_pos, y_pos);
	LCD_putchar(chr);

	chr = ((value % 10) + 0x30);
	LCD_goto((x_pos + 1), y_pos);
	LCD_putchar(chr);
}


void display_time(void)
{
	P15 ^= 1;
	LCD_goto(6, 1);
	LCD_putchar(' ');
	LCD_goto(9, 1);
	LCD_putchar(' ');
	delay_ms(400);

	show_value(4, 1, time.h);
	show_value(7, 1, time.m);
	show_value(10, 1, time.s);

	LCD_goto(6, 1);
	LCD_putchar(':');
	LCD_goto(9, 1);
	LCD_putchar(':');
	delay_ms(400);
}
