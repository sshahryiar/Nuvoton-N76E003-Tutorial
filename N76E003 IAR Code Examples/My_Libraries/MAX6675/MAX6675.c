#include "N76E003_IAR.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "MAX6675.h"


void MAX6675_SPI_HW_Init(unsigned char clk_value)
{
  switch(clk_value)
	{
		case 1:
		{
			clr_SPR1;
      set_SPR0;
			break;
		}
		case 2:
		{
			set_SPR1;
      clr_SPR0;
			break;
		}
		case 3:
		{
			set_SPR1;
      set_SPR0;
			break;
		}
		default:
		{
			clr_SPR1;
      clr_SPR0;
			break;
		}
	}		
	
	set_DISMODF;
	set_MSTR;
	clr_CPOL;
	set_CPHA;
	set_SPIEN;
}


void MAX6675_init(void)
{
	MAX6675_SPI_GPIO_init();
	MAX6675_SPI_HW_Init(0);
}


unsigned char MAX6675_get_ADC(unsigned int *ADC_data)
{
	unsigned char lb = 0;
	unsigned char hb = 0;
	unsigned char samples = no_of_samples;
	unsigned int temp_data = 0;
	unsigned long avg_value = 0;


	while(samples > 0)
	{
		 MAX6675_CS_OUT_LOW();
			
		 SPDR = 0x00;
		 while(!(SPSR & SET_BIT7));  
		 hb = SPDR;
		 clr_SPIF;  

		 SPDR = 0x00;
		 while(!(SPSR & SET_BIT7));          
		 lb = SPDR;
		 clr_SPIF;    

		 MAX6675_CS_OUT_HIGH();
		 
		 temp_data = hb;
		 temp_data <<= 8;
		 temp_data |= lb;
		 temp_data &= 0x7FFF;
		 
		 avg_value += (unsigned long)temp_data;
		 
		 samples--;
		 Timer0_Delay1ms(10);
	};

	temp_data = (avg_value >> 4);

	if((temp_data & 0x04) == close_contact)
	{
		*ADC_data = (temp_data >> 3);
		return close_contact;
	}
	else
	{
		*ADC_data = (count_max + 1);
		return open_contact;
	}
}


float MAX6675_get_T(unsigned int ADC_value, unsigned char T_unit)
{
	float tmp = 0.0;

	tmp = (((float)ADC_value) * scalar_deg_C);

	switch(T_unit)
	{
		case deg_F:
		{
			 tmp *= scalar_deg_F_1;
			 tmp += scalar_deg_F_2;
			 break;
		}
		case tmp_K:
		{
			tmp += scalar_tmp_K;
			break;
		}
		default:
		{
			break;
		}
	}

	return tmp;
}
