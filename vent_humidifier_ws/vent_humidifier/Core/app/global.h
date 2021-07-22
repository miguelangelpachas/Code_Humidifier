/*
 * global.h
 *
 *  Created on: 27 may. 2021
 *      Author: mtorres
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

/* File inclusion */
#include "main.h"
#include <stdint.h>

/* These variables are required to manipulate the peripherarls with STM32 Cube */
extern ADC_HandleTypeDef hadc1;
extern RTC_HandleTypeDef hrtc;
extern TIM_HandleTypeDef htim2;
extern UART_HandleTypeDef huart3;
extern ADC_ChannelConfTypeDef sConfig;

/* Application global variable */
extern volatile uint32_t system_flags;
extern volatile uint32_t alarm_flags;
extern volatile uint8_t system_state;
extern float aref_actual_value;

/* Just for testing purposes */
extern float my_kp;
extern float my_ki;
extern float my_kd;
extern float my_setpoint;
extern float wire_setpoint;

extern uint8_t uart_tx_buffer[];
extern volatile uint8_t uart_rx_buffer[];
extern volatile uint8_t uart_rx_individual_buffer;

#endif /* APP_GLOBAL_H_ */
