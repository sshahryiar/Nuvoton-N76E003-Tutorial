#include "N76E003_IAR.h"
#include "Common.h"
#include "Delay.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "soft_delay.h"
#include "MAX72xx.h"
#include "MAX6675.h"


void main(void)
{
  unsigned int ti = 0x0000;
  unsigned int t = 0;

  P15_PushPull_Mode;
  MAX6675_init();
  MAX72xx_init();	

  while(1)
  {
      P15 = 1;
      clr_CPOL;
      set_CPHA;
      MAX6675_get_ADC(&ti);
      t = ((unsigned int)MAX6675_get_T(ti, tmp_K)); 
      delay_ms(100);
      
      P15 = 0;
      clr_CPOL;
      clr_CPHA;
      MAX72xx_write(DIG3, ((t / 1000) % 10));
      MAX72xx_write(DIG2, ((t / 100) % 10));
      MAX72xx_write(DIG1, ((t / 10) % 10));
      MAX72xx_write(DIG0, (t % 10));
      delay_ms(100);
  };
}

