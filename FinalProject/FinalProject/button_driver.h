#ifndef BUTTON_DRIVER_H
#define BUTTON_DRIVER_H

#include "main.h"

#define BUTTON_PIN B
#define BUTTONA_LOC 1
#define BUTTONB_LOC 4
#define BUTTONC_LOC 5

void configure_push_button_array();
bool left_button_is_pressed();
bool middle_button_is_pressed();
bool right_button_is_pressed();
bool button_pressed();

#endif
