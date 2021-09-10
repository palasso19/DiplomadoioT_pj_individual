/*! @file : irq_lptmr0.h
 * @author  PABLO LASSO HERNANDEZ
 * @version 1.0.0
 * @date    5/09/2021
 * @brief   Driver para IRQ de LPTMR0
 * @details
 *
 */
#ifndef IOT_SDK_IRQ_IRQ_LPTMR0_H_
#define IOT_SDK_IRQ_IRQ_LPTMR0_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "peripherals.h"

/*!
 * @addtogroup IRQ
 * @{
 */
/*!
 * @addtogroup LPTMR0
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/

/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/
extern volatile uint32_t lptmr0_irq_counter;
extern volatile uint32_t flag_led_rojo_iqr_counter;
extern volatile uint32_t flag_boton1_presionado;
extern volatile uint32_t flag_boton2_presionado;
/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/


/** @} */ // end of LPTMR0 group
/** @} */ // end of IRQ group

#endif /* IOT_SDK_IRQ_IRQ_LPTMR0_H_ */
