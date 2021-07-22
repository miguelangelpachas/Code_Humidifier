/*
 * Temperature_controller.c
 *
 *  Created on: 7 jun. 2021
 *      Author: mtorres
 */

/* File inclusion */
#include "temperature_controller.h"

/* Function definition */


/* Non-invasive heater with high flow (30 to 60 LPM) */
double Temperature_Controller_01(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset){

    static double ctrl_error[3];
    static double ctrl_output = 0.0;

    if(ctrl_reset){

	    ctrl_error[2] = 0.0;
	    ctrl_error[1] = 0.0;
	    ctrl_error[0] = 0.0;
	    ctrl_output = 0.0;

	 }else{

		ctrl_error[2] = ctrl_error[1];
		ctrl_error[1] = ctrl_error[0];
		ctrl_error[0] = ctrl_setpoint - ctrl_feedback;

//		if(ctrl_error[0] < -0.2){
//		    ctrl_output = 10.0;
//		}else if(ctrl_error[0] < -0.05){
//			ctrl_output = 28.0;
//		}else if(ctrl_error[0] >= 5.0){
//			ctrl_output = 100.0;
//		}else if(ctrl_error[0] >= 0.2){
//			ctrl_output = 42.0;
//		}else if(ctrl_error[0] >= 0.05){
//			ctrl_output = 30.0;
//		}else{
//		   //Does nothing
//		}

		if(ctrl_error[0] < -0.9){
					ctrl_output = 30;
				}else if(ctrl_error[0] < -0.7){
					ctrl_output = 33;
				}else if(ctrl_error[0] < -0.6){
					ctrl_output = 35;
				}else if(ctrl_error[0] < -0.4){
					ctrl_output = 37;
				}else if(ctrl_error[0] < -0.2){
					ctrl_output = 40;
				}else if(ctrl_error[0] >= 0.9){
					ctrl_output = 50;
				}else if(ctrl_error[0] >= 0.8){
					ctrl_output = 49;;
				}else if(ctrl_error[0] >= 0.5){
					ctrl_output = 48;
				}else if(ctrl_error[0] >= 0.4){
					ctrl_output = 47;
				}else if(ctrl_error[0] >= 0.25){
				    ctrl_output = 46;
				}else if(ctrl_error[0] >= 0.1){
					ctrl_output = 44;
				}else{
					//Does nothing
				}

			 }

    return ctrl_output;
}


/* Invasive heater with high flow (30 to 60 LPM) */
double Temperature_Controller_02(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset){

    static double ctrl_error[3];
    static double ctrl_output = 0.0;

    if(ctrl_reset){

	    ctrl_error[2] = 0.0;
	    ctrl_error[1] = 0.0;
	    ctrl_error[0] = 0.0;
	    ctrl_output = 0.0;

	 }else{

		ctrl_error[2] = ctrl_error[1];
		ctrl_error[1] = ctrl_error[0];
		ctrl_error[0] = ctrl_setpoint - ctrl_feedback;

		if(ctrl_error[0] < -0.8){
					ctrl_output = 40;
				}else if(ctrl_error[0] < -0.5){
					ctrl_output = 42;
				}else if(ctrl_error[0] < -0.4){
					ctrl_output = 45;
				}else if(ctrl_error[0] < -0.3){
					ctrl_output = 47;
				}else if(ctrl_error[0] < -0.2){
					ctrl_output = 50;
				}else if(ctrl_error[0]  < -0.1){
					ctrl_output = 50;
				}else if(ctrl_error[0] >= 1.0){
					ctrl_output = 50;
				}else if(ctrl_error[0] >= 0.5){
					ctrl_output = 49;
				}else if(ctrl_error[0] >= 0.4){
					ctrl_output = 48;
				}else if(ctrl_error[0] >= 0.3){
					ctrl_output = 47;
				}else if(ctrl_error[0] >= 0.2){
					ctrl_output = 46;
				}else if(ctrl_error[0] >= 0.1){
					ctrl_output = 45;
				}else if(ctrl_error[0] >= 0.05){
					ctrl_output = 44;
				}else{
					//Does nothing
				}

			 }


    return ctrl_output;
}


/* Non-invasive non-heater with high flow (30 to 60 LPM) */
double Temperature_Controller_03(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset){

    static double ctrl_error[3];
    static double ctrl_output = 0.0;

    if(ctrl_reset){

	    ctrl_error[2] = 0.0;
	    ctrl_error[1] = 0.0;
	    ctrl_error[0] = 0.0;
	    ctrl_output = 0.0;

	 }else{

		ctrl_error[2] = ctrl_error[1];
		ctrl_error[1] = ctrl_error[0];
		ctrl_error[0] = ctrl_setpoint - ctrl_feedback;

		if(ctrl_error[0] < -1.1){
					ctrl_output = 18;
				}else if(ctrl_error[0] < -0.9){
					ctrl_output = 25;
				}else if(ctrl_error[0] < -0.8){
		  			ctrl_output = 26;
				}else if(ctrl_error[0] < -0.6){
				 ctrl_output = 28;
				}else if(ctrl_error[0] < -0.5){
					ctrl_output = 34;
				}else if(ctrl_error[0] < -0.4){
					ctrl_output = 37;
				}else if(ctrl_error[0] < -0.3){
					ctrl_output = 40;
				}else if(ctrl_error[0] < -0.2){
					ctrl_output = 45;
				}else if(ctrl_error[0] >= 1.0){
					ctrl_output = 50;
				}else if(ctrl_error[0] >= 0.6){
					ctrl_output = 47;
				}else if(ctrl_error[0] >= 0.5){
		  		ctrl_output = 48;
				}else if(ctrl_error[0] >= 0.4){
					ctrl_output = 47;
				}else if(ctrl_error[0] >= 0.3){
					ctrl_output = 46;
				}else if(ctrl_error[0] >= 0.2){
				    ctrl_output = 45;
				}else if(ctrl_error[0] >= 0.1){
				    ctrl_output = 44;
				}else{
					//Does nothing
				}

			 }


    return ctrl_output;
}



/* Invasive non-heater with high flow (30 to 60 LPM) */
double Temperature_Controller_04(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset){

    static double ctrl_error[3];
    static double ctrl_output = 0.0;

    if(ctrl_reset){

	    ctrl_error[2] = 0.0;
	    ctrl_error[1] = 0.0;
	    ctrl_error[0] = 0.0;
	    ctrl_output = 0.0;

	 }else{

		ctrl_error[2] = ctrl_error[1];
		ctrl_error[1] = ctrl_error[0];
		ctrl_error[0] = ctrl_setpoint - ctrl_feedback;

		if(ctrl_error[0] < -1.5){
					ctrl_output = 15;
		    	}else if(ctrl_error[0] < -1.0){
		  			ctrl_output = 27;
				}else if(ctrl_error[0] < -0.8){
					ctrl_output = 28;
				}else if(ctrl_error[0] < -0.7){
		  			ctrl_output = 29;
				}else if(ctrl_error[0] < -0.6){
				 ctrl_output = 30;
				}else if(ctrl_error[0] < -0.5){
					ctrl_output = 32;
				}else if(ctrl_error[0] < -0.4){
					ctrl_output = 34;
				}else if(ctrl_error[0] < -0.3){
					ctrl_output = 36;
				}else if(ctrl_error[0] < -0.2){
					ctrl_output = 38;
				}else if(ctrl_error[0] >= 1.0){
					ctrl_output = 50;
				}else if(ctrl_error[0] >= 0.7){
					ctrl_output = 48;
				}else if(ctrl_error[0] >= 0.6){
		  			ctrl_output = 47;
		    	}else if(ctrl_error[0] >= 0.5){
		  		ctrl_output = 46;
				}else if(ctrl_error[0] >= 0.4){
					ctrl_output = 45;
				}else if(ctrl_error[0] >= 0.3){
					ctrl_output = 44;
				}else if(ctrl_error[0] >= 0.2){
				    ctrl_output = 43;
				}else if(ctrl_error[0] >= 0.1){
				    ctrl_output = 42;
				}else{

				}
			}
    return ctrl_output;
}


/* Invasive heater with high flow (30 to 60 LPM) FOR HEATING WIRE */
double Temperature_Controller_05(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset){

    static double ctrl_error[3];
    static double ctrl_output = 0.0;

    if(ctrl_reset){

	    ctrl_error[2] = 0.0;
	    ctrl_error[1] = 0.0;
	    ctrl_error[0] = 0.0;
	    ctrl_output = 0.0;

	 }else{

		ctrl_error[2] = ctrl_error[1];
		ctrl_error[1] = ctrl_error[0];
		ctrl_error[0] = ctrl_setpoint - ctrl_feedback;

		if(ctrl_error[0] < -3.0){
									ctrl_output = 0;
								}else if(ctrl_error[0] < -1.0){
									ctrl_output = 65;
								}else if(ctrl_error[0] < -0.8){
						  			ctrl_output = 70;
						    	}else if(ctrl_error[0] < -0.7){
						  			ctrl_output = 73;
								}else if(ctrl_error[0] < -0.6){
									ctrl_output = 76;
								}else if(ctrl_error[0] < -0.5){
									ctrl_output = 80;
								}else if(ctrl_error[0] < -0.4){
									ctrl_output = 84;
								}else if(ctrl_error[0] < -0.3){
									ctrl_output = 88;
								}else if(ctrl_error[0] < -0.2){
									ctrl_output = 95;
								}else if(ctrl_error[0] >= 1.0){
									ctrl_output = 100;
								}else if(ctrl_error[0] >= 0.7){
									ctrl_output = 99;
								}else if(ctrl_error[0] >= 0.6){
						  			ctrl_output = 98;
								}else if(ctrl_error[0] >= 0.5){
									ctrl_output = 97;
								}else if(ctrl_error[0] >= 0.4){
									ctrl_output = 96;
								}else if(ctrl_error[0] >= 0.3){
									ctrl_output = 95;
								}else if(ctrl_error[0] >= 0.2){
								    ctrl_output = 92;
								}else if(ctrl_error[0] >= 0.1){
								    ctrl_output = 90;
								}else{

								}

			 }

    return ctrl_output;
}


/* Non-invasive heater with high flow (30 to 60 LPM) FOR HEATING WIRE */
double Temperature_Controller_06(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset){

    static double ctrl_error[3];
    static double ctrl_output = 0.0;

    if(ctrl_reset){

	    ctrl_error[2] = 0.0;
	    ctrl_error[1] = 0.0;
	    ctrl_error[0] = 0.0;
	    ctrl_output = 0.0;

	 }else{

		ctrl_error[2] = ctrl_error[1];
		ctrl_error[1] = ctrl_error[0];
		ctrl_error[0] = ctrl_setpoint - ctrl_feedback;

		if(ctrl_error[0] < -3.0){
							ctrl_output = 30;
						}else if(ctrl_error[0] < -1.0){
							ctrl_output = 50;
						}else if(ctrl_error[0] < -0.8){
				  			ctrl_output = 60;
				    	}else if(ctrl_error[0] < -0.7){
				  			ctrl_output = 70;
						}else if(ctrl_error[0] < -0.6){
							ctrl_output = 80;
						}else if(ctrl_error[0] < -0.5){
							ctrl_output = 83;
						}else if(ctrl_error[0] < -0.4){
							ctrl_output = 85;
						}else if(ctrl_error[0] < -0.3){
							ctrl_output = 87;
						}else if(ctrl_error[0] < -0.2){
							ctrl_output = 88;
						}else if(ctrl_error[0] >= 1.0){
							ctrl_output = 100;
						}else if(ctrl_error[0] >= 0.7){
							ctrl_output = 99;
						}else if(ctrl_error[0] >= 0.6){
				  			ctrl_output = 98;
						}else if(ctrl_error[0] >= 0.5){
							ctrl_output = 97;
						}else if(ctrl_error[0] >= 0.4){
							ctrl_output = 96;
						}else if(ctrl_error[0] >= 0.3){
							ctrl_output = 95;
						}else if(ctrl_error[0] >= 0.2){
						    ctrl_output = 94;
						}else if(ctrl_error[0] >= 0.1){
						    ctrl_output = 93;
						}else{

						}

			 }

    return ctrl_output;
}


void Temperature_Controllers_Initialize(void){
	Temperature_Controller_01(0.0, 0.0, 1);
	Temperature_Controller_02(0.0, 0.0, 1);
	Temperature_Controller_03(0.0, 0.0, 1);
	Temperature_Controller_04(0.0, 0.0, 1);
	Temperature_Controller_05(0.0, 0.0, 1);
	Temperature_Controller_06(0.0, 0.0, 1);
	Temperature_Controller_07(0.0, 0.0, 1);
	Temperature_Controller_08(0.0, 0.0, 1);
	Temperature_Controller_09(0.0, 0.0, 1);
	Temperature_Controller_10(0.0, 0.0, 1);
	Temperature_Controller_11(0.0, 0.0, 1);
	Temperature_Controller_12(0.0, 0.0, 1);
}



/* Non-invasive heater with low flow (20 to 40 LPM) */
double Temperature_Controller_07(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset){

    static double ctrl_error[3];
    static double ctrl_output = 0.0;

    if(ctrl_reset){

	    ctrl_error[2] = 0.0;
	    ctrl_error[1] = 0.0;
	    ctrl_error[0] = 0.0;
	    ctrl_output = 0.0;

	 }else{

		ctrl_error[2] = ctrl_error[1];
		ctrl_error[1] = ctrl_error[0];
		ctrl_error[0] = ctrl_setpoint - ctrl_feedback;

//		if(ctrl_error[0] < -0.2){
//		    ctrl_output = 10.0;
//		}else if(ctrl_error[0] < -0.05){
//			ctrl_output = 28.0;
//		}else if(ctrl_error[0] >= 5.0){
//			ctrl_output = 100.0;
//		}else if(ctrl_error[0] >= 0.2){
//			ctrl_output = 42.0;
//		}else if(ctrl_error[0] >= 0.05){
//			ctrl_output = 30.0;
//		}else{
//		   //Does nothing
//		}

		if(ctrl_error[0] < -0.9){
					ctrl_output = 5;
				}else if(ctrl_error[0] < -0.7){
					ctrl_output = 16;
				}else if(ctrl_error[0] < -0.6){
					ctrl_output = 19;
				}else if(ctrl_error[0] < -0.4){
					ctrl_output = 21;
				}else if(ctrl_error[0] < -0.2){
					ctrl_output = 27;
				}else if(ctrl_error[0] >= 0.9){
					ctrl_output = 47;
				}else if(ctrl_error[0] >= 0.8){
					ctrl_output = 45;
				}else if(ctrl_error[0] >= 0.5){
					ctrl_output = 34;
				}else if(ctrl_error[0] >= 0.4){
					ctrl_output = 32;
				}else if(ctrl_error[0] >= 0.25){
				    ctrl_output = 30;
				}else if(ctrl_error[0] >= 0.1){
					ctrl_output = 27;
				}else{
					//Does nothing
				}

			 }

    return ctrl_output;
}


/* Invasive heater with low flow (20 to 40 LPM) */
double Temperature_Controller_08(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset){

    static double ctrl_error[3];
    static double ctrl_output = 0.0;

    if(ctrl_reset){

	    ctrl_error[2] = 0.0;
	    ctrl_error[1] = 0.0;
	    ctrl_error[0] = 0.0;
	    ctrl_output = 0.0;

	 }else{

		ctrl_error[2] = ctrl_error[1];
		ctrl_error[1] = ctrl_error[0];
		ctrl_error[0] = ctrl_setpoint - ctrl_feedback;

		if(ctrl_error[0] < -0.8){
					ctrl_output = 39;
				}else if(ctrl_error[0] < -0.5){
					ctrl_output = 40;
				}else if(ctrl_error[0] < -0.4){
					ctrl_output = 41;
				}else if(ctrl_error[0] < -0.3){
					ctrl_output = 42;
				}else if(ctrl_error[0] < -0.2){
					ctrl_output = 43;
				}else if(ctrl_error[0]  < -0.1){
					ctrl_output = 44;
				}else if(ctrl_error[0] >= 1.0){
					ctrl_output = 100;
				}else if(ctrl_error[0] >= 0.5){
					ctrl_output = 90;
				}else if(ctrl_error[0] >= 0.4){
					ctrl_output = 80;
				}else if(ctrl_error[0] >= 0.3){
					ctrl_output = 70;
				}else if(ctrl_error[0] >= 0.2){
					ctrl_output = 60;
				}else if(ctrl_error[0] >= 0.1){
					ctrl_output = 45;
				}else if(ctrl_error[0] >= 0.05){
					ctrl_output = 44;
				}else{
					//Does nothing
				}

			 }

    return ctrl_output;
}


/* Non-invasive non-heater with low flow (20 to 40 LPM) */
double Temperature_Controller_09(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset){

    static double ctrl_error[3];
    static double ctrl_output = 0.0;

    if(ctrl_reset){

	    ctrl_error[2] = 0.0;
	    ctrl_error[1] = 0.0;
	    ctrl_error[0] = 0.0;
	    ctrl_output = 0.0;

	 }else{

		ctrl_error[2] = ctrl_error[1];
		ctrl_error[1] = ctrl_error[0];
		ctrl_error[0] = ctrl_setpoint - ctrl_feedback;

		if(ctrl_error[0] < -1.1){
					ctrl_output = 5;
				}else if(ctrl_error[0] < -0.9){
					ctrl_output = 19;
				}else if(ctrl_error[0] < -0.8){
		  			ctrl_output = 20;
				}else if(ctrl_error[0] < -0.6){
				 ctrl_output = 22;
				}else if(ctrl_error[0] < -0.5){
					ctrl_output = 25;
				}else if(ctrl_error[0] < -0.4){
					ctrl_output = 26;
				}else if(ctrl_error[0] < -0.3){
					ctrl_output = 31;
				}else if(ctrl_error[0] < -0.2){
					ctrl_output = 33;
				}else if(ctrl_error[0] >= 1.0){
					ctrl_output = 46;
				}else if(ctrl_error[0] >= 0.6){
					ctrl_output = 41;
				}else if(ctrl_error[0] >= 0.5){
		  		ctrl_output = 40;
				}else if(ctrl_error[0] >= 0.4){
					ctrl_output = 39;
				}else if(ctrl_error[0] >= 0.3){
					ctrl_output = 38;
				}else if(ctrl_error[0] >= 0.2){
				    ctrl_output = 37;
				}else if(ctrl_error[0] >= 0.1){
				    ctrl_output = 36;
				}else{
					//Does nothing
				}

			 }


    return ctrl_output;
}


/* Invasive non-heater with low flow (20 to 40 LPM) */
double Temperature_Controller_10(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset){

    static double ctrl_error[3];
    static double ctrl_output = 0.0;

    if(ctrl_reset){

	    ctrl_error[2] = 0.0;
	    ctrl_error[1] = 0.0;
	    ctrl_error[0] = 0.0;
	    ctrl_output = 0.0;

	 }else{

		ctrl_error[2] = ctrl_error[1];
		ctrl_error[1] = ctrl_error[0];
		ctrl_error[0] = ctrl_setpoint - ctrl_feedback;

		if(ctrl_error[0] < -1.5){
				ctrl_output = 11;
	    	}else if(ctrl_error[0] < -1.0){
	  			ctrl_output = 23;
			}else if(ctrl_error[0] < -0.8){
				ctrl_output = 24;
			}else if(ctrl_error[0] < -0.7){
	  			ctrl_output = 25;
			}else if(ctrl_error[0] < -0.6){
			 ctrl_output = 26;
			}else if(ctrl_error[0] < -0.5){
				ctrl_output = 28;
			}else if(ctrl_error[0] < -0.4){
				ctrl_output = 29;
			}else if(ctrl_error[0] < -0.3){
				ctrl_output = 32;
			}else if(ctrl_error[0] < -0.2){
				ctrl_output = 34;
			}else if(ctrl_error[0] >= 1.0){
				ctrl_output = 46;
			}else if(ctrl_error[0] >= 0.7){
				ctrl_output = 47;
			}else if(ctrl_error[0] >= 0.6){
	  			ctrl_output = 43;
	    	}else if(ctrl_error[0] >= 0.5){
	  		ctrl_output = 42;
			}else if(ctrl_error[0] >= 0.4){
				ctrl_output = 41;
			}else if(ctrl_error[0] >= 0.3){
				ctrl_output = 40;
			}else if(ctrl_error[0] >= 0.2){
			    ctrl_output = 39;
			}else if(ctrl_error[0] >= 0.1){
			    ctrl_output = 38;
			}else{

			}
		}
    return ctrl_output;
}


/* Invasive heater with low flow (20 to 40 LPM) FOR HEATING WIRE */
double Temperature_Controller_11(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset){

    static double ctrl_error[3];
    static double ctrl_output = 0.0;

    if(ctrl_reset){

	    ctrl_error[2] = 0.0;
	    ctrl_error[1] = 0.0;
	    ctrl_error[0] = 0.0;
	    ctrl_output = 0.0;

	 }else{

		ctrl_error[2] = ctrl_error[1];
		ctrl_error[1] = ctrl_error[0];
		ctrl_error[0] = ctrl_setpoint - ctrl_feedback;

		if(ctrl_error[0] < -3.0){
									ctrl_output = 0;
								}else if(ctrl_error[0] < -1.0){
									ctrl_output = 72;
								}else if(ctrl_error[0] < -0.8){
						  			ctrl_output = 73;
						    	}else if(ctrl_error[0] < -0.7){
						  			ctrl_output = 74;
								}else if(ctrl_error[0] < -0.6){
									ctrl_output = 75;
								}else if(ctrl_error[0] < -0.5){
									ctrl_output = 78;
								}else if(ctrl_error[0] < -0.4){
									ctrl_output = 81;
								}else if(ctrl_error[0] < -0.3){
									ctrl_output = 83;
								}else if(ctrl_error[0] < -0.2){
									ctrl_output = 90;
								}else if(ctrl_error[0] >= 1.0){
									ctrl_output = 100;
								}else if(ctrl_error[0] >= 0.7){
									ctrl_output = 99;
								}else if(ctrl_error[0] >= 0.6){
						  			ctrl_output = 98;
								}else if(ctrl_error[0] >= 0.5){
									ctrl_output = 97;
								}else if(ctrl_error[0] >= 0.4){
									ctrl_output = 96;
								}else if(ctrl_error[0] >= 0.3){
									ctrl_output = 95;
								}else if(ctrl_error[0] >= 0.2){
								    ctrl_output = 94;
								}else if(ctrl_error[0] >= 0.1){
								    ctrl_output = 92;
								}else{

								}

			 }

    return ctrl_output;
}


/* Non-invasive heater with low flow (20 to 40 LPM) FOR HEATING WIRE */
double Temperature_Controller_12(double ctrl_setpoint, double ctrl_feedback, uint8_t ctrl_reset){

    static double ctrl_error[3];
    static double ctrl_output = 0.0;

    if(ctrl_reset){

	    ctrl_error[2] = 0.0;
	    ctrl_error[1] = 0.0;
	    ctrl_error[0] = 0.0;
	    ctrl_output = 0.0;

	 }else{

		ctrl_error[2] = ctrl_error[1];
		ctrl_error[1] = ctrl_error[0];
		ctrl_error[0] = ctrl_setpoint - ctrl_feedback;

		if(ctrl_error[0] < -3.0){
							ctrl_output = 27;
						}else if(ctrl_error[0] < -1.0){
							ctrl_output = 31;
						}else if(ctrl_error[0] < -0.8){
				  			ctrl_output = 36;
				    	}else if(ctrl_error[0] < -0.7){
				  			ctrl_output = 41;
						}else if(ctrl_error[0] < -0.6){
							ctrl_output = 46;
						}else if(ctrl_error[0] < -0.5){
							ctrl_output = 51;
						}else if(ctrl_error[0] < -0.4){
							ctrl_output = 56;
						}else if(ctrl_error[0] < -0.3){
							ctrl_output = 61;
						}else if(ctrl_error[0] < -0.2){
							ctrl_output = 66;
						}else if(ctrl_error[0] >= 1.0){
							ctrl_output = 100;
						}else if(ctrl_error[0] >= 0.7){
							ctrl_output = 93;
						}else if(ctrl_error[0] >= 0.6){
				  			ctrl_output = 91;
						}else if(ctrl_error[0] >= 0.5){
							ctrl_output = 86;
						}else if(ctrl_error[0] >= 0.4){
							ctrl_output = 81;
						}else if(ctrl_error[0] >= 0.3){
							ctrl_output = 78;
						}else if(ctrl_error[0] >= 0.2){
						    ctrl_output = 75;
						}else if(ctrl_error[0] >= 0.1){
						    ctrl_output = 71;
						}else{

						}

			 }

    return ctrl_output;
}

