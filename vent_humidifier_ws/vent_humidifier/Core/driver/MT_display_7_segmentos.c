/*
 * display_7_segmentos.c
 *
 *  Created on: 17 dic. 2017
 *      Author: MiguelAngel
 */

#include "main.h"
#include <stdint.h>
#include "MT_display_7_segmentos.h"

/* Variables globales */
volatile uint8_t display_buffer[N_DISPLAYS];
volatile uint8_t display_mask = 0xFF;

/****************************************************************************
* Nombre de la funci�n: Display_Inicializar
* retorna : Nada
* Descripci�n : Configura los pines conectados a los segmentos de los display
* 				y los pines conectados a los habilitadores de cada display
* 				como salidas digitales. Adem�s, inicializa los displays en
* 				estado apagado y los habilitadores desactivados.
* Notas : Se asume que un puerto contiene 8 bits.
*****************************************************************************/
void Display_Inicializar(void){
	/* Inicializar con todos los segmentos apagados*/
	PORT_DISPLAY &= 0xFF00;
	/* Inicializar con todos los habilitadores desactivados*/
	PORT_ENABLES &= ~MASK_ENABLES;
}

/****************************************************************************
* Nombre de la funci�n: Display_Decodificar_Digito
* retorna : d�gito decodificado (uint8_t)
* arg : num_binario
* Descripci�n : Recibe un d�gito (n�mero de 0 a 9), lo decodifica, y retorna
* 				la secuencia de bits correspondiente para mostrar el valor
* 				num�rico del d�gito en un display de 7 segmentos.
* Notas : Debe asegurarse que el valor recibido se encuentra entre 0 y 9.
* 		  Cualquier valor fuera de este rango puede generar errores en la
* 		  ejecuci�n del programa.
*****************************************************************************/
uint8_t Display_Decodificar_Digito_Decimal(uint8_t num_binario){

	/* Tabla de b�squeda para decodificar los d�gitos */
	uint8_t tabla_display[10] = {
									0x3F, // 0
									0x06, // 1
									0x5B, // 2
									0x4F, // 3
									0x66, // 4
									0x6D, // 5
									0x7D, // 6
									0x07, // 7
									0x7F, // 8
									0x6F, // 9
								};

	/* Retorna el valor del d�gito decodificado */
	return tabla_display[num_binario];
}

/****************************************************************************
* Nombre de la funci�n: Display_Decodificar_Entero_Decimal
* retorna : Nada
* arg : num_binario (uint16_t)
* Descripci�n : Recibe un n�mero entero (uint16_t), extrae los N �ltimos
* 				d�gitos, los decodifica y almacena los valores decodificados
* 				en el arreglo display_buffer.
* 				El n�mero de d�gitos extra�dos se encuentra determinado por
* 				el n�mero displays, definido en la constante N_DISPLAYS.
* Notas : La cantidad de d�gitos almacenados en el buffer depende solo de
* 		  la constante N_DISPLAYS, sin importar la cantidad de d�gitos
* 		  significativos que contenga el par�metro num_binario.
*****************************************************************************/
void Display_Decodificar_Entero_Decimal(uint16_t num_binario){

	uint8_t pos_digito;

	/* Extraer los d�gitos (en base decimal)del n�mero deseado*/
	for(pos_digito = 0; pos_digito < N_DISPLAYS; pos_digito++){
		/* Extraer el d�gito de las unidades, decodificarlo y almacenarlo */
		display_buffer[pos_digito] = Display_Decodificar_Digito_Decimal(num_binario % 10);
		/* Desplazar el n�mero un d�gito decimal hacia la derecha */
		num_binario /= 10;
	}
}


void Display_Turn_On(void){
	__disable_irq();
	display_mask = 0xFF;
	__enable_irq();
}

void Display_Turn_Off(void){
	__disable_irq();
	display_mask = 0x00;
	__enable_irq();
}




