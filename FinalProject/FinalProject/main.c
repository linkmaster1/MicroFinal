/* FinalProject 
 * Sambrit Adhikari
 */

#include "main.h"

int main()
{
	lcd_initialize();
	lcd_display_on();
	configure_left_motor();
	configure_right_motor();
	init_buzzer();
	configure_reflectance_sensors();
	configure_push_button_array();
	
	playFrequency(500,1); //Code Uploaded
	
	lcd_puts("Final");
	lcd_goto_xy(0,1);
	lcd_puts("Project");
	
	uint32_t time;
	char val[36];
	
	//sensortest();
	while(1){
		//demo_sensors();
		/*
		time = get_discharge_time(1);
		lcd_goto_xy(0,0);
		itoa(time,val,10);
		lcd_puts(val);
		*/
	}
	
return 0;

}

	


