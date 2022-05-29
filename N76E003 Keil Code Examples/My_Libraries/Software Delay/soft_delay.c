#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "soft_delay.h"


void delay_us(unsigned int value)
{
  value = (value / osc_scalar);
  
  while(value > 0)
  {
		nop;
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