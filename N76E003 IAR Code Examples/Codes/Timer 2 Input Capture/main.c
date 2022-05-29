#include "N76E003_iar.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "LCD_3_Wire.h"


#define HIRC		0
#define LIRC	         1
#define ECLK		2

#define timer_clock_speed  8000000.0


unsigned long overflow = 0;
unsigned long pulse_time = 0; 
unsigned long start_time = 0; 
unsigned long end_time = 0;


void setup(void);
void set_clock_source(unsigned char clock_source);
void disable_clock_source(unsigned char clock_source);
void set_clock_division_factor(unsigned char value);
void setup_GPIOs(void);
void setup_Timer_1(void);
void setup_Timer_2(void);
void setup_capture(void);
void set_Timer_1(unsigned int value);
void lcd_print(unsigned char x_pos, unsigned char y_pos, unsigned long value);


#pragma vector = 0x1B
__interrupt void Timer_1_ISR(void)     
{  
  set_Timer_1(0);
}


#pragma vector = 0x2B
__interrupt void Timer_2_ISR(void)     
{  
  clr_TF2;
  overflow++;
}


#pragma vector = 0x63
__interrupt void Input_Capture_ISR(void)     
{
  if((CAPCON0 & SET_BIT0) != 0)
  {
    clr_CAPF0;    
    end_time = C0H; 
    end_time <<= 8;
    end_time |= C0L;
    pulse_time = ((overflow << 16) - start_time + end_time);
    start_time = end_time; 
    overflow = 0;
  }
}


void main(void)
{
  register float f = 0.0;
  
  setup();
  
  LCD_init();
  LCD_clear_home(); 
  LCD_goto(1, 0); 
  LCD_putstr("Nu Freq. Meter");
  LCD_goto(0, 1); 
  LCD_putstr("Freq./Hz:");

  while(1)
  {
    f = (timer_clock_speed / ((float)pulse_time));
    lcd_print(11, 1, ((unsigned long)f));
    Timer0_Delay1ms(100);
  };
}


void setup(void)
{
  disable_clock_source(ECLK);    // Disable external clock source
  set_clock_source(HIRC);        // Set HIRC as clock system source
  set_clock_division_factor(1);  // Scale down system clock frequency to 8 MHz
  setup_GPIOs();
  setup_capture();
  setup_Timer_1();
  setup_Timer_2();
  set_EA;                        // Enable global interrupt
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


void setup_GPIOs(void)
{
  P00_PushPull_Mode;
  P12_Input_Mode;
}


void setup_Timer_1(void)
{
  set_T1M;                       // Timer 1 clock = System clock
  TIMER1_MODE1_ENABLE;           // Set Timer 1 as a 16 bit timer-counter
  set_Timer_1(0);                // Set Timer 1 counter to 0
  P2S |= SET_BIT3;               // Enable Timer 1 output
  set_TR1;                       // Start Timer 1;
  set_ET1;                       // Enable Timer 1 interrupt
}


void setup_Timer_2(void)
{
  T2CON &= ~SET_BIT0;            // Auto-reload mode
  T2MOD = 0x00;                  // No clock division and continue counting
  set_TR2;                       // Start Timer 2;
  set_ET2;                       // Enable Timer 2 interrupt
}


void setup_capture(void)
{
  IC0_P12_CAP0_FallingEdge_Capture;
  set_ECAP;                      // Enable capture interrupt
}

  
void set_Timer_1(unsigned int value)
{
  TH1 = ((value && 0xFF00) >> 8);
  TL1 = (value & 0x00FF);
}


void lcd_print(unsigned char x_pos, unsigned char y_pos, unsigned long value)
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