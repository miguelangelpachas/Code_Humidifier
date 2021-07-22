/*
 * heater_manager.h
 *
 * Created: 7/05/2021 16:46:46
 *  Author: mtorres
 */ 


#ifndef HEATER_MANAGER_H_
#define HEATER_MANAGER_H_

/* File inclusion */
#include <stdint.h>
#include "main.h"
#include "project_defines.h"
#include "global.h"

/* Function declaration */
void Set_Heater_Wire_01_Duty_Cycle(uint8_t duty_cycle);
uint8_t Get_Heater_Wire_01_Duty_Cycle(void);
void Heater_Wire_01_Manager(void);
void Heater_Wire_01_Turn_Off(void);

void Set_Heater_Wire_02_Duty_Cycle(uint8_t duty_cycle);
uint8_t Get_Heater_Wire_02_Duty_Cycle(void);
void Heater_Wire_02_Manager(void);
void Heater_Wire_02_Turn_Off(void);

void Set_Heater_Plate_Duty_Cycle(uint8_t duty_cycle);
uint8_t Get_Heater_Plate_Duty_Cycle(void);
void Heater_Plate_Turn_Off(void);

/* Variable declaration */
extern volatile uint8_t heater_plate_duty_cycle;


/* In-line functions */

static inline void Heater_Plate_Manager(void){

	static uint8_t count = 0;

	count++;

	if(count == (HEATER_PLATE_MAX_DUTY_CYCLE - 1)){
		system_flags |= (1 << HEATER_PLATE_OUTPUT_UPDATE_FLAG);
	}

	if(count >= HEATER_PLATE_MAX_DUTY_CYCLE){
		count = 0;
	}


	if(count < heater_plate_duty_cycle){
		PORT_HEATER_PLATE |= (1 << HEATER_PLATE);
	}else{
		PORT_HEATER_PLATE &= ~(1 << HEATER_PLATE);
	}

}

#endif /* HEATER_MANAGER_H_ */
