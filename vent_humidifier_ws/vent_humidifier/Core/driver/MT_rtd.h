/*
 * MT_rtd.h
 *
 * Created: 25/05/2021 16:52:32
 *  Author: mtorres
 */ 


#ifndef MT_RTD_H_
#define MT_RTD_H_

/* File inclusion */
#include <stdint.h>


/* Constants and macros */

#define A_COEFF							(3.9083e-3)
#define B_COEFF							(-5.775e-7)
#define C_COEFF							(-4.183e-12)

#define R_AT_T0_OHM						1000.0
#define R_AT_T100_OHM					1385.055
#define ALPHA_TEMP_COEFF				((R_AT_T100_OHM - R_AT_T0_OHM)/(100.0 * R_AT_T0_OHM))
#define R_AT_TN100_OHM					602.5584
#define NEG_ALPHA_TEMP_COEFF			((R_AT_TN100_OHM - R_AT_T0_OHM)/(100.0 * R_AT_T0_OHM))

#define RTD_TABLE_MAX_POS_VALUE			100
#define RTD_TABLE_MIN_NEG_VALUE			(-100)
#define RTD_POS_LINEAR_TABLE_N_POINTS   10
#define RTD_NEG_LINEAR_TABLE_N_POINTS   2
#define RTD_POS_LINEAR_TABLE_STEP       (RTD_TABLE_MAX_POS_VALUE / RTD_POS_LINEAR_TABLE_N_POINTS)
#define RTD_NEG_LINEAR_TABLE_STEP       (-RTD_TABLE_MIN_NEG_VALUE / RTD_NEG_LINEAR_TABLE_N_POINTS)

/* Function declaration */
void RTD_Generate_LUT(void);
float RTD_Calculate_R_From_T(float temp);
float RTD_Calculate_T_From_R(float res);
float RTD_Approximate_R_From_T(float temp);
float RTD_Approximate_T_From_R(float res);


#endif /* MT_RTD_H_ */
