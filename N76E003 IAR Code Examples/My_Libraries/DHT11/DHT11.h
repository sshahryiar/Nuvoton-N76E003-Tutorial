#define HIGH  				1
#define LOW 				0

#define DHT11_pin_init()     		P05_Quasi_Mode		

#define DHT11_pin_HIGH()                     set_P05
#define DHT11_pin_LOW()                      clr_P05

#define DHT11_pin_IN()   			P05				


void DHT11_init();
unsigned char get_byte();
unsigned char get_data();
