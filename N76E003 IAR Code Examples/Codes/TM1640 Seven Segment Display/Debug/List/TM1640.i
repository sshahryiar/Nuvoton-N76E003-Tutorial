



 
__sfr __no_init volatile union
{
  unsigned char P0;  
  struct  
  {
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
    
__sfr __no_init volatile unsigned char SP @ 0x81;  
__sfr __no_init volatile unsigned char DPL @ 0x82;  
__sfr __no_init volatile unsigned char DPH @ 0x83;  
__sfr __no_init volatile unsigned char RCTRIM0 @ 0x84;
__sfr __no_init volatile unsigned char RCTRIM1 @ 0x85;	
__sfr __no_init volatile unsigned char RWK @ 0x86;
__sfr __no_init volatile unsigned char PCON @ 0x87;

__sfr __no_init volatile union
{
  unsigned char TCON;  
  struct  
  {
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
__sfr __no_init volatile unsigned char TL0 @ 0x8A;  
__sfr __no_init volatile unsigned char TL1 @ 0x8B;  
__sfr __no_init volatile unsigned char TH0 @ 0x8C;  
__sfr __no_init volatile unsigned char TH1 @ 0x8D;  
__sfr __no_init volatile unsigned char CKCON @ 0x8E;
__sfr __no_init volatile unsigned char WKCON @ 0x8F;

__sfr __no_init volatile union
{
  unsigned char P1;  
  struct  
  {
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

__sfr __no_init volatile unsigned char SFRS    @ 0x91; 
__sfr __no_init volatile unsigned char CAPCON0 @ 0x92;
__sfr __no_init volatile unsigned char CAPCON1 @ 0x93;
__sfr __no_init volatile unsigned char CAPCON2 @ 0x94;
__sfr __no_init volatile unsigned char CKDIV   @ 0x95;
__sfr __no_init volatile unsigned char CKSWT   @ 0x96; 
__sfr __no_init volatile unsigned char CKEN    @ 0x97; 

__sfr __no_init volatile union
{
  unsigned char SCON;  
  struct  
  {
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

__sfr __no_init volatile unsigned char SBUF @ 0x99;  
__sfr __no_init volatile unsigned char SBUF_1 @ 0x9A;  
__sfr __no_init volatile unsigned char EIE @ 0x9B;
__sfr __no_init volatile unsigned char EIE1 @ 0x9C;
__sfr __no_init volatile unsigned char CHPCON @ 0x9F; 

__sfr __no_init volatile union
{
  unsigned char P2;  
  struct  
  {
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
__sfr __no_init volatile unsigned char BODCON0 @ 0xA3; 
__sfr __no_init volatile unsigned char IAPTRG @ 0xA4; 
__sfr __no_init volatile unsigned char IAPUEN @ 0xA5;	
__sfr __no_init volatile unsigned char IAPAL @ 0xA6;
__sfr __no_init volatile unsigned char IAPAH @ 0xA7;

__sfr __no_init volatile union
{
  unsigned char IE;  
  struct  
  {
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
__sfr __no_init volatile unsigned char WDCON @ 0xAA; 
__sfr __no_init volatile unsigned char BODCON1 @ 0xAB; 
__sfr __no_init volatile unsigned char P3M1 @ 0xAC;
__sfr __no_init volatile unsigned char P3S @ 0xAC; 
__sfr __no_init volatile unsigned char P3M2 @ 0xAD;
__sfr __no_init volatile unsigned char P3SR @ 0xAD; 
__sfr __no_init volatile unsigned char IAPFD @ 0xAE;
__sfr __no_init volatile unsigned char IAPCN @ 0xAF;


__sfr __no_init volatile union
{
  unsigned char P3;  
  struct  
  {
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
__sfr __no_init volatile unsigned char P0S  @ 0xB1; 
__sfr __no_init volatile unsigned char P0M2 @ 0xB2;
__sfr __no_init volatile unsigned char P0SR @ 0xB2; 
__sfr __no_init volatile unsigned char P1M1 @ 0xB3;
__sfr __no_init volatile unsigned char P1S  @ 0xB3; 
__sfr __no_init volatile unsigned char P1M2 @ 0xB4;
__sfr __no_init volatile unsigned char P1SR @ 0xB4; 
__sfr __no_init volatile unsigned char P2S @ 0xB5; 
__sfr __no_init volatile unsigned char IPH @ 0xB7;
__sfr __no_init volatile unsigned char PWMINTC @ 0xB7;	

__sfr __no_init volatile union
{
  unsigned char IP;  
  struct  
  {
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


__sfr __no_init volatile union
{
  unsigned char I2CON;  
  struct  
  {
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
__sfr __no_init volatile unsigned char PWM4H @ 0xC4; 
__sfr __no_init volatile unsigned char RL3 @ 0xC5;
__sfr __no_init volatile unsigned char PWM5H @ 0xC5;	
__sfr __no_init volatile unsigned char RH3 @ 0xC6;
__sfr __no_init volatile unsigned char PIOCON1 @ 0xC6; 
__sfr __no_init volatile unsigned char TA @ 0xC7;

__sfr __no_init volatile union
{
  unsigned char T2CON;  
  struct  
  {
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
__sfr __no_init volatile unsigned char TL2 @ 0xCC;  
__sfr __no_init volatile unsigned char PWM4L @ 0xCC; 
__sfr __no_init volatile unsigned char TH2 @ 0xCD;
__sfr __no_init volatile unsigned char PWM5L @ 0xCD; 
__sfr __no_init volatile unsigned char ADCMPL @ 0xCE;
__sfr __no_init volatile unsigned char ADCMPH @ 0xCF;

__sfr __no_init volatile union
{
  unsigned char PSW;  
  struct  
  {
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


__sfr __no_init volatile union
{
  unsigned char PWMCON0;  
  struct  
  {
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
  unsigned char ACC;  
  struct  
  {
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

__sfr __no_init volatile union
{
  unsigned char ADCCON0;  
  struct  
  {
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
  unsigned char B;  
  struct  
  {
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
__sfr __no_init volatile unsigned char SPCR2 @ 0xF3; 
__sfr __no_init volatile unsigned char SPSR @ 0xF4;
__sfr __no_init volatile unsigned char SPDR @ 0xF5;
__sfr __no_init volatile unsigned char AINDIDS @ 0xF6;
__sfr __no_init volatile unsigned char EIPH @ 0xF7;

__sfr __no_init volatile union
{
  unsigned char SCON_1 ;  
  struct  
  {
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

__sfr __no_init volatile unsigned char PDTEN @ 0xF9; 
__sfr __no_init volatile unsigned char PDTCNT @ 0xFA; 
__sfr __no_init volatile unsigned char PMEN @ 0xFB;
__sfr __no_init volatile unsigned char PMD @ 0xFC;
__sfr __no_init volatile unsigned char EIP1 @ 0xFE;
__sfr __no_init volatile unsigned char EIPH1 @ 0xFF;

 
 

 

 



 
 
 

   

   


 

  

 

      

 

   








                            


                            
               






























 








                            

 



                            







                            


                            

 











                            







       








                            


                            
                            

       




                            


















        


        













                            
























                            








                            


























                            













                            










 














 












                            



















                            


                            
                            

                            
   







                            
















                            







                            

 








                            
                            

                            


                            


                            







                            


                            
               



















 


  #pragma system_include







 


  #pragma system_include









 


  #pragma system_include














 

 
typedef unsigned char    size_t;
typedef signed char ptrdiff_t;













 




typedef void *va_list[1];

__intrinsic void __va_start(va_list);


 
 
 
 
 
 
 
 
 







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
















 









 


 


 


 


 




 



















 












 





 

typedef unsigned char         UINT8;
typedef unsigned int          UINT16;
typedef unsigned long         UINT32;

typedef unsigned char         uint8_t;
typedef unsigned int          uint16_t;
typedef unsigned long         uint32_t;







void  InitialUART0_Timer1(UINT32 u32Baudrate); 
void  InitialUART0_Timer3(UINT32 u32Baudrate); 
void  InitialUART1_Timer3(UINT32 u32Baudrate);
void  Send_Data_To_UART0(UINT8 c);
UINT8 Receive_Data_From_UART0(void);
void  Send_Data_To_UART1(UINT8 c);
UINT8 Receive_Data_From_UART1(void);
void  InitialUART1(UINT32 u32Baudrate);
void printf_UART(uint8_t *str, ...);
extern UINT8 BIT_TMP;
void Timer0_Delay100us(UINT32 u32CNT);
void Timer0_Delay1ms(UINT32 u32CNT);
void Timer1_Delay10ms(UINT32 u32CNT);
void Timer2_Delay500us(UINT32 u32CNT);
void Timer3_Delay100ms(UINT32 u32CNT);

void Timer0_Delay40ms(UINT32 u32CNT);
void Timer3_Delay10us(UINT32 u32CNT);


                                 
                                  

                                                             
                                    

void TM1640_init(unsigned char brightness_level);   
void TM1640_start(void);
void TM1640_stop(void);
void TM1640_write(unsigned char value);       
void TM1640_send_command(unsigned char value);
void TM1640_send_data(unsigned char address, unsigned char value);
void TM1640_clear_display(void);
             
               
void TM1640_init(unsigned char brightness_level)
{                
  do{P0M1&=~0x08;P0M2|=0x08; P0M1&=~0x10;P0M2|=0x10;}while(0);
  
  Timer0_Delay1ms(10);  
  
  P0_bit . BIT3 = 1;
  P0_bit . BIT4 = 1;

  TM1640_send_command(0x40);
  TM1640_send_command(brightness_level);
  TM1640_clear_display();
}   


void TM1640_start(void)
{
  P0_bit . BIT3 = 1;
  P0_bit . BIT4 = 1;
  Timer3_Delay10us(1);
  P0_bit . BIT3 = 0;
  Timer3_Delay10us(1);
  P0_bit . BIT4 = 0;
}


void TM1640_stop(void)
{
  P0_bit . BIT3 = 0;
  P0_bit . BIT4 = 0;
  Timer3_Delay10us(1);
  P0_bit . BIT4 = 1;
  Timer3_Delay10us(1);
  P0_bit . BIT3 = 1;
}
                           
                                                                             
void TM1640_write(unsigned char value)  
{                                                       
  unsigned char s = 0x08;
  
  while(s > 0)
  {
    P0_bit . BIT4 = 0;
    
    if((value & 0x01) == 0x01)
    {
     P0_bit . BIT3 = 1;
    }
    else
    {
     P0_bit . BIT3 = 0;
    }
    
    P0_bit . BIT4 = 1;

    value >>= 0x01;
    s--;
  };
}                                 


void TM1640_send_command(unsigned char value)    
{                            
  TM1640_start();
  TM1640_write(value);
  TM1640_stop();
}               


void TM1640_send_data(unsigned char address, unsigned char value)
{                  
  TM1640_send_command(0x44);
  
  TM1640_start();
  
  TM1640_write((0xC0 | (0x0F & address)));
  TM1640_write(value);
  
  TM1640_stop();
}  


void TM1640_clear_display(void)
{ 
  unsigned char s = 0x00;
  
  for(s = 0x00; s < 16; s++)
  {
    TM1640_send_data(s, 0);
  };
}
