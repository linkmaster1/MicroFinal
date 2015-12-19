
#include "display_driver.h"
#include <stdbool.h>
#include <avr/io.h>
#include <stdint.h>

#include <util/delay.h>

static void set_RS();
static void set_RW();
static void set_E();
static void set_DB0();
static void set_DB1();
static void set_DB2();
static void set_DB3();

static void clear_RS();
static void clear_RW();
static void clear_E();
static void clear_DB0();
static void clear_DB1();
static void clear_DB2();
static void clear_DB3();

static bool get_DB0();
static bool get_DB1();
static bool get_DB2();
static bool get_DB3();
static void busywait();
static void setup_RS_RW_E();
static void set_DB_input();
static void set_DB_output();


static uint8_t pulse_E();
static uint8_t read_register( bool reg );
static void busywait();
static void nibble_out(uint8_t num);
static void write_reg(uint8_t num, uint8_t rs);


void lcd_initialize()
{
	clear_RW();
	clear_E();
	clear_RS();
	setup_RS_RW_E();
	set_DB_output();
	
	_delay_ms(10);
	nibble_out(0x3);
	_delay_ms(10);
	nibble_out(0x3);
	_delay_ms(10);
	nibble_out(0x3);
	_delay_ms(10);
	nibble_out(0x2);
	busywait();
	write_reg(0x28,0);
	write_reg(0x08,0);
	write_reg(0x01,0);
	write_reg(0x06,0);
}

void lcd_goto_xy1(uint8_t col, uint8_t row)
{
	uint8_t num=0x80;
	row = row%2;
	col = col%8;
	if(row==1) num |= (1<<6);
	num |= col;
	write_reg(num,0);
}

void lcd_erase()
{
	write_reg(0x01,0);
}

static uint8_t pulse_E()
{
	uint8_t num=0;
	set_E();
	_delay_ms(10);
	if(get_DB0()) num |= (1<<0);
	if(get_DB1()) num|= (1<<1);
	if(get_DB2()) num |= (1<<2);
	if(get_DB3()) num |= (1<<3);
	clear_E();
	return num;
}
static uint8_t read_register( bool reg )
{
	uint8_t num;
	if(reg) set_RS();
	else clear_RS();
	_delay_ms(10);
	set_DB_input();
	set_RW();
	num = (pulse_E()<<4);
	num |= pulse_E();
	return num;
	
}
static void busywait()
{
	uint8_t num;
	do
	{
		num=read_register(0);
	}
	while(num&(BUSY_FLAG));

}
static void nibble_out(uint8_t num)
{
	if(num&(1<<0)) set_DB0();
	else clear_DB0();
	if(num&(1<<1)) set_DB1();
	else clear_DB1();
	if(num&(1<<2)) set_DB2();
	else clear_DB2();
	if(num&(1<<3)) set_DB3();
	else clear_DB3();
	pulse_E();
}
static void write_reg(uint8_t num, uint8_t rs)
{
	busywait();
	clear_RW();
	if(rs) set_RS();
	else clear_RS();
	set_DB_output();
	nibble_out(num>>4);
	nibble_out(num);
	set_DB_input();
}

void lcd_display_on()
{
	write_reg(0x0C, 0);
}

void lcd_display_off()
{
	write_reg(0x08,0);
}


void lcd_putc(const char x)
{
	write_reg(x,1);
}

void lcd_puts(const char *str)
{
	while(*str) lcd_putc(*str++);
}

static void setup_RS_RW_E()
{
	DDR(RS_PORT) |= (1<<RS_LOC);
	DDR(RW_PORT) |= (1<<RW_LOC);
	DDR(E_PORT) |= (1<<E_LOC);
}

static void set_DB_input()
{
	DDR(DB0_PORT) &= ~(1<<DB0_LOC);
	DDR(DB1_PORT) &= ~(1<<DB1_LOC);
	DDR(DB2_PORT) &= ~(1<<DB2_LOC);
	DDR(DB3_PORT) &= ~(1<<DB3_LOC);
	PORT(DB0_PORT) |= (1<<DB0_LOC);
	PORT(DB1_PORT) |= (1<<DB1_LOC);
	PORT(DB2_PORT) |= (1<<DB2_LOC);
	PORT(DB3_PORT) |= (1<<DB3_LOC);
}

static void set_DB_output()
{
	DDR(DB0_PORT) |= (1<<DB0_LOC);
	DDR(DB1_PORT) |= (1<<DB1_LOC);
	DDR(DB2_PORT) |= (1<<DB2_LOC);
	DDR(DB3_PORT) |= (1<<DB3_LOC);
}

static bool get_DB1()
{
	return PIN(DB1_PORT)&(1<<DB1_LOC);
}

static bool get_DB2()
{
	return PIN(DB2_PORT)&(1<<DB2_LOC);
}

static bool get_DB3()
{
	return PIN(DB3_PORT)&(1<<DB3_LOC);
}

static void set_RS()
{
	PORT(RS_PORT) |= (1<<RS_LOC);
}

static void set_RW()
{
	PORT(RW_PORT) |= (1<<RW_LOC);
}

static void clear_RS()
{
	PORT(RS_PORT) &= ~(1<<RS_LOC);
}

static void clear_RW()
{
	PORT(RW_PORT) &= ~(1<<RW_LOC);
}

static void clear_E()
{
	PORT(E_PORT) &= ~(1<<E_LOC);
}

static void clear_DB0()
{
	PORT(DB0_PORT) &= ~(1<<DB0_LOC);
}

static void clear_DB1()
{
	PORT(DB1_PORT) &= ~(1<<DB1_LOC);
}

static void set_E()
{
	PORT(E_PORT) |= (1<<E_LOC);
}

static bool get_DB0()
{
	return PIN(DB0_PORT)&(1<<DB0_LOC);
}
static void set_DB0()
{
	PORT(DB0_PORT) |= (1<<DB0_LOC);
}

static void set_DB1()
{
	PORT(DB1_PORT) |= (1<<DB1_LOC);
}

static void set_DB2()
{
	PORT(DB2_PORT) |= (1<<DB2_LOC);
}

static void set_DB3()
{
	PORT(DB3_PORT) |= (1<<DB3_LOC);
}

static void clear_DB2()
{
	PORT(DB2_PORT) &= ~(1<<DB2_LOC);
}

static void clear_DB3()
{
	PORT(DB3_PORT) &= ~(1<<DB3_LOC);
}


