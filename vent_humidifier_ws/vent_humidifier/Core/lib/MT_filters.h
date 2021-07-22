/*
 * MT_filters.h
 *
 * Created: 6/05/2021 14:14:35
 *  Author: mtorres
 */ 


#ifndef MT_FILTERS_H_
#define MT_FILTERS_H_

/*  File inclusion */
#include <stdint.h>
#include "project_defines.h"

///* Macro definition */
//
//#define RC_LPF_01_FC_HZ                  1.0
//#define RC_LPF_02_FC_HZ                  1.0
//#define RC_LPF_03_FC_HZ                  1.0
//#define RC_LPF_04_FC_HZ                  1.0
//
//#define RC_LPF_01_RC_CONSTANT_S            (1 / (6.28 * RC_LPF_01_FC_HZ))
//#define RC_LPF_02_RC_CONSTANT_S            (1 / (6.28 * RC_LPF_02_FC_HZ))
//#define RC_LPF_03_RC_CONSTANT_S            (1 / (6.28 * RC_LPF_03_FC_HZ))
//#define RC_LPF_04_RC_CONSTANT_S            (1 / (6.28 * RC_LPF_04_FC_HZ))
//
//#define RC_LPF_01_SAMPLE_PERIOD_MS        10
//#define RC_LPF_02_SAMPLE_PERIOD_MS        10
//#define RC_LPF_03_SAMPLE_PERIOD_MS        10
//#define RC_LPF_04_SAMPLE_PERIOD_MS        10


/* Function declaration */

void Filters_Initialize(void);

float RC_LPF_01(float raw_value, uint8_t restart);
float RC_LPF_02(float raw_value, uint8_t restart);
float RC_LPF_03(float raw_value, uint8_t restart);
float RC_LPF_04(float raw_value, uint8_t restart);

void Apply_RC_LPF_01(float signal);
void Apply_RC_LPF_02(float signal);
void Apply_RC_LPF_03(float signal);
void Apply_RC_LPF_04(float signal);

float Get_RC_LPF_01_Output(void);
float Get_RC_LPF_02_Output(void);
float Get_RC_LPF_03_Output(void);
float Get_RC_LPF_04_Output(void);


#endif /* MT_FILTERS_H_ */
