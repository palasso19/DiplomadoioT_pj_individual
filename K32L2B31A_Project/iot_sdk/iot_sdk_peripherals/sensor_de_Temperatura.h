/*! @file : sensor_de_Temperatura.h
 * @author  PABLO LASSO HERNANDEZ
 * @version 1.0.0
 * @date    4/09/2021
 * @brief   Driver para 
 * @details
 *
 */
#ifndef IOT_SDK_PERIPHERALS_SENSOR_DE_TEMPERATURA_H_
#define IOT_SDK_PERIPHERALS_SENSOR_DE_TEMPERATURA_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "peripherals.h"

/*!
 * @addtogroup PERIPHERALS
 * @{
 */
/*!
 * @addtogroup SENSOR_DE_TEMPERATURA
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
#define SENSOR_DE_TEMPERATURA_ADC16_BASE          ADC0
#define SENSOR_DE_TEMPERATURA_ADC16_CHANNEL_GROUP 0U
#define SENSOR_DE_TEMPERATURA_ADC16_USER_CHANNEL  26U /* PTE22, ADC0_SE3 */
/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/
/********************************************************************************/

/*!
 * @brief Retorna resultado de la conversion ADC para sensor de Temperatura
 *
 */
float SensorDeTemperaturaObtenerDatoADC(void);

/** @} */ // end of SENSOR_DE_TEMPERATURA group
/** @} */ // end of PERIPHERALS group

#endif /* IOT_SDK_PERIPHERALS_SENSOR_DE_TEMPERATURA_H_ */
