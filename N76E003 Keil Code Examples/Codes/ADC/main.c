#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "LCD_3_Wire.h"


#define scalar          0.12412


void setup(void);
unsigned int ADC_read(void);
void lcd_print_i(unsigned char x_pos, unsigned char y_pos, unsigned int value);
void lcd_print_f(unsigned char x_pos, unsigned char y_pos, unsigned int value);


void main(void)
{
  unsigned int temp = 0;
  unsigned int adc_count = 0;
  
  setup();
  
  while(1)
  {
    adc_count = ADC_read();
    temp = ((unsigned int)(((float)adc_count) / scalar));
    lcd_print_i(12, 0, adc_count);
    lcd_print_f(11, 1, temp);
    Timer0_Delay1ms(600);
  }
}


void setup(void)
{ 
  LCD_init();
  LCD_clear_home(); 
  LCD_goto(0, 0); 
  LCD_putstr("ADC Count:");
  LCD_goto(0, 1); 
  LCD_putstr("Tmp/deg C:");
  
  Enable_ADC_AIN0;
}


unsigned int ADC_read(void)
{
  register unsigned int value = 0x0000;
  
  clr_ADCF;
  set_ADCS;									
  while(ADCF == 0);
  
  value = ADCRH;
  value <<= 4;
  value |= ADCRL;
  
  return value;
}


void lcd_print_i(unsigned char x_pos, unsigned char y_pos, unsigned int value)
{  
  LCD_goto(x_pos, y_pos);
  LCD_putchar((value / 1000) + 0x30);
  LCD_goto((x_pos + 1), y_pos);
  LCD_putchar(((value % 1000) / 100) + 0x30);  
  LCD_goto((x_pos + 2), y_pos);
  LCD_putchar(((value % 100) / 10) + 0x30);
  LCD_goto((x_pos + 3), y_pos);
  LCD_putchar((value % 10) + 0x30);
}

void lcd_print_f(unsigned char x_pos, unsigned char y_pos, unsigned int value)
{  
  LCD_goto(x_pos, y_pos);
  LCD_putchar((value / 1000) + 0x30);
  LCD_goto((x_pos + 1), y_pos);
  LCD_putchar(((value % 1000) / 100) + 0x30);  
  LCD_goto((x_pos + 2), y_pos);
  LCD_putchar('.');
  LCD_goto((x_pos + 3), y_pos);
  LCD_putchar(((value % 100) / 10) + 0x30);
  LCD_goto((x_pos + 4), y_pos);
  LCD_putchar((value % 10) + 0x30);
}