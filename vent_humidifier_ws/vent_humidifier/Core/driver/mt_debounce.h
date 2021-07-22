
#ifndef MT_DEBOUNCE_H_
#define MT_DEBOUNCE_H_

#include "project_defines.h"

#define PIN_BUTTON_G1		(GPIOB->IDR)

#define BUTTON_01			POWER_BUTTON
#define BUTTON_02			MODE_BUTTON
#define BUTTON_03			MUTE_BUTTON
#define BUTTON_04			HEATER_WIRE_01_FEEDBACK
#define BUTTON_05			HEATER_WIRE_02_FEEDBACK

#define G1_ALL_BUTTON_MASK	((1 << BUTTON_01) | (1 << BUTTON_02) | (1 << BUTTON_03) | (1 << BUTTON_04) | (1 << BUTTON_05))
#define G1_REPEAT_MASK		((1 << BUTTON_01) | (1 << BUTTON_02) | (1 << BUTTON_03))

#define REPEAT_START    100
#define REPEAT_NEXT     20
#define KEY_NULL		-1


/* Variables globales */
extern volatile uint16_t g1_button_state;	// debounced and inverted key state:
extern volatile uint16_t g1_button_press;	// key press detect
extern volatile uint16_t g1_button_rpt;	// key long press and repeat
extern volatile uint16_t g1_button_release;


/* Decaracion de funciones (prototipos) */

void Button_Debounce_Initialize(void);

uint16_t G1_Get_Button_Press(uint16_t button_mask);
uint16_t G1_Get_Button_Rpt(uint16_t button_mask);
uint16_t G1_Get_Button_Short(uint16_t button_mask);
uint16_t G1_Get_Button_Long(uint16_t button_mask);
uint16_t G1_Get_Button_Release(uint16_t button_mask);
void Clean_Buttons(void);

/****************************************************************************
* Nombre de la funci�n: Gx_Button_Scan
* retorna : Nada
* arg : Ninguno
* Descripci�n : Esta funci�n mide los valores de los botones, elimina los
* 				efectos de los rebotes mec�nicos, y determina si un bot�n
* 				ha sido pulsado.
*
* 				La variable boton_pulsado indica los botones que han sido
* 				pulsados: el valor de cada bit en esta variable representa
* 				el estado de un bot�n. Por ejemplo: si el bit 3 de la
* 				variable boton_pulsado es '1', eso indica que el BUTTON3
* 				de la entrada PIN_BUTTON ha sido pulsado.
*
* 				De forma an�loga, el estado del bot�n (PRESIONADO --> 1,
* 				SUELTO --> 0), con los rebotes filtrados, se indica en
* 				cada uno de los bits de la variable boton_Estado
*
* Notas : 		Esta funci�n debe ser llamada, peri�dicamente. Es necesario
* 				llamar a esta funci�n antes de utilizar la funci�n de nombre
* 				Botones_Escanear.
*****************************************************************************/


//void buttonDebounce(void){
	//static unsigned char ct0, ct1;
	//unsigned char k = 0;
//
	//k = button_state ^ (~buttons);           // button changed ?
	//ct1 = (ct0 ^ ct1) & k;                   // reset or count ct1
	//ct0 = (~ct0) & k;                        // reset or count ct0
	//k &= ct0 & ct1;                          // count until roll over
	//button_state ^= k;                       // then toggle debounced state
	//button_press |= button_state & k;        // 0->1: button press detect
//
//}




static inline void G1_Button_Scan(void){
	
	uint16_t button_change, aux;
	static uint16_t counter0, counter1;
	static uint16_t g1_rpt;	
	
	// Si emplea resistencia pull-down
	//button_change = g1_button_state ^ PIN_BUTTON_G1;
	// Si emplea resistencia pull-up
	button_change = g1_button_state ^ (~PIN_BUTTON_G1);	
	
	counter1 = (counter0 ^ counter1) & button_change;   // reset or count counter bit 1
	counter0 = (~counter0) & button_change;              // reset or count counter bit 0
	aux = button_change & counter0 & counter1;          // count until roll over
	g1_button_state ^= aux;								// then toggle debounced state  
	g1_button_press |= (g1_button_state & aux);
	g1_button_release |= (~g1_button_state & aux);                    

	if ((g1_button_state & G1_REPEAT_MASK) == 0){
		g1_rpt = REPEAT_START;
	}
	
	if (--g1_rpt == 0) {
		g1_rpt = REPEAT_NEXT;
		g1_button_rpt |= g1_button_state & G1_REPEAT_MASK;
	}	
}


#endif
