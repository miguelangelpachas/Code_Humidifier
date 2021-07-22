/*
 * heat_manager.c
 *
 * Created: 7/05/2021 16:48:11
 *  Author: mtorres
 */ 

/* File inclusion */
#include "heater_manager.h"

/* Variable definition */
static uint8_t heater_wire_01_duty_cycle = 0;
static uint8_t heater_wire_02_duty_cycle = 0;
volatile uint8_t heater_plate_duty_cycle = 0;

/* Function definition */
void Set_Heater_Wire_01_Duty_Cycle(uint8_t duty_cycle){

	if(duty_cycle > HEATER_WIRE_01_MAX_DUTY_CYCLE){
		duty_cycle = HEATER_WIRE_01_MAX_DUTY_CYCLE;
	}else if(duty_cycle < HEATER_WIRE_01_MIN_DUTY_CYCLE){
		duty_cycle = HEATER_WIRE_01_MIN_DUTY_CYCLE;
	}else{
		// Does nothing
	}

	heater_wire_01_duty_cycle = duty_cycle;
}

uint8_t Get_Heater_Wire_01_Duty_Cycle(void){
	return heater_wire_01_duty_cycle;
}

void Heater_Wire_01_Manager(void){
	
	static uint8_t count = 0;
	
	count++;

	if(count == (HEATER_WIRE_01_MAX_DUTY_CYCLE - 1)){
		system_flags |= (1 << HEATER_WIRE_OUTPUT_UPDATE_FLAG);
	}

	if(count >= HEATER_WIRE_01_MAX_DUTY_CYCLE ){
		count = 0;
	}
	
	if(count < heater_wire_01_duty_cycle){
		PORT_HEATER_WIRE_01 |= (1 << HEATER_WIRE_01);
	}else{
		PORT_HEATER_WIRE_01 &= ~(1 << HEATER_WIRE_01);
	}
	
}

void Set_Heater_Wire_02_Duty_Cycle(uint8_t duty_cycle){

	if(duty_cycle > HEATER_WIRE_01_MAX_DUTY_CYCLE){
		duty_cycle = HEATER_WIRE_01_MAX_DUTY_CYCLE;
	}else if(duty_cycle < HEATER_WIRE_01_MIN_DUTY_CYCLE){
		duty_cycle = HEATER_WIRE_01_MIN_DUTY_CYCLE;
	}else{
		// Does nothing
	}

	heater_wire_02_duty_cycle = duty_cycle;
}

uint8_t Get_Heater_Wire_02_Duty_Cycle(void){

	return heater_wire_02_duty_cycle;
}


void Heater_Wire_02_Manager(void){

	static uint8_t count = 0;
	
	count++;
	if(count >= HEATER_WIRE_02_MAX_DUTY_CYCLE ){
		count = 0;
	}
	
	if(count < heater_wire_02_duty_cycle){
		PORT_HEATER_WIRE_02 |= (1 << HEATER_WIRE_02);
	}else{
		PORT_HEATER_WIRE_02 &= ~(1 << HEATER_WIRE_02);
	}
	
}

void Set_Heater_Plate_Duty_Cycle(uint8_t duty_cycle){

	if(duty_cycle > HEATER_PLATE_MAX_DUTY_CYCLE){
		duty_cycle = HEATER_PLATE_MAX_DUTY_CYCLE;
	}else if(duty_cycle < HEATER_PLATE_MIN_DUTY_CYCLE){
		duty_cycle = HEATER_PLATE_MIN_DUTY_CYCLE;
	}else{
		// Does nothing
	}

	heater_plate_duty_cycle = duty_cycle;
}

uint8_t Get_Heater_Plate_Duty_Cycle(void){
	return heater_plate_duty_cycle;
}



void Heater_Wire_01_Turn_Off(void){
	__disable_irq();
	Set_Heater_Wire_01_Duty_Cycle(0);
	PORT_HEATER_WIRE_01 &= ~(1 << HEATER_WIRE_01);
	__enable_irq();

}


void Heater_Wire_02_Turn_Off(void){
	__disable_irq();
	Set_Heater_Wire_02_Duty_Cycle(0);
	PORT_HEATER_WIRE_02 &= ~(1 << HEATER_WIRE_01);
	__enable_irq();

}


void Heater_Plate_Turn_Off(void){
	__disable_irq();
	Set_Heater_Plate_Duty_Cycle(0);
	PORT_HEATER_PLATE &= ~(1 << HEATER_PLATE);
	__enable_irq();

}

