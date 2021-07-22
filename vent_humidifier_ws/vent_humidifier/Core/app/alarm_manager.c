/*
 * alarm_manager.c
 *
 * Created: 5/05/2021 17:53:08
 *  Author: mtorres
 */ 

/* File inclusion */
#include "alarm_manager.h"

/* Variable definition */
static uint8_t alarm_blink= 1;
static uint8_t low_flow_mode_blink = 1;
static uint8_t high_flow_mode_blink = 1;
static uint32_t buzzer_mute_counter = 0;
static uint32_t low_temp_counter = 0;
static uint32_t low_temp_counter_top_value = LOW_TEMP_ALARM_TIMEOUT_SEC * 10;
static uint32_t probe_misplacement_counter = 0;

/* Function definition */

void Alarm_Manager(void){

	static uint32_t alarm_count_100ms = 0;
	static uint32_t low_flow_count_100ms = 0;
	static uint32_t high_flow_count_100ms = 0;

	/* Toggle high flow LED every 200ms */
	high_flow_count_100ms++;
	if(high_flow_count_100ms >= 2){
		high_flow_count_100ms = 0;
		high_flow_mode_blink = !high_flow_mode_blink;
	}


	/* Toggle low flow LED every 1 second */
	low_flow_count_100ms++;
	if(low_flow_count_100ms >= 10){
		low_flow_count_100ms = 0;
		low_flow_mode_blink = !low_flow_mode_blink;
	}


	/* Toggle buzzer and LEDs every second */
	alarm_count_100ms++;
	if(alarm_count_100ms >= (ALARM_TOGGLE_TIMEOUT_SEC * 10)){// 1 second = 10 * 0.1s
		alarm_count_100ms = 0;
		alarm_blink = !alarm_blink;
	}

	if(system_flags & (1 << BUZZER_MUTE_FLAG)){
		/* Mute the buzzer for 2 minutes */
		buzzer_mute_counter++;
		if(buzzer_mute_counter >= (BUZZER_MUTE_TIMEOUT_SEC * 10)){ // 2 minutes = 120 seconds = 1200 * 0.1s
			buzzer_mute_counter = 0;
			__disable_irq();
			system_flags &= ~(1 << BUZZER_MUTE_FLAG);
			__enable_irq();
		}

	}


	if(system_flags & ((uint32_t)1 << INVASIVE_MODE_FLAG)){
//		PORT_INVASIVE_MODE_LED |= (1 << INVASIVE_MODE_LED);
//		__disable_irq();
//		PORT_NONINVASIVE_MODE_LED &= ~(1 << PORT_NONINVASIVE_MODE_LED);
//		__enable_irq();

		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);

	}else{
//		PORT_INVASIVE_MODE_LED &= ~(1 << INVASIVE_MODE_LED);
//		__disable_irq();
//		PORT_NONINVASIVE_MODE_LED |= (1 << PORT_NONINVASIVE_MODE_LED);
//		__enable_irq();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);

		if(system_flags & ((uint32_t)1 << HIGH_FLOW_MODE_FLAG)){

			if(high_flow_mode_blink){
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);
			}else{
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);
			}

		}else{

			if(low_flow_mode_blink){
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);
			}else{
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);
			}

		}

	}


	if(system_state == STANDBY_STATE){

		if(alarm_flags & QUICK_FIX_ALARM_MASK){

			__disable_irq();
			alarm_flags &= ~SLOW_FIX_ALARM_MASK;
			alarm_flags &= ~(1 << LOW_TEMP_WARNING_FLAG);
			alarm_flags &= ~(1 << CHAMBER_PROBE_MISPLACED_ALARM_FLAG);
			alarm_flags &= ~(1 << AIRWAY_PROBE_MISPLACED_ALARM_FLAG);
			__enable_irq();

		}

		probe_misplacement_counter = 0;
		low_temp_counter = 0;

	}else{

		if((alarm_flags & (1 << CHAMBER_PROBE_MISPLACED_ALARM_FLAG)) || (alarm_flags & (1 << AIRWAY_PROBE_MISPLACED_ALARM_FLAG))){
			probe_misplacement_counter++;
			if(probe_misplacement_counter >= (PROBE_MISPLACED_TIMEOUT_SEC * 10)){// 5 minutes = 300 seconds = 3000 * 0.1s
				probe_misplacement_counter = 0;
				__disable_irq();
				alarm_flags |= (1 << CHAMBER_AND_AIRWAY_PROBES_ALARM_FLAG);
				__enable_irq();
			}
		}else{
			__disable_irq();
			alarm_flags &= ~(1 << CHAMBER_AND_AIRWAY_PROBES_ALARM_FLAG);
			__enable_irq();
			probe_misplacement_counter = 0;
		}

		if(alarm_flags & (1 << DISPLAY_LOW_TEMP_ALARM_FLAG)){
			low_temp_counter++;
			if(low_temp_counter == (LOW_TEMP_WARNING_TIMEOUT_SEC * 10)){ //25 seconds = 250 * 0.1s
				__disable_irq();
				alarm_flags |= (1 << LOW_TEMP_WARNING_FLAG);
				__enable_irq();
			}
		}else{
			low_temp_counter = 0;
		}

		if(alarm_flags & (1 << LOW_TEMP_WARNING_FLAG)){
			low_temp_counter++;
			if(low_temp_counter >= low_temp_counter_top_value){
				__disable_irq();
				alarm_flags |= (1 << LOW_TEMP_ALARM_FLAG);
				__enable_irq();
			}
		}

	}


	if((alarm_flags & (1 << CHAMBER_PROBE_CONN_ALARM_FLAG)) && (alarm_flags & (1 << AIRWAY_PROBE_CONN_ALARM_FLAG))){
		__disable_irq();
		alarm_flags |= (1 << TEMPERATURE_PROBE_CONN_ALARM_FLAG);
		alarm_flags &= ~(1 << CHAMBER_TEMP_PROBE_ALARM_FLAG);
		alarm_flags &= ~(1 << AIRWAY_TEMP_PROBE_ALARM_FLAG);
		__enable_irq();
	}else if((alarm_flags & (1 << CHAMBER_PROBE_CONN_ALARM_FLAG)) && (!(alarm_flags & (1 << AIRWAY_PROBE_CONN_ALARM_FLAG)))){
		__disable_irq();
		alarm_flags &= ~(1 << TEMPERATURE_PROBE_CONN_ALARM_FLAG);
		alarm_flags |= (1 << CHAMBER_TEMP_PROBE_ALARM_FLAG);
		alarm_flags &= ~(1 << AIRWAY_TEMP_PROBE_ALARM_FLAG);
		__enable_irq();
	}else if((!(alarm_flags & (1 << CHAMBER_PROBE_CONN_ALARM_FLAG))) && (alarm_flags & (1 << AIRWAY_PROBE_CONN_ALARM_FLAG))){
		__disable_irq();
		alarm_flags &= ~(1 << TEMPERATURE_PROBE_CONN_ALARM_FLAG);
		alarm_flags &= ~(1 << CHAMBER_TEMP_PROBE_ALARM_FLAG);
		alarm_flags |= (1 << AIRWAY_TEMP_PROBE_ALARM_FLAG);
		__enable_irq();
	}else{
		__disable_irq();
		alarm_flags &= ~(1 << TEMPERATURE_PROBE_CONN_ALARM_FLAG);
		alarm_flags &= ~(1 << CHAMBER_TEMP_PROBE_ALARM_FLAG);
		alarm_flags &= ~(1 << AIRWAY_TEMP_PROBE_ALARM_FLAG);
		__enable_irq();
	}


	if((alarm_flags & (1 << HEATER_PLATE_SCR_FAIL_ALARM_FLAG)) || (alarm_flags & (1 << NTC_DISCONNECTED_ALARM_FLAG))){
		__disable_irq();
		alarm_flags |= (1 << SEE_MANUAL_ALARM_FLAG);
		__enable_irq();
	}else{
		__disable_irq();
		alarm_flags &= ~(1 << SEE_MANUAL_ALARM_FLAG);
		__enable_irq();
	}

	if((alarm_flags & (1 << DISPLAY_HIGH_TEMP_ALARM_FLAG)) || (alarm_flags & (1 << AIRWAY_HIGH_TEMP_ALARM_FLAG))){
		__disable_irq();
		alarm_flags |= (1 << HIGH_TEMP_ALARM_FLAG);
		__enable_irq();
	}else{
		__disable_irq();
		alarm_flags &= ~(1 << HIGH_TEMP_ALARM_FLAG);
		__enable_irq();
	}


	if(system_flags & (1 << DISPLAY_TEMP_SCAN_FLAG)){

		Chamber_And_Airway_Probes_Alarm_Off();
		Heater_Wire_Alarm_Off();
		See_Manual_Alarm_Off();
		Temperature_Probe_Connector_Alarm_Off();
		Chamber_Probe_Alarm_Off();
		Airway_Probe_Alarm_Off();
		Temperature_Alarm_Off();
		Buzzer_Off();

		if(system_flags & (1 << DISPLAY_SHOW_CHAMBER_TEMP_FLAG)){
			PORT_AIRWAY_PROBE_LED &= ~(1 << AIRWAY_PROBE_LED);
			PORT_CHAMBER_PROBE_LED |= (1 << CHAMBER_PROBE_LED);
		}else if(system_flags & (1 << DISPLAY_SHOW_AIRWAY_TEMP_FLAG)){
			PORT_CHAMBER_PROBE_LED &= ~(1 << CHAMBER_PROBE_LED);
			PORT_AIRWAY_PROBE_LED |= (1 << AIRWAY_PROBE_LED);
		}else{
			PORT_AIRWAY_PROBE_LED &= ~(1 << AIRWAY_PROBE_LED);
			PORT_CHAMBER_PROBE_LED &= ~(1 << CHAMBER_PROBE_LED);
		}

	}else{


		if(alarm_flags & (1 << CHAMBER_AND_AIRWAY_PROBES_ALARM_FLAG)){
			if(alarm_blink){
				Chamber_And_Airway_Probes_Alarm_On();
			}else{
				Chamber_And_Airway_Probes_Alarm_Off();
			}
		}else{
			Chamber_And_Airway_Probes_Alarm_Off();
		}


		if(alarm_flags & (1 << HEATER_WIRE_ALARM_FLAG)){
			if(alarm_blink){
				Heater_Wire_Alarm_On();
			}else{
				Heater_Wire_Alarm_Off();
			}
		}else{
			Heater_Wire_Alarm_Off();
		}


		if(alarm_flags & (1 << SEE_MANUAL_ALARM_FLAG)){
			if(alarm_blink){
				See_Manual_Alarm_On();
			}else{
				See_Manual_Alarm_Off();
			}

		}else{
			See_Manual_Alarm_Off();
		}


		if(alarm_flags & (1 << TEMPERATURE_PROBE_CONN_ALARM_FLAG)){

			Chamber_Probe_Alarm_Off();
			Airway_Probe_Alarm_Off();

			if(alarm_blink){
				Temperature_Probe_Connector_Alarm_On();
			}else{
				Temperature_Probe_Connector_Alarm_Off();
			}

		}else if(alarm_flags & (1 << CHAMBER_TEMP_PROBE_ALARM_FLAG)){

			Temperature_Probe_Connector_Alarm_Off();
			Airway_Probe_Alarm_Off();

			if(alarm_blink){
				Chamber_Probe_Alarm_On();
			}else{
				Chamber_Probe_Alarm_Off();
			}


		}else if(alarm_flags & (1 << AIRWAY_TEMP_PROBE_ALARM_FLAG)){

			Temperature_Probe_Connector_Alarm_Off();
			Chamber_Probe_Alarm_Off();

			if(alarm_blink){
				Airway_Probe_Alarm_On();
			}else{
				Airway_Probe_Alarm_Off();
			}

		}else{
			Temperature_Probe_Connector_Alarm_Off();
			Chamber_Probe_Alarm_Off();
			Airway_Probe_Alarm_Off();
		}


		if((alarm_flags & (1 << HIGH_TEMP_ALARM_FLAG)) || (alarm_flags & (1 << LOW_TEMP_ALARM_FLAG)) || (alarm_flags & (1 << LOW_TEMP_WARNING_FLAG))){

			if(alarm_blink){
				Temperature_Alarm_On();
			}else{
				Temperature_Alarm_Off();
			}

		}else{
			Temperature_Alarm_Off();
		}


		if(system_flags & (1 << BUZZER_MUTE_FLAG)){
			Buzzer_Off();
		}else{
			if(alarm_flags & ALARM_MASK){
				if(alarm_blink){
					Buzzer_On();
				}else{
					Buzzer_Off();
				}
			}else{
				Buzzer_Off();
			}

		}

	}

}


void Chamber_And_Airway_Probes_Alarm_On(void){
	PORT_AIRWAY_PROBE_LED |= (1 << AIRWAY_PROBE_LED);
	PORT_CHAMBER_PROBE_LED |= (1 << CHAMBER_PROBE_LED);
}

void Chamber_And_Airway_Probes_Alarm_Off(void){

	if((!(alarm_flags & (1 << HEATER_WIRE_ALARM_FLAG))) && (!(alarm_flags & (1 << CHAMBER_TEMP_PROBE_ALARM_FLAG)))){
		PORT_CHAMBER_PROBE_LED &= ~(1 << CHAMBER_PROBE_LED);
	}

	if(!(alarm_flags & (1 << AIRWAY_TEMP_PROBE_ALARM_FLAG))){
		PORT_AIRWAY_PROBE_LED &= ~(1 << AIRWAY_PROBE_LED);
	}	
}

void Heater_Wire_Alarm_On(void){
	PORT_CHAMBER_PROBE_LED |= (1 << CHAMBER_PROBE_LED);
	PORT_HEATER_ADAPTER_LED	|= (1 << HEATER_ADAPTER_LED);
}


void Heater_Wire_Alarm_Off(void){
	PORT_HEATER_ADAPTER_LED	&= ~(1 << HEATER_ADAPTER_LED);
	if(!(alarm_flags & (1 << CHAMBER_AND_AIRWAY_PROBES_ALARM_FLAG))){
		PORT_CHAMBER_PROBE_LED &= ~(1 << CHAMBER_PROBE_LED);
	}	
}

void Temperature_Probe_Connector_Alarm_On(void){
	PORT_SENSOR_ADAPTER_LED |= (1 << SENSOR_ADAPTER_LED);
}

void Temperature_Probe_Connector_Alarm_Off(void){

	if((!(alarm_flags & (1 << CHAMBER_TEMP_PROBE_ALARM_FLAG))) && (!(alarm_flags & (1 << AIRWAY_TEMP_PROBE_ALARM_FLAG)))){
		PORT_SENSOR_ADAPTER_LED &= ~(1 << SENSOR_ADAPTER_LED);
	}

}


void Chamber_Probe_Alarm_On(void){
	PORT_SENSOR_ADAPTER_LED |= (1 << SENSOR_ADAPTER_LED);
	PORT_CHAMBER_PROBE_LED |= (1 << CHAMBER_PROBE_LED);
}


void Chamber_Probe_Alarm_Off(void){

	if((!(alarm_flags & (1 << CHAMBER_AND_AIRWAY_PROBES_ALARM_FLAG))) && (!(alarm_flags & (1 << HEATER_WIRE_ALARM_FLAG)))){
		PORT_CHAMBER_PROBE_LED &= ~(1 << CHAMBER_PROBE_LED);
	}

	if((!(alarm_flags & (1 << AIRWAY_TEMP_PROBE_ALARM_FLAG))) && (!(alarm_flags & (1 << TEMPERATURE_PROBE_CONN_ALARM_FLAG)))){
		PORT_SENSOR_ADAPTER_LED &= ~(1 << SENSOR_ADAPTER_LED);
	}

}

void Airway_Probe_Alarm_On(void){
	PORT_SENSOR_ADAPTER_LED |= (1 << SENSOR_ADAPTER_LED);
	PORT_AIRWAY_PROBE_LED |= (1 << AIRWAY_PROBE_LED);
}

void Airway_Probe_Alarm_Off(void){

	if(!(alarm_flags & (1 << CHAMBER_AND_AIRWAY_PROBES_ALARM_FLAG))){
		PORT_AIRWAY_PROBE_LED &= ~(1 << AIRWAY_PROBE_LED);
	}

	if((!(alarm_flags & (1 << CHAMBER_TEMP_PROBE_ALARM_FLAG))) && (!(alarm_flags & (1 << TEMPERATURE_PROBE_CONN_ALARM_FLAG)))){
		PORT_SENSOR_ADAPTER_LED &= ~(1 << SENSOR_ADAPTER_LED);
	}
}


void Water_Out_Alarm_On(void){
	PORT_WATER_OUT_LED	|= (1 << WATER_OUT_LED);
}

void Water_Out_Alarm_Off(void){
	PORT_WATER_OUT_LED	&= ~(1 << WATER_OUT_LED);
}

void See_Manual_Alarm_On(void){
	PORT_SEE_MANUAL_LED |= (1 << SEE_MANUAL_LED);
}

void See_Manual_Alarm_Off(void){
	PORT_SEE_MANUAL_LED &= ~(1 << SEE_MANUAL_LED);
}

void Temperature_Alarm_On(void){
	PORT_HUMIDITY_LED |= (1 << HUMIDITY_LED);
}

void Temperature_Alarm_Off(void){
	PORT_HUMIDITY_LED &= ~(1 << HUMIDITY_LED);
}


void Buzzer_On(void){
	PORT_BUZZER |= (1 << BUZZER);
}


void Buzzer_Off(void){
	PORT_BUZZER &= ~(1 << BUZZER);
}

void Alarm_Buzzer_Mute(void){
	buzzer_mute_counter = 0;
	__disable_irq();
	system_flags |= (1 << BUZZER_MUTE_FLAG);
	__enable_irq();
}






