#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"


#define HIRC		0
#define LIRC	        1
#define ECLK		2


void set_clock_source(unsigned char clock_source);
void disable_clock_source(unsigned char clock_source);
void set_clock_division_factor(unsigned char value);


void main(void)
{
  signed char i = 30;			

  P11_PushPull_Mode;  
  P15_PushPull_Mode;

  set_clock_division_factor(0);
  set_clock_source(HIRC);

  set_CLOEN;

  while(i > 0)																	
  {   
    clr_P15;														
    Timer0_Delay1ms(100);
    set_P15;
    Timer0_Delay1ms(100);
    i--;
  }
  
  set_clock_source(ECLK);
  disable_clock_source(HIRC);
  
  i = 30;
  
  while(i > 0)																	
  {   
    clr_P15;														
    Timer0_Delay1ms(100);
    set_P15;
    Timer0_Delay1ms(100);
    i--;
  }

  set_clock_source(LIRC);
  disable_clock_source(HIRC);

  while(1)
  {
    clr_P15;														
    Timer0_Delay1ms(1);
    set_P15;
    Timer0_Delay1ms(1);
  };
}


void set_clock_source(unsigned char clock_source)
{
  switch(clock_source)
  {
    case LIRC:
    {
      set_OSC1;											
      clr_OSC0;  
      
      break;
    }
    
    case ECLK:
    {
      set_EXTEN1;
      set_EXTEN0;
      
      while((CKSWT & SET_BIT3) == 0);	
      
      clr_OSC1;											
      set_OSC0; 
      
      break;
    }
    
    default:
    {
      set_HIRCEN;					
      
      while((CKSWT & SET_BIT5) == 0);		
      
      clr_OSC1;												
      clr_OSC0;
      
      break;
    }
  }

  while((CKEN & SET_BIT0) == 1);	
}


void disable_clock_source(unsigned char clock_source)
{
  switch(clock_source)
  {
    case HIRC:
    {
      clr_HIRCEN;
      break;
    }
    
    default:
    {
      clr_EXTEN1;
      clr_EXTEN0;
      break;
    }
  }
}


void set_clock_division_factor(unsigned char value)
{
  CKDIV = value;
}