/*
 * vent_humidifier.h
 *
 * Created: 6/05/2021 11:37:39
 *  Author: mtorres
 */ 


#ifndef VENT_HUMIDIFIER_H_
#define VENT_HUMIDIFIER_H_

/* File inclusion */
#include <stdint.h>
#include <temperature_controller.h>
#include "project_defines.h"
#include "global.h"
#include "MT_filters.h"
#include "MT_display_7_segmentos.h"
#include "MT_rtd.h"
#include "mt_debounce.h"
#include "display_interface.h"
#include "heater_manager.h"
#include "temperature_measurement.h"
#include "alarm_manager.h"
#include "heater_plate_feedback.h"
#include "fuzzy_controller_basic.h"


/* Function declaration */
void Buzzer_Initialize(void);
void Heaters_Initialize(void);
void LEDs_Initialize(void);
void System_Initialize(void);

uint8_t Internal_Self_Test_Sequence(void);
uint8_t Test_Heater_Wire_Presence(void);
uint8_t Test_Heater_Plate_SCR(void);
uint8_t Test_Temperature_Probe(void);
uint8_t Visual_Audio_Test_Sequence(void);

uint8_t Get_Heater_Wire_01_State(void);
uint8_t Get_Heater_Wire_02_State(void);

void System_Power_On_Sequence(void);
void System_Test_Sequence(void);
void System_Working_Sequence(void);
void System_Power_Off_Sequence(void);
void System_Error_Sequence(void);
void System_Standby_Sequence(void);
void System_Sequence(void);

void Update_Chamber_Temp_Controller(void);
void Update_Wires_Temp_Controller(void);
void Standby_Timeout_Select(void);

#endif /* VENT_HUMIDIFIER_H_ */

	
