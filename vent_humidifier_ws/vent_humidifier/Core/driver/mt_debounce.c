

/* Inclusion de archivos */
#include "main.h"
#include <stdint.h>
#include "mt_debounce.h"

/* Variables globales */
volatile uint16_t g1_button_state;	// debounced and inverted key state:
volatile uint16_t g1_button_press;	// key press detect
volatile uint16_t g1_button_rpt;	// key long press and repeat
volatile uint16_t g1_button_release;



void Button_Debounce_Initialize(void) {

}


uint16_t G1_Get_Button_Press(uint16_t button_mask) {
	__disable_irq();
	// read and clear atomic !
	button_mask &= g1_button_press; // read key(s)
	g1_button_press ^= button_mask; // clear key(s)
	__enable_irq();
	return button_mask;
}



uint16_t G1_Get_Button_Rpt(uint16_t button_mask) {
	__disable_irq();
	// read and clear atomic !
	button_mask &= g1_button_rpt; // read key(s)
	g1_button_rpt ^= button_mask; // clear key(s)
	__enable_irq();
	return button_mask;
}


uint16_t G1_Get_Button_Short(uint16_t button_mask) {
	__disable_irq();
	// read key state and key press atomic !
	return G1_Get_Button_Press(~g1_button_state & button_mask);
}


uint16_t G1_Get_Button_Long(uint16_t button_mask) {
	return G1_Get_Button_Press(G1_Get_Button_Rpt(button_mask));
}



uint16_t G1_Get_Button_Release(uint16_t button_mask) {
	__disable_irq();
	// read and clear atomic !
	button_mask &= g1_button_release; // read key(s)
	g1_button_release ^= button_mask; // clear key(s)
	__enable_irq();
	return button_mask;
}

void Clean_Buttons(void){
	G1_Get_Button_Press(1 << MODE_BUTTON);
	G1_Get_Button_Press(1 << MUTE_BUTTON);
	G1_Get_Button_Press(1 << POWER_BUTTON);
	G1_Get_Button_Long(1 << MODE_BUTTON);
	G1_Get_Button_Long(1 << MUTE_BUTTON);
	G1_Get_Button_Long(1 << POWER_BUTTON);
	G1_Get_Button_Release(1 << MODE_BUTTON);
	G1_Get_Button_Release(1 << MUTE_BUTTON);
	G1_Get_Button_Release(1 << POWER_BUTTON);
}
