#include "N76E003_iar.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "soft_delay.h"
#include "LCD_2_Wire.h"


static unsigned char bl_state;
static unsigned char data_value;


void LCD_init(void)
{                       
  PCF8574_init();
  delay_ms(10);

  bl_state = BL_ON;
  data_value = 0x04;
  PCF8574_write(data_value);

  delay_ms(10);

  LCD_send(0x33, CMD);
  LCD_send(0x32, CMD);

  LCD_send((_4_pin_interface | _2_row_display | _5x7_dots), CMD);         
  LCD_send((display_on | cursor_off | blink_off), CMD);     
  LCD_send((clear_display), CMD);         
  LCD_send((cursor_direction_inc | display_no_shift), CMD);        
}   


void LCD_toggle_EN(void)
{
  data_value |= 0x04;
  PCF8574_write(data_value);
  delay_ms(1);
  data_value &= 0xF9;
  PCF8574_write(data_value);
  delay_ms(1);
}
   

void LCD_send(unsigned char value, unsigned char mode)
{
  switch(mode)
  {
     case CMD:
     {
        data_value &= 0xF4;
        break;
     }
     case DAT:
     {
        data_value |= 0x01;
        break;
     }
  }

  switch(bl_state)
  {
     case BL_ON:
     {
        data_value |= 0x08;
        break;
     }
     case BL_OFF:
     {
        data_value &= 0xF7;
        break;
     }
  }

  PCF8574_write(data_value);
  LCD_4bit_send(value);
  delay_ms(1);
}
    

void LCD_4bit_send(unsigned char lcd_data)       
{
  unsigned char temp = 0x00;

  temp = (lcd_data & 0xF0);
  data_value &= 0x0F;
  data_value |= temp;
  PCF8574_write(data_value);
  LCD_toggle_EN();

  temp = (lcd_data & 0x0F);
  temp <<= 0x04;
  data_value &= 0x0F;
  data_value |= temp;
  PCF8574_write(data_value);
  LCD_toggle_EN();
}  


void LCD_putstr(char *lcd_string)
{
  do
  {
    LCD_putchar(*lcd_string++);
  }while(*lcd_string != '\0') ;
}


void LCD_putchar(char char_data)
{
  if((char_data >= 0x20) && (char_data <= 0x7F))
  {
    LCD_send(char_data, DAT);
  }
}


void LCD_clear_home(void)
{
  LCD_send(clear_display, CMD);
  LCD_send(goto_home, CMD);
}


void LCD_goto(unsigned char x_pos,unsigned char y_pos)
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
