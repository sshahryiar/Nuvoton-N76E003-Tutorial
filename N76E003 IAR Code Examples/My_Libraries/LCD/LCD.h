#define LCD_GPIO_init()					   do{P00_PushPull_Mode; P01_PushPull_Mode; P10_PushPull_Mode; P11_PushPull_Mode; P12_PushPull_Mode; P13_PushPull_Mode;}while(0)

#define LCD_RS_HIGH                        set_P00
#define LCD_RS_LOW                         clr_P00

#define LCD_EN_HIGH                        set_P01
#define LCD_EN_LOW                         clr_P01

#define LCD_DB4_HIGH                       set_P10
#define LCD_DB4_LOW                        clr_P10

#define LCD_DB5_HIGH                       set_P11
#define LCD_DB5_LOW                        clr_P11

#define LCD_DB6_HIGH                       set_P12
#define LCD_DB6_LOW                        clr_P12

#define LCD_DB7_HIGH                       set_P13
#define LCD_DB7_LOW                        clr_P13

#define clear_display                      0x01
#define goto_home                          0x02

#define cursor_direction_inc               (0x04 | 0x02)
#define cursor_direction_dec               (0x04 | 0x00)
#define display_shift                      (0x04 | 0x01)
#define display_no_shift                   (0x04 | 0x00)

#define display_on                         (0x08 | 0x04)
#define display_off                        (0x08 | 0x02)
#define cursor_on                          (0x08 | 0x02)
#define cursor_off                         (0x08 | 0x00)
#define blink_on                           (0x08 | 0x01)
#define blink_off                          (0x08 | 0x00)

#define _8_pin_interface                   (0x20 | 0x10)
#define _4_pin_interface                   (0x20 | 0x00)
#define _2_row_display                     (0x20 | 0x08)
#define _1_row_display                     (0x20 | 0x00)
#define _5x10_dots                         (0x20 | 0x40)
#define _5x7_dots                          (0x20 | 0x00)

#define DAT                                1
#define CMD                                0


void LCD_init(void);
void LCD_send(unsigned char value, unsigned char mode);
void LCD_4bit_send(unsigned char lcd_data);
void LCD_putstr(char *lcd_string);
void LCD_putchar(char char_data);
void LCD_clear_home(void);
void LCD_goto(unsigned char x_pos, unsigned char y_pos);
void toggle_EN_pin(void);
