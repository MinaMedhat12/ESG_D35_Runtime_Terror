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
#include "HLED_cfg.h"
#include "HLED_interface.h"

/***************************************************************************************************/
/*                                       Functions definitions                                     */
/***************************************************************************************************/


void hled_init(u8_t au8_lednumber){
    switch(au8_lednumber){
        case LED0:   
            mdio_setPinStatus(LED0_PORT , LED0_PIN , OUTPUT);
            break;
        case LED1:   
            mdio_setPinStatus(LED1_PORT , LED1_PIN , OUTPUT);
            break;
        case LED2:   
            mdio_setPinStatus(LED2_PORT , LED2_PIN , OUTPUT);
            break;
        default: break;
    }
    return;
}

void hled_on(u8_t au8_lednumber){

    switch(au8_lednumber){
    case LED0:   
        mdio_setPinValue(LED0_PORT , LED0_PIN , HIGH);
        break;
    case LED1:   
        mdio_setPinValue(LED1_PORT , LED1_PIN , HIGH);
        break;
    case LED2:   
        mdio_setPinValue(LED2_PORT , LED2_PIN , HIGH);
        break;
    default: break;
    }
    return;

}

void hled_off(u8_t au8_lednumber){

    switch(au8_lednumber){
    case LED0:   
        mdio_setPinValue(LED0_PORT , LED0_PIN , LOW);
        break;
    case LED1:   
        mdio_setPinValue(LED1_PORT , LED1_PIN , LOW);
        break;
    case LED2:   
        mdio_setPinValue(LED2_PORT , LED2_PIN , LOW);
        break;
    default: break;
    }
    return;

}

void hled_toggle(u8_t au8_lednumber){

    switch(au8_lednumber){
    case LED0:   
        mdio_togglePinValue(LED0_PORT , LED0_PIN);
        break;
    case LED1:   
        mdio_togglePinValue(LED1_PORT , LED1_PIN);
        break;
    case LED2:   
        mdio_togglePinValue(LED2_PORT , LED2_PIN);
        break;
    default: break;
    }

    return;

}
