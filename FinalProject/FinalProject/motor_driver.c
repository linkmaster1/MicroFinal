/* FinalProject 
 */

#include "main.h"

static void set_LA();
static void clear_LA();
static void set_LB();
static void clear_LB();
static void set_RA();
static void clear_RA();
static void set_RB();
static void clear_RB();

static void enable_PWM_LA();
static void disable_PWM_LA();
static void enable_PWM_LB();
static void disable_PWM_LB();
static void enable_PWM_RA();
static void disable_PWM_RA();
static void enable_PWM_RB();
static void disable_PWM_RB();

static bool get_LA_PWM();
static bool get_LB_PWM();
static bool get_RA_PWM();
static bool get_RB_PWM();

void pidcoltrol()
{
	//uint32_t val = get_sensor_value(); 
	
}

void configure_motors(){
	
	 configure_left_motor();
	 configure_right_motor();
}

void configure_left_motor()
{
	DDR(LMOTORA_PORT) |= (1<<LMOTORA_LOC);
	DDR(LMOTORB_PORT) |= (1<<LMOTORB_LOC);
	TCCR0A = 0x03;
	TCCR0B = ((TCCR0B&0xC0)|0x01);
}

void configure_right_motor()
{
	DDR(RMOTORA_PORT) |= (1<<RMOTORA_LOC);
	DDR(RMOTORB_PORT) |= (1<<RMOTORB_LOC);
	TCCR2A = 0x03;
	TCCR2B = ((TCCR2B&0xC0)|0x01);
}

void set_left_motor_speed(uint8_t speed)
{
	if(speed<5) speed=0;
	LA_PWM_MATCH = duty_to_match(speed);
	LB_PWM_MATCH = duty_to_match(speed);
}

void set_right_motor_speed(uint8_t speed)
{
	if(speed<5) speed=0;
	RA_PWM_MATCH = duty_to_match(speed);
	RB_PWM_MATCH = duty_to_match(speed);
}

uint8_t get_left_motor_speed()
{
	if(get_LA_PWM())return LA_PWM_MATCH;
	else if (get_LB_PWM())
	{
		 return LB_PWM_MATCH;
	}
}

uint8_t get_right_motor_speed()
{
	if(get_RA_PWM()) return RA_PWM_MATCH;
	else if (get_RB_PWM()) return RB_PWM_MATCH;
}

void shift_left_motor_forward()
{
	disable_PWM_LA();
	set_LA();
	enable_PWM_LB();
}

void shift_right_motor_forward()
{
	disable_PWM_RA();
	set_RA();
	enable_PWM_RB();
}

void shift_left_motor_reverse()
{
	disable_PWM_LB();
	set_LB();
	enable_PWM_LA();
}

void shift_right_motor_reverse()
{
	disable_PWM_RB();
	set_RB();
	enable_PWM_RA();
}

void shift_left_motor_brake()
{
	disable_PWM_LA();
	disable_PWM_LB();
	set_LA();
	set_LB();
}

void shift_right_motor_brake()
{
	disable_PWM_RA();
	disable_PWM_RB();
	set_RA();
	set_RB();
}

void shift_left_motor_coast()
{
	disable_PWM_LA();
	disable_PWM_LB();
	clear_LA();
	clear_LB();
}

void shift_right_motor_coast()
{
	disable_PWM_RA();
	disable_PWM_RB();
	clear_RA();
	clear_RB();
}

uint8_t duty_to_match(uint8_t duty)
{
	if(duty>=0&&duty<=100) return duty*2.55;
	else return (duty%100)*2.55;
}





void turn_on_left_motor_reverse()
{
	disable_PWM_LA();
	disable_PWM_LB();
	clear_LA();
	set_LB();
}

void turn_on_left_motor_forward()
{
	disable_PWM_LA();
	disable_PWM_LB();
	set_LA();
	clear_LB();
}

void turn_on_right_motor_reverse()
{
	disable_PWM_RA();
	disable_PWM_RB();
	clear_RA();
	set_RB();
}

void turn_on_right_motor_forward()
{
	disable_PWM_RA();
	disable_PWM_RB();
	set_RA();
	clear_RB();
}


uint8_t get_left_motor_state()
{
	uint8_t a = (PIN(LMOTORA_PORT)&(1<<LMOTORA_LOC))>>(LMOTORA_LOC -1);
	uint8_t b = (PIN(LMOTORB_PORT)&(1<<LMOTORB_LOC))>>(LMOTORB_LOC);
	return a|b;
}

uint8_t get_right_motor_state()
{
	uint8_t a = (PIN(RMOTORA_PORT)&(1<<RMOTORA_LOC))>>(RMOTORA_LOC -1);
	uint8_t b = (PIN(RMOTORB_PORT)&(1<<RMOTORB_LOC))>>(RMOTORB_LOC);
	return a|b;
}





static void set_LA()
{	PORT(LMOTORA_PORT) |= (1<<LMOTORA_LOC);}
static void clear_LA()
{	PORT(LMOTORA_PORT) &= ~(1<<LMOTORA_LOC);}
static void set_LB()
{	PORT(LMOTORB_PORT) |= (1<<LMOTORB_LOC);}
static void clear_LB()
{	PORT(LMOTORB_PORT) &= ~(1<<LMOTORB_LOC);}
static void set_RA()
{	PORT(RMOTORA_PORT) |= (1<<RMOTORA_LOC);}
static void clear_RA()
{	PORT(RMOTORA_PORT) &= ~(1<<RMOTORA_LOC);}
static void set_RB()
{	PORT(RMOTORB_PORT) |= (1<<RMOTORB_LOC);}
static void clear_RB()
{	PORT(RMOTORB_PORT) &= ~(1<<RMOTORB_LOC);}
static void enable_PWM_LA()
{	TCCR0A |= PWM_A_MASK;}
static void disable_PWM_LA()
{	TCCR0A &= ~PWM_A_MASK;}
static void enable_PWM_LB()
{	TCCR0A |= PWM_B_MASK;}
static void disable_PWM_LB()
{	TCCR0A &= ~PWM_B_MASK;}
static void enable_PWM_RA()
{	TCCR2A |= PWM_A_MASK;}
static void disable_PWM_RA()
{	TCCR2A &= ~PWM_A_MASK;}
static void enable_PWM_RB()
{	TCCR2A |= PWM_B_MASK;}
static void disable_PWM_RB()
{	TCCR2A &= ~PWM_B_MASK;}
static bool get_LA_PWM()
{	return TCCR0A &= PWM_A_MASK;}
static bool get_LB_PWM()
{	return TCCR0A &= PWM_B_MASK;}
static bool get_RA_PWM()
{	return TCCR2A &= PWM_A_MASK;}
static bool get_RB_PWM()
{	return TCCR2A &= PWM_B_MASK;}
