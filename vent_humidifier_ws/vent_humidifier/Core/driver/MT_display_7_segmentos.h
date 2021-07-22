/*
 * MT_display_7_segmentos.h
 *
 * Created: 4/05/2021 10:49:37
 *  Author: mtorres
 */ 


#ifndef MT_DISPLAY_7_SEGMENTOS_H_
#define MT_DISPLAY_7_SEGMENTOS_H_

/* Inclusiones */
#include "main.h"
#include <stdint.h>
#include "project_defines.h"

/* Constantes y macros */

//// Cantidad de displays
//#define	N_DISPLAYS	3

//// Definici�n de pines
//#define PORT_DISPLAY					(GPIOA->ODR)
//#define PORT_ENABLES					(GPIOB->ODR)
//#define EN_0							10
//#define EN_1							1
//#define EN_2							0
//
//#define MASK_ENABLES					((1 << EN_0) | (1 << EN_1) | (1 << EN_2))

/* Variables globales */
extern volatile uint8_t display_buffer[N_DISPLAYS];
extern volatile uint8_t display_mask;

/* Declaraci�n de funciones (prototipos) */
void Display_Inicializar(void);
uint8_t Display_Decodificar_Digito(uint8_t num_binario);
void Display_Decodificar_Entero_Decimal(uint16_t num_binario);
void Display_Turn_On(void);
void Display_Turn_Off(void);


/****************************************************************************
* Nombre de la funci�n: Display_Gestionar_Habilitadores
* retorna : Nada
* Descripci�n : Desactiva todos los habilitadores, actualiza el valor que se
* 				mostrar� sobre los displays (segmentos encendidos) y activa
* 				el habilitador correspondiente.
* Notas : Esta funci�n debe ser invocada peri�dicamente con una frecuencia
* 		  lo suficientemente alta como para que no se perciban interrupciones
* 		  en la visualizaci�n de los d�gitos.
*****************************************************************************/
static inline void Display_Gestionar_Habilitadores(void){

	uint8_t posicion_enable[N_DISPLAYS] = {EN_0, EN_1, EN_2};

	static uint8_t pos_digito = 0;

	// Apagar todos los displays
	PORT_ENABLES &= ~MASK_ENABLES;
	// Cargar el digito correspondiente a los segmentos
	PORT_DISPLAY &= 0xFF00;
	PORT_DISPLAY |= display_buffer[pos_digito] & display_mask;
	// Habilitar el display correspondiente
	PORT_ENABLES |= (1 << posicion_enable[pos_digito]);
	// Actualizar el valor de la posici�n
	pos_digito++;
	if(pos_digito >= N_DISPLAYS){
		pos_digito = 0;
	}
}



#endif /* MT_DISPLAY_7_SEGMENTOS_H_ */
