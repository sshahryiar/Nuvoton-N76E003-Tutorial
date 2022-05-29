#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "SW_I2C.h"


void SW_I2C_init(void)
{
    SDA_DIR_OUT();
    SCL_DIR_OUT();
    Timer0_Delay100us(1);
    SDA_HIGH();
    SCL_HIGH();
}


void SW_I2C_start(void)
{
    SDA_DIR_OUT();
    SDA_HIGH();
    SCL_HIGH();
    Timer3_Delay10us(4);
    SDA_LOW();
    Timer3_Delay10us(4);
    SCL_LOW();
}


void SW_I2C_stop(void)
{
    SDA_DIR_OUT();
    SDA_LOW();
    SCL_LOW();
    Timer3_Delay10us(4);
    SDA_HIGH();
    SCL_HIGH();
    Timer3_Delay10us(4);
}


unsigned char SW_I2C_read(unsigned char ack)
{
    unsigned char i = 8;
    unsigned char j = 0;

    SDA_DIR_IN();

    while(i > 0)
    {
        SCL_LOW();
        Timer3_Delay10us(2);
        SCL_HIGH();
        Timer3_Delay10us(2);
        j <<= 1;

        if(SDA_IN() != 0x00)
        {
            j++;
        }

        Timer3_Delay10us(1);
        i--;
    };

    switch(ack)
    {
        case I2C_ACK:
        {
            SW_I2C_ACK_NACK(I2C_ACK);;
            break;
        }
        default:
        {
            SW_I2C_ACK_NACK(I2C_NACK);;
            break;
        }
    }

    return j;
}


void SW_I2C_write(unsigned char value)
{
    unsigned char i = 8;

    SDA_DIR_OUT();
    SCL_LOW();

    while(i > 0)
    {

        if(((value & 0x80) >> 7) != 0x00)
        {
            SDA_HIGH();
        }
        else
        {
            SDA_LOW();
        }


        value <<= 1;
        Timer3_Delay10us(2);
        SCL_HIGH();
        Timer3_Delay10us(2);
        SCL_LOW();
        Timer3_Delay10us(2);
        i--;
    };
}


void SW_I2C_ACK_NACK(unsigned char mode)
{
    SCL_LOW();
    SDA_DIR_OUT();

    switch(mode)
    {
        case I2C_ACK:
        {
            SDA_LOW();
            break;
        }
        default:
        {
            SDA_HIGH();
            break;
        }
    }

    Timer3_Delay10us(2);
    SCL_HIGH();
    Timer3_Delay10us(2);
    SCL_LOW();
}


unsigned char SW_I2C_wait_ACK(void)
{
    signed int timeout = 0;

    SDA_DIR_IN();

    SDA_HIGH();
    Timer3_Delay10us(1);
    SCL_HIGH();
    Timer3_Delay10us(1);

    while(SDA_IN() != 0x00)
    {
        timeout++;

        if(timeout > I2C_timeout)
        {
            SW_I2C_stop();
            return 1;
        }
    };

    SCL_LOW();
    return 0;
}
