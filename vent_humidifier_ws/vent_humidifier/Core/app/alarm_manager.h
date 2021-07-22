/*
 * alarm_manager.h
 *
 * Created: 5/05/2021 17:52:38
 *  Author: mtorres
 */ 


#ifndef ALARM_MANAGER_H_
#define ALARM_MANAGER_H_

/* File inclusion */
#include <stdint.h>
#include "main.h"
#include "project_defines.h"
#include "global.h"

/* Function declaration */
void Alarm_Manager(void);
void Chamber_And_Airway_Probes_Alarm_On(void);
void Chamber_And_Airway_Probes_Alarm_Off(void);
void Heater_Wire_Alarm_On(void); 
void Heater_Wire_Alarm_Off(void); 
void Temperature_Probe_Connector_Alarm_On(void);
void Temperature_Probe_Connector_Alarm_Off(void);
void Chamber_Probe_Alarm_On(void);
void Chamber_Probe_Alarm_Off(void);
void Airway_Probe_Alarm_On(void);
void Airway_Probe_Alarm_Off(void);
void Water_Out_Alarm_On(void);
void Water_Out_Alarm_Off(void);
void See_Manual_Alarm_On(void);
void See_Manual_Alarm_Off(void);
void Temperature_Alarm_On(void);
void Temperature_Alarm_Off(void);
void Buzzer_On(void);
void Buzzer_Off(void);
void Alarm_Buzzer_Mute(void);

#endif /* ALARM_MANAGER_H_ */
