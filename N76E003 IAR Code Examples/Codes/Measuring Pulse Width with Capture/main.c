#include "N76E003_iar.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "LCD_3_Wire.h"


#define HIRC		0
#define LIRC	         1
#define ECLK		2


unsigned int pulse_width = 0;


void setup(void);
void set_clock_source(unsigned char clock_source);
void disable_clock_source(unsigned char clock_source);
void set_system_clock_frequency(unsigned long F_osc, unsigned long F_sys);
void setup_GPIOs(void);
void setup_Timer_2(void);
void setup_capture(void);
void set_Timer_2(unsigned int value);
void set_Timer_2_reload_compare(unsigned int value);
void lcd_print(unsigned char x_pos, unsigned char y_pos, unsigned int value);


#pragma vector = 0x63
__interrupt void Input_Capture_ISR(void)     
{
  if(CAPCON0 & 0x01)
  {
    clr_CAPF0;    
  }
  
  if(CAPCON0 & 0x02)
  {
    clr_CAPF1;                    
    
    pulse_width = C1H; 
    pulse_width <<= 8;
    pulse_width |= C1L;
  }

}


void main(void)
{
  unsigned int range = 0;
  
  LCD_init();
  LCD_clear_home(); 
  LCD_goto(0, 0); 
  LCD_putstr("Pamge/cm:");
  LCD_goto(0, 1); 
  LCD_putstr("Pulse/us:");
  
  setup();

  while(1)
  { 
    set_P11;
    Timer3_Delay10us(1);
    clr_P11;
    
    range = ((unsigned int)(((float)pulse_width) / 58.0));
    
    lcd_print(11, 0, range);
    lcd_print(11, 1, pulse_width);
    Timer0_Delay1ms(900);
  };
}


void setup(void)
{
  disable_clock_source(ECLK);    
  set_clock_source(HIRC);       
  set_system_clock_frequency(16, 16);
  setup_GPIOs();
  setup_capture();
  setup_Timer_2();
  set_EA;                        
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


void set_system_clock_frequency(unsigned long F_osc, unsigned long F_sys)
{
  F_osc = (F_osc / (0x02 * F_sys));

  if((F_osc >= 0x00) && (F_osc <= 0xFF))
  {
    CKDIV = ((unsigned char)F_osc); 
  }
}


void setup_GPIOs(void)
{
  P11_PushPull_Mode;
  P12_Input_Mode;
}


void setup_Timer_2(void)
{
  set_Timer_2_reload_compare(0);
  set_Timer_2(0);  
  set_LDEN;
  T2MOD |= 0x01;  
  T2MOD |= 0x20;
  set_TR2;                  
}


void setup_capture(void)
{
  CAPCON0 = 0x30;
  CAPCON1 = 0x01;
  CAPCON2 = 0x30;
  CAPCON3 = 0x00;
  CAPCON4 = 0x00;
  set_ECAP;             
}


void set_Timer_2(unsigned int value)
{
  TL2 = (value & 0x00FF);
  TH2 = ((value & 0xFF00) >> 0x08);
}


void set_Timer_2_reload_compare(unsigned int value)
{
  RCMP2L = (value & 0x00FF);
  RCMP2H = ((value & 0xFF00) >> 0x08);
}


void lcd_print(unsigned char x_pos, unsigned char y_pos, unsigned int value)
{  
  LCD_goto(x_pos, y_pos);
  LCD_putchar((value / 10000) + 0x30);
  LCD_goto((x_pos + 1), y_pos);
  LCD_putchar(((value % 10000) / 1000) + 0x30);  
  LCD_goto((x_pos + 2), y_pos);
  LCD_putchar(((value % 1000) / 100) + 0x30);
  LCD_goto((x_pos + 3), y_pos);
  LCD_putchar(((value % 100) / 10) + 0x30);
  LCD_goto((x_pos + 4), y_pos);
  LCD_putchar((value % 10) + 0x30);
}