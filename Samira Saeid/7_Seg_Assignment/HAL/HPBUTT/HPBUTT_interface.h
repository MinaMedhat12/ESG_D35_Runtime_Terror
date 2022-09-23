/**
 * @file HPBUTT_interface.h
 * @author Samira Saeid (samirasaeid264@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Header file guard*/
#ifndef __HPBUTT_INTERFACE_H__
#define __HPBUTT_INTERFACE_H__

/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/

/*System push buttons*/
#define PUSH_BUTTON_0    (0)
#define PUSH_BUTTON_1    (1)
#define PUSH_BUTTON_2    (2)

/* Push button status:
 * PRESSED  (HIGH -> 1)
 * RELEASED (LOW -> 0)
 */
#define PRESSED          (1)
#define RELEASED         (0)

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

/**
 * @brief This function is responsible for initializing the push button as input
 * 
 * @param au8_pbNumber 
 */
void hpbutt_init(u8_t au8_pbNumber);

/**
 * @brief This function is resposible for getting the push button status [PRESSED / RELEASED]
 * 
 * @param au8_pbNumber 
 * @param pu8_pbStatus 
 */
void hpbutt_getStatus(u8_t au8_pbNumber, u8_t* pu8_pbStatus);

#endif /*__HPBUTT_INTERFACE_H__*/