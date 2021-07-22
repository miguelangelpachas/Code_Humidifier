/*
 * heater_plate_feedback.c
 *
 * Created: 25/05/2021 10:24:43
 *  Author: mtorres
 */ 

/* File inclusion */
#include "heater_plate_feedback.h"

/* Variable definition */
static float current_sense_output_max_ma = 0.0;

/* Function definition */

void Heater_Plate_Feedback_Measure(void){
	
	uint16_t bin_val;
	float current_sensor_volt;
	float current_sense_feedback_value_ma;

	/* Select the respective ADC channel and take a sample */
	sConfig.Channel = HEATER_PLATE_FEEDBACK_ADC_CH;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	HAL_ADC_Start(&hadc1);
	if(HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY) == HAL_OK){

		/* Transform the ADC value into volts and eliminate the 1.5 offset */
		bin_val = HAL_ADC_GetValue(&hadc1);

		current_sensor_volt = ((float)bin_val * aref_actual_value) / 4096.0;
		current_sense_feedback_value_ma = (current_sensor_volt - 1.65) * (1000000.0 / CURRENT_SENSOR_SENSITIVITY_MV_A);

		/* Rectify the current (absolute value) */
		if(current_sense_feedback_value_ma < 0.0){
		   current_sense_feedback_value_ma = -current_sense_feedback_value_ma;
		}

		if(current_sense_feedback_value_ma > current_sense_output_max_ma){
			current_sense_output_max_ma = current_sense_feedback_value_ma;
		}

	}
	
}




float Heater_Plate_Max_Current_Get(void){
	return current_sense_output_max_ma;
}


void Heater_Plate_Max_Current_Reset(void){
	current_sense_output_max_ma = 0.0;
}


