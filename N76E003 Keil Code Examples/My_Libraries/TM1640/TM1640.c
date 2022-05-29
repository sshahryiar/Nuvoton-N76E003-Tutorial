#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "TM1640.h"
             
               
void TM1640_init(unsigned char brightness_level)
{                
  TM1640_GPIO_init();
  
  Timer0_Delay1ms(10);  
  
  DIN_pin_HIGH();
  SCLK_pin_HIGH();

  TM1640_send_command(auto_address);
  TM1640_send_command(brightness_level);
  TM1640_clear_display();
}   


void TM1640_start(void)
{
  DIN_pin_HIGH();
  SCLK_pin_HIGH();
  Timer3_Delay10us(1);
  DIN_pin_LOW();
  Timer3_Delay10us(1);
  SCLK_pin_LOW();
}


void TM1640_stop(void)
{
  DIN_pin_LOW();
  SCLK_pin_LOW();
  Timer3_Delay10us(1);
  SCLK_pin_HIGH();
  Timer3_Delay10us(1);
  DIN_pin_HIGH();
}
                           
                                                                             
void TM1640_write(unsigned char value)  
{                                                       
  unsigned char s = 0x08;
  
  while(s > 0)
  {
    SCLK_pin_LOW();
    
    if((value & 0x01) == 0x01)
    {
     DIN_pin_HIGH();
    }
    else
    {
     DIN_pin_LOW();
    }
    
    SCLK_pin_HIGH();

    value >>= 0x01;
    s--;
  };
}                                 


void TM1640_send_command(unsigned char value)    
{                            
  TM1640_start();
  TM1640_write(value);
  TM1640_stop();
}               


void TM1640_send_data(unsigned char address, unsigned char value)
{                  
  TM1640_send_command(fixed_address);
  
  TM1640_start();
  
  TM1640_write((0xC0 | (0x0F & address)));
  TM1640_write(value);
  
  TM1640_stop();
}  


void TM1640_clear_display(void)
{ 
  unsigned char s = 0x00;
  
  for(s = 0x00; s < no_of_segments; s++)
  {
    TM1640_send_data(s, 0);
  };
}