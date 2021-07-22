/*
 * display_interface.c
 *
 *  Created on: 31 may. 2021
 *      Author: mtorres
 */


/* File inclusion */
#include "display_interface.h"


/* Function definition */

void Display_Interface_Show_Temp(float temp){

	/* Round temp to one decimal digit */
	temp *= 10.0f;
	temp = (temp > (floor(temp) + 0.5f)) ? ceil(temp) : floor(temp);
	/* Print the temperature value on the display */
	Display_Decodificar_Entero_Decimal((uint16_t)temp);
	display_buffer[1] |= (1 << 7);

}


void Display_Interface_Show_High_Temp_Message(void){
	display_buffer[0] = 0x04; //i
	display_buffer[1] = 0x76; //H
	display_buffer[2] = 0x00;

}


void Display_Interface_Show_Low_Temp_Message(void){
	display_buffer[0] = 0x5C; //o
	display_buffer[1] = 0x38; //L
	display_buffer[2] = 0x00;

}

void Display_Interface_Show_No_Probe_Message(void){
	display_buffer[0] = 0x40; //-
	display_buffer[1] = 0x40; //-
	display_buffer[2] = 0x40; //-
}

void Display_Interface_Show_Diagnostics_Message(void){
	display_buffer[0] = 0x48; //=
	display_buffer[1] = 0x48; //=
	display_buffer[2] = 0x48; //=
}

void Display_Interface_Show_Error_Message(void){
	display_buffer[0] = 0x50; //r
	display_buffer[1] = 0x50; //r
	display_buffer[2] = 0x79; //E
}


void Display_Update(void){

	float ch_temp,aw_temp;

	ch_temp = Chamber_Temperature_Get();
	aw_temp = Airway_Temperature_Get();

	if(system_flags & (1 << DISPLAY_SHOW_CHAMBER_TEMP_FLAG)){


		if(alarm_flags & (1 << CHAMBER_PROBE_CONN_ALARM_FLAG)){

			Display_Interface_Show_No_Probe_Message();

		}else{

			if(alarm_flags & (1 << CHAMBER_TOO_HIGH_TEMP_ALARM_FLAG)){
				Display_Interface_Show_High_Temp_Message();
			}else if(alarm_flags & (1 << CHAMBER_TOO_LOW_TEMP_ALARM_FLAG)){
				 Display_Interface_Show_Low_Temp_Message();
			}else{
				Display_Interface_Show_Temp(ch_temp);
			}

		}




	}else if(system_flags & (1 << DISPLAY_SHOW_AIRWAY_TEMP_FLAG)){

		if(alarm_flags & (1 << AIRWAY_PROBE_CONN_ALARM_FLAG)){

			Display_Interface_Show_No_Probe_Message();

		}else{

			if(alarm_flags & (1 << AIRWAY_TOO_HIGH_TEMP_ALARM_FLAG)){
				Display_Interface_Show_High_Temp_Message();
			}else if(alarm_flags & (1 << AIRWAY_TOO_LOW_TEMP_ALARM_FLAG)){
				Display_Interface_Show_Low_Temp_Message();
			}else{
				Display_Interface_Show_Temp(aw_temp);
			}


		}

	}else{

		if(alarm_flags & (1 << AIRWAY_PROBE_CONN_ALARM_FLAG)){
			Display_Interface_Show_No_Probe_Message();
		}else{

			if(ch_temp < aw_temp){

				if(alarm_flags & (1 << CHAMBER_TOO_HIGH_TEMP_ALARM_FLAG)){
					Display_Interface_Show_High_Temp_Message();
				}else if(alarm_flags & (1 << CHAMBER_TOO_LOW_TEMP_ALARM_FLAG)){
					 Display_Interface_Show_Low_Temp_Message();
				}else{
					Display_Interface_Show_Temp(ch_temp);
				}

			}else{

				if(alarm_flags & (1 << AIRWAY_TOO_HIGH_TEMP_ALARM_FLAG)){
					Display_Interface_Show_High_Temp_Message();
				}else if(alarm_flags & (1 << AIRWAY_TOO_LOW_TEMP_ALARM_FLAG)){
					 Display_Interface_Show_Low_Temp_Message();
				}else{
					Display_Interface_Show_Temp(aw_temp);
				}

			}
		}
	}
}



void Display_Temperature_Scan(void){

		static uint32_t counter_100ms = 0;
		static uint8_t scan_state = 0;

		switch(scan_state){

		case 0:

			__disable_irq();
			system_flags &= ~(1 << DISPLAY_SHOW_CHAMBER_TEMP_FLAG);
			system_flags &= ~(1 << DISPLAY_SHOW_AIRWAY_TEMP_FLAG);
			__enable_irq();
			Display_Turn_Off();
			counter_100ms = 0;
			scan_state++;

			break;

		case 1:

			counter_100ms++;

			if(counter_100ms >= 5){
				__disable_irq();
				system_flags |= (1 << DISPLAY_SHOW_CHAMBER_TEMP_FLAG);
				system_flags &= ~(1 << DISPLAY_SHOW_AIRWAY_TEMP_FLAG);
				__enable_irq();
				Display_Turn_On();
				counter_100ms = 0;
				scan_state++;
			}

			break;


		case 2:

			counter_100ms++;

			if(counter_100ms >= 15){
				__disable_irq();
				system_flags &= ~(1 << DISPLAY_SHOW_CHAMBER_TEMP_FLAG);
				system_flags &= ~(1 << DISPLAY_SHOW_AIRWAY_TEMP_FLAG);
				__enable_irq();
				Display_Turn_Off();
				counter_100ms = 0;
				scan_state++;
			}

			break;

		case 3:

			counter_100ms++;

			if(counter_100ms >= 5){
				__disable_irq();
				system_flags &= ~(1 << DISPLAY_SHOW_CHAMBER_TEMP_FLAG);
				system_flags |= (1 << DISPLAY_SHOW_AIRWAY_TEMP_FLAG);
				__enable_irq();
				Display_Turn_On();
				counter_100ms = 0;
				scan_state++;
			}

			break;

		case 4:
			counter_100ms++;

			if(counter_100ms >= 15){
				__disable_irq();
				system_flags &= ~(1 << DISPLAY_SHOW_CHAMBER_TEMP_FLAG);
				system_flags &= ~(1 << DISPLAY_SHOW_AIRWAY_TEMP_FLAG);
				__enable_irq();
				Display_Turn_Off();
				counter_100ms = 0;
				scan_state++;
			}

			break;

		case 5:

			counter_100ms++;
			if(counter_100ms >= 5){
				Display_Turn_On();
				counter_100ms = 0;
				scan_state = 0;
				__disable_irq();
				system_flags &= ~(1 << DISPLAY_TEMP_SCAN_FLAG);
				__enable_irq();
				Clean_Buttons();
			}

			break;

		default:

			break;

		}

}
