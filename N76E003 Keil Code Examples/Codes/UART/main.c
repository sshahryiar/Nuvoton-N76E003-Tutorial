#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "soft_delay.h"
#include "LCD_2_Wire.h"
#include "HMC1022.h"


const unsigned char symbol[8] = 
{
   0x00, 0x06, 0x09, 0x09, 0x06, 0x00, 0x00, 0x00
};


extern unsigned char done;
extern unsigned char data_bytes[no_of_data_bytes_returned];


void setup(void);
void lcd_symbol(void);


void main(void)
{
  setup();
  
  while(1)
  {
    read_heading(); 
    
    if(done)
     {
			 LCD_goto(6, 1); 
			 LCD_putchar(data_bytes[2]);
			 
			 LCD_goto(7, 1); 
			 LCD_putchar(data_bytes[3]);
			 
			 LCD_goto(8, 1); 
			 LCD_putchar(data_bytes[4]);
			 
			 LCD_goto(9, 1); 
			 LCD_putchar('.');
			 LCD_goto(10, 1); 
			 LCD_putchar(data_bytes[6]);
			 
			 done = 0;
     }
     
     P15 = ~P15;
     delay_ms(200);
  };
}


void setup(void)
{ 
  P15_PushPull_Mode;
  
  LCD_init();
  LCD_clear_home(); 
  lcd_symbol();
  LCD_goto(3, 0); 
  LCD_putstr("Heading  N");
  LCD_goto(11, 0); 
  LCD_send(0, DAT);
  
  InitialUART1_Timer3(9600);
}


void lcd_symbol(void)  
{
  unsigned char s = 0;  

  LCD_send(0x40, CMD);

  for(s = 0; s < 8; s++)
  {
   LCD_send(symbol[s], DAT);
  }

  LCD_send(0x80, CMD);
} 