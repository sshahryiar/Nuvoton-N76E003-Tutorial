#include "N76E003_iar.h"
#include "Common.h"
#include "Delay.h"
#include "SFR_Macro.h"
#include "Function_define.h"


void main (void)
{
  unsigned char s = 0;

  P15_PushPull_Mode;

  Timer0_Delay1ms(1000);

  for(s = 0; s <= 9; s++)
  {
    P15 = ~P15;
    Timer0_Delay1ms(60);
  }

  TA = 0xAA;
  TA = 0x55;
  WDCON = 0x07;						
  set_WDCLR;													
  while((WDCON | ~SET_BIT6) == 0xFF);			
  EA = 1;
  set_WDTR;														
      
  while(1)
  {
    for(s = 0; s <= 9; s++)
    {
            P15 = ~P15;
            Timer0_Delay1ms(200);
    }
    while(1);
  }
}