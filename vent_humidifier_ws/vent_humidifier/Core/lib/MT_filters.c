/*
 * MT_filters.c
 *
 * Created: 6/05/2021 14:31:49
 *  Author: mtorres
 */ 

/* File inclusion */
#include "MT_filters.h"

/* Global variables */

static float rc_lpf_01_output = 0;
static float rc_lpf_02_output = 0;
static float rc_lpf_03_output = 0;
static float rc_lpf_04_output = 0;


/* Function definition */

void Filters_Initialize(void){

	RC_LPF_01(0.0, 1);
	RC_LPF_02(0.0, 1);
	RC_LPF_03(0.0, 1);
	RC_LPF_04(0.0, 1);
}


float RC_LPF_01(float raw_value, uint8_t restart){

	static float lpf_prev_out = 0.0;
	float lpf_out, sample_period_sec, div;
	
	if(restart){
		lpf_prev_out = 25.0;
		lpf_out = 25.0;
	}else{
		sample_period_sec = 0.001 * ((float)RC_LPF_01_SAMPLE_PERIOD_MS);
		div = sample_period_sec + RC_LPF_01_RC_CONSTANT_S;
		
		lpf_out = (raw_value * (sample_period_sec / div)) +  (lpf_prev_out * (RC_LPF_01_RC_CONSTANT_S / div));
		lpf_prev_out = lpf_out;
	}
	
	return lpf_out;
}



float RC_LPF_02(float raw_value, uint8_t restart){

	static float lpf_prev_out = 0.0;
	float lpf_out, sample_period_sec, div;
	
	if(restart){
		lpf_prev_out = 0.0;
		lpf_out = 0.0;
	}else{
		sample_period_sec = 0.001 * ((float)RC_LPF_02_SAMPLE_PERIOD_MS);
		div = sample_period_sec + RC_LPF_02_RC_CONSTANT_S;
		
		lpf_out = (raw_value * (sample_period_sec / div)) +  (lpf_prev_out * (RC_LPF_02_RC_CONSTANT_S / div));
		lpf_prev_out = lpf_out;
	}
	
	return lpf_out;
}


float RC_LPF_03(float raw_value, uint8_t restart){

	static float lpf_prev_out = 0.0;
	float lpf_out, sample_period_sec, div;
	
	if(restart){
		lpf_prev_out = 0.0;
		lpf_out = 0.0;
	}else{
		sample_period_sec = 0.001 * ((float)RC_LPF_03_SAMPLE_PERIOD_MS);
		div = sample_period_sec + RC_LPF_03_RC_CONSTANT_S;
		
		lpf_out = (raw_value * (sample_period_sec / div)) +  (lpf_prev_out * (RC_LPF_03_RC_CONSTANT_S / div));
		lpf_prev_out = lpf_out;
	}
	
	return lpf_out;
}


float RC_LPF_04(float raw_value, uint8_t restart){

	static float lpf_prev_out = 0.0;
	float lpf_out, sample_period_sec, div;
	
	if(restart){
		lpf_prev_out = 0.0;
		lpf_out = 0.0;
		}else{
		sample_period_sec = 0.001 * ((float)RC_LPF_04_SAMPLE_PERIOD_MS);
		div = sample_period_sec + RC_LPF_04_RC_CONSTANT_S;
		
		lpf_out = (raw_value * (sample_period_sec / div)) +  (lpf_prev_out * (RC_LPF_04_RC_CONSTANT_S / div));
		lpf_prev_out = lpf_out;
	}
	
	return lpf_out;
}


void Apply_RC_LPF_01(float signal){
	rc_lpf_01_output = RC_LPF_01(signal, 0);
}


void Apply_RC_LPF_02(float signal){
	rc_lpf_02_output = RC_LPF_02(signal, 0);
}


void Apply_RC_LPF_03(float signal){
	rc_lpf_03_output = RC_LPF_03(signal, 0);
}


void Apply_RC_LPF_04(float signal){
	rc_lpf_04_output = RC_LPF_04(signal, 0);
}


float Get_RC_LPF_01_Output(void){
	return rc_lpf_01_output;
}


float Get_RC_LPF_02_Output(void){
	return rc_lpf_02_output;
}


float Get_RC_LPF_03_Output(void){
	return rc_lpf_03_output;
}


float Get_RC_LPF_04_Output(void){
	return rc_lpf_04_output;
}










