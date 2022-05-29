#include "N76E003_iar.h"
#include "Common.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "soft_delay.h"


#pragma vector = 0x8B
__interrupt void WKT_ISR(void)
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