#line 1 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Common\\Common.c"
/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2017 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Jan/21/2017
//***********************************************************************************************************
#line 1 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
/*--------------------------------------------------------------------------
N76E003.H

Header file for Nuvoton N76E003 in IAR
--------------------------------------------------------------------------*/
__sfr __no_init volatile union
{
  unsigned char P0; /* Port 0 */
  struct /* Port 0 */
  {
#line 21 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
    
  } P0_bit;
} @ 0x80;
    
__sfr __no_init volatile unsigned char SP @ 0x81; /* Stack Pointer */
__sfr __no_init volatile unsigned char DPL @ 0x82; /* Data Pointer Low byte, LSB of DPTR */
__sfr __no_init volatile unsigned char DPH @ 0x83; /* Data Pointer High byte, MSB of DPTR */
__sfr __no_init volatile unsigned char RCTRIM0 @ 0x84;
__sfr __no_init volatile unsigned char RCTRIM1 @ 0x85;	
__sfr __no_init volatile unsigned char RWK @ 0x86;
__sfr __no_init volatile unsigned char PCON @ 0x87;

__sfr __no_init volatile union
{
  unsigned char TCON; /* Timer Control */
  struct /* Timer Control */
  {
#line 56 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
    
  } TCON_bit;
} @ 0x88;
    
__sfr __no_init volatile unsigned char TMOD @ 0x89;
__sfr __no_init volatile unsigned char TL0 @ 0x8A; /* Timer0 Low */
__sfr __no_init volatile unsigned char TL1 @ 0x8B; /* Timer1 Low*/
__sfr __no_init volatile unsigned char TH0 @ 0x8C; /* Timer0 High*/
__sfr __no_init volatile unsigned char TH1 @ 0x8D; /* Timer1 High*/
__sfr __no_init volatile unsigned char CKCON @ 0x8E;
__sfr __no_init volatile unsigned char WKCON @ 0x8F;

__sfr __no_init volatile union
{
  unsigned char P1; /* Port 1 */
  struct /* Port 1 */
  {
#line 91 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;    
  } P1_bit;
} @ 0x90;

__sfr __no_init volatile unsigned char SFRS    @ 0x91; //TA Protection
__sfr __no_init volatile unsigned char CAPCON0 @ 0x92;
__sfr __no_init volatile unsigned char CAPCON1 @ 0x93;
__sfr __no_init volatile unsigned char CAPCON2 @ 0x94;
__sfr __no_init volatile unsigned char CKDIV   @ 0x95;
__sfr __no_init volatile unsigned char CKSWT   @ 0x96; //TA Protection
__sfr __no_init volatile unsigned char CKEN    @ 0x97; //TA Protection

__sfr __no_init volatile union
{
  unsigned char SCON; /* Serial Control */
  struct /* Serial Control */
  {
#line 125 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } SCON_bit;
} @ 0x98;

__sfr __no_init volatile unsigned char SBUF @ 0x99; /* Serial Data Buffer */
__sfr __no_init volatile unsigned char SBUF_1 @ 0x9A; /* Serial 1 Data Buffer */
__sfr __no_init volatile unsigned char EIE @ 0x9B;
__sfr __no_init volatile unsigned char EIE1 @ 0x9C;
__sfr __no_init volatile unsigned char CHPCON @ 0x9F; //TA Protection

__sfr __no_init volatile union
{
  unsigned char P2; /* Port 2 */
  struct /* Port 2 */
  {
#line 157 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } P2_bit;
} @ 0xA0;

__sfr __no_init volatile unsigned char AUXR1 @ 0xA2;
__sfr __no_init volatile unsigned char BODCON0 @ 0xA3; //TA Protection
__sfr __no_init volatile unsigned char IAPTRG @ 0xA4; //TA Protection
__sfr __no_init volatile unsigned char IAPUEN @ 0xA5;	//TA Protection
__sfr __no_init volatile unsigned char IAPAL @ 0xA6;
__sfr __no_init volatile unsigned char IAPAH @ 0xA7;
//__sfr __no_init volatile unsigned char IE @ 0xA8;
__sfr __no_init volatile union
{
  unsigned char IE; /* Interrupt Enable */
  struct /* Interrupt Enable */
  {
#line 190 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } IE_bit;
} @ 0xA8;

__sfr __no_init volatile unsigned char SADDR @ 0xA9;
__sfr __no_init volatile unsigned char WDCON @ 0xAA; //TA Protection
__sfr __no_init volatile unsigned char BODCON1 @ 0xAB; //TA Protection
__sfr __no_init volatile unsigned char P3M1 @ 0xAC;
__sfr __no_init volatile unsigned char P3S @ 0xAC; //Page1
__sfr __no_init volatile unsigned char P3M2 @ 0xAD;
__sfr __no_init volatile unsigned char P3SR @ 0xAD; //Page1
__sfr __no_init volatile unsigned char IAPFD @ 0xAE;
__sfr __no_init volatile unsigned char IAPCN @ 0xAF;

//__sfr __no_init volatile unsigned char P3   @ 0xB0;
__sfr __no_init volatile union
{
  unsigned char P3; /* Port 3 */
  struct /* Port 3 */
  {
#line 227 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } P3_bit;
} @ 0xB0;

__sfr __no_init volatile unsigned char P0M1 @ 0xB1;
__sfr __no_init volatile unsigned char P0S  @ 0xB1; //Page1
__sfr __no_init volatile unsigned char P0M2 @ 0xB2;
__sfr __no_init volatile unsigned char P0SR @ 0xB2; //Page1
__sfr __no_init volatile unsigned char P1M1 @ 0xB3;
__sfr __no_init volatile unsigned char P1S  @ 0xB3; //Page1
__sfr __no_init volatile unsigned char P1M2 @ 0xB4;
__sfr __no_init volatile unsigned char P1SR @ 0xB4; //Page1
__sfr __no_init volatile unsigned char P2S @ 0xB5; 
__sfr __no_init volatile unsigned char IPH @ 0xB7;
__sfr __no_init volatile unsigned char PWMINTC @ 0xB7;	//Page1
//__sfr __no_init volatile unsigned char IP @ 0xB8;
__sfr __no_init volatile union
{
  unsigned char IP; /* IP  */
  struct /* IP  */
  {
#line 265 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
        unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } IP_bit;
} @ 0xB8;
__sfr __no_init volatile unsigned char SADEN @ 0xB9;
__sfr __no_init volatile unsigned char SADEN_1 @ 0xBA;
__sfr __no_init volatile unsigned char SADDR_1 @ 0xBB;
__sfr __no_init volatile unsigned char I2DAT @ 0xBC;
__sfr __no_init volatile unsigned char I2STAT @ 0xBD;
__sfr __no_init volatile unsigned char I2CLK @ 0xBE;
__sfr __no_init volatile unsigned char I2TOC @ 0xBF;

//__sfr __no_init volatile unsigned I2CON @ 0xC0;
__sfr __no_init volatile union
{
  unsigned char I2CON; /* I2CON  */
  struct /* I2CON  */
  {
#line 299 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } I2CON_bit;
} @ 0xC0;
__sfr __no_init volatile unsigned char I2ADDR @ 0xC1;
__sfr __no_init volatile unsigned char ADCRL @ 0xC2;
__sfr __no_init volatile unsigned char ADCRH @ 0xC3;
__sfr __no_init volatile unsigned char T3CON @ 0xC4;
__sfr __no_init volatile unsigned char PWM4H @ 0xC4; //Page1
__sfr __no_init volatile unsigned char RL3 @ 0xC5;
__sfr __no_init volatile unsigned char PWM5H @ 0xC5;	//Page1
__sfr __no_init volatile unsigned char RH3 @ 0xC6;
__sfr __no_init volatile unsigned char PIOCON1 @ 0xC6; //Page1
__sfr __no_init volatile unsigned char TA @ 0xC7;

__sfr __no_init volatile union
{
  unsigned char T2CON; /* Timer 2 Control */
  struct /* Timer 2 Control */
  {
#line 335 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
        unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } T2CON_bit;
} @ 0xC8;

__sfr __no_init volatile unsigned char T2MOD @ 0xC9;
__sfr __no_init volatile unsigned char RCMP2L @ 0xCA;
__sfr __no_init volatile unsigned char RCMP2H @ 0xCB;
__sfr __no_init volatile unsigned char TL2 @ 0xCC; /* Timer2 Low */
__sfr __no_init volatile unsigned char PWM4L @ 0xCC; //Page1
__sfr __no_init volatile unsigned char TH2 @ 0xCD;
__sfr __no_init volatile unsigned char PWM5L @ 0xCD; //Page1
__sfr __no_init volatile unsigned char ADCMPL @ 0xCE;
__sfr __no_init volatile unsigned char ADCMPH @ 0xCF;

__sfr __no_init volatile union
{
  unsigned char PSW; /* Program Status Word */
  struct /* Program Status Word */
  {
#line 371 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;    
  } PSW_bit;
} @ 0xD0;
__sfr __no_init volatile unsigned char PWMPH @ 0xD1;
__sfr __no_init volatile unsigned char PWM0H @ 0xD2;
__sfr __no_init volatile unsigned char PWM1H @ 0xD3;
__sfr __no_init volatile unsigned char PWM2H @ 0xD4;
__sfr __no_init volatile unsigned char PWM3H @ 0xD5;
__sfr __no_init volatile unsigned char PNP @ 0xD6;
__sfr __no_init volatile unsigned char FBD @ 0xD7;

//__sfr __no_init volatile unsigned char PWMCON0 @ 0xD8;
__sfr __no_init volatile union
{
  unsigned char PWMCON0; /* PWMCON0  */
  struct /* PWMCON0  */
  {
#line 405 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;    
  } PWMCON0_bit;
} @ 0xD8;

__sfr __no_init volatile unsigned char PWMPL @ 0xD9;
__sfr __no_init volatile unsigned char PWM0L @ 0xDA;
__sfr __no_init volatile unsigned char PWM1L @ 0xDB;
__sfr __no_init volatile unsigned char PWM2L @ 0xDC;
__sfr __no_init volatile unsigned char PWM3L @ 0xDD;
__sfr __no_init volatile unsigned char PIOCON0 @ 0xDE;
__sfr __no_init volatile unsigned char PWMCON1 @ 0xDF;

__sfr __no_init volatile union
{
  unsigned char ACC; /* Accumulator */
  struct /* Accumulator */
  {
#line 439 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;    
  } ACC_bit;
} @ 0xE0;

__sfr __no_init volatile unsigned char ADCCON1 @ 0xE1;
__sfr __no_init volatile unsigned char ADCCON2 @ 0xE2;
__sfr __no_init volatile unsigned char ADCDLY @ 0xE3;
__sfr __no_init volatile unsigned char C0L @ 0xE4;
__sfr __no_init volatile unsigned char C0H @ 0xE5;
__sfr __no_init volatile unsigned char C1L @ 0xE6;
__sfr __no_init volatile unsigned char C1H @ 0xE7;
//__sfr __no_init volatile unsigned char ADCCON0 @ 0xE8;
__sfr __no_init volatile union
{
  unsigned char ADCCON0; /* ADCCON0  */
  struct /* ADCCON0  */
  {
#line 473 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } ADCCON0_bit;
} @ 0xE8;
__sfr __no_init volatile unsigned char PICON @ 0xE9;
__sfr __no_init volatile unsigned char PINEN @ 0xEA;
__sfr __no_init volatile unsigned char PIPEN @ 0xEB;
__sfr __no_init volatile unsigned char PIF @ 0xEC;
__sfr __no_init volatile unsigned char C2L @ 0xED;
__sfr __no_init volatile unsigned char C2H @ 0xEE;
__sfr __no_init volatile unsigned char EIP @ 0xEF;

__sfr __no_init volatile union
{
  unsigned char B; /* B Register */
  struct /* B Register */
  {
#line 506 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } B_bit;
} @ 0xF0;
__sfr __no_init volatile unsigned char CAPCON3 @ 0xF1;
__sfr __no_init volatile unsigned char CAPCON4 @ 0xF2;
__sfr __no_init volatile unsigned char SPCR @ 0xF3;
__sfr __no_init volatile unsigned char SPCR2 @ 0xF3; //Page1
__sfr __no_init volatile unsigned char SPSR @ 0xF4;
__sfr __no_init volatile unsigned char SPDR @ 0xF5;
__sfr __no_init volatile unsigned char AINDIDS @ 0xF6;
__sfr __no_init volatile unsigned char EIPH @ 0xF7;
//__sfr __no_init volatile unsigned char SCON_1 @ 0xF8;
__sfr __no_init volatile union
{
  unsigned char SCON_1 ; /* SCON_1  Register */
  struct /* SCON_1  Register */
  {
#line 540 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } SCON_1_bit;
} @ 0xF8;

__sfr __no_init volatile unsigned char PDTEN @ 0xF9; //TA Protection
__sfr __no_init volatile unsigned char PDTCNT @ 0xFA; //TA Protection
__sfr __no_init volatile unsigned char PMEN @ 0xFB;
__sfr __no_init volatile unsigned char PMD @ 0xFC;
__sfr __no_init volatile unsigned char EIP1 @ 0xFE;
__sfr __no_init volatile unsigned char EIPH1 @ 0xFF;

/*  BIT Registers  */
/*  SCON_1  */
#line 569 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"

/*  ADCCON0  */
#line 579 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"

/*  PWMCON0  */







/*  T2CON  */



 
/*  I2CON  */
#line 600 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"

/*  IP  */  
#line 609 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"

/*  P3  */  



/*  IE  */
#line 623 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"

/*  P2  */ 


/*  SCON  */
#line 637 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"

/*  P1  */     
#line 650 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"

/*  TCON  */
#line 660 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"

/*  P0  */  
#line 676 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\N76E003_iar.h"








                            


                            
               





























#line 13 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Common\\Common.c"
#line 1 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Common.h"
typedef unsigned char         UINT8;
typedef unsigned int          UINT16;
typedef unsigned long         UINT32;

typedef unsigned char         uint8_t;
typedef unsigned int          uint16_t;
typedef unsigned long         uint32_t;







#line 24 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Common.h"


void  InitialUART0_Timer1(UINT32 u32Baudrate); //T1M = 1, SMOD = 1
void  InitialUART0_Timer3(UINT32 u32Baudrate); //Timer3 as Baudrate, SMOD=1, Prescale=0
void  InitialUART1_Timer3(UINT32 u32Baudrate);
void  Send_Data_To_UART0(UINT8 c);
UINT8 Receive_Data_From_UART0(void);
void  Send_Data_To_UART1(UINT8 c);
UINT8 Receive_Data_From_UART1(void);
void  InitialUART1(UINT32 u32Baudrate);
void printf_UART(uint8_t *str, ...);
extern UINT8 BIT_TMP;
#line 14 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Common\\Common.c"
#line 1 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Delay.h"
void Timer0_Delay100us(UINT32 u32CNT);
void Timer0_Delay1ms(UINT32 u32CNT);
void Timer1_Delay10ms(UINT32 u32CNT);
void Timer2_Delay500us(UINT32 u32CNT);
void Timer3_Delay100ms(UINT32 u32CNT);

void Timer0_Delay40ms(UINT32 u32CNT);
void Timer3_Delay10us(UINT32 u32CNT);
#line 15 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Common\\Common.c"
#line 1 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

/**** P0		80H *****/
#line 11 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 20 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** SP  	81H **** 
//**** DPH  82H **** 
//**** DPL  83H **** 
//**** RWK  86H **** 

//**** PCON	87H *****
#line 34 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 42 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

/**** TCON		88H ****/
#line 52 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 61 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** TMOD		89H **** 
#line 71 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 80 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** TH1		8AH **** 
//**** TH0		8BH **** 
//**** TL1		8CH	**** 
//**** TL0		8DH **** 

//**** CKCON	8EH ****




                            





//**** WKCON	8FH ****
#line 104 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 111 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

/**** P1		90H *****/
#line 121 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 130 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//****SFRS		91H ****



//****CAPCON0	92H ****
#line 142 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 149 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** CAPCON1	93H ****
#line 157 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 164 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** CAPCON2		94H ****



                            




//**** CKDIV		95H ****

//**** CKSWT		96H ****  TA protect register












//**** CKEN 	97H **** TA protect register




       





//**** SCON		98H ****
#line 209 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 218 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** SBUF		99H ****
//**** SBUF_1	9AH ****

//**** EIE		9BH ****                      
#line 231 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 240 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** EIE1		9CH ****                      



                            



                            
//**** CHPCON		9DH ****  TA protect register




       





//**** P2		A0H ****

//**** AUXR1	A2H ****
#line 270 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 277 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** BODCON0	A3H ****  TA protect register
#line 287 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 296 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** IAPTRG		A4H	****  TA protect register



//**** IAPUEN		A5H **** TA protect register








//**** IAPAL	A6H ****
//**** IAPAH	A7H ****

//**** IE			A8H ****
#line 322 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 331 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** SADDR		A9H ****

//**** WDCON		AAH **** TA protect register
#line 343 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
        
#line 351 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** BODCON1 ABH **** TA protect register



        





//**** P3M1		ACH PAGE0 ****



//**** P3S		ACH PAGE1 **** SFRS must set as 1 to modify this register  



//**** P3M2		ADH PAGE0 ****



//**** P3SR		ADH PAGE1 **** SFRS must set as 1 to modify this register  



//**** IAPFD	AEH ****

//**** IAPCN	AFH ****
#line 387 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 394 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** P3		B0H ****



//**** P0M1	B1H PAGE0 ****
#line 408 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 417 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** P0S	B2H PAGE1 **** SFRS must set as 1 to modify this register  
#line 427 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 436 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** P0M2		B2H PAGE0 ****
#line 446 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 455 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"


//**** P0SR		B0H PAGE1 **** SFRS must set as 1 to modify this register  
#line 466 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 475 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"


//**** P1M1	B3H PAGE0 ****
#line 486 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 495 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** P1S B3H PAGE1 **** SFRS must set as 1 to modify this register  
#line 505 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 514 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** P1M2		B4H PAGE0 ****                      



                            




//**** P1SR		B4H PAGE1 **** SFRS must set as 1 to modify this register  
#line 533 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 542 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"


//**** P2S		B5H	****



//**** IPH    B7H PAGE0 ****                    
#line 556 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 564 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** PWMINTC B7H PAGE1 **** SFRS must set as 1 to modify this register  












//**** IP		B8H	****
#line 586 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 594 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** SADEN		B9H ****
//**** SADEN_1	8AH ****
//**** SADDR_1	BBH ****
//**** I2DAT		BCH ****
//**** I2STAT		BDH ****
//**** I2CLK		BEH ****

//**** I2TOC		BFH ****








//**** I2CON  C0H **** 
#line 618 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 625 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** I2ADDR		C1H ****



//**** ADCRL		C2H ****
//**** ADCRH		C3H ****

//**** T3CON		C4H	PAGE0 ****                     
#line 642 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 651 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** PWM4H	C4H	PAGE1 **** SFRS must set as 1 to modify this register  
//**** RL3		C5H PAGE0 ****
//**** PWM5H	C5H PAGE1 **** SFRS must set as 1 to modify this register  
//**** RH3		C6H PAGE0 ****

//**** PIOCON1 C6H PAGE1 **** SFRS must set as 1 to modify this register  










//**** T2CON  C8H ****








//**** T2MOD	C9H ****                     
#line 686 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 695 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** RCMP2H CAH ****
//**** RCMP2L CBH ****
//**** TL2		CCH PAGE0 ****
//**** PWM4L 	CCH PAGE1 **** SFRS must set as 1 to modify this register  
//**** TH2		CDH PAGE0 ****
//**** PWM5L	CDH PAGE1 **** SFRS must set as 1 to modify this register  
//**** ADCMPL	CEH **** 
//**** ADCMPH	CFH ****

/****  PSW 		D0H ****/
#line 713 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 721 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** PWMPH		D1H ****
//**** PWM0H		D2H ****
//**** PWM1H		D3H ****
//**** PWM2H		D4H ****
//**** PWM3H		D5H	****

//**** PNP			D6H ****
#line 735 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 742 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** FBD		D7H ****
#line 752 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 761 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

/**** PWMCON0			D8H ****/










//**** PWMPL		D9H ****
//**** PWM0L		DAH ****
//**** PWM1L		DBH ****
//**** PWM2L		DCH ****
//**** PWM3L		DDH ****

//**** PIOCON0	DEH ****
#line 786 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 793 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** PWMCON1	DFH ****
#line 803 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 812 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** ACC	E0H ****

//**** ADCCON1	E1H ****












//**** ADCON2		E2H ****










//**** ADCDLY		E3H ****
//**** C0L			E4H ****
//**** C0H			E5H ****
//**** C1L			E6H ****
//**** C1H			E7H ****

//**** ADCCON0	EAH ****
#line 854 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 863 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** PICON	E9H	****
#line 873 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 882 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** PINEN		EAH **** 
#line 892 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 901 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
//**** PIPEN 		EBH ****
#line 911 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 920 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
   
//**** PIF	ECH ****
#line 930 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 939 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** C2L  EDH ****  
//**** C2H	EEH ****

//**** EIP	EFH ****                      
#line 952 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 961 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** B	F0H ****

//**** CAPCON3		F1H ****
#line 973 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 982 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** CAPCON4		F2H ****










//**** SPCR		F3H PAGE0 ****
#line 1003 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 1012 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** SPCR2		F3H PAGE1 **** SFRS must set as 1 to modify this register  






//**** SPSR			F4H ****





                            






//**** SPDR		F5H ****

//**** AINDIDS	F6H ****
#line 1044 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 1053 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** EIPH			F7H ****
#line 1063 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 1072 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

/**** SCON_1		F8H ****/
#line 1082 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

#line 1091 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//**** PDTEN		F9H ****








//**** PDTCNT		FAH ****

//**** PMEN   	FBH ****                   
#line 1110 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 1117 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
//**** PMD		FCH ****                       
#line 1127 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"
                            
#line 1136 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\SFR_Macro.h"

//****	EIP1 		FEH ****                     



                            




//**** EIPH1		FFH ****                



                            










                            


                            
               












#line 16 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Common\\Common.c"
#line 1 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 8.0\\8051\\inc\\clib\\stdio.h"
/*                      - STDIO.H -

   Subset of ANSI standard I/O function declarations.

   $Revision: 6900 $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/





  #pragma system_include


#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 8.0\\8051\\inc\\clib\\stdarg.h"
/*                      - STDARG.H -
   The ANSI macros for reading variable argument lists (...).

   $Revision: 45429 $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/





  #pragma system_include


#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 8.0\\8051\\inc\\clib\\sysmac.h"
/*                      - SYSMAC.H -

   Defines system macros to maintain source compatibility
   with different IAR compilers.

   $Revision: 13296 $

   Copyright 1986 - 1999 IAR Systems. All rights reserved.
*/





  #pragma system_include


#line 25 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 8.0\\8051\\inc\\clib\\sysmac.h"





























#line 61 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 8.0\\8051\\inc\\clib\\sysmac.h"

#line 69 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 8.0\\8051\\inc\\clib\\sysmac.h"

#line 80 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 8.0\\8051\\inc\\clib\\sysmac.h"





/* Macro for frmwri and frmrd */


/* Typedefs put here to appear only once */
typedef unsigned char    size_t;
typedef signed char ptrdiff_t;



/* A definiton for a function of what effects it has.
   NS  = no_state, errno, i.e. it uses no internal or external state. It may
         write to errno though
   NE  = no_state, i.e. it uses no internal or external state, not even
         writing to errno. 
   NRx = no_read(x), i.e. it doesn't read through pointer parameter x.
   NWx = no_write(x), i.e. it doesn't write through pointer parameter x.
   Rx  = returns x, i.e. the function will return parameter x.
   
   All the functions with effects also has "always_returns", 
   i.e. the function will always return.
*/

#line 126 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 8.0\\8051\\inc\\clib\\sysmac.h"

#line 17 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 8.0\\8051\\inc\\clib\\stdarg.h"


typedef void *va_list[1];

__intrinsic void __va_start(va_list);




/*=====================================*/
/*  These targets has char pushed as   */
/*  word on stack.                     */
/*  Stack grows in negativ direction.  */
/*  (New type of code-generators)      */
/* - - - - - - - - - - - - - - - - - - */
/*     ICC78000 version 4.xx           */
/*     M32C version 3.xx               */
/*=====================================*/
#line 48 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 8.0\\8051\\inc\\clib\\stdarg.h"


#line 18 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 8.0\\8051\\inc\\clib\\stdio.h"













#line 40 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 8.0\\8051\\inc\\clib\\stdio.h"

#pragma language=save
#pragma language=extended
_Pragma("function_effects = no_write(1), always_returns")                int  puts(const char *);




 int  putchar(int);
 int  getchar(void);

_Pragma("function_effects = no_read(1), no_write(2), always_returns") _Pragma("__printf_args") _Pragma("library_default_requirements _formatted_write = unknown")  int  sprintf(char *,const char *,...);
_Pragma("function_effects = no_read(1), no_write(2), always_returns") _Pragma("__printf_args") _Pragma("library_default_requirements _formatted_write = unknown")  int  vsprintf(char *,const char *,
                                                       va_list);
_Pragma("function_effects = no_write(1), always_returns")    _Pragma("__printf_args") _Pragma("library_default_requirements _formatted_write = unknown")  int  printf(const char *,...);
_Pragma("function_effects = no_write(1), always_returns")    _Pragma("__printf_args") _Pragma("library_default_requirements _formatted_write = unknown")  int  vprintf(const char *,va_list);
_Pragma("function_effects = no_write(1), always_returns")    _Pragma("__scanf_args") _Pragma("library_default_requirements _formatted_read = unknown")   int  scanf(const char *,...);
_Pragma("function_effects = no_write(1,2), always_returns") _Pragma("__scanf_args") _Pragma("library_default_requirements _formatted_read = unknown")   int  sscanf(const char *, 
                                                     const char *,...);
_Pragma("function_effects = no_read(1), always_returns")                char *gets(char *);
#pragma language=restore


#line 2 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"




//16 --> 8 x 2


//8 x 2 --> 16

//8 x 4 --> 32

//32 --> 16 x 2


//32 --> 8 x 4





#line 38 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"

#line 47 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"

#line 56 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"




/*****************************************************************************************
* For GPIO INIT setting 
*****************************************************************************************/
//------------------- Define Port as Quasi mode  -------------------
#line 81 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"
//------------------- Define Port as Push Pull mode -------------------
#line 100 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"
//------------------- Define Port as Input Only mode -------------------
#line 118 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"
//-------------------Define Port as Open Drain mode -------------------
#line 136 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"
//--------- Define all port as quasi mode ---------





/****************************************************************************
   Enable INT port 0~3
***************************************************************************/




/*****************************************************************************
 Enable each bit low level trig mode
*****************************************************************************/
#line 160 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"
/*****************************************************************************
 Enable each bit high level trig mode
*****************************************************************************/
#line 171 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"
/*****************************************************************************
 Enable each bit falling edge trig mode
*****************************************************************************/
#line 182 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"
/*****************************************************************************
 Enable each bit rasing edge trig mode
*****************************************************************************/
#line 193 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"


/*****************************************************************************************
* For TIMER VALUE setting is base on " option -> C51 -> Preprocesser Symbols -> Define "
*****************************************************************************************/
#line 276 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"
//-------------------- Timer0 function define --------------------




//-------------------- Timer1 function define --------------------




//-------------------- Timer2 function define --------------------
#line 297 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"
//-------------------- Timer2 Capture define --------------------
//--- Falling Edge -----
#line 308 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"

#line 318 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"

#line 328 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"

//----- Rising edge ----
#line 339 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"

#line 349 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"

#line 359 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"

//-----BOTH  edge ----
#line 370 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"

#line 380 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"

#line 390 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"





/*****************************************************************************************
* For PWM setting 
*****************************************************************************************/
//--------- PMW clock source select define ---------------------


//--------- PWM clock devide define ----------------------------
#line 409 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"
//--------- PWM I/O select define ------------------------------
#line 432 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"
//--------- PWM I/O Polarity Control ---------------------------
#line 447 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"
//--------- PWM type define ------------------------------------


//--------- PWM mode define ------------------------------------





//--------- PMW interrupt setting ------------------------------




//--------- PWM interrupt pin select ---------------------------
#line 468 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"
//--------- PWM Dead time setting ------------------------------




/*****************************************************************************************
* For ADC INIT setting 
*****************************************************************************************/
#line 485 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"

#line 498 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"






/*****************************************************************************************
* For ADC INIT setting 
*****************************************************************************************/
#line 513 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Include\\Function_define.h"

#line 17 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Common\\Common.c"

//----------------------------------------------------------------------------------
// UART0 baud rate initial setting 
//----------------------------------------------------------------------------------
void InitialUART0_Timer1(UINT32 u32Baudrate)    //T1M = 1, SMOD = 1
{
		P0M1&=~0x40;P0M2&=~0x40;		//Setting UART pin as Quasi mode for transmit
		P0M1&=~0x80;P0M2&=~0x80;		//Setting UART pin as Quasi mode for transmit
	
    SCON = 0x50;     	//UART0 Mode1,REN=1,TI=1
    TMOD |= 0x20;    	//Timer1 Mode1
    
    PCON |= 0x80;        	//UART0 Double Rate Enable
    CKCON |= 0x10;
    T3CON &= ~0x20;        	//Serial port 0 baud rate clock source = Timer1
 

    TH1 = 256 - (1000000/u32Baudrate+1);               /*16 MHz */




    TCON_bit . BIT6 = 1;
		SCON_bit . BIT1 = 1;						//For printf function must setting TI = 1
}
//---------------------------------------------------------------
void InitialUART0_Timer3(UINT32 u32Baudrate) //use timer3 as Baudrate generator
{
		P0M1&=~0x40;P0M2&=~0x40;		//Setting UART pin as Quasi mode for transmit
		P0M1&=~0x80;P0M2&=~0x80;		//Setting UART pin as Quasi mode for transmit	
	
    SCON = 0x50;     //UART0 Mode1,REN=1,TI=1
    PCON |= 0x80;        //UART0 Double Rate Enable
    T3CON &= 0xF8;   //T3PS2=0,T3PS1=0,T3PS0=0(Prescale=1)
    T3CON |= 0x20;        //UART0 baud rate clock source = Timer3


		RH3    = ((UINT8)((65536 - (1000000/u32Baudrate)-1)>>8));  		/*16 MHz */
		RL3    = ((UINT8)((65536 - (1000000/u32Baudrate)-1)&0xFF));			/*16 MHz */





    T3CON |= 0x08;         //Trigger Timer3
		SCON_bit . BIT1 = 1;					 //For printf function must setting TI = 1
}

UINT8 Receive_Data_From_UART0(void)
{
    UINT8 c;
    while (!SCON_bit . BIT0);
    c = SBUF;
    SCON_bit . BIT0 = 0;
    return (c);
}

void Send_Data_To_UART0 (UINT8 c)
{
    SCON_bit . BIT1 = 0;
    SBUF = c;
    while(SCON_bit . BIT1==0);
}
void printf_UART(uint8_t *str, ...);
void printInteger(uint32_t u32Temp)
{
    uint8_t print_buf[16];
    uint32_t i = 15, j;

    *(print_buf + i) = '\0';
    j = u32Temp >> 31;
    if(j)
        u32Temp = ~u32Temp + 1;
    do
    {
        i--;
        *(print_buf + i) = '0' + u32Temp % 10;
        u32Temp = u32Temp / 10;
    }
    while(u32Temp != 0);
    if(j)
    {
        i--;
        *(print_buf + i) = '-';
    }
    printf_UART(print_buf + i);
}
void printHex(uint32_t u32Temp)
{
    uint8_t print_buf[16];
    uint32_t i = 15;
    uint32_t temp;

    *(print_buf + i) = '\0';
    do
    {
        i--;
        temp = u32Temp % 16;
        if(temp < 10)
            *(print_buf + i) = '0' + temp;
        else
            *(print_buf + i) = 'a' + (temp - 10) ;
        u32Temp = u32Temp / 16;
    }
    while(u32Temp != 0);
    printf_UART(print_buf + i);
}
void printf_UART(uint8_t *str, ...)
{
    va_list args;
    __va_start(args);
    while(*str != '\0')
    {
        if(*str == '%')
        {
            str++;
            if(*str == '\0') return;
            if(*str == 'd')
            {
                str++;
                printInteger((* --(*(int * *)args)));
            }
            else if(*str == 'x')
            {
                str++;
                printHex((* --(*(int * *)args)));
            }
        }
        Send_Data_To_UART0(*str++);
    }
}


//----------------------------------------------------------------------------------
// UART1 baud rate initial setting 
//----------------------------------------------------------------------------------
void InitialUART1_Timer3(UINT32 u32Baudrate) //use timer3 as Baudrate generator
{
		P0M1&=~0x04;P0M2&=~0x04;		//Setting UART pin as Quasi mode for transmit
		P1M1&=~0x40;P1M2&=~0x40;		//Setting UART pin as Quasi mode for transmit
	
	  SCON_1 = 0x50;   	//UART1 Mode1,REN_1=1,TI_1=1
    T3CON = 0x08;   	//T3PS2=0,T3PS1=0,T3PS0=0(Prescale=1), UART1 in MODE 1
		T3CON &= ~0x20;
	

		RH3    = ((UINT8)((65536 - (1000000/u32Baudrate)-1)>>8));  		/*16 MHz */
		RL3    = ((UINT8)((65536 - (1000000/u32Baudrate)-1)&0xFF));			/*16 MHz */





    T3CON |= 0x08;         //Trigger Timer3
}

UINT8 Receive_Data_From_UART1(void)
{
    UINT8 c;
    
    while (!SCON_1_bit . BIT0);
    c = SBUF_1;
    SCON_1_bit . BIT0 = 0;
    return (c);
}

void Send_Data_To_UART1 (UINT8 c)
{
    SCON_1_bit . BIT1 = 0;
    SBUF_1 = c;
    while(SCON_1_bit . BIT1==0);
}


/*==========================================================================*/
#line 200 "C:\\Users\\SShahryiar\\Desktop\\N76E003 Tutorial\\N76E003 IAR Code Examples\\Common\\Common.c"
/*==========================================================================*/
