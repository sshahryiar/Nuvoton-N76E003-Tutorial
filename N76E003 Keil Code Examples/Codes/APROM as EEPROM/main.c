#include "N76E003.h"
#include "Common.h"
#include "soft_delay.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "LCD_3_Wire.h"


#define BASE_ADDRESS  			3700


void write_data_byte(unsigned int address, unsigned char value);
unsigned char read_data_byte(unsigned int code *address);
void lcd_print_c(unsigned char x_pos, unsigned char y_pos, unsigned char value);
void lcd_print_i(unsigned char x_pos, unsigned char y_pos, unsigned int value);


void main (void) 
{
	unsigned char s = 0;
	unsigned char data_value = 0;
	
	P15_PushPull_Mode;
	
	LCD_init();
  LCD_clear_home(); 
	
	clr_P15;	
	LCD_goto(0, 0); 
	LCD_putstr("R Addr:");
	LCD_goto(0, 1); 
	LCD_putstr("R Data:");
	
	for(s = 0; s <= 9; s++)
	{
		data_value = read_data_byte((s + BASE_ADDRESS));
		delay_ms(10);
		lcd_print_i(11, 0, (s + BASE_ADDRESS));
		lcd_print_c(13, 1, data_value);
		delay_ms(600);
	}
	
	delay_ms(2000);
	
	set_P15;	
	LCD_goto(0, 0); 
	LCD_putstr("W Addr:");
	LCD_goto(0, 1); 
	LCD_putstr("W Data:");
	
	for(s = 0; s <= 9; s++)
	{
		write_data_byte((s + BASE_ADDRESS), s);
		delay_ms(10);
		lcd_print_i(11, 0, (s + BASE_ADDRESS));
		lcd_print_c(13, 1, s);
		delay_ms(600);
	}
	
	while(1)
	{
	};
}


void write_data_byte(unsigned int address, unsigned char value)
{
	unsigned char looptmp = 0;
	unsigned char u8_addrl_r = 0;
	unsigned char code *cd_longaddr;
	unsigned char xdata *xd_tmp;
	

	u8_addrl_r = address;
	
	if(u8_addrl_r < 0x80)
	{
		u8_addrl_r = 0;
	}
	else 
	{
		u8_addrl_r = 0x80;
	}

	xd_tmp = 0x280;
	cd_longaddr = ((address & 0xff00) + u8_addrl_r);	
	
	while(xd_tmp !=0x300)
	{
		*xd_tmp = *cd_longaddr;
		looptmp++;
		xd_tmp++;
		cd_longaddr++;
	}

	u8_addrl_r = address;
	
	if (u8_addrl_r < 0x80)
	{
		xd_tmp = (u8_addrl_r + 0x280);
	}
	else
	{
		xd_tmp = (u8_addrl_r + 0x200);
	}
	
	*xd_tmp = value;

	IAPAL = address;
	IAPAH = (address >> 8);
	IAPFD = 0xFF;
	set_IAPEN; 
	set_APUEN;
	IAPCN = 0x22; 		
	set_IAPGO; 

	u8_addrl_r = address;
	
	if (u8_addrl_r < 0x80)
	{
		u8_addrl_r = 0;
	}
	else
	{
		u8_addrl_r = 0x80;
	}
	
	xd_tmp = 0x280;
	IAPAL = u8_addrl_r;
	IAPAH = (address >> 8);
	set_IAPEN; 
	set_APUEN;
	IAPCN = 0x21;
	
	while(xd_tmp !=0x2FF)
	{
		IAPFD = *xd_tmp;
		set_IAPGO;
		IAPAL++;
		xd_tmp++;
	}
	
	clr_APUEN;
	clr_IAPEN;
}	


unsigned char read_data_byte(unsigned int code *address)
{
	unsigned char value = 0;
	
	value = (*address >> 8);
	
	return value;
}


void lcd_print_c(unsigned char x_pos, unsigned char y_pos, unsigned char value)
{  
  LCD_goto(x_pos, y_pos);
  LCD_putchar((value / 100) + 0x30);
  LCD_goto((x_pos + 1), y_pos);
  LCD_putchar(((value % 10) / 10) + 0x30);
  LCD_goto((x_pos + 2), y_pos);
  LCD_putchar((value % 10) + 0x30);
}


void lcd_print_i(unsigned char x_pos, unsigned char y_pos, unsigned int value)
{  
  LCD_goto(x_pos, y_pos);
  LCD_putchar((value / 10000) + 0x30);
  LCD_goto((x_pos + 1), y_pos);
  LCD_putchar(((value % 10000) / 1000) + 0x30);  
  LCD_goto((x_pos + 2), y_pos);
  LCD_putchar(((value % 1000) / 100) + 0x30);
  LCD_goto((x_pos + 3), y_pos);
  LCD_putchar(((value % 100) / 10) + 0x30);
  LCD_goto((x_pos + 4), y_pos);
  LCD_putchar((value % 10) + 0x30);
}