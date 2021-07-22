
/* FIle inclusion */
#include "fuzzy_controller_basic.h"

/* Variabledefinition */

static double ge_01 = 0.0 , gce_01 = 0.0 , gcu_01 = 0.0;



/* Function definition */


void Flow_Fuzzy_Linear_PD_Controller(double error, double error_change, double *controller_output){

    /* Set boundaries for error input */
    if(error < -1.0){
        error = -1.0;
    }else if(error > 1.0){
        error = 1.0;
    }else{
        /* Does nothing */
    }

    /* Set boundaries for error change input */
    if(error_change < -1.0){
        error_change = -1.0;
    }else if(error_change > 1.0){
        error_change = 1.0;
    }else{
        /* Does nothing */
    }

    *controller_output = (error + error_change) / 2.0;

}


float Flow_Fuzzy_Incremental_Controller(float control_setpoint, float control_feedback, uint8_t control_reset){

    static double error[2];
    double fuzzy_error;
    double error_change, fuzzy_error_change;
    static double fuzzy_output[2] = {0.0, 0.0};
    static double controller_output = 0.0;
    double delta_area;

    if(control_reset){
       error[0] = 0.0;
       error[1] = 0.0;
       fuzzy_output[0] = 0.0;
       fuzzy_output[1] = 0.0;
       controller_output = 0.0;
    }else{
        error[1] = error[0];
        error[0] = control_setpoint - control_feedback;

        error_change = (error[0] - error[1]) / FUZZY_CONTROLLER_SAMPLE_PERIOD_S;

        fuzzy_error = ge_01 * error[0];
        fuzzy_error_change = gce_01 * error_change;

        fuzzy_output[1] = fuzzy_output[0];
        Flow_Fuzzy_Linear_PD_Controller(fuzzy_error, fuzzy_error_change, &fuzzy_output[0]);
        fuzzy_output[0] *= gcu_01;

        delta_area = FUZZY_CONTROLLER_SAMPLE_PERIOD_S * (fuzzy_output[0] + fuzzy_output[1]) / 2.0;
        controller_output += delta_area;

        if(controller_output < FUZZY_CONTROL_01_MIN_OUTPUT){
            controller_output = FUZZY_CONTROL_01_MIN_OUTPUT;
        }else if(controller_output > FUZZY_CONTROL_01_MAX_OUTPUT){
            controller_output = FUZZY_CONTROL_01_MAX_OUTPUT;
        }else{
            /* Does nothing */
        }

    }

    return (float)controller_output;

}

void Fuzzy_Inremental_Controller_01_Set_Parameters(float new_ge, float new_gce, float new_gcu){
	ge_01 = new_ge;
	gce_01 = new_gce;
	gcu_01 = new_gcu;
}


void Fuzzy_Controllers_Initialize(void){
	Flow_Fuzzy_Incremental_Controller(0.0, 0.0, 1);
}


