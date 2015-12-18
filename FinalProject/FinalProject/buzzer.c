/* FinalProject 
 */

#include "main.h"

void init_buzzer(){
	DDR(BUZZER_PORT) |= (BUZZER_PIN);
	TIMER1_CLK |= ( (1<<0)	| (1<<4) | (1<<5) );
	TIMER2_CLK |= (1<<4);
}
void playFrequency(uint32_t freq, uint8_t dur)
{
	if (freq < 40) freq = 40;	
	if (freq > 10000) freq = 10000;    
 
	uint32_t top = (F_CPU/freq);
	TIMER2_CLK |= (1<<0);
	OCR1A = top;	
	OCR1B = (top>>2);
	
	uint8_t i;
	for (i=0;i<dur; i++){
		
		_delay_ms(500);
	}
	TIMER2_CLK &= ~(1<<0);
	//OCR2A = (freq>>1);                        // set timer 2 pwm frequency
	//OCR2B = freq; 

}


void testtone()
{
	uint32_t x;
	for (x=0;x<500;x++)
	{
		playFrequency(400, 5);
		//x+=5;
		_delay_ms(20);
		
	}

}