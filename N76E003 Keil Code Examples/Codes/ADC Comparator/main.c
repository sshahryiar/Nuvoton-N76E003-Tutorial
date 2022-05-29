#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "soft_delay.h"
#include "LCD_2_Wire.h"


unsigned int adc_value = 0x0000;


void setup(void);
unsigned int ADC_read(void);
void set_ADC_comparator_value(unsigned int value);
void lcd_print_i(unsigned char x_pos, unsigned char y_pos, unsigned int value);



void ADC_ISR(void)
interrupt 11	
{
  adc_value = ADC_read();
  clr_ADCF;
}


void main(void)
{
  setup();
  
  while(1)
  {
    set_ADCS;
    lcd_print_i(12, 0, adc_value);
    
    LCD_goto(12, 1);
    
    if((ADCCON2 & 0x10) != 0x00)
    {
      LCD_putstr("HIGH");
      set_P15; 
    }
    else
    {
      LCD_putstr(" LOW");
      clr_P15;
    }
    
    delay_ms(400);
  }
}


void setup(void)
{ 
  P15_PushPull_Mode;
  
  LCD_init();
  LCD_clear_home(); 
  LCD_goto(0, 0); 
  LCD_putstr("ADC Count:");
  LCD_goto(0, 1); 
  LCD_putstr("Cmp State:");
  
  Enable_ADC_BandGap;
  Enable_ADC_AIN4;
  
  set_ADC_comparator_value(1023);  
  set_ADCMPEN;
  
  set_EADC;
  set_EA;
}


unsigned int ADC_read(void)
{
  register unsigned int value = 0x0000;	
  
  value = ADCRH;
  value <<= 4;
  value |= ADCRL;
  
  return value;
}


void set_ADC_comparator_value(unsigned int value)
{
  ADCMPH = ((value & 0x0FF0) >> 4);
  ADCMPL = (value & 0x000F);
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


