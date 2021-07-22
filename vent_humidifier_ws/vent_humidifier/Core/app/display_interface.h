/*
 * display_interface.h
 *
 *  Created on: 31 may. 2021
 *      Author: mtorres
 */

#ifndef DISPLAY_INTERFACE_H_
#define DISPLAY_INTERFACE_H_

/* File inclusion */
#include <stdint.h>
#include <math.h>
#include "project_defines.h"
#include "global.h"
#include "main.h"
#include "MT_display_7_segmentos.h"
#include "temperature_measurement.h"
#include "mt_debounce.h"

/* Function declaration */
void Display_Interface_Show_Temp(float temp);
void Display_Interface_Show_High_Temp_Message(void);
void Display_Interface_Show_Low_Temp_Message(void);
void Display_Interface_Show_No_Probe_Message(void);
void Display_Interface_Show_Diagnostics_Message(void);
void Display_Interface_Show_Error_Message(void);
void Display_Update(void);

void Display_Temperature_Scan(void);

#endif /* APP_DISPLAY_INTERFACE_H_ */
