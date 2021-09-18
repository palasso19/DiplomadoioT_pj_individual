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
#include "irq_lpuart0.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

enum _ec25_lista_comandos_at {
    kAT = 0,
    kATI,
    kAT_CPIN,
    kAT_CREG,
    kAT_CMGF_1,
    kAT_CMGS,
    kAT_TEXT_MSG_END,
};

enum _lista_comandos_control {
	LED_VERDE_ON,
	LED_VERDE_OFF,
	LED_ROJO_ON,
	LED_ROJO_OFF,
	Temperatura,
	LUZ,
	ATI,
	OK,
};

#define COMANDOS_DISPONIBLES  8
#define SIZE_BUFFER_COMANDO 50
/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/

/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Local vars
 ******************************************************************************/
//Listado de comando AT disponibles para ser enviados al modem Quectel

const char *ec25_comandos_at[] = {
    "AT",            //comprueba disponibilidad de dispositivo
	"ATI",            //consulta información del modem
    "AT+CPIN?",        //consulta estado de la simcard
    "AT+CREG?",        //consulta estado de la red celular y tecnología usada en red celular
    "AT+CMGF=1",    //asigna modo texto para enviar mensajes
    "AT+CMGS=\"300xxxxxxx\"",//envia mensaje de texto a numero definido
    "Mensaje",         //MENSAJE & CTRL+Z
    };

const char *ec25_respuestas_at[]={


};
//Listado de comando AT disponibles para ser enviados al modem Quectel

const char *comandos_control[] = {
    "LED_VERDE_ON",            //Enciende LED
	"LED_VERDE_OFF",            //Apaga LED
	"LED_ROJO_ON",
	"LED_ROJO_OFF",
	"Temperatura",
	"LUZ",
	"ATI",
	"OK",
    };
char buffer_nuevo_comando_recibido[SIZE_BUFFER_COMANDO];
uint32_t index_buffer_nuevo_comando_recibido=0;
/*******************************************************************************
 * Private Source Code
 ******************************************************************************/

void limpiarBufferComando(){
	for(int i=0;i<50;i++){
		buffer_nuevo_comando_recibido[i]=0x00;
	}
	index_buffer_nuevo_comando_recibido=0;
}

int main(void) {
	float sensor_de_luz,sensor_de_Temperatura;
	bool boton1_activado,boton2_activado;
	uint8_t nuevo_byte_lpuart0;

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    printf("FDRM-K32L2B3 iniciando.....\r\n");
    printf("%s\r\n",ec25_comandos_at[kAT_CREG]);


    /* Start counting */
       LPTMR_StartTimer(LPTMR0);

    while(1) {
    	//pregunta si existe byte disponible
    	if(numeroDeBytesDisponiblesEnBufferRx()!=0){
    		nuevo_byte_lpuart0=pullByteDesdeBufferCircular();
    		buffer_nuevo_comando_recibido[index_buffer_nuevo_comando_recibido]=nuevo_byte_lpuart0;
    		index_buffer_nuevo_comando_recibido++;

    		char *puntero_ok;
    		if(nuevo_byte_lpuart0=='\n'){
    			for(int i=0;i<COMANDOS_DISPONIBLES;i++){
    			 puntero_ok=(uint8_t*)(strstr((char*)(&buffer_nuevo_comando_recibido[0]),(char*)(comandos_control[i])));
    				if(puntero_ok!=0){
    					switch(i){
    					case LED_VERDE_ON:
    						 encender_led_verde();
    						break;
    					case LED_VERDE_OFF:
    					      apagar_led_verde();
    					    break;
    					case LED_ROJO_ON:
    						encender_led_rojo();
    					    break;

    					case LED_ROJO_OFF:
    					    apagar_led_rojo();
    					    break;

    					case Temperatura:
    						sensor_de_Temperatura = SensorDeTemperaturaObtenerDatoADC();
    						printf("Temperatura en grados: %.3f\r\n", sensor_de_Temperatura);

    						break;


    					case LUZ:
    						sensor_de_luz = SensorDeLuzObtenerDatoADC();
    						printf("Luz en lux: %.3f\r\n", sensor_de_luz);

    						break;



    					case ATI:
    						printf("COMANDO ATI OK\r\n");

    						break;


    					}
    				}
    			}

    			limpiarBufferComando();
    		}

    	}

         if(lptmr0_irq_counter != 0){


    		lptmr0_irq_counter = 0;

    		boton1_activado = !boton1LeerEstado();
    		boton2_activado = !boton2LeerEstado();

    		if(boton1_activado && !flag_boton1_presionado){
    			flag_boton1_presionado = 1;
    			printf("Boton1\r\n");

    		}

    		if(!boton1_activado){
    			flag_boton1_presionado = 0;
    		}

    		if(boton2_activado && !flag_boton2_presionado){
    			flag_boton2_presionado = 1;
    			printf("Boton2\r\n");



    		}

    		if(!boton2_activado){
    			flag_boton2_presionado = 0;
    		}

    	}



    		//if(flag_led_rojo_iqr_counter == 1000){

    		   //flag_led_rojo_iqr_counter = 0;
    		   //toggle_led_rojo();
    	//}
    }


    return 0;
}
