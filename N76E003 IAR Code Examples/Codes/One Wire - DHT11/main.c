#include "N76E003_IAR.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "soft_delay.h"
#include "LCD_2_Wire.h"
#include "DHT11.h"


extern unsigned char values[5]; 


const unsigned char symbol[8] = 
{
   0x00, 0x06, 0x09, 0x09, 0x06, 0x00, 0x00, 0x00
};


void setup(void);
void lcd_symbol(void);
void lcd_print(unsigned char x_pos, unsigned char y_pos, unsigned char value);


void main(void)
{
  unsigned char state = 0;
  
  setup();
  
  while(1)
  {
    state = get_data();
      
    switch(state)
    {
        case 1:
        {
        }
        case 2:
        {
           LCD_clear_home(); 
           LCD_putstr("No Sensor Found!");
           break;
        }
        case 3:
        {
           LCD_clear_home(); 
           LCD_putstr("Checksum Error!");
           break;
        }
        default:
        {
           LCD_goto(0, 0); 
           LCD_putstr("R.H/ %:       ");
           
           lcd_print(14, 0, values[0]);
           
           LCD_goto(0, 1); 
           LCD_putstr("Tmp/");
           LCD_goto(4, 1); 
           LCD_send(0, DAT);
           LCD_goto(5, 1); 
           LCD_putstr("C:");
                                     
           if((values[2] & 0x80) == 1)
           {
             LCD_goto(13, 1); 
             LCD_putstr("-");
           }
           else
           {
             LCD_goto(13, 1); 
             LCD_putstr(" ");
           }
                 
           lcd_print(14, 1, values[2]); 
           break;
        }
    }
    
    delay_ms(1000);
  };
}


void setup(void)
{ 
  DHT11_init();
	
  LCD_init();  
  LCD_clear_home(); 
  lcd_symbol();
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


void lcd_print(unsigned char x_pos, unsigned char y_pos, unsigned char value)
{
 unsigned char chr = 0x00;
 
 chr = ((value / 10) + 0x30);
 LCD_goto(x_pos, y_pos);
 LCD_putchar(chr); 
 
 chr = ((value % 10) + 0x30);
 LCD_goto((x_pos + 1), y_pos);
 LCD_putchar(chr); 
}

