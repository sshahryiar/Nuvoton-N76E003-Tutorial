#define TM1640_GPIO_init()								 do{P03_PushPull_Mode; P04_PushPull_Mode;}while(0)

#define DIN_pin_HIGH()                                   set_P03
#define DIN_pin_LOW()                                    clr_P03

#define SCLK_pin_HIGH()                                  set_P04
#define SCLK_pin_LOW()                                   clr_P04
                                 
#define no_of_segments                                   16
                                  
#define auto_address                                     0x40
#define fixed_address                                    0x44
#define normal_mode                                      0x40
#define test_mode                                        0x48

#define start_address                                    0xC0
                                                             
#define brightness_5_pc                                  0x88
#define brightness_10_pc                                 0x89
#define brightness_25_pc                                 0x8A
#define brightness_60_pc                                 0x8B
#define brightness_70_pc                                 0x8C
#define brightness_75_pc                                 0x8D
#define brightness_80_pc                                 0x8E
#define brightness_100_pc                                0x8F
#define display_off                                      0x80
#define display_on                                       0x8F
                                    

void TM1640_init(unsigned char brightness_level);   
void TM1640_start(void);
void TM1640_stop(void);
void TM1640_write(unsigned char value);       
void TM1640_send_command(unsigned char value);
void TM1640_send_data(unsigned char address, unsigned char value);
void TM1640_clear_display(void);