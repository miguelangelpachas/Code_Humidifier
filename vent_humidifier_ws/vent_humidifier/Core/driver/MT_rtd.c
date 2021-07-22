/*
 * MT_rtd.c
 *
 * Created: 25/05/2021 16:55:12
 *  Author: mtorres
 */ 

/* FIle inclusion */
#include "MT_rtd.h"

/* Variable definition */
static float rtd_res_pos_table[RTD_POS_LINEAR_TABLE_N_POINTS + 1];
static float rtd_res_neg_table[RTD_NEG_LINEAR_TABLE_N_POINTS + 1];


/* Function Definition */

void RTD_Generate_LUT(void){
	
	uint16_t index;
	float temp;
		
	for(index = 0; index <= RTD_POS_LINEAR_TABLE_N_POINTS; index++){
		temp = ((float)RTD_POS_LINEAR_TABLE_STEP) * index;
		rtd_res_pos_table[index] = RTD_Calculate_R_From_T(temp);
	}
	
	for(index = 0; index <= RTD_NEG_LINEAR_TABLE_N_POINTS; index++){
		temp = -((float)RTD_NEG_LINEAR_TABLE_STEP) * index;
		rtd_res_neg_table[index] = RTD_Calculate_R_From_T(temp);
	}
	
}


float RTD_Calculate_R_From_T(float temp){
	
	float res;
	
	if(temp >= 0){
		res = R_AT_T0_OHM * (1 + (A_COEFF*temp) + (B_COEFF * temp * temp));
	}else{
		res = R_AT_T0_OHM * (1 + (A_COEFF*temp) + (B_COEFF * temp * temp) + ((C_COEFF * temp * temp * temp) * (temp - 100)));
	}
	
	return res;
	
}


float RTD_Calculate_T_From_R(float res){
	
	float temp;
	float slope = 1.0, offset = 0.0;
	uint16_t index;
	
	
	if(res >= R_AT_T0_OHM){
		
		index = 0;
		
		while((index < RTD_POS_LINEAR_TABLE_N_POINTS) && (res > rtd_res_pos_table[index + 1])){
			index++;
		}
		
		if(index < RTD_POS_LINEAR_TABLE_N_POINTS){
			
			slope = ((float)RTD_POS_LINEAR_TABLE_STEP) / (rtd_res_pos_table[index + 1] - rtd_res_pos_table[index]);
			offset = index*(float)RTD_POS_LINEAR_TABLE_STEP;
			
			temp = offset + slope*(res - rtd_res_pos_table[index]);
			
		}else{
			
			//temp = RTD_POS_LINEAR_TABLE_N_POINTS*((float)RTD_POS_LINEAR_TABLE_STEP);
			temp = RTD_TABLE_MAX_POS_VALUE;

		}
		
		
	}else{
		
		index = 0;
		while((index < RTD_NEG_LINEAR_TABLE_N_POINTS) && (res < rtd_res_neg_table[index + 1])){
			index++;
		}
		
		if(index < RTD_NEG_LINEAR_TABLE_N_POINTS){
			
			slope = -((float)RTD_NEG_LINEAR_TABLE_STEP) / (rtd_res_neg_table[index + 1] - rtd_res_neg_table[index]);
			offset = -index*(float)RTD_NEG_LINEAR_TABLE_STEP;
			
			temp = offset + slope*(res - rtd_res_neg_table[index]);
			
		}else{
			
			//temp = -RTD_NEG_LINEAR_TABLE_N_POINTS*((float)RTD_NEG_LINEAR_TABLE_STEP);
			temp = RTD_TABLE_MAX_POS_VALUE;
		
		}
		
	}
	
	return temp;
}


float RTD_Approximate_R_From_T(float temp){
	
	float res;
	
	if(temp > 0){
		res = R_AT_T0_OHM + (R_AT_T0_OHM * ALPHA_TEMP_COEFF * temp);
		}else{
		res = R_AT_T0_OHM + (R_AT_T0_OHM * NEG_ALPHA_TEMP_COEFF * temp);
	}
	
	return res;
}


float RTD_Approximate_T_From_R(float res){
	
	float temp;
	
	if(res >= R_AT_T0_OHM){
		temp = (res - R_AT_T0_OHM) / (R_AT_T0_OHM * ALPHA_TEMP_COEFF);
		}else{
		temp = -(res - R_AT_T0_OHM) / (R_AT_T0_OHM * NEG_ALPHA_TEMP_COEFF);
	}
	
	return temp;
}

