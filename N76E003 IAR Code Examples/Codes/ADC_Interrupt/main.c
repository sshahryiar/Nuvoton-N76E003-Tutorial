#include "N76E003_IAR.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "soft_delay.h"
#include "LCD_2_Wire.h"


//LDR Definitions//

#define LDR_constant                  100000.0
#define R_fixed                        10000.0             
#define VDD                               4095


unsigned int adc_value = 0x0000;


void setup(void);
unsigned int ADC_read(void);
void lcd_print_i(unsigned char x_pos, unsigned char y_pos, unsigned int value);
unsigned int measure_light_intensity(void);


#pragma vector = 0x5B
__interrupt void ADC_ISR(void) 
{
  adc_value = ADC_read();
  clr_ADCF;
}


void main(void)
{
  unsigned int lux = 0;
  
  setup();
  
  while(1)
  {
    set_ADCS;
    lux = measure_light_intensity();
    lcd_print_i(12, 0, adc_value);
    lcd_print_i(12, 1, lux);
    delay_ms(400);
  }
}


void setup(void)
{ 
  LCD_init();
  LCD_clear_home(); 
  LCD_goto(0, 0); 
  LCD_putstr("ADC Count:");
  LCD_goto(0, 1); 
  LCD_putstr("Lux Value:");
  
  Enable_ADC_AIN4;
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


unsigned int measure_light_intensity(void)
{
  float lux = 0;

  lux = adc_value;
  
  lux = (LDR_constant * ((VDD / (R_fixed * lux))) - 0.1); 

  if((lux >= 0) && (lux <= 9999))
  {
    return ((unsigned int)lux);
  }
  else
  {
    return 0;
  }
}