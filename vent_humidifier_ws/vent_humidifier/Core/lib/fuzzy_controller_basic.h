/*
 * fuzzy_controller_basic.h
 *
 *  Created on: 8 jun. 2021
 *      Author: mtorres
 */

#ifndef FUZZY_CONTROLLER_BASIC_H_
#define FUZZY_CONTROLLER_BASIC_H_

/* File inclusion */
#include <stdint.h>
#include "project_defines.h"

/* Constants and macros */
//#define FUZZY_CONTROLLER_SAMPLE_PERIOD_S	0.4167
//#define FUZZY_CONTROL_01_MAX_OUTPUT		50.0
//#define FUZZY_CONTROL_01_MIN_OUTPUT		0.0

/* Function declaration */
void Fuzzy_Linear_PD_Controller_01(double error, double error_change, double *controller_output);
float Fuzzy_Incremental_Controller_01(float control_setpoint, float control_feedback, uint8_t control_reset);
void Fuzzy_Inremental_Controller_01_Set_Parameters(float new_ge, float new_gce, float new_gcu);
void Fuzzy_Controllers_Initialize(void);

#endif /* LIB_FUZZY_CONTROLLER_BASIC_H_ */
