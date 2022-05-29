#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "soft_delay.h"
#include "LCD_2_Wire.h"


signed char encoder_value = 0;


void setup(void);
void lcd_print(unsigned char x_pos, unsigned char y_pos, unsigned int value);


void PIN_INT(void) 
interrupt 7
{
  clr_EA;
  
  if(PIF == 0x01)
  {
    if((P1 & 0x03) == 0x02)
    {
      encoder_value++;
    }
    
    if(encoder_value > 99)
    {
      encoder_value = 0;
    }
  }

  if(PIF == 0x02)
  {        
    if((P1 & 0x03) == 0x01)
    {
      encoder_value--;
    }
    
    if(encoder_value < 0)
    {
      encoder_value = 99;
    }
  }
  
  PIF = 0x00;
  
  P15 = ~P15;
}


void main(void)
{
  setup();
  
  while(1)
  {
    set_EA; 
    lcd_print(14, 0, encoder_value);
    delay_ms(40);
  }
}


void setup(void)
{    
  P10_Input_Mode;
  P11_Input_Mode;	

  P15_PushPull_Mode;
  
  Enable_BIT0_LowLevel_Trig;
  Enable_BIT1_LowLevel_Trig;

  Enable_INT_Port1;

  set_EPI;	
  
  LCD_init();
  LCD_clear_home(); 
  LCD_goto(0, 0); 
  LCD_putstr("ENC Count:");
}


void lcd_print(unsigned char x_pos, unsigned char y_pos, unsigned int value)
{  
  LCD_goto(x_pos, y_pos);
  LCD_putchar((value / 10) + 0x30);
  LCD_goto((x_pos + 1), y_pos);
  LCD_putchar((value % 10) + 0x30);
}


