/**
 * @file    HPBUTT_interface.h
 * @author  Omar Mohamed (Amooory1888@gmail.com)
 * @brief   This file contains interfacing information related to push button module
 * @version 1.0
 * @date    2022-09-16
 * 
 * 
 */

/*Header file guard*/
#ifndef __HPBUTT_INTERFACE_H__
#define __HPBUTT_INTERFACE_H__

/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/

/* System Push Buttons */
#define PUSH_BUTTON_0        (0)
#define PUSH_BUTTON_1        (1)
#define PUSH_BUTTON_2        (2)

/* 
   Push Button Status 
   Pressed    (HIGH -> 1)
   Released   (LOW -> 0)
*/
#define PRESSED              (1)
#define RELEASED             (0)


/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

/**
 * @brief This function is responsible for initializing the push button as input
 * 
 * @param au8_pbuttNumber 
 */
void hpbutt_init(u8_t au8_pbuttNumber);

/**
 * @brief This function is responsible for getting the push button status (Pressed / Released)
 * 
 * @param au8_pbuttNumber 
 * @param pu8_pbstatus 
 */
void hpbutt_getStatus(u8_t au8_pbuttNumber, u8_t* pu8_pbstatus);



#endif /*__HPBUTT_INTERFACE_H__*/