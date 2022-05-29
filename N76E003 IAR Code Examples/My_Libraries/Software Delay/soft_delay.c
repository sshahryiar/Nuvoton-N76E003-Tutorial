#include "soft_delay.h"


void delay_us(unsigned int value)
{
  value = (value / osc_scalar);
  
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