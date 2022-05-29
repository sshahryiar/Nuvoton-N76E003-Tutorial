#include "SW_I2C.h"


#define PCF8574_address                 0x4E

#define PCF8574_write_cmd               PCF8574_address
#define PCF8574_read_cmd                (PCF8574_address | 1)


void PCF8574_init(void);
unsigned char PCF8574_read(void);
void PCF8574_write(unsigned char data_byte);
