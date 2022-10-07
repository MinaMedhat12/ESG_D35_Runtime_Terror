/**
 * @file    HLED_program.h
 * @author  Mina M
 * @brief   This file contains logical implementation related to LED module
 * @version 1.0
 * @date    2022-09-19
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
/*                                       Functions definitions                                     */
/***************************************************************************************************/


void hpbutt_init(u8_t au8_pbuttNumber){
    switch(au8_pbuttNumber){
        case PBUTT0:
            mdio_setPinStatus( PBUTT0_PORT , PBUTT0_PIN , INPUT_FLOAT);
            break;
        case PBUTT1:
            mdio_setPinStatus( PBUTT1_PORT , PBUTT1_PIN , INPUT_FLOAT);
            break;
        case PBUTT2:
            mdio_setPinStatus( PBUTT2_PORT , PBUTT2_PIN , INPUT_FLOAT);
            break;    
    }

    return;
}

void hpbutt_status(u8_t au8_pbuttNumber , u8_t* pu8_pbuttStatus){
    switch(au8_pbuttNumber){
        case PBUTT0:
            mdio_getPinValue( PBUTT0_PORT , PBUTT0_PIN , pu8_pbuttStatus);
            break;
        case PBUTT1:
            mdio_getPinValue( PBUTT1_PORT , PBUTT1_PIN , pu8_pbuttStatus);
            break;
        case PBUTT2:
            mdio_getPinValue( PBUTT2_PORT , PBUTT2_PIN , pu8_pbuttStatus);
            break;    
    }

    return;
}