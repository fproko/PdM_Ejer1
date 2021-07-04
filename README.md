# PdM - Práctica clase 1
Autores:
        Armando Suhuan 
        Fernando Prokopiuk

Última actualización: 04/07/2021
# Ejercicio 1
Prender secuencialmente los leds de la placa LED1, LED2, LED3 y LEDB.

**Condiciones de funcionamiento**
- Una vez que se pasa al siguiente led los demás deberán apagarse.
- Utilizar solamente LED azul de los leds RGB.
- Controlar el sentido de la secuencia con los botones TEC1 y TEC4:
    - Incialmente la secuencia es LEDB -> LED1 -> LED2 -> LED3 ...
    - Al presionar TEC4 recorre una secuencia inversa : LED3 -> LED2 -> LED1 -> LEDB ...
    - Al presionar TEC1 recorre la secuencia original: LEDB -> LED1 -> LED2 -> LED3 ...
- Controlar el tiempo de encendido de los leds dentro de la secuencia:
    - Al presionar TEC2 cada led queda encendido 150 ms.
    - Al presionar TEC3 cada led queda encendido 750 ms.

Objetivo:

1.Utilizar funciones que encapsulen el código y hagan el programa más legible, como
por ejemplo:
    
    /* encender un led en particular */
    bool_t encenderLed(gpioMap_t led); 

    /* apagar todos los leds */
    bool_t apagarLeds(); 
    
    /* leer el estado de una tecla. Devuelve por valor el estado de la tecla pulsada (verdadero) o liberada (falso)*/
    bool_t leerTecla (gpioMap_t tecla); 

    /* psecuencia apunta a una secuencia de leds o arreglo de gpioMap_t */
    void activarSecuencia(gpioMap_t * psecuencia, int8_t i); 

Las funciones deben devolver verdadero o falso en función de si pudieron realizar su
tarea correctamente o no o si la tecla está presionada o no, según corresponda.

2.Incorpora conceptos de programación defensiva al código:
- Limitar la visibilidad de la información al mínimo:
- Uso de variables locales en lugar de globales, preferentemente.
- Uso de modificador static donde corresponda.
- Verificar los valores de retorno de las funciones.
- Verificar los parámetros/argumentos antes de utilizarlos.

3.[OPCIONAL] Utilizar arreglos para hacer la implementación reutilizable y escalable,
por ejemplo:.




