#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "MAX72xx.h"


void MAX72xx_SPI_HW_Init(unsigned char clk_value)
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
	clr_CPHA;
	set_SPIEN;
}


void MAX72xx_init(void)
{
	MAX72xx_SPI_GPIO_init();
	MAX72xx_SPI_HW_Init(0);

	MAX72xx_write(shutdown_reg, run_cmd);
	MAX72xx_write(decode_mode_reg, Code_B_decode_digit_0_to_3);
	MAX72xx_write(scan_limit_reg, digit_0_to_3);
	MAX72xx_write(intensity_reg, 0x19);
}


void MAX72xx_write(unsigned char address, unsigned char value)
{
	MAX72xx_CS_OUT_LOW();	

	SPDR = address;
	while(!(SPSR & SET_BIT7));  
	clr_SPIF;

	SPDR = value;
	while(!(SPSR & SET_BIT7));  
	clr_SPIF;

	MAX72xx_CS_OUT_HIGH();
}