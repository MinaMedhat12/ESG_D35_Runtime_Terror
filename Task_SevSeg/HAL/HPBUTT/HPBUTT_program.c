/**
 * @file    HPBUTT_program.c
 * @author  Omar Mohamed (Amooory1888@gmail.com)
 * @brief   This file contains logical implementation related to push button module
 * @version 1.0
 * @date    2022-09-16
 * 
 * 
 */

/***************************************************************************************************/
/*                                             Includes                                            */
/***************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HPBUTT_cfg.h"
#include "HPBUTT_interface.h"

/***************************************************************************************************/
/*                                       Functions' definitions                                    */
/***************************************************************************************************/


void hpbutt_init(u8_t au8_pbNumber)
{
    /* Switching over Push Button number */
    switch(au8_pbNumber)
    {
        /* In case of Push Button 0 */
        case PUSH_BUTTON_0:
                
                /* setting the PB0 as input */
                mdio_setPinStatus(PB0_PORT, PB0_PIN, INPUT_FLOAT);

                /* break from this case */
                break;

        /* In case of Push Button 1 */
        case PUSH_BUTTON_1:
                
                /* setting the PB1 as input */
                mdio_setPinStatus(PB1_PORT, PB1_PIN, INPUT_FLOAT);

                /* break from this case */
                break;

        /* In case of Push Button 2 */
        case PUSH_BUTTON_2:
                
                /* setting the PB2 as input */
                mdio_setPinStatus(PB2_PORT, PB2_PIN, INPUT_FLOAT);

                /* break from this case */
                break;

        /* In case of default */
        default:
                
                /* break from this case */
                break;
        
    }
    /* Return from this function */
    return;
}


void hpbutt_getStatus(u8_t au8_pbNumber, u8_t* pu8_pbstatus)
{
    /* Switching over Push Button number */
    switch(au8_pbNumber)
    {
        /* In case of Push Button 0 */
        case PUSH_BUTTON_0:
                
                /* getting the PB0 value */
                mdio_getPinValue(PB0_PORT, PB0_PIN, pu8_pbstatus);

                /* break from this case */
                break;

        /* In case of Push Button 1 */
        case PUSH_BUTTON_1:
                
                /* getting the PB1 value */
                mdio_getPinValue(PB1_PORT, PB1_PIN, pu8_pbstatus);

                /* break from this case */
                break;

        /* In case of Push Button 2 */
        case PUSH_BUTTON_2:
                
                /* getting the PB2 value */
                mdio_getPinValue(PB2_PORT, PB2_PIN, pu8_pbstatus);

                /* break from this case */
                break;

        /* In case of default */
        default:
                
                /* break from this case */
                break;
        
    }
    /* Return from this function */
    return;
}

