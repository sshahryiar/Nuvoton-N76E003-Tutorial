#include "N76E003_iar.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "soft_delay.h"
#include "Flash.h"


static unsigned char EA_Save_bit;


void enable_IAP_mode(void)
{
    EA_Save_bit = EA;
    clr_EA;
    TA = 0xAA;
    TA = 0x55;
    CHPCON |= 0x01;
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
      write_data_to_one_page(u16_addr, pDat, num);
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
