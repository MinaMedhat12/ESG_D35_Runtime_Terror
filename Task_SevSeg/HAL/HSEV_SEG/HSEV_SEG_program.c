/**
 * @file    HPBUTT_program.c
 * @author  Omar Mohamed (Amooory1888@gmail.com)
 * @brief   This file contains logical implementation related to seven segment module
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
#include "HSEV_SEG_cfg.h"
#include "HSEV_SEG_interface.h"

/***************************************************************************************************/
/*                                       Functions' definitions                                    */
/***************************************************************************************************/

#define BIT_0                       (0)
#define BIT_1                       (1)
#define BIT_2                       (2)
#define BIT_3                       (3)

/***************************************************************************************************/
/*                                       Functions' definitions                                    */
/***************************************************************************************************/

void hsev_seg_init(u8_t au8_sev_segNumber)
{
        /* setting seven segment decoder pins as output */
        mdio_setPinStatus(SEV_SEG_DECODER_PORT, SEV_SEG_A_PIN, OUTPUT);
        mdio_setPinStatus(SEV_SEG_DECODER_PORT, SEV_SEG_B_PIN, OUTPUT);
        mdio_setPinStatus(SEV_SEG_DECODER_PORT, SEV_SEG_C_PIN, OUTPUT);
        mdio_setPinStatus(SEV_SEG_DECODER_PORT, SEV_SEG_D_PIN, OUTPUT);
        

        /* switching over seven segment module */
        switch (au8_sev_segNumber)
        {
        /* In case of seven segment 1 */
        case SEV_SEG_1:

                /* Setting the Seven segment 1 as output */
                mdio_setPinStatus(SEV_SEG_1_EN_PORT, SEV_SEG_1_EN_PIN, OUTPUT);

                /* Breaking from this case */
                break;
        
        /* In case of seven segment 2 */
        case SEV_SEG_2:

                /* Setting the Seven segment 1 as output */
                mdio_setPinStatus(SEV_SEG_2_EN_PORT, SEV_SEG_2_EN_PIN, OUTPUT);

                /* Breaking from this case */
                break;
        
        /* In case of default */
        default:

                /* Breaking from this case */
                break;
        }

        /*return from this funtion */
        return;
}

void hsev_seg_enable(u8_t au8_sev_segNumber)
{
        /* switching over seven segment module */
        switch (au8_sev_segNumber)
        {
        /* In case of seven segment 1 */
        case SEV_SEG_1:

                /* Setting the Seven segment 1 as high */
                mdio_setPinValue(SEV_SEG_1_EN_PORT, SEV_SEG_1_EN_PIN, HIGH);

                /* Breaking from this case */
                break;
        
        /* In case of seven segment 2 */
        case SEV_SEG_2:

                /* Setting the Seven segment 1 as high */
                mdio_setPinValue(SEV_SEG_2_EN_PORT, SEV_SEG_2_EN_PIN, HIGH);

                /* Breaking from this case */
                break;
        
        /* In case of default */
        default:

                /* Breaking from this case */
                break;
        }


        /*return from this funtion */
        return;
}


void hsev_seg_disable(u8_t au8_sev_segNumber)
{
        /* switching over seven segment module */
        switch (au8_sev_segNumber)
        {
        /* In case of seven segment 1 */
        case SEV_SEG_1:

                /* Setting the Seven segment 1 as Low */
                mdio_setPinValue(SEV_SEG_1_EN_PORT, SEV_SEG_1_EN_PIN, LOW);

                /* Breaking from this case */
                break;
        
        /* In case of seven segment 2 */
        case SEV_SEG_2:

                /* Setting the Seven segment 1 as low */
                mdio_setPinValue(SEV_SEG_2_EN_PORT, SEV_SEG_2_EN_PIN, LOW);

                /* Breaking from this case */
                break;
        
        /* In case of default */
        default:

                /* Breaking from this case */
                break;
        }


        /*return from this funtion */
        return;
}


void hsev_seg_displayNumber(u8_t au8_number)
{
        /* Checking if the number is smaller than or equal 9 or not */
        if(au8_number <= NUMBER_9)
        {       
                /* etting the A,B,C and D pins values */
                mdio_setPinValue(SEV_SEG_DECODER_PORT, SEV_SEG_A_PIN, GET_BIT(au8_number, BIT_0));
                mdio_setPinValue(SEV_SEG_DECODER_PORT, SEV_SEG_B_PIN, GET_BIT(au8_number, BIT_1));
                mdio_setPinValue(SEV_SEG_DECODER_PORT, SEV_SEG_C_PIN, GET_BIT(au8_number, BIT_2));
                mdio_setPinValue(SEV_SEG_DECODER_PORT, SEV_SEG_D_PIN, GET_BIT(au8_number, BIT_3));
                
        }
        else
        {
                /* Do nothing */
        }


        /*return from this funtion */
        return;
}


