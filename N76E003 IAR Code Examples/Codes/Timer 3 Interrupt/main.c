#include "N76E003_iar.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"


#define HIRC		            0
#define LIRC	                    1
#define ECLK		            2

#define GATE_HIGH                   set_P15
#define GATE_LOW                    clr_P15

#define CLK_HIGH                    set_P16
#define CLK_LOW                     clr_P16

#define A_HIGH                      set_P00
#define A_LOW                       clr_P00

#define B_HIGH                      set_P01
#define B_LOW                       clr_P01

#define C_HIGH                      set_P02
#define C_LOW                       clr_P02

#define D_HIGH                      set_P03
#define D_LOW                       clr_P03

#define SW                          P17

#define top_seg                     4
#define bot_seg                     0

#define HIGH                        1
#define LOW                         0


const unsigned char num[0x0A] = {0xED, 0x21, 0x8F, 0xAB, 0x63, 0xEA, 0xEE, 0xA1, 0xEF, 0xEB};
unsigned char data_values[0x09] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


unsigned char SW_in = 0;
unsigned char n = 0;


void setup(void);
void setup_GPIOs(void);
void setup_Timer_3(void);
void set_Timer_3(unsigned int value);
unsigned int get_Timer_3(void);
void write_74HC164(register unsigned char value);
void write_74HC145(register unsigned char channel);
void show_LEDs(unsigned char LED1_state, unsigned char LED2_state, unsigned char LED3_state, unsigned char LED4_state);
void show_numbers(signed int value, unsigned char pos);


#pragma vector = 0x83
__interrupt void Timer3_ISR(void)
{
  write_74HC164(data_values[n]);
  write_74HC145(n);

  n++;
  if(n > 9)
  {
    n = 0;
  }
  
  clr_TF3;
}


void main (void)
{
  
  unsigned int i = 0;
  unsigned int j = 9999;
     
  setup();
  
  while(1)
  {
    switch(SW_in)
    {
     case 1:
     {
         show_LEDs(1, 0, 0, 0);
         break;
     }
     case 2:
     {
         show_LEDs(0, 1, 0, 0);
         break;
     }
     case 3:
     {
         show_LEDs(0, 0, 1, 0);
         break;
     }
     case 4:
     {
         show_LEDs(0, 0, 0, 1);
         break;
     }
    }

    SW_in = 0x00;

    i++;
    j--;

    if(i > 9999)
    {
     i = 0;
     j = 9999;
    }

    show_numbers(i, bot_seg);
    show_numbers(j, top_seg);

    Timer1_Delay10ms(40);
    show_LEDs(0, 0, 0, 0);
  };
}


void setup(void)
{
  setup_GPIOs();
  setup_Timer_3();
}


void setup_GPIOs(void)
{
  P00_PushPull_Mode;
  P01_PushPull_Mode;
  P02_PushPull_Mode;
  P03_PushPull_Mode;
  P15_PushPull_Mode;
  P16_PushPull_Mode;
  P17_Input_Mode;
}


void setup_Timer_3(void)
{ 
  set_Timer_3(0xF9C0);
  set_ET3;                                  
  set_EA;                                    
  set_TR3;    
}


void set_Timer_3(unsigned int value)
{
  RL3 = (value & 0x00FF);  
  RH3 = ((value && 0xFF00) >> 8);
}


unsigned int get_Timer_3(void)
{
  unsigned int value = 0x0000;
  
  value = RH3;
  value <<= 8;
  value |= RL3;

  return value;   
}


void write_74HC164(register unsigned char value)
{
  register unsigned char s = 0x08;

  while(s > 0)
  {
    if((value & 0x80) != 0x00)
    {
        GATE_HIGH;
    }
    else
    {
        GATE_LOW;
    }

    CLK_HIGH;
    CLK_LOW;

    value <<= 1;
    s--;
  };
}


void write_74HC145(register unsigned char channel)
{
  P0 = 0x00;    
   
  switch(channel)
  {
    case 0:
    {
      asm("nop");
    
      if(SW == LOW)
      {
          SW_in = 1;
      }
      break;
  }

    case 1:
    {
      P0 = 0x01;
      break;
    }

    case 2:
    {
      P0 = 0x02;
      break;
    }

    case 3:
    {
      P0 = 0x03;
      break;
    }

    case 4:
    {
      P0 = 0x04;
      break;
    }

    case 5:
    {
      P0 = 0x05;
      break;
    }

    case 6:
    {
      P0 = 0x06;
      break;
    }

    case 7:
    {
      P0 = 0x07;
      asm("nop");
      
      if(SW == LOW)
      {
          SW_in = 2;
      }
      break;
    }

    case 8:
    {
      P0 = 0x08;
      asm("nop");
      
      if(SW == LOW)
      {
          SW_in = 3;
      }
      break;
    }

    case 9:
    {
      P0 = 0x09;
      asm("nop");
      
      if(SW == LOW)
      {
          SW_in = 4;
      }
      break;
    }
  }
}


void show_LEDs(unsigned char LED1_state, unsigned char LED2_state, unsigned char LED3_state, unsigned char LED4_state)
{
  switch(LED1_state)
  {
    case HIGH:
    {
       data_values[8] |= 0x80;
       break;
    }
    case LOW:
    {
       data_values[8] &= 0x7F;
       break;
    }
  }

  switch(LED2_state)
  {
    case HIGH:
    {
       data_values[8] |= 0x40;
       break;
    }
    case LOW:
    {
       data_values[8] &= 0xBF;
       break;
    }
  }

  switch(LED3_state)
  {
    case HIGH:
    {
       data_values[8] |= 0x08;
       break;
    }
    case LOW:
    {
       data_values[8] &= 0xF7;
       break;
    }
  }

  switch(LED4_state)
  {
    case HIGH:
    {
       data_values[8] |= 0x02;
       break;
    }
    case LOW:
    {
       data_values[8] &= 0xFD;
       break;
    }
  }
}


void show_numbers(signed int value, unsigned char pos)
{
  register unsigned char ch = 0x00;

  if((value >= 0) && (value <= 9))
  {
    ch = (value % 10);
    data_values[(0 + pos)] = num[ch];
    data_values[(1 + pos)] = 0x00;
    data_values[(2 + pos)] = 0x00;
    data_values[(3 + pos)] = 0x00;
  }
  else if((value > 9) && (value <= 99))
  {
    ch = (value % 10);
    data_values[(0 + pos)] = num[ch];
    ch = ((value / 10) % 10);
    data_values[(1 + pos)] = num[ch];
    data_values[(2 + pos)] = 0x00;
    data_values[(3 + pos)] = 0x00;
  }
  else if((value > 99) && (value <= 999))
  {
    ch = (value % 10);
    data_values[(0 + pos)] = num[ch];
    ch = ((value / 10) % 10);
    data_values[(1 + pos)] = num[ch];
    ch = ((value / 100) % 10);
    data_values[(2 + pos)] = num[ch];
    data_values[(3 + pos)] = 0x00;
  }
  else if((value > 999) && (value <= 9999))
  {
    ch = (value % 10);
    data_values[(0 + pos)] = num[ch];
    ch = ((value / 10) % 10);
    data_values[(1 + pos)] = num[ch];
    ch = ((value / 100) % 10);
    data_values[(2 + pos)] = num[ch];
    ch = (value / 1000);
    data_values[(3 + pos)] = num[ch];
  }
}