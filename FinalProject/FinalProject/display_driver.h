
#ifndef DISPLAY_DRIVER_H
#define DISPLAY_DRIVER_H
#include "main.h"


#define BUSY_FLAG (1<<7)
#define RS_PORT D
#define RW_PORT B
#define E_PORT D
#define DB0_PORT B
#define DB1_PORT B
#define DB2_PORT B
#define DB3_PORT D

#define RS_LOC 2
#define RW_LOC 0
#define E_LOC 4
#define DB0_LOC 1
#define DB1_LOC 4
#define DB2_LOC 5
#define DB3_LOC 7

void lcd_initialize();
void lcd_goto_xy1(uint8_t row, uint8_t col);
void lcd_erase();
void lcd_putc(const char x);
void lcd_puts(const char *str);
void lcd_display_on();
void lcd_display_off();

#endif
