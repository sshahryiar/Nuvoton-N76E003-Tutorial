#define SDA_DIR_OUT()   P03_PushPull_Mode
#define SDA_DIR_IN()    P03_Input_Mode

#define SCL_DIR_OUT()   P04_PushPull_Mode
#define SCL_DIR_IN()    P04_Input_Mode

#define SDA_HIGH()      set_P03
#define SDA_LOW()       clr_P03

#define SCL_HIGH()      set_P04
#define SCL_LOW()       clr_P04

#define SDA_IN()        P03

#define I2C_ACK         0xFF
#define I2C_NACK        0x00

#define I2C_timeout     1000


void SW_I2C_init(void);
void SW_I2C_start(void);
void SW_I2C_stop(void);
unsigned char SW_I2C_read(unsigned char ack);
void SW_I2C_write(unsigned char value);
void SW_I2C_ACK_NACK(unsigned char mode);
unsigned char SW_I2C_wait_ACK(void);
