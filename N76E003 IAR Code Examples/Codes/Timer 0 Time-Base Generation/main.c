#include "N76E003_iar.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"


#define HIRC		0
#define LIRC	        1
#define ECLK		2


void setup(void);
void set_clock_source(unsigned char clock_source);
void disable_clock_source(unsigned char clock_source);
void set_clock_division_factor(unsigned char value);
void set_Timer_0(unsigned int value);
unsigned int get_Timer_0(void);


void main(void)
{
  setup();

  while(1)
  {    
    if(get_Timer_0() < 32767)
    {
      P15 = 1;
    }
    else
    {
      P15 = 0;
    }
  };
}


void setup(void)
{	
  disable_clock_source(ECLK);    // Disable external clock source
  set_clock_source(HIRC);        // Set HIRC as clock system source
  set_clock_division_factor(80); // Scale down system clock frequency to 100 kHz
  
  P15_PushPull_Mode;             // Declare P15 as an output
  
  set_T0M;                       // Timer 0 clock = System clock
  TIMER0_MODE1_ENABLE;           // Set Timer 0 as a 16 bit timer-counter
  set_Timer_0(0);                // Set timer counter to 0
  set_TR0;                       // Start Timer 0;
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


void set_Timer_0(unsigned int value)
{
  TH0 = ((value && 0xFF00) >> 8);
  TL0 = (value & 0x00FF);
}


unsigned int get_Timer_0(void)
{
  unsigned int value = 0x0000;
  
  value = TH0;
  value <<= 8;
  value |= TL0;

  return value; 
}