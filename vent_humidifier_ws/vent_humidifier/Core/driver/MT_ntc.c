

/* File inclusion */
#include "MT_ntc.h"
#include <stdio.h>


/* Variable definition */
static float ntc_res_pos_table[NTC_POS_LINEAR_TABLE_N_POINTS + 1];
static float ntc_res_neg_table[NTC_NEG_LINEAR_TABLE_N_POINTS + 1];
static float r_at_t0_ohm = 0.0;


/* Function definition */

void NTC_Generate_LUT(void){

	uint16_t index;
	float temp;

	for(index = 0; index <= NTC_POS_LINEAR_TABLE_N_POINTS; index++){
		temp = ((float)NTC_POS_LINEAR_TABLE_STEP) * index;
		ntc_res_pos_table[index] = NTC_Calculate_R_From_T(temp);
	}

	for(index = 0; index <= NTC_NEG_LINEAR_TABLE_N_POINTS; index++){
		temp = -((float)NTC_NEG_LINEAR_TABLE_STEP) * index;
		ntc_res_neg_table[index] = NTC_Calculate_R_From_T(temp);
	}

    r_at_t0_ohm = NTC_Calculate_R_From_T(0.0);

}


float NTC_Calculate_R_From_T(float temp){

    float power_num;
    float power_den;
    float temp_k;
    float res;


    temp_k = temp + 273.15;

    power_num = NTC_BETA_COEFFICIENT * (temp_k - NTC_BASE_POINT_TEMP_K);
    power_den = temp_k *  NTC_BASE_POINT_TEMP_K;
    res = NTC_R_AT_BASE_POINT_TEMP / exp(power_num / power_den);

    return res;
}


float NTC_Calculate_T_From_R(float res){

 	float temp;
	float slope = 1.0, offset = 0.0;
	uint16_t index;


	if(res <= r_at_t0_ohm){

		index = 0;

		while((index < NTC_POS_LINEAR_TABLE_N_POINTS) && (res < ntc_res_pos_table[index + 1])){
			index++;
		}

		if(index < NTC_POS_LINEAR_TABLE_N_POINTS){

			slope = ((float)NTC_POS_LINEAR_TABLE_STEP) / (ntc_res_pos_table[index + 1] - ntc_res_pos_table[index]);
			offset = index*(float)NTC_POS_LINEAR_TABLE_STEP;

			temp = offset + slope*(res - ntc_res_pos_table[index]);

		}else{

			temp = NTC_TABLE_MAX_POS_VALUE;

		}


	}else{

		index = 0;
		while((index < NTC_NEG_LINEAR_TABLE_N_POINTS) && (res > ntc_res_neg_table[index + 1])){
			index++;
		}

		if(index < NTC_NEG_LINEAR_TABLE_N_POINTS){

			slope = -((float)NTC_NEG_LINEAR_TABLE_STEP) / (ntc_res_neg_table[index + 1] - ntc_res_neg_table[index]);
			offset = -index*(float)NTC_NEG_LINEAR_TABLE_STEP;

			temp = offset + slope*(res - ntc_res_neg_table[index]);

		}else{

			temp = NTC_TABLE_MAX_POS_VALUE;

		}

	}

	return temp;

}
