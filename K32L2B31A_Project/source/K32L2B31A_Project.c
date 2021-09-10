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
#include "sensor_de_Temperatura.h"

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
	float sensor_de_luz, sensor_de_Temperatura;
	bool boton1_activado,boton2_activado;

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





    while(1) {

    	if(lptmr0_irq_counter != 0){


    		lptmr0_irq_counter = 0;

    		boton1_activado = !boton1LeerEstado();
    		boton2_activado = !boton2LeerEstado();

    		if(boton1_activado && !flag_boton1_presionado){
    			flag_boton1_presionado = 1;
    			sensor_de_luz = SensorDeLuzObtenerDatoADC();
    			printf("luminosidad en lux: %.3f\r\n", sensor_de_luz);
    		}

    		if(!boton1_activado){
    			flag_boton1_presionado = 0;
    		}

    		if(boton2_activado && !flag_boton2_presionado){
    			flag_boton2_presionado = 1;
    			sensor_de_Temperatura = SensorDeTemperaturaObtenerDatoADC();
    			printf("Temperatura en grados: %.3f\r\n", sensor_de_Temperatura);


    		}

    		if(!boton2_activado){
    			flag_boton2_presionado = 0;
    		}

    	}



    		if(flag_led_rojo_iqr_counter == 1000){

    		   flag_led_rojo_iqr_counter = 0;
    		   toggle_led_rojo();
    	}
    }


    return 0;
}
