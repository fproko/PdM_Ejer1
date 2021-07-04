/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/04
 * Version: v1.2
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "PdM_Ejer1.h"
#include "sapi.h"
#include "Lib_Ejer1.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main(void)
{
	// ----- Setup -----------------------------------
	boardInit();

	int8_t i = 0; 
	delay_t delay;
	delayConfig(&delay, 800);
	static gpioMap_t secuencia1[] = {LEDB, LED1, LED2, LED3};
	static gpioMap_t secuencia2[] = {LED3, LED2, LED1, LEDB};
	static bool_t  flagsControl[] = {FALSE, FALSE, FALSE, FALSE};
	/*
	flagsControl[0]-> Tecla leída
	flagsControl[1]-> Led encendido
	flagsControl[2]-> Leds apagados
	*/
	gpioMap_t * psecuencia = secuencia1;
	const uint8_t ultimoLed = sizeof(secuencia1)/sizeof(gpioMap_t); 
	// ----- Repeat for ever -------------------------
	while (true)
	{
		if (leerTecla(TEC1)==flagsControl[0])
		{
			psecuencia = secuencia1;			
		}
		if (leerTecla(TEC2)==flagsControl[0])
		{
			delayWrite(&delay, 150);
		}
		if (leerTecla(TEC3)==flagsControl[0])
		{
			delayWrite(&delay, 1500);
		}
		if (leerTecla(TEC4)==flagsControl[0])
		{
			psecuencia = secuencia2;
		}

		activarSecuencia(psecuencia,i);

		if (delayRead(&delay))
		{
			i++;
		}
		if (i > ultimoLed - 1)
		{
			i = 0;
		}
	}

	// YOU NEVER REACH HERE, because this program runs directly or on a
	// microcontroller and is not called by any Operating System, as in the
	// case of a PC program.
	return 0;
}
