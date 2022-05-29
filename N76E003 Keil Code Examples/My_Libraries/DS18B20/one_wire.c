#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "soft_delay.h"
#include "one_wire.h"
    

unsigned char onewire_reset(void)  
{                                         
	 unsigned char res = FALSE; 
	 
	 DS18B20_GPIO_init();
	
	 DS18B20_OUT_LOW();
	 delay_us(480);        
	 DS18B20_OUT_HIGH();
	 delay_us(60);        

	 res = DS18B20_IN();
	 delay_us(480);       
	 
	 return res; 
} 


void onewire_write_bit(unsigned char bit_value)
{
	DS18B20_OUT_LOW(); 
   	
	if(bit_value)
	{     	
		delay_us(104);
		DS18B20_OUT_HIGH();   
	}              
}     


unsigned char onewire_read_bit(void)        
{     
	DS18B20_OUT_LOW();  
	DS18B20_OUT_HIGH();  
  delay_us(15); 

	return(DS18B20_IN());    
}


void onewire_write(unsigned char value) 
{                    
	 unsigned char s = 0; 

	 while(s < 8)    
	 {                              
		  if((value & (1 << s)))
		  {
			  DS18B20_OUT_LOW(); 
				nop;
			  DS18B20_OUT_HIGH();  
			  delay_us(60);   
		  }       
		                      
		  else
		  {
		    DS18B20_OUT_LOW();           
			  delay_us(60);           
			  DS18B20_OUT_HIGH();   
			  nop;
		  }

		  s++;
	 }
}                                      


unsigned char onewire_read(void)
{
	 unsigned char s = 0x00;
	 unsigned char value = 0x00;
	
	 while(s < 8) 
	 {
		  DS18B20_OUT_LOW();
		  nop;
		  DS18B20_OUT_HIGH();  
		  
		  if(DS18B20_IN())  
		  {                                      
		      value |=  (1 << s);                         
		  }        
		   
		  delay_us(60);

		  s++;
	 }     
	 
	 return value;
}                       
