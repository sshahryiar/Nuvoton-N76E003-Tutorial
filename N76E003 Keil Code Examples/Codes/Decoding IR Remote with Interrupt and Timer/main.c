#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "soft_delay.h"
#include "LCD_2_Wire.h"


#define sync_high          22000
#define sync_low           14000
#define one_high            3600
#define one_low             2400
#define zero_high           1800
#define zero_low            1200


bit received;
unsigned char bits = 0;
unsigned int frames[33];


void setup(void);
void set_Timer_0(unsigned int value);
unsigned int get_Timer_0(void);
void erase_frames(void);
unsigned char decode(unsigned char start_pos, unsigned char end_pos);
void decode_NEC(unsigned char *addr, unsigned char *cmd);
void lcd_print(unsigned char x_pos, unsigned char y_pos, unsigned char value);


void EXTI0_ISR(void)
interrupt 0
{
	frames[bits] = get_Timer_0();
	bits++;
	set_TR0;
	
	if(bits >= 33)
	{
		 received = 1;
		 clr_EA;
		 clr_TR0;
	}
	set_Timer_0(0x0000);
	P15 = ~P15;
}


void main(void)
{
  unsigned char address = 0x00;
  unsigned char command = 0x00;
	
	setup();

  while(1)
  {    
     if(received)
		 {
		   decode_NEC(&address, &command);
			 lcd_print(13, 0, address);	
			 lcd_print(13, 1, command);
			 delay_ms(100);
			 erase_frames();
			 set_EA;
		 }
  };
}


void setup(void)
{	
	erase_frames();
  P15_PushPull_Mode;	
  TIMER0_MODE1_ENABLE;           
  set_Timer_0(0x0000); 
	set_IT0;
	set_EX0;	
	set_EA;
	
	LCD_init();
  LCD_clear_home(); 
  LCD_goto(0, 0); 
  LCD_putstr("Address:");
	LCD_goto(0, 1); 
  LCD_putstr("Command:");
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


void erase_frames(void)
{
	for(bits = 0; bits < 33; bits++)
	{
		frames[bits] = 0x0000;
	}

	set_Timer_0(0x0000); 
	received = 0;
	bits = 0;
}


unsigned char decode(unsigned char start_pos, unsigned char end_pos)
{
	unsigned char value = 0;

	for(bits = start_pos; bits <= end_pos; bits++)
	{
		value <<= 1;
		
		if((frames[bits] >= one_low) && (frames[bits] <= one_high))
		{
			value |= 1;
		}
		
		else if((frames[bits] >= zero_low) && (frames[bits] <= zero_high))
		{
			value |= 0;
		}
		
		else if((frames[bits] >= sync_low) && (frames[bits] <= sync_high))
		{
			return 0xFF;
		}
	}

	return value;
}


void decode_NEC(unsigned char *addr, unsigned char *cmd)
{
	*addr = decode(2, 9);
	*cmd = decode(18, 25);
}


void lcd_print(unsigned char x_pos, unsigned char y_pos, unsigned char value)
{  
  LCD_goto(x_pos, y_pos);
  LCD_putchar((value / 100) + 0x30);
  LCD_goto((x_pos + 1), y_pos);
  LCD_putchar(((value % 10) / 10) + 0x30);
  LCD_goto((x_pos + 2), y_pos);
  LCD_putchar((value % 10) + 0x30);
}