#line 1 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\My_Libraries\\Software Delay\\soft_delay.c"
#line 1 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\My_Libraries\\Software Delay\\soft_delay.h"




void delay_us(unsigned int value);
void delay_ms(unsigned int value);
#line 2 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\My_Libraries\\Software Delay\\soft_delay.c"


void delay_us(unsigned int value)
{
  value = (value / (16 / 16));
  
  while(value > 0)
  {
    asm("nop");
    value--;
  }
}


void delay_ms(unsigned int value)
{ 
  while(value > 0)
  {
    --value;
    delay_us(1000);
  }
}
