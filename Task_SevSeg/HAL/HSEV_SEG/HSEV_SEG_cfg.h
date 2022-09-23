/**
 * @file    HPBUTT_cfg.h
 * @author  Omar Mohamed (Amooory1888@gmail.com)
 * @brief   This file contains private information related to seven segment module
 * @version 1.0
 * @date    2022-09-16
 * 
 * 
 */

/*Header file guard*/
#ifndef __HSEV_SEG_CFG_H__
#define __HSEV_SEG_CFG_H__

/***************************************************************************************************/
/*                                        Configuration Macros'                                    */
/***************************************************************************************************/

/* Seven segment 1 configuration */
#define SEV_SEG_1_EN_PORT           (PORTB)
#define SEV_SEG_1_EN_PIN            (PIN2)

/* Seven segment 2 configuration */
#define SEV_SEG_2_EN_PORT           (PORTB)
#define SEV_SEG_2_EN_PIN            (PIN1)

/* Decoder input pins */
#define SEV_SEG_DECODER_PORT        (PORTA)
#define SEV_SEG_A_PIN               (PIN4)
#define SEV_SEG_B_PIN               (PIN5)
#define SEV_SEG_C_PIN               (PIN6)
#define SEV_SEG_D_PIN               (PIN7)


#endif /*__HSEV_SEG_CFG_H__*/