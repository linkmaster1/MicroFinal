/* FinalProject 
 * Sambrit Adhikari
 */

#include "main.h"
#include<pololu/3pi.h>

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
	sensortest();

	lcd_puts("Final");
	lcd_goto_xy(0,1);
	lcd_puts("Project");
	

	
	
	while(1){
		//time = get_discharge_time(1);
		//print_hex(time);
		//get_sensor_location();
		/*
		time = get_discharge_time(1);
		lcd_goto_xy(0,0);
		itoa(time,val,10);
		lcd_puts(val);
		*/
	}
	
return 0;

}

	


