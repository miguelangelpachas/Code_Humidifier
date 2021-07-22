

#ifndef MT_NTC_H_
#define MT_NTC_H_

/* File inclusion */
#include <stdint.h>
#include <math.h>

/* Constants and macros */
#define NTC_BASE_POINT_TEMP_C       25
#define NTC_BASE_POINT_TEMP_K       (NTC_BASE_POINT_TEMP_C + 273.15)
#define NTC_R_AT_BASE_POINT_TEMP    10000.0
#define NTC_BETA_COEFFICIENT        3435.0 //Beta 25/85

#define NTC_TABLE_MAX_POS_VALUE			125
#define NTC_TABLE_MIN_NEG_VALUE			(-40)
#define NTC_POS_LINEAR_TABLE_N_POINTS   25
#define NTC_NEG_LINEAR_TABLE_N_POINTS   2
#define NTC_POS_LINEAR_TABLE_STEP       (NTC_TABLE_MAX_POS_VALUE / NTC_POS_LINEAR_TABLE_N_POINTS)
#define NTC_NEG_LINEAR_TABLE_STEP       (-NTC_TABLE_MIN_NEG_VALUE / NTC_NEG_LINEAR_TABLE_N_POINTS)


/* Function declaration */
void NTC_Generate_LUT(void);
float NTC_Calculate_R_From_T(float temp);
float NTC_Calculate_T_From_R(float res);

#endif

