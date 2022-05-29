#include "N76E003_iar.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "soft_delay.h"
#include "HMC1022.h" 


unsigned char done = 0;
unsigned char data_bytes[no_of_data_bytes_returned] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; 
                                                          

void read_heading(void)
{                         
     unsigned char s = 0;  
     unsigned long CRC = 0;
                                                
     Send_Data_To_UART1(Get_Angular_Measurement);  
               
     for(s = 0; s < no_of_data_bytes_returned; s++)
     {                
        data_bytes[s] = Receive_Data_From_UART1();
        if(s < (no_of_data_bytes_returned - 1))   
        {
            CRC += data_bytes[s];
        }
     }                                                       
     
     CRC = (CRC & 0xFF); 
     
     if(CRC == data_bytes[7])
     {                                     
       done = 1;
     }     
} 


void calibrate_compass(void)
{
 unsigned char s = 0x00;   	

 Send_Data_To_UART1(Start_Calibration); 
 
 for(s = 0; s < 60; s++)
 {
     calibration_LED = 1;   	
     delay_ms(100);
     calibration_LED = 0;
     delay_ms(900);
 }  
 
 for(s = 0; s < 60; s++)    
 {
     calibration_LED = 1;  	
     delay_ms(400);             
     calibration_LED = 0;
     delay_ms(600);
 }              
 
 Send_Data_To_UART1(End_Calibration); 
}


void factory_reset(void)
{
 Send_Data_To_UART1(0xA0); 
 Send_Data_To_UART1(0xAA);
 Send_Data_To_UART1(0xA5);  
 Send_Data_To_UART1(0xC5); 
}      


void set_declination_angle(unsigned long angle)
{ 
 unsigned long hb = 0;
 unsigned char lb = 0;
 
 lb = (angle & 0x00FF);    
                          
 hb = (angle & 0xFF00);
 hb >>= 8;  
             
 Send_Data_To_UART1(Set_Magnetic_Declination_High_Byte);   	
 Send_Data_To_UART1(hb);
 
 Send_Data_To_UART1(Set_Magnetic_Declination_Low_Byte);
 Send_Data_To_UART1(lb);
}
