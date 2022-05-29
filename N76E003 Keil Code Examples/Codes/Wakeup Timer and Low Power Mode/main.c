#include "N76E003.h"
#include "Common.h"
#include "Delay.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "soft_delay.h"


void WKT_ISR(void)
interrupt 17
{
  clr_WKTR;
  clr_WKTF;                    		          
}


void main(void)
{
  unsigned char s = 0; 
  
  P15_PushPull_Mode;

  WKCON = 0x03; 											
  RWK = 0X00;
  set_EWKT;												
  set_EA;
	
  while(1)
  {
    for(s = 0; s < 9; s++)
    {
      P15 = ~P15;
      delay_ms(100);
    }
    
    set_WKTR; 													
    set_PD;
    
    for(s = 0; s <= 9; s++)
    {
      P15 = ~P15;
      delay_ms(300);
    }
    
    set_WKTR; 													
    set_PD;
  };
}