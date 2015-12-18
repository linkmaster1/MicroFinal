#include "button_driver.h"

void configure_push_button_array()
{
	DDR(BUTTON_PIN) &= ~(1<<BUTTONA_LOC);
	DDR(BUTTON_PIN) &= ~(1<<BUTTONB_LOC);
	DDR(BUTTON_PIN) &= ~(1<<BUTTONC_LOC);
	PORT(BUTTON_PIN) |= (1<<BUTTONA_LOC);
	PORT(BUTTON_PIN) |= (1<<BUTTONB_LOC);
	PORT(BUTTON_PIN) |= (1<<BUTTONC_LOC);
}

bool left_button_is_pressed()
{
	return ~(PIN(BUTTON_PIN)|~(1<<BUTTONA_LOC));
}

bool middle_button_is_pressed()
{
	return ~(PIN(BUTTON_PIN)|~(1<<BUTTONB_LOC));
}

bool right_button_is_pressed()
{
	return ~(PIN(BUTTON_PIN)|~(1<<BUTTONC_LOC));
}

bool button_pressed()
{
	return left_button_is_pressed()|middle_button_is_pressed()|right_button_is_pressed();
}