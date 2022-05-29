#define Get_Angular_Measurement						 0x31
#define Start_Calibration							 0xC0  
#define End_Calibration							 0xC1                      
#define Set_Magnetic_Declination_High_Byte					 0x03   
#define Set_Magnetic_Declination_Low_Byte					 0x04
                                                                                                                                                               
#define no_of_data_bytes_returned               				 0x08

#define calibration_LED													   P15
                                                                       

void read_heading(void);
void calibrate_compass(void);  
void factory_reset(void);
void set_declination_angle(unsigned long angle);
