/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/04
 * Version: v1.2
 *===========================================================================*/
#ifndef MISPROGS_PDM_EJER1_LIB_EJER1_H_
#define MISPROGS_PDM_EJER1_LIB_EJER1_H_

#include "sapi.h"

/*=============================================================================
 * Function: encenderLed 
 * Description: Enciende un led en particular (LEDX) -> LED1, LED2, LED3 o LEDB 
 * Inpunt: Led que se busca encender
 * Output: Valor booleano que indica el encendido exitoso del LEDX
	"1" -> Se completó el encendido del LEDX
 *===========================================================================*/
bool_t encenderLed(gpioMap_t led);

/*=============================================================================
 * Function: apagarLeds 
 * Description: Apaga todos los Leds
 * Inpunt: No recibe entradas
 * Output: Valor booleano
	"1" -> Se completó el apagado de Leds
 *===========================================================================*/
bool_t apagarLeds();

/*=============================================================================
 * Function: leerTecla 
 * Description: La función lee el estado de la entrada del uC luego de apretar una tecla
 * Inpunt: 
	1) Tecla a leer -> TEC1, TEC2, TEC3 o TEC4
 * Output: Valor booleano estado_tecla
	"0" -> Tecla apretada (ON)
	"1" -> Tecla sin apretar (OFF)
 *===========================================================================*/
bool_t leerTecla (gpioMap_t tecla);

/*=============================================================================
 * Function: activarSecuencia 
 * Description: Enciende el Led correspondiente a la posición dentro de una secuencia determinada

Secuencia 1:					Secuencia 2:
	 ____ ____ ____ ____		 ____ ____ ____ ____
    |LEDB|LED1|LED2|LED3|		|LED3|LED2|LED1|LEDB|
i->   0     1    2    3	     i->  0     1    2    3		

 * Inpunt: 
	1) Puntero que apunta a la secuencia según la tecla presionada
	2) Posición del Led que corresponde encender dentro la secuencia que corresponda.
 * Output: No devuelve salida
 *===========================================================================*/
void activarSecuencia(gpioMap_t * psecuencia, int8_t i);

#endif /* MISPROGS_PDM_EJER1_LIB_EJER1_H_ */
