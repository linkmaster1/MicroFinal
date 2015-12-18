/* FinalProject 
 */

#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "main.h"

#define LMOTORA_PORT D
#define LMOTORA_LOC 6
#define LA_PWM_MATCH OCR0A

#define LMOTORB_PORT D
#define LMOTORB_LOC 5
#define LB_PWM_MATCH OCR0B

#define RMOTORA_PORT B
#define RMOTORA_LOC 3
#define RA_PWM_MATCH OCR2A

#define RMOTORB_PORT D
#define RMOTORB_LOC 3
#define RB_PWM_MATCH OCR2B

#define COAST 0x00
#define FORWARD 0x02
#define REVERSE 0x01
#define BRAKE 0x03

#define PWM_A_MASK 0xC0
#define PWM_B_MASK 0x30


void configure_motors();
uint8_t duty_to_match(uint8_t duty);
void set_left_motor_speed(uint8_t speed);
void set_right_motor_speed(uint8_t speed);
uint8_t get_left_motor_speed();
uint8_t get_right_motor_speed();
void shift_left_motor_forward();
void shift_right_motor_forward();
void shift_left_motor_reverse();
void shift_right_motor_reverse();
void shift_left_motor_brake();
void shift_right_motor_brake();
void shift_left_motor_coast();
void shift_right_motor_coast();
void configure_left_motor();
void configure_right_motor();

void turn_on_left_motor_forward();
void turn_on_left_motor_backward();
void turn_on_right_motor_forward();
void turn_on_right_motor_backward();
uint8_t get_left_motor_state();
uint8_t get_right_motor_state();

#endif