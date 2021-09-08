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
#include "sensor_de_luz.h"
#include "irq_lptmr0.h"
#include "botones.h"
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


int main(void) {
	uint32_t adc_sensor_de_luz;
	bool boton1,boton2;

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
    /* Start counting */
        LPTMR_StartTimer(LPTMR0);





    volatile static int i = 0 ;/* Force the counter to be placed into memory. */
    /* Enter an infinite loop, just incrementing a counter. */
    printf("Inicia");



    while(1) {

    	if(lptmr0_irq_counter!=0){
    		toggle_led_rojo();
    		lptmr0_irq_counter=0;
    		i++ ;
    		printf("i:%u\r\n",i);
    		adc_sensor_de_luz=SensorDeLuzObtenerDatoADC();
    		printf("sensor de luz:%u\r\n",adc_sensor_de_luz);
    		boton1=boton1LeerEstado();
    		boton2=boton2LeerEstado();
    		printf("boton1:%u\r\n",boton1);
    		printf("boton2:%u\r\n",boton2);
    	}
    }

    return 0;
}
