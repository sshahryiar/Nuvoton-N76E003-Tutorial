#include "N76E003_iar.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "soft_delay.h"
#include "lcd.h"


void LCD_init(void)
{
	delay_ms(10);

	LCD_GPIO_init();
	
	delay_ms(100);

	toggle_EN_pin();

	LCD_RS_LOW;

	LCD_DB7_LOW;
	LCD_DB6_LOW;
	LCD_DB5_HIGH;
	LCD_DB4_HIGH;

	toggle_EN_pin();

	LCD_DB7_LOW;
	LCD_DB6_LOW;
	LCD_DB5_HIGH;
	LCD_DB4_HIGH;

	toggle_EN_pin();

	LCD_DB7_LOW;
	LCD_DB6_LOW;
	LCD_DB5_HIGH;
	LCD_DB4_HIGH;

	toggle_EN_pin();

	LCD_DB7_LOW;
	LCD_DB6_LOW;
	LCD_DB5_HIGH;
	LCD_DB4_LOW;

	toggle_EN_pin();

	LCD_send((_4_pin_interface | _2_row_display | _5x7_dots), CMD);
	LCD_send((display_on | cursor_off | blink_off), CMD);
	LCD_send(clear_display, CMD);
	LCD_send((cursor_direction_inc | display_no_shift), CMD);
}


void LCD_send(unsigned char value, unsigned char mode)
{
	switch(mode)
	{
		case DAT:
		{
			LCD_RS_HIGH;
			break;
		}
		case CMD:
		{
			LCD_RS_LOW;
			break;
		}
	}

	LCD_4bit_send(value);
}


void LCD_4bit_send(unsigned char lcd_data)
{
	unsigned char temp = 0;
	
	temp = ((lcd_data & 0x80) >> 7);
	
	switch(temp)
	{
		case 1:
		{ 
			LCD_DB7_HIGH;
			break;
		}
		default:
		{
			LCD_DB7_LOW;
			break;
		}
	}
	
	temp = ((lcd_data & 0x40) >> 6);
	
	switch(temp)
	{
		case 1:
		{ 
			LCD_DB6_HIGH;
			break;
		}
		default:
		{
			LCD_DB6_LOW;
			break;
		}
	}
	
	temp = ((lcd_data & 0x20) >> 5);
	
	switch(temp)
	{
		case 1:
		{ 
			LCD_DB5_HIGH;
			break;
		}
		default:
		{
			LCD_DB5_LOW;
			break;
		}
	}
	
	temp = ((lcd_data & 0x10) >> 4);
	
	switch(temp)
	{
		case 1:
		{ 
			LCD_DB4_HIGH;
			break;
		}
		default:
		{
			LCD_DB4_LOW;
			break;
		}
	}

	toggle_EN_pin();

	temp = ((lcd_data & 0x08) >> 3);
	
	switch(temp)
	{
		case 1:
		{ 
			LCD_DB7_HIGH;
			break;
		}
		default:
		{
			LCD_DB7_LOW;
			break;
		}
	}
	
	temp = ((lcd_data & 0x04) >> 2);
	
	switch(temp)
	{
		case 1:
		{ 
			LCD_DB6_HIGH;
			break;
		}
		default:
		{
			LCD_DB6_LOW;
			break;
		}
	}
	
	temp = ((lcd_data & 0x02) >> 1);
	
	switch(temp)
	{
		case 1:
		{ 
			LCD_DB5_HIGH;
			break;
		}
		default:
		{
			LCD_DB5_LOW;
			break;
		}
	}
	
	temp = ((lcd_data & 0x01));
	
	switch(temp)
	{
		case 1:
		{ 
			LCD_DB4_HIGH;
			break;
		}
		default:
		{
			LCD_DB4_LOW;
			break;
		}
	}

	toggle_EN_pin();
}


void LCD_putstr(char *lcd_string)
{
	do
	{
		LCD_send(*lcd_string++, DAT);
	}while(*lcd_string != '\0');
}


void LCD_putchar(char char_data)
{
	LCD_send(char_data, DAT);
}


void LCD_clear_home(void)
{
	LCD_send(clear_display, CMD);
	LCD_send(goto_home, CMD);
}


void LCD_goto(unsigned char x_pos, unsigned char y_pos)
{
	if(y_pos == 0)
	{
		LCD_send((0x80 | x_pos), CMD);
	}
	else
	{
		LCD_send((0x80 | 0x40 | x_pos), CMD);
	}
}


void toggle_EN_pin(void)
{
	LCD_EN_HIGH;
	delay_ms(4);
	LCD_EN_LOW;
	delay_ms(4);
}
