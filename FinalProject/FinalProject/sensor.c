#include "sensor.h"

void configure_reflectance_sensors()
{
	DDR(SENSORS_PORT) &= ~SENSORS_PIN;
	PORT(SENSORS_PORT) |= SENSORS_PIN;
}

int8_t get_sensor_location()
{
	int8_t pos = 0;
	uint8_t i = 0;
	if(get_SENSORA())
	{	
		pos-=100;
		i++;
	}
	if(get_SENSORB())
	{
		pos-=30;
		i++;
	}
	if(get_SENSORC())
	{	pos+=0;
		i++;
	}
	if(get_SENSORD())
	{
		pos+=30;
		i++;
	}
	if(get_SENSORE())
	{
		pos+=100;
		i++;
	}
	else if(all_white())
	{
		pos=-128;
		i=1;
	}
	return pos/i;
}

void sensortest(){
	
	configure_left_motor();
	configure_right_motor();

	set_left_motor_speed(15);
	set_right_motor_speed(15);
	
	shift_right_motor_forward();
	shift_left_motor_forward();
	
	while(1)
	{
		int8_t sens = get_sensor_location();
		if(sens!=-128)
		{
			set_left_motor_speed((1500+15*(sens))/100);
			set_right_motor_speed((1500-15*(sens))/100);
		}
	}

}

bool all_white()
{
	return !(PIN(SENSORS_PORT)&SENSORS_PIN);
}

bool get_SENSORA()
{
		return PIN(SENSORS_PORT)&(SENSORA);
}
bool get_SENSORB()
{	
	return PIN(SENSORS_PORT)&(SENSORB);
	}
bool get_SENSORC()
{	
	return PIN(SENSORS_PORT)&(SENSORC);
}
bool get_SENSORD()
{	
	return PIN(SENSORS_PORT)&(SENSORD);
}
bool get_SENSORE()
{	
	return PIN(SENSORS_PORT)&(SENSORE);
	}
	
void irledon()
{
	DDR(SENSORS_PORT) = (1<<5);
	PORT(SENSORS_PORT) = (1<<5);
	_delay_ms(10);
}


uint32_t get_discharge_time(uint8_t sensor)
{
	irledon();
	uint32_t thresh = 5000;
	uint32_t time = 0;
	
	DDR(SENSORS_PORT) |= (1<<sensor); //Outputs
	PORT(SENSORS_PORT) |= (1<<sensor); //Charging Sensor A
	_delay_us(10);
	DDR(SENSORS_PORT) &= ~(1<<sensor); // As output
	PORT(SENSORS_PORT) &= ~(1<<sensor); //Disabling Pull up
	
//	while( ((PIN(SENSORS_PORT)& SENSORS_PIN)) != 0)
	while(( (PIN(SENSORS_PORT)& (1<<sensor))) != 0)
	{
		_delay_ms(1);
		time++;
		if (time>thresh) break;
	}
	return time;
	
}
