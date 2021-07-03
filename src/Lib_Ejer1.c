/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/03
 * Version: v1.1
 *===========================================================================*/
#include "Lib_Ejer1.h"

/*=============================================================================
 * Function: encenderLed 
 * encender un led en particular
 *===========================================================================*/
bool_t encenderLed(gpioMap_t led){
	gpioWrite( led, ON );
	return 1;
}

/*=============================================================================
 * Function: apagarLeds 
 * apagar todos los leds
 *===========================================================================*/
bool_t apagarLeds(){
	gpioWrite( LEDB, OFF );
	gpioWrite( LED1, OFF );
	gpioWrite( LED2, OFF );
	gpioWrite( LED3, OFF );
	return 1;
}

/*=============================================================================
 * Function: leerTecla 
 * leer el estado de una tecla
 *===========================================================================*/
bool_t leerTecla (gpioMap_t tecla){
	  bool_t estado_tecla;
	  estado_tecla = gpioRead( tecla );
	  return estado_tecla;
}

