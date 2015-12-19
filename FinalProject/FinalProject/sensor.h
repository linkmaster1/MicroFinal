//Sambrit Adhikari

#ifndef _SENSOR_H
#define _SENSOR_H

#include "main.h"

#define SENSORS_PORT C
// PIN PINC
#define SENSORS_PIN 0x1F
#define SENSORA (1<<0)
#define SENSORB (1<<1)
#define SENSORC (1<<2)
#define SENSORD (1<<3)
#define SENSORE (1<<4)

bool get_SENSORA();
bool get_SENSORB();
bool get_SENSORC();
bool get_SENSORD();
bool get_SENSORE();

void configure_reflectance_sensors();
int8_t read_sensors();
bool all_white();
uint32_t get_discharge_time(uint8_t sensor);
void sensortest();

#endif
