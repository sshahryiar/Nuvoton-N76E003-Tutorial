#define HIGH								1
#define LOW									0

#define TRUE								1
#define FALSE								0

#define YES									1
#define NO									0

#define ENABLE								1
#define DISABLE								0

#define osc_freq_in_MHz    					16
#define osc_scalar         					(16 / osc_freq_in_MHz) 

#define HIRC								0
#define LIRC	    						1
#define ECLK								2

#define bit_set(reg, bit_val)               reg |= (1 << bit_val)
#define bit_clr(reg, bit_val)               reg &= (~(1 << bit_val))
#define bit_tgl(reg, bit_val)               reg ^= (1 << bit_val)
#define get_bit(reg, bit_val)               (reg & (1 << bit_val))
#define get_reg(reg, msk)                   (reg & msk)      

#define  CID_READ            				0x0B
#define  DID_READ            				0x0C

#define  PAGE_ERASE_AP       				0x22
#define  BYTE_READ_AP        				0x00
#define  BYTE_PROGRAM_AP     				0x21
#define  PAGE_SIZE           				128

#define  ERASE_FAIL          				0x70
#define  PROGRAM_FAIL        				0x71
#define  IAPFF_FAIL          				0x72
#define  IAP_PASS            				0x00

#define regular_I2C_pins					0
#define alternate_I2C_pins					1

#define regular_I2C_GPIOs()					do{P13_OpenDrain_Mode; P14_OpenDrain_Mode; clr_I2CPX;}while(0)
#define alternative_I2C_GPIOs()				do{P02_OpenDrain_Mode; P16_OpenDrain_Mode; set_I2CPX;}while(0)

#define I2C_GPIO_Init(mode)					do{if(mode != 0){alternative_I2C_GPIOs();}else{regular_I2C_GPIOs();}}while(0)

#define I2C_CLOCK							0x27 //Fclk = Fsys / (4*(prescalar + 1))

#define I2C_ACK								0
#define I2C_NACK							1

#define timeout_count						1000

#define SPI_clock_rate_8Mbps				0x00 
#define SPI_clock_rate_4Mbps				0x01 
#define SPI_clock_rate_2Mbps				0x02 
#define SPI_clock_rate_1Mbps				0x03 

#define SPI_Mode_1							0x00
#define SPI_Mode_2							0x04
#define SPI_Mode_3							0x08
#define SPI_Mode_4							0x0C

#define set_SPI_mode(value)                 do{SPCR &= 0xF3; SPCR |= value;}while(0)
#define set_SPI_clock_rate(value)           do{SPCR &= 0xFC; SPCR |= value;}while(0)

#define TA_protection_disable()             do{TA = 0xAA; TA = 0x55}while(0)

#define WDT_6ms                             0x00
#define WDT_26ms                            0x01
#define WDT_51ms                            0x02
#define WDT_102ms                           0x03
#define WDT_204ms                           0x04
#define WDT_409ms                           0x05
#define WDT_810ms                           0x06
#define WDT_1638ms                          0x07


void delay_us(unsigned int value);
void delay_ms(unsigned int value);

void set_clock_source(unsigned char clock_source);
void disable_clock_source(unsigned char clock_source);
void set_clock_division_factor(unsigned char value);
void set_system_clock_frequency(unsigned long F_osc, unsigned long F_sys);
void setup_clock(unsigned long F_osc, unsigned long F_sys, unsigned char clock_source, unsigned char clock_source_to_disable);

void set_Timer_0_for_Mode_0(unsigned int value);
unsigned int get_Timer_0_for_Mode_0(void);
void set_Timer_0_for_Mode_0(unsigned int value);
unsigned int get_Timer_0_for_Mode_1(void);

void set_Timer_1_for_Mode_0(unsigned int value);
unsigned int get_Timer_1_for_Mode_0(void);
void set_Timer_1_for_Mode_0(unsigned int value);
unsigned int get_Timer_0_for_Mode_1(void);

void set_Timer_2(unsigned int value);
unsigned int get_Timer_2(void);

void set_Timer_2_reload_compare(unsigned int value);
unsigned int get_Timer_2_reload_compare(void);

void set_Timer_3(unsigned int value);
unsigned int get_Timer_3(void);

void set_capture_0(unsigned int value);
unsigned int get_capture_0(void);
void set_capture_1(unsigned int value);
unsigned int get_capture_1(void);
void set_capture_2(unsigned int value);
unsigned int get_capture_2(void);

void set_PWM_period_count(unsigned int value);
void set_PWM0(unsigned int value);
void set_PWM1(unsigned int value);
void set_PWM2(unsigned int value);
void set_PWM3(unsigned int value);
void set_PWM4(unsigned int value);
void set_PWM5(unsigned int value);
void set_complementary_PWM_dead_time(unsigned int value);

void setup_WDT(unsigned char WDT_time);
void setup_WKT(unsigned char status, unsigned char reload_value, unsigned char clk_prescalar);

unsigned int ADC_read(void);
void set_ADC_comparator_value(unsigned int value);

void enable_IAP_mode(void);
void disable_IAP_mode(void);
void trigger_IAP(void);
unsigned char write_data_to_one_page(unsigned int u16_addr, const unsigned char *pDat, unsigned char num);
void write_data_flash(unsigned int u16_addr, unsigned char *pDat, unsigned int num);
void read_data_flash(unsigned int u16_addr, unsigned char *pDat, unsigned int num);

void I2C_init(void);
void I2C_start(void);
void I2C_stop(void);
unsigned char I2C_read(unsigned char ack_mode);
void I2C_write(unsigned char value);

void SPI_init(unsigned char clk_speed, unsigned char mode);
unsigned char SPI_transfer(unsigned char write_value);
