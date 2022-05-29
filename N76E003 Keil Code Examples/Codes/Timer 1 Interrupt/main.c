#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "LCD_3_Wire.h"


#define HIRC		0
#define LIRC	  1
#define ECLK		2


unsigned char toggle = 0;
unsigned int ms = 0;

unsigned char sec = 0;
unsigned char min = 0;
unsigned char hrs = 0;


void setup(void);
void set_clock_source(unsigned char clock_source);
void disable_clock_source(unsigned char clock_source);
void set_clock_division_factor(unsigned char value);
void set_Timer_1_for_Mode_0(unsigned int value);
unsigned int get_Timer_1_for_Mode_0(void);
void print_C(unsigned char x_pos, unsigned char y_pos, unsigned char value);
void print_I(unsigned char x_pos, unsigned char y_pos, unsigned int value);



void Timer1_ISR (void)     
interrupt 3	
{
	set_Timer_1_for_Mode_0(0x1D64);

	ms++;
	
	if(ms == 499)
	{
		toggle = ~toggle;
	}
	
	if(ms > 999)
	{
		ms = 0;
		sec++;
		
		if(sec > 59)
		{
			sec = 0;
			min++;
			
			if(min > 59)
			{
				min = 0;
				hrs++;
				
				if(hrs > 23)
				{
					hrs = 0;
				}
			}
		}
	}
}


void main(void)
{
  static char txt[] = {"Nu Stopwatch"};
  
  setup();
  
  LCD_goto(2, 0);
  LCD_putstr(txt);

  while(1)
  {    
		if(P05 == 1)
		{
			set_ET1;                     
			set_EA;                        
			set_TR1;                     
			set_Timer_1_for_Mode_0(0x1D64);
		}
		
		if(P06 == 1)
		{
			clr_ET1;                     
			clr_EA;                       
			clr_TR1;                    
			toggle = 0;
		}
		
		if((P05 == 1) && (P06 == 1))
		{
			clr_ET1;                      
			clr_EA;                       
			clr_TR1;                    
			
			ms = 0;
			sec = 0;
			min = 0;
			hrs = 0;
			
			toggle = 0;  
			set_Timer_1_for_Mode_0(0x1D64);
		}
		

		print_C(2, 1, hrs);
		print_C(5, 1, min);
		print_C(8, 1, sec);
		print_I(11, 2, ms);
		
		if(!toggle)
		{
			 LCD_goto(4, 1);
			 LCD_putchar(':');
			 LCD_goto(7, 1);
			 LCD_putchar(':');
			 LCD_goto(10, 1);
			 LCD_putchar(':');
		}
		else
		{
			 LCD_goto(4, 1);
			 LCD_putchar(' ');
			 LCD_goto(7, 1);
			 LCD_putchar(' ');
			 LCD_goto(10, 1);
			 LCD_putchar(' ');
		}
  };
}


void setup(void)
{	
  disable_clock_source(ECLK);    // Disable external clock source
  set_clock_source(HIRC);        // Set HIRC as clock system source
  set_clock_division_factor(1);  // Scale down system clock frequency to 8 MHz
  
  P05_Input_Mode;
  P06_Input_Mode;
  
  clr_T1M;                       // Timer 1 clock = System clock / 12
  TIMER1_MODE0_ENABLE;           // Set Timer 1 as a 13 bit timer-counter
  set_Timer_1_for_Mode_0(0x1D64);
  
  LCD_init();
  LCD_clear_home();
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


void set_Timer_1_for_Mode_0(unsigned int value)
{
  TL1 = (value & 0x1F);
  TH1 = ((value & 0xFFE0) >> 5);
}


unsigned int get_Timer_1_for_Mode_0(void)
{
  unsigned char hb = 0x00;
  unsigned char lb = 0x00;
  unsigned int value = 0x0000;
  
  
  value = TH1;
  value <<= 8;
  value |= TL1;
  
  lb = (value & 0x001F);
  hb = ((value & 0xFFE0) >> 5);
  
  value = hb;
  value <<= 8;
  value |= lb;  

  return value; 
}


void print_C(unsigned char x_pos, unsigned char y_pos, unsigned char value)
{
	LCD_goto(x_pos, y_pos);
	LCD_putchar((value / 10) + 0x30);
	LCD_goto((x_pos + 1), y_pos);
	LCD_putchar((value % 10) + 0x30);
}


void print_I(unsigned char x_pos, unsigned char y_pos, unsigned int value)
{
	LCD_goto(x_pos, y_pos);
	LCD_putchar((value / 100) + 0x30);
	LCD_goto((x_pos + 1), y_pos);
	LCD_putchar(((value % 100) / 10) + 0x30);
	LCD_goto((x_pos + 2), y_pos);
	LCD_putchar((value % 10) + 0x30);
}