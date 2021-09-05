/*! @file : sensor_de_luz.c
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
#include "sensor_de_luz.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/
/*!
 * @brief Inicia captura por ADC de Voltaje generado por sensor de luz
 *
 */
void SensorDeLuzIniciarCaptura(void);
/*!
 * @brief Espera a que finalice el trabajo del ADC
 *
 */
void SensorDeLuzEsperarResultado(void);

/*******************************************************************************
 * External vars
 ******************************************************************************/


/*******************************************************************************
 * Local vars
 ******************************************************************************/


/*******************************************************************************
 * Private Source Code
 ******************************************************************************/
void SensorDeLuzIniciarCaptura(void){
	 ADC16_SetChannelConfig(SENSOR_DE_LUZ_ADC16_BASE, SENSOR_DE_LUZ_ADC16_CHANNEL_GROUP, &ADC0_channelsConfig[0]);

}

/*----------------------------------------------------------------------------*/
void SensorDeLuzEsperarResultado(void){
	  while (0U == (kADC16_ChannelConversionDoneFlag & ADC16_GetChannelStatusFlags(SENSOR_DE_LUZ_ADC16_BASE, SENSOR_DE_LUZ_ADC16_CHANNEL_GROUP)))
	        {
	        }

}


/*******************************************************************************
 * Public Source Code
 ******************************************************************************/



uint32_t SensorDeLuzObtenerDatoADC(void){

	uint32_t resultadoADC;
	SensorDeLuzIniciarCaptura();
	SensorDeLuzEsperarResultado();
	resultadoADC=ADC16_GetChannelConversionValue(SENSOR_DE_LUZ_ADC16_BASE, SENSOR_DE_LUZ_ADC16_CHANNEL_GROUP);

	return (resultadoADC);

}
