/**
 * @file    HLED_program.c
 * @author  Omar Mohamed (Amooory1888@gmail.com)
 * @brief   This file contains logical implementation related to LED module
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
#include "HLED_cfg.h"
#include "HLED_interface.h"

/***************************************************************************************************/
/*                                       Functions' definitions                                    */
/***************************************************************************************************/


void hled_init(u8_t au8_ledNumber)
{
    /* Switching over LED number */
    switch (au8_ledNumber)
    {
        /* IN case of LED0 */    
        case LED0:

                /* Setting LED0 pin as output */
                mdio_setPinStatus(LED0_PORT, LED0_PIN, OUTPUT);

             /* breaking from this case */
             break;

        /* IN case of LED1 */    
        case LED1:

                /* Setting LED1 pin as output */
                mdio_setPinStatus(LED1_PORT, LED1_PIN, OUTPUT);

             /* breaking from this case */
             break;

        /* IN case of LED2 */    
        case LED2:

                /* Setting LED2 pin as output */
                mdio_setPinStatus(LED2_PORT, LED2_PIN, OUTPUT);

             /* breaking from this case */
             break;
        
        /* In case of default */
        default:

            /* Breaking from this case */
             break;
    }


    /* Return from this function */
    return;
}


void hled_ledValueON(u8_t au8_ledNumber)
{
    /* Switching over LED number */
    switch (au8_ledNumber)
    {
        /* IN case of LED0 */    
        case LED0:

                /* Setting LED0 pin as ON */
                mdio_setPinValue(LED0_PORT, LED0_PIN, HIGH);

             /* breaking from this case */
             break;

        /* IN case of LED1 */    
        case LED1:
        
                /* Setting LED1 pin as ON */
                mdio_setPinValue(LED1_PORT, LED1_PIN, HIGH);

             /* breaking from this case */
             break;

        /* IN case of LED2 */    
        case LED2:

                /* Setting LED2 pin as ON */
                mdio_setPinValue(LED2_PORT, LED2_PIN, HIGH);

             /* breaking from this case */
             break;
        
        /* In case of default */
        default:

            /* Breaking from this case */
             break;
    }

    /* Return from this function */
    return;
}


void hled_ledValueOFF(u8_t au8_ledNumber)
{
    /* Switching over LED number */
    switch (au8_ledNumber)
    {
        /* IN case of LED0 */    
        case LED0:

                /* Setting LED0 pin as OFF */
                mdio_setPinValue(LED0_PORT, LED0_PIN, LOW);

             /* breaking from this case */
             break;

        /* IN case of LED1 */    
        case LED1:
        
                /* Setting LED1 pin as OFF */
                mdio_setPinValue(LED1_PORT, LED1_PIN, LOW);

             /* breaking from this case */
             break;

        /* IN case of LED2 */    
        case LED2:

                /* Setting LED2 pin as OFF */
                mdio_setPinValue(LED2_PORT, LED2_PIN, LOW);

             /* breaking from this case */
             break;
        
        /* In case of default */
        default:

            /* Breaking from this case */
             break;
    }

    /* Return from this function */
    return;
}


void hled_toggleledValue(u8_t au8_ledNumber)
{
    /* Switching over LED number */
    switch (au8_ledNumber)
    {
        /* IN case of LED0 */    
        case LED0:

                /* Toggling LED0 pin  */
                mdio_togglePinValue(LED0_PORT, LED0_PIN);

             /* breaking from this case */
             break;

        /* IN case of LED1 */    
        case LED1:
        
                /* Toggling LED1 pin  */
                mdio_togglePinValue(LED1_PORT, LED1_PIN);

             /* breaking from this case */
             break;

        /* IN case of LED2 */    
        case LED2:

                /* Toggling LED2 pin  */
                mdio_togglePinValue(LED2_PORT, LED2_PIN);

             /* breaking from this case */
             break;
        
        /* In case of default */
        default:

            /* Breaking from this case */
             break;
    }

    /* Return from this functio */
    return;
}