/*
 * temperature_measurement.h
 *
 * Created: 26/05/2021 08:56:07
 *  Author: mtorres
 */ 


#ifndef TEMPERATURE_MEASUREMENT_H_
#define TEMPERATURE_MEASUREMENT_H_

/* File inclusion */
#include "main.h"
#include <stdint.h>
#include "project_defines.h"
#include "global.h"
#include "MT_rtd.h"
#include "MT_ntc.h"
#include "MT_filters.h"


/* Function declaration */

void Temp_Sensor_Input_Voltage_Measure(void);
void Chamber_Temperature_Measure(void);
void Airway_Temperature_Measure(void);
void Heater_Plate_Temperature_Measure(void);

float Chamber_Temperature_Get(void);
float Airway_Temperature_Get(void);
float Heater_Plate_Temperature_Get(void);
float Temp_Sensor_Input_Voltage_Get(void);

#endif /* TEMPERATURE_MEASUREMENT_H_ */
