#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "soft_delay.h"
#include "Delay.h"
#include "PCF8574.h"


void PCF8574_init(void)
{
    SW_I2C_init();
    delay_ms(10);
}


unsigned char PCF8574_read(void)
{
    unsigned char port_byte = 0;

    SW_I2C_start();
    SW_I2C_write(PCF8574_read_cmd);
    port_byte = SW_I2C_read(I2C_NACK);
    SW_I2C_stop();

    return port_byte;
}


void PCF8574_write(unsigned char data_byte)
{
    SW_I2C_start();
    SW_I2C_write(PCF8574_write_cmd);
    SW_I2C_ACK_NACK(I2C_ACK);
    SW_I2C_write(data_byte);
    SW_I2C_ACK_NACK(I2C_ACK);
    SW_I2C_stop();
}
