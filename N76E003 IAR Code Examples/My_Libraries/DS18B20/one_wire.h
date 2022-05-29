#define DS18B20_GPIO_init()				P06_OpenDrain_Mode

#define DS18B20_IN()							P06

#define DS18B20_OUT_LOW()				  clr_P06
#define DS18B20_OUT_HIGH()				set_P06

#define TRUE                      1
#define FALSE                     0


unsigned char onewire_reset(void); 
void onewire_write_bit(unsigned char bit_value);
unsigned char onewire_read_bit(void);
void onewire_write(unsigned char value);    
unsigned char onewire_read(void);
