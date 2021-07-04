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
 * encender un led en particular
 *===========================================================================*/
bool_t encenderLed(gpioMap_t led);

/*=============================================================================
 * Function: apagarLeds
 * apagar todos los leds
 *===========================================================================*/
bool_t apagarLeds();

/*=============================================================================
 * Function: leerTecla 
 * leer el estado de una tecla
 *===========================================================================*/
bool_t leerTecla (gpioMap_t tecla);

/*=============================================================================
 * Function: activarSecuencia 
 * psecuencia apunta a una secuencia de leds o arreglo de gpioMap_t
 *===========================================================================*/
void activarSecuencia(gpioMap_t * psecuencia, int8_t i);

#endif /* MISPROGS_PDM_EJER1_LIB_EJER1_H_ */
