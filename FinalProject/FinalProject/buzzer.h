/* FinalProject 
 */
#ifndef _BUZZER_H_
#define _BUZZER_H_

#include "main.h"

#define BUZZER_PORT B
#define BUZZER_PIN (1 << 2)

#define TIMER1_CLK  TCCR1A
#define TIMER2_CLK  TCCR1B


void playFrequency(uint32_t freq, uint8_t dur);
void init_buzzer();
void testtone();
#endif