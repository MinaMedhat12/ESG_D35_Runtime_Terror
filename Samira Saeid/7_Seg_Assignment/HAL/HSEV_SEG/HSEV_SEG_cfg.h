/**
 * @file HSEV_SEG_cfg.h
 * @author samira saeid (samirasaeid264@gmail.com)
 * @brief This file contains configuration information related to seven segement module
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/*Header file guard*/
#ifndef __HSEV_SEG_CFG_H__
#define __HSEV_SEG_CFG_H__

/**********************************************************************************************/
/*                                Configurations macros                                       */
/**********************************************************************************************/


/*Seven Segment 1 Configurations*/
#define SEV_SEG_1_EN_PORT (PORTB)
#define SEV_SEG_1_EN_PIN  (PIN2)

/*Seven segemnet 2 configurations*/
#define SEV_SEG_2_EN_PORT   (PORTB)
#define SEV_SEG_2_EN_PIN    (PIN1)

/*Decoder input pins*/
#define SEV_SEG_DECODER_PORT    (PORTA)
#define SEV_SEG_A_PIN           (PIN4)
#define SEV_SEG_B_PIN           (PIN5)
#define SEV_SEG_C_PIN           (PIN6)
#define SEV_SEg_D_PIN           (PIN7)

#endif /*__HSEV_SEV_CFG_H__*/