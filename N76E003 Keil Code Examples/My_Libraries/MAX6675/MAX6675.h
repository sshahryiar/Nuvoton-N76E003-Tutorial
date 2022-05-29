#define MAX6675_SPI_GPIO_init() do{P01_Input_Mode; P10_PushPull_Mode; P12_PushPull_Mode;}while(0)

#define MAX6675_CS_OUT_HIGH()		set_P12
#define MAX6675_CS_OUT_LOW()		clr_P12

#define T_min             			0
#define T_max              			1024

#define count_max          			4096

#define no_of_pulses       			16

#define deg_C              			0
#define deg_F              			1
#define tmp_K              			2

#define open_contact       			0x04
#define close_contact      			0x00

#define scalar_deg_C       			0.25
#define scalar_deg_F_1     			1.8
#define scalar_deg_F_2     			32.0
#define scalar_tmp_K       			273.0

#define no_of_samples      			16


void MAX6675_SPI_HW_Init(unsigned char clk_value);
void MAX6675_init(void);
unsigned char MAX6675_get_ADC(unsigned int *ADC_data);
float MAX6675_get_T(unsigned int ADC_value, unsigned char T_unit);