/*! @file : K32L2B31A_Project.c
 * @author  Ernesto Andres Rincon Cruz
 * @version 0.0.000
 * @date    23/08/2021
 * @brief   Funcion principal main
 * @details
 *			v0.0.000	Proyecto base creado usando MCUXpresso
 *
 *
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "K32L2B31A.h"
#include "fsl_debug_console.h"

#include "leds.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/

/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Local vars
 ******************************************************************************/
unsigned int test_global_var=100;
float dato_float=3.1416;
/*******************************************************************************
 * Private Source Code
 ******************************************************************************/
/*!
 * @brief genera bloqueo de microcontrolador por tiempo fijo
 *
 */
void delay_block(void){
	uint32_t i;
	for(i=0;i<0xFFFFF;i++){

	}
}

int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    PRINTF("Hello World\r\n");
    printf("test_global_var:%d\r\n",test_global_var);
    printf("dato_float:%g\r\n",dato_float);





    volatile static int i = 0 ;/* Force the counter to be placed into memory. */
    /* Enter an infinite loop, just incrementing a counter. */
    printf("Inicia");

    bool intercambio = false;

    while(1) {

        for(short k = 0; k < 10 ; k++ ) {
            encender_led_verde();
            delay_block();
            apagar_led_verde();
            delay_block();
        }

        if( !intercambio ){ 
            intercambio = true;
            encender_led_rojo();
            delay_block();
        }else{
            intercambio = false;
            apagar_led_rojo();
            delay_block();
        }

    }

    return 0;
}
