#ifndef _MAIN_H_
#define _MAIN_H_

# define F_CPU 1000000UL

#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <stdbool.h>

#define CONCATENATE(type,letter) type##letter
#define DDR(letter)  CONCATENATE(DDR,letter)
#define PORT(letter) CONCATENATE(PORT,letter)
#define PIN(letter)  CONCATENATE(PIN,letter)


#include "sensor.h"
#include "buzzer.h"
#include "motor_driver.h"
#include "button_driver.h"
#include "display_driver.h"
#include <pololu/3pi.h>

#endif 


