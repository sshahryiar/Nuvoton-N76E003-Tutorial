#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "font.h"
#include "TM1640.h"


void display_data(unsigned char segment, signed int value);


void main(void)
{	
	unsigned int i = 0;
	unsigned int j = 999;
	
	TM1640_init(brightness_75_pc);;
	
	while(1)
	{
		display_data(0, i++);
    display_data(4, j--);
    Timer3_Delay100ms(4);
	};
}


void display_data(unsigned char segment, signed int value)
{
	unsigned char ch = 0;
	
	if((value > 99) && (value <= 999))
	{
		ch = (value / 100);
		TM1640_send_data((2 + segment), fonts[1 + ch]);

		ch = ((value / 10) % 10);
		TM1640_send_data((1 + segment), fonts[1 + ch]);

		ch = (value % 10);
		TM1640_send_data(segment, fonts[1 + ch]);
	}
	
	else if((value > 9) && (value <= 99))
	{
		TM1640_send_data((2 + segment), 0);

		ch = (value / 10);
		TM1640_send_data((1 + segment), fonts[1 + ch]);

		ch = (value % 10);
		TM1640_send_data(segment, fonts[1 + ch]);
	}
	
	else
	{
		TM1640_send_data((2 + segment), 0);

		TM1640_send_data((1 + segment), 0);

		ch = (value % 10);
		TM1640_send_data(segment, fonts[1 + ch]);
	}
}