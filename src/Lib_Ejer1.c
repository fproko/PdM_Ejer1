/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/04
 * Version: v1.2
 *===========================================================================*/
#include "Lib_Ejer1.h"

/*=============================================================================
 * Function: encenderLed 
 * Description: Enciende un led en particular (LEDX) -> LED1, LED2, LED3 o LEDB 
 * Inpunt: Led que se busca encender
 * Output: Valor booleano que indica el encendido exitoso del LEDX
	"1" -> Se completó el encendido del LEDX
 *===========================================================================*/
bool_t encenderLed(gpioMap_t led){
	gpioWrite( led, ON );
	return 1;
}

/*=============================================================================
 * Function: apagarLeds 
 * Description: Apaga todos los Leds
 * Inpunt: No recibe entradas
 * Output: Valor booleano
	"1" -> Se completó el apagado de Leds
 *===========================================================================*/
bool_t apagarLeds(){
	gpioWrite( LEDR, OFF );
	gpioWrite( LEDG, OFF );
	gpioWrite( LEDB, OFF );
	gpioWrite( LED1, OFF );
	gpioWrite( LED2, OFF );
	gpioWrite( LED3, OFF );
	return 1;
}

/*=============================================================================
 * Function: leerTecla 
 * Description: La función lee el estado de la entrada del uC luego de apretar una tecla
 * Inpunt: 
	1) Tecla a leer -> TEC1, TEC2, TEC3 o TEC4
 * Output: Valor booleano estado_tecla
	"0" -> Tecla apretada (ON)
	"1" -> Tecla sin apretar (OFF)
 *===========================================================================*/
bool_t leerTecla(gpioMap_t tecla)
{
	bool_t estado_tecla;
	estado_tecla = gpioRead(tecla);
	return estado_tecla;
}

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
void activarSecuencia(gpioMap_t * psecuencia, int8_t i){
	apagarLeds();
	encenderLed(*(psecuencia+i));
}

