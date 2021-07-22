/*
 * heater_plate_feedback.h
 *
 * Created: 25/05/2021 10:24:22
 *  Author: mtorres
 */ 


#ifndef HEATER_PLATE_FEEDBACK_H_
#define HEATER_PLATE_FEEDBACK_H_

/* File inclusion */
#include "main.h"
#include "project_defines.h"
#include "global.h"
#include <stdint.h>
#include "MT_filters.h"

/* Function declaration */
void Heater_Plate_Feedback_Measure(void);
float Heater_Plate_Max_Current_Get(void);
void Heater_Plate_Max_Current_Reset(void);

#endif /* HEATER_PLATE_FEEDBACK_H_ */
