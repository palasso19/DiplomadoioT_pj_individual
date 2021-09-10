/*! @file : irq_lptmr0.c
 * @author  PABLO LASSO HERNANDEZ
 * @version 1.0.0
 * @date    5/09/2021
 * @brief   Driver para 
 * @details
 *
*/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "irq_lptmr0.h"

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
volatile uint32_t lptmr0_irq_counter=0;
volatile uint32_t flag_led_rojo_iqr_counter = 0;
volatile uint32_t flag_boton1_presionado = 0;
volatile uint32_t flag_boton2_presionado = 0;

/*******************************************************************************
 * Private Source Code
 ******************************************************************************/
/*!
 * @brief Interrupcion por LPTMR0 cada 1 segundo
 *
 */

void LPTMR0_IRQHANDLER(void) {
  uint32_t intStatus;
  /* Reading all interrupt flags of status register */
  intStatus = LPTMR_GetStatusFlags(LPTMR0_PERIPHERAL);
  LPTMR_ClearStatusFlags(LPTMR0_PERIPHERAL, intStatus);

  /* Place your code here */


  lptmr0_irq_counter++;
  flag_led_rojo_iqr_counter+=5;

  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}


/*******************************************************************************
 * Public Source Code
 ******************************************************************************/
