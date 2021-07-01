/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Date: 2021/06/30
 * Version: v1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "PdM_Ejer1.h"
#include "sapi.h"

bool_t encenderLed(gpioMap_t led){/* encender un led en particular */
	gpioWrite( led, ON );
	return 1;
}

bool_t apagarLeds(){ /* apagar todos los leds */
	gpioWrite( LEDB, OFF );
	gpioWrite( LED1, OFF );
	gpioWrite( LED2, OFF );
	gpioWrite( LED3, OFF );
	return 1;
}

bool_t leerTecla (gpioMap_t tecla){ /* leer el estado de una tecla*/
	  bool_t estado_tecla;
	  estado_tecla = gpioRead( tecla );
	  return estado_tecla;
}

/* psecuencia apunta a una secuencia de leds o arreglo de gpioMap_t */
//void activarSecuencia(gpioMap_t * psecuencia){

//}


/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();

   //tipo *nombre_puntero


   int8_t i = 0;
   uint8_t secuencia = 1;
   delay_t delay;
   delayConfig( &delay, 800 );

   // ----- Repeat for ever -------------------------
   while( true ) {
	  if ( !leerTecla( TEC1 ) ){
	     secuencia= 0;
	  }
	  if ( !leerTecla( TEC2 ) ){
	     delayWrite( &delay, 150 );
	  }
	  if ( !leerTecla( TEC3 ) ){
         delayWrite( &delay, 750 );
      }
	  if ( !leerTecla( TEC4 ) ){
         secuencia = 1;
      }

      if ( delayRead( &delay ) ){
         if ( !secuencia ){
            i--;
         }
         else{
            i++;
         }
      }

	  if ( i == 0 ){
		  apagarLeds();
		  encenderLed( LEDB);
	      }
	  if ( i == 1 ){
		  apagarLeds();
		  encenderLed( LED1);
	      }
	  if ( i == 2 ){
		  apagarLeds();
		  encenderLed( LED2);
	      }
	  if ( i == 3 ){
		  apagarLeds();
		  encenderLed( LED3);
	      }

	      if ( i < 0 ){
	             i = 3;
	          }
	          if ( i > 3 ){
	             i = 0;
	          }

   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
