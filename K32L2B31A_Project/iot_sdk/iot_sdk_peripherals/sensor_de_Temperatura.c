/*! @file : sensor_de_Temperatura.c
 * @author  PABLO LASSO HERNANDEZ
 * @version 1.0.0
 * @date    4/09/2021
 * @brief   Driver para 
 * @details
 *
*/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "sensor_de_Temperatura.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define SENSOR_DE_TEMPERATURA_ADC16_BASE          ADC0
#define SENSOR_DE_TEMPERATURA_ADC16_CHANNEL_GROUP 0U
#define SENSOR_DE_TEMPERATURA_ADC16_USER_CHANNEL  26U /* PTE22, ADC0_SE3 */

/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/
/*!
 * @brief Inicia captura por ADC de Voltaje generado por sensor de temperatura
 *
 */
void SensorDeTemperaturaIniciarCaptura(void);
/*!
 * @brief Espera a que finalice el trabajo del ADC
 *
 */
void SensorDeTemperaturaEsperarResultado(void);

/*******************************************************************************
 * External vars
 ******************************************************************************/


/*******************************************************************************
 * Local vars
 ******************************************************************************/


/*******************************************************************************
 * Private Source Code
 ******************************************************************************/
void SensorDeTemperaturaIniciarCaptura(void){
	 ADC16_SetChannelConfig(SENSOR_DE_TEMPERATURA_ADC16_BASE, SENSOR_DE_TEMPERATURA_ADC16_CHANNEL_GROUP, &ADC0_channelsConfig[1]);

}

/*----------------------------------------------------------------------------*/
void SensorDeTemperaturaEsperarResultado(void){
	  while (0U == (kADC16_ChannelConversionDoneFlag & ADC16_GetChannelStatusFlags(SENSOR_DE_TEMPERATURA_ADC16_BASE, SENSOR_DE_TEMPERATURA_ADC16_CHANNEL_GROUP)))
	        {
	        }

}


/*******************************************************************************
 * Public Source Code
 ******************************************************************************/



float SensorDeTemperaturaObtenerDatoADC(void){

	float resultadoADC;
	SensorDeTemperaturaIniciarCaptura();
	SensorDeTemperaturaEsperarResultado();
	resultadoADC=ADC16_GetChannelConversionValue(SENSOR_DE_TEMPERATURA_ADC16_BASE, SENSOR_DE_TEMPERATURA_ADC16_CHANNEL_GROUP);
	resultadoADC=(3*resultadoADC)/4095;
	resultadoADC = (resultadoADC*90)/3.3;

	return (resultadoADC);

}
