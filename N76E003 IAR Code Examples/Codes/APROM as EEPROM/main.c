#include "N76E003_IAR.h"
#include "Common.h"
#include "Delay.h"
#include "soft_delay.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "LCD_2_Wire.h"
#include "Flash.h"


#define BASE_ADDRESS  			3700


void lcd_print_c(unsigned char x_pos, unsigned char y_pos, unsigned char value);
void lcd_print_i(unsigned char x_pos, unsigned char y_pos, unsigned int value);


void main (void) 
{
  unsigned char s = 0;
  unsigned char val[1] = {0};
  unsigned char ret_val[1] = {0};

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
    read_data_flash((s + BASE_ADDRESS), ret_val, 1);
    delay_ms(10);
    lcd_print_i(11, 0, (s + BASE_ADDRESS));
    lcd_print_c(13, 1, ret_val[0]);
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
    val[0] = s;    
    write_data_flash((s + BASE_ADDRESS), val, 1);
    delay_ms(10);
    lcd_print_i(11, 0, (s + BASE_ADDRESS));
    lcd_print_c(13, 1, val[0]);
    delay_ms(600);
  }

  while(1)
  {
  };
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