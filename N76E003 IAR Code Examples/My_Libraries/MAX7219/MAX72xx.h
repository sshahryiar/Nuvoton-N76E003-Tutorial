#define MAX72xx_SPI_GPIO_init()   	do{P00_PushPull_Mode; P10_PushPull_Mode; P11_PushPull_Mode;}while(0)

#define MAX72xx_CS_OUT_HIGH()				set_P11
#define MAX72xx_CS_OUT_LOW()				clr_P11

#define NOP													0x00
#define DIG0												0x01
#define DIG1												0x02
#define DIG2												0x03
#define DIG3												0x04
#define DIG4												0x05
#define DIG5												0x06
#define DIG6												0x07
#define DIG7												0x08
#define decode_mode_reg							0x09
#define intensity_reg								0x0A
#define scan_limit_reg							0x0B
#define shutdown_reg								0x0C
#define display_test_reg						0x0F

#define shutdown_cmd								0x00
#define run_cmd											0x01

#define no_test_cmd               	0x00
#define test_cmd                  	0x01
                             
#define digit_0_only								0x00
#define digit_0_to_1								0x01
#define digit_0_to_2								0x02
#define digit_0_to_3								0x03
#define digit_0_to_4								0x04
#define digit_0_to_5								0x05
#define digit_0_to_6								0x06
#define digit_0_to_7								0x07
                                                  
#define No_decode_for_all						0x00
#define Code_B_decode_digit_0				0x01
#define Code_B_decode_digit_0_to_3	0x0F	
#define Code_B_decode_for_all				0xFF


void MAX72xx_SPI_HW_Init(unsigned char clk_value);
void MAX72xx_init(void);
void MAX72xx_write(unsigned char address, unsigned char value);
