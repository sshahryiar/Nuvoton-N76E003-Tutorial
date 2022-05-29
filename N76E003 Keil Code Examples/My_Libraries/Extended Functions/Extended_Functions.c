#include "N76E003.h"
#include "Common.h"
#include "Delay.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Extended_Functions.h"


static unsigned char EA_Save_bit;


void delay_us(unsigned int value)
{
  value = (value / osc_scalar);
  
  while(value > 0x00)
  {
    asm("nop");
    value--;
  }
}


void delay_ms(unsigned int value)
{ 
  while(value > 0x00)
  {
    --value;
    delay_us(1000);
  }
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
      
      while((CKSWT & SET_BIT3) == FALSE); 
      
      clr_OSC1;                     
      set_OSC0; 
      
      break;
    }
    
    default:
    {
      set_HIRCEN;         
      
      while((CKSWT & SET_BIT5) == FALSE);   
      
      clr_OSC1;                       
      clr_OSC0;
      
      break;
    }
  }

  while((CKEN & SET_BIT0) == TRUE);  
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
    
    case ECLK:
    {
        clr_EXTEN1;
        clr_EXTEN0;
        break;
    }

    default:
    {
        break;
    }
  }
}


void set_clock_division_factor(unsigned char value)
{
  CKDIV = value;
}


void set_system_clock_frequency(unsigned long F_osc, unsigned long F_sys)
{
  F_osc = (F_osc / (0x02 * F_sys));

  if((F_osc >= 0x00) && (F_osc <= 0xFF))
  {
    CKDIV = ((unsigned char)F_osc); 
  }
}


void setup_clock(unsigned long F_osc, unsigned long F_sys, unsigned char clock_source, unsigned char clock_source_to_disable)
{
  set_clock_source(clock_source);	
  disable_clock_source(clock_source_to_disable);
  set_clock_frequency(F_osc, F_sys);
}


void set_Timer_0_for_Mode_0(unsigned int value)
{
  TL0 = (value & 0x1F);
  TH0 = ((value & 0xFFE0) >> 0x05);
}


unsigned int get_Timer_0_for_Mode_0(void)
{
  unsigned char hb = 0x00;
  unsigned char lb = 0x00;
  register unsigned int value = 0x0000;
  
  
  value = TH0;
  value <<= 0x08;
  value |= TL0;
  
  lb = (value & 0x001F);
  hb = ((value & 0xFFE0) >> 0x05);
  
  value = hb;
  value <<= 0x08;
  value |= lb;  

  return value; 
}


void set_Timer_0_for_Mode_1(unsigned int value)
{
  TL0 = (value & 0x00FF);
  TH0 = ((value & 0xFF00) >> 0x08);
}


unsigned int get_Timer_0_for_Mode_1(void)
{
  register unsigned int value = 0x0000;
  
  value = TH0;
  value <<= 0x08;
  value |= TL0;

  return value; 
}


void set_Timer_1_for_Mode_0(unsigned int value)
{
  TL1 = (value & 0x1F);
  TH1 = ((value & 0xFFE0) >> 0x05);
}


unsigned int get_Timer_1_for_Mode_0(void)
{
  unsigned char hb = 0x00;
  unsigned char lb = 0x00;
  register unsigned int value = 0x0000;
  
  
  value = TH1;
  value <<= 0x08;
  value |= TL1;
  
  lb = (value & 0x001F);
  hb = ((value & 0xFFE0) >> 0x05);
  
  value = hb;
  value <<= 0x08;
  value |= lb;  

  return value; 
}


void set_Timer_1_for_Mode_1(unsigned int value)
{
  TL1 = (value & 0x00FF);
  TH1 = ((value & 0xFF00) >> 0x08);
}


unsigned int get_Timer_1_for_Mode_1(void)
{
  register unsigned int value = 0x0000;
  
  value = TH1;
  value <<= 0x08;
  value |= TL1;

  return value; 
}


void set_Timer_2(unsigned int value)
{
  TL2 = (value & 0x00FF);
  TH2 = ((value & 0xFF00) >> 0x08);
}


unsigned int get_Timer_2(void)
{
  register unsigned int value = 0x0000;
  
  value = TH2;
  value <<= 0x08;
  value |= TL2;

  return value; 
}


void set_Timer_2_reload_compare(unsigned int value)
{
  RCMP2L = (value & 0x00FF);
  RCMP2H = ((value & 0xFF00) >> 0x08);
}


unsigned int get_Timer_2_reload_compare(void)
{
  register unsigned int value = 0x0000;
  
  value = RCMP2H;
  value <<= 0x08;
  value |= RCMP2L;

  return value; 
}


void set_Timer_3(unsigned int value)
{
  RL3 = (value & 0x00FF);
  RH3 = ((value & 0xFF00) >> 0x08);
}


unsigned int get_Timer_3(void)
{
  register unsigned int value = 0x0000;
  
  value = RH3;
  value <<= 0x08;
  value |= RL3;

  return value; 
}


void set_capture_0(unsigned int value)
{
  C0L = (value & 0x00FF);
  C0H = ((value & 0xFF00) >> 0x08);
}


unsigned int get_capture_0(void)
{
  register unsigned int value = 0x0000;
  
  value = C0H;
  value <<= 0x08;
  value |= C0L;

  return value; 
}


void set_capture_1(unsigned int value)
{
  C1L = (value & 0x00FF);
  C1H = ((value & 0xFF00) >> 0x08);
}


unsigned int get_capture_1(void)
{
  register unsigned int value = 0x0000;
  
  value = C1H;
  value <<= 0x08;
  value |= C1L;

  return value; 
}


void set_capture_2(unsigned int value)
{
  C2L = (value & 0x00FF);
  C2H = ((value & 0xFF00) >> 0x08);
}


unsigned int get_capture_2(void)
{
  register unsigned int value = 0x0000;
  
  value = C2H;
  value <<= 0x08;
  value |= C2L;

  return value; 
}


void set_PWM_period_count(unsigned int value)
{
  PWMPL = (value & 0x00FF);
  PWMPH = ((value & 0xFF00) >> 0x08);  
}


void set_PWM0(unsigned int value)
{
  PWM0L = (value & 0x00FF);
  PWM0H = ((value & 0xFF00) >> 0x08);
  set_LOAD;
}


void set_PWM1(unsigned int value)
{
  PWM1L = (value & 0x00FF);
  PWM1H = ((value & 0xFF00) >> 0x08);
  set_LOAD;
}


void set_PWM2(unsigned int value)
{
  PWM2L = (value & 0x00FF);
  PWM2H = ((value & 0xFF00) >> 0x08);
  set_LOAD;
}


void set_PWM3(unsigned int value)
{
  PWM3L = (value & 0x00FF);
  PWM3H = ((value & 0xFF00) >> 0x08);
  set_LOAD;
}


void set_PWM4(unsigned int value)
{
  set_SFRPAGE;
  PWM4L = (value & 0x00FF);
  PWM4H = ((value & 0xFF00) >> 0x08);
  clr_SFRPAGE;
  set_LOAD;
}


void set_PWM5(unsigned int value)
{
  set_SFRPAGE;
  PWM5L = (value & 0x00FF);
  PWM5H = ((value & 0xFF00) >> 0x08);
  clr_SFRPAGE;
  set_LOAD;
}


void set_complementary_PWM_dead_time(unsigned int value)
{
  unsigned char hb = 0;
  unsigned char lb = 0;

  lb = (value & 0x00FF);
  hb = ((value & 0x0100) >> 8);
  BIT_TMP = EA;

  EA = 0;
  TA_protection_disable();
  PDTEN &= 0xEF;
  PDTEN |= hb;
  PDTCNT = lb;
  EA = BIT_TMP;	
}


void setup_WDT(unsigned char WDT_time)
{
  TA_protection_disable();
  WDCON |= WDT_time;						
  set_WDCLR;													
  while((WDCON | ~SET_BIT6) == 0xFF);			
  set_EA;
  set_WDTR;	
}


void setup_WKT(unsigned char status, unsigned char reload_value, unsigned char clk_prescalar)
{
	WKCON = ((status << 3) | (clk_prescalar & 0x07)
  RWK = reload_value;   	 
}


unsigned int ADC_read(void)
{
  register unsigned int value = 0x0000; 
  
  value = ADCRH;
  value <<= 0x04;
  value |= ADCRL;
  
  return value;
}


void set_ADC_comparator_value(unsigned int value)
{
  ADCMPL = (value & 0x000F);
  ADCMPH = ((value & 0x0FF0) >> 0x04);
}


void enable_IAP_mode(void)
{
    EA_Save_bit = EA;
    clr_EA;
    TA = 0xAA;
    TA = 0x55;
    CHPCON |= 0x01 ;
    TA = 0xAA;
    TA = 0x55;
    IAPUEN |= 0x01;
    EA = EA_Save_bit;
}


void disable_IAP_mode(void)
{
    EA_Save_bit = EA;
    clr_EA;
    TA = 0xAA;
    TA = 0x55;
    IAPUEN &= ~0x01;
    TA = 0xAA;
    TA = 0x55;
    CHPCON &=~ 0x01;
    EA = EA_Save_bit;
}


void trigger_IAP(void)
{
    EA_Save_bit = EA;
    clr_EA;
    TA = 0xAA;
    TA = 0x55;
    IAPTRG |= 0x01;
    EA = EA_Save_bit;
}

  
unsigned char write_data_to_one_page(unsigned int u16_addr, const unsigned char *pDat, unsigned char num)
{
    unsigned char i = 0;
    unsigned char offset = 0;
    unsigned char __code *pCode;
    unsigned char __xdata *xd_tmp;

    enable_IAP_mode(); 
    offset = (u16_addr & 0x007F);
    i = (PAGE_SIZE - offset);

    if(num > i)
    {
      num = i;
    }

    pCode = (unsigned char __code *)u16_addr;
    
    for(i = 0; i < num; i++)
    {
        if(pCode[i] != 0xFF)
        {
          break;
        }
    }

    if(i == num)
    {
        IAPCN = BYTE_PROGRAM_AP;
        IAPAL = u16_addr;
        IAPAH = u16_addr>>8;

        for(i = 0; i < num; i++)
        {
          IAPFD = pDat[i];
          trigger_IAP();
          IAPAL++;
        }

        for(i = 0; i < num; i++)
        {
          if(pCode[i] != pDat[i])
          {
                   break; 
          } 
        }

        if(i != num) 
        {
          goto WriteDataToPage20;
        }
    }

    else
    {
      WriteDataToPage20:
      pCode = (unsigned char __code *)(u16_addr & 0xff80);
      for(i = 0; i < 128; i++)
      {
           xd_tmp[i] = pCode[i];
      }

      for(i = 0; i < num; i++)
      {
           xd_tmp[offset + i] = pDat[i];
      }

      do
      {
           IAPAL = (u16_addr & 0xFF80);
           IAPAH = (u16_addr >> 8);
           IAPCN = PAGE_ERASE_AP;
           IAPFD = 0xFF;  
           trigger_IAP(); 
           IAPCN =BYTE_PROGRAM_AP;
           
           for(i = 0; i < 128; i++)
           {
                IAPFD = xd_tmp[i];
                trigger_IAP();
                IAPAL++;
           }

           for(i = 0; i < 128; i++)
           {
                if(pCode[i] != xd_tmp[i])
                {
                     break;
                }
           }
      }while(i != 128);
      
    }

    disable_IAP_mode();

    return num;
} 


void write_data_flash(unsigned int u16_addr, unsigned char *pDat,unsigned int num)
{
    unsigned int CPageAddr = 0;
    unsigned int EPageAddr = 0;
    unsigned int cnt = 0;

    CPageAddr = (u16_addr >> 7);
    EPageAddr = ((u16_addr + num) >> 7);

    while(CPageAddr != EPageAddr)
    {
      cnt = write_data_to_one_page(u16_addr, pDat, 128);
      u16_addr += cnt;
      pDat += cnt;
      num -= cnt;
      CPageAddr = (u16_addr >> 7);
    }

    if(num)
    {
      write_data_to_one_page(u16_addr, pDat,num);
    }
}


void read_data_flash(unsigned int u16_addr, unsigned char *pDat, unsigned int num)
{
    unsigned int i = 0;
    
    for(i = 0; i < num; i++)
    {
        pDat[i] = *(unsigned char __code *)(u16_addr+i);
    }
}



void I2C_init(void)
{
  I2C_GPIO_Init(regular_I2C_pins);
  I2CLK = I2C_CLOCK; 
  set_I2CEN; 
}


void I2C_start(void)
{
  signed int t = timeout_count;
  
  set_STA;                                
  clr_SI;
  while((SI == 0) && (t > 0))
  {
    t--;
  };     
}

void I2C_stop(void)
{
  signed int t = timeout_count;
  
  clr_SI;
  set_STO;
  while((STO == 1) && (t > 0))
  {
    t--;
  };     
}


unsigned char I2C_read(unsigned char ack_mode)
{
  signed int t = timeout_count;
  unsigned char value = 0x00;

  set_AA;                             
  clr_SI;
  while((SI == 0) && (t > 0))
  {
    t--;
  };    
  
  value = I2DAT;

  if(ack_mode == I2C_NACK)
  {
    t = timeout_count;
    clr_AA;   
    clr_SI;
    while((SI == 0) && (t > 0))
    {
      t--;
    };      
  }
  
  return value;
}


void I2C_write(unsigned char value)
{
  signed int t = timeout_count;
  
  I2DAT = value; 
  clr_STA;           
  clr_SI;
  while((SI == 0) && (t > 0))
  {
    t--;
  };  
}


void SPI_init(unsigned char clk_speed, unsigned char mode)
{
  set_SPI_clock_rate(clk_speed);
  set_SPI_mode(mode);
  set_DISMODF;
  set_MSTR;
  set_SPIEN;
}


unsigned char SPI_transfer(unsigned char write_value)
{
  signed int t = timeout_count;
  register unsigned char read_value = 0x00; 

  SPDR = write_value;
  while((!(SPSR & SET_BIT7)) && (t > 0))
  {
    t--;
  };         
  read_value = SPDR;
  clr_SPIF;    

  return read_value;
}