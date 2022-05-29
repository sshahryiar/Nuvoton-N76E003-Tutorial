#include "N76E003_iar.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "soft_delay.h"
#include "DHT11.h"


unsigned char values[5]; 


void DHT11_init()
{
   DHT11_pin_init();
   delay_ms(1000);
}


unsigned char get_byte()
{
   unsigned char s = 0;
   unsigned char value = 0;
   for(s = 0; s < 8; s += 1) 
   {
      value <<= 1;
      while(DHT11_pin_IN() == LOW);
      delay_us(30);
      if(DHT11_pin_IN() == HIGH)
      {
          value |= 1;
      }
      while(DHT11_pin_IN() == HIGH);
   }
   return value;
}


unsigned char get_data()
{
   short chk = 0;
   unsigned char s = 0;
   unsigned char check_sum = 0;

   DHT11_pin_HIGH();
   DHT11_pin_LOW();
   delay_ms(18);
   DHT11_pin_HIGH();
   delay_us(26);
   
   chk = DHT11_pin_IN();
   
   if(chk)
   {
      return 1;
   }
   delay_us(80);
   
   chk = DHT11_pin_IN();

   if(!chk)
   {
      return 2;
   }
   delay_us(80);

   for(s = 0; s <= 4; s += 1)
   {
       values[s] = get_byte();
   }
  
   DHT11_pin_HIGH(); 
   
   for(s = 0; s < 4; s += 1)
   {
       check_sum += values[s];
   }
   
   if(check_sum != values[4])
   {
      return 3;
   }
   else
   {
      return 0;
   }
}
