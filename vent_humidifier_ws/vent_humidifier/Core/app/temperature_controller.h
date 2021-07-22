/*
 * on_off_controller.h
 *
 *  Created on: 7 jun. 2021
 *      Author: mtorres
 */

#ifndef TEMPERATURE_CONTROLLER_H_
#define TEMPERATURE_CONTROLLER_H_

/* File inclusion */
#include "stdint.h"
#include "project_defines.h"
#include "fuzzy_controller_basic.h"

/* Function declaration */
double Temperature_Controller_01(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset);
double Temperature_Controller_02(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset);
double Temperature_Controller_03(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset);
double Temperature_Controller_04(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset);

double Temperature_Controller_05(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset);
double Temperature_Controller_06(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset);

double Temperature_Controller_07(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset);
double Temperature_Controller_08(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset);
double Temperature_Controller_09(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset);
double Temperature_Controller_10(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset);

double Temperature_Controller_11(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset);
double Temperature_Controller_12(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset);


void Temperature_Controllers_Initialize(void);

#endif /* APP_TEMPERATURE_CONTROLLER_H_ */
