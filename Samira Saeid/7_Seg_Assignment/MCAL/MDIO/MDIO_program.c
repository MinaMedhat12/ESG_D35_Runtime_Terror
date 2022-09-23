/**
 * @file MDIO_program.c
 * @author Samira Saeid (samirasaeid264@gmail.com)
 * @brief This file contains logical implementation related to DIO module
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/***************************************************************************************************/
/*                                        Includes                                    */
/***************************************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"

/***************************************************************************************************/
/*                                        Important macros                                   */
/***************************************************************************************************/
#define NUMBER_OF_PORTS     (4)

/***************************************************************************************************/
/*                                        Important Variables                                   */
/***************************************************************************************************/
/*DDRX array*/
static volatile u8_t* garr_ddrArray[NUMBER_OF_PORTS]={MDIO_DDRA_ADDRESS,MDIO_DDRB_ADDRESS,MDIO_DDRC_ADDRESS,MDIO_DDRD_ADDRESS};
/*PORTX array*/
static volatile u8_t* garr_portArray[NUMBER_OF_PORTS]={MDIO_PORTA_ADDRESS,MDIO_PORTB_ADDRESS,MDIO_PORTC_ADDRESS,MDIO_PORTD_ADDRESS};
/*PINX array*/
static volatile u8_t* garr_pinArray[NUMBER_OF_PORTS]={MDIO_PINA_ADDRESS,MDIO_PINB_ADDRESS,MDIO_PINC_ADDRESS,MDIO_PIND_ADDRESS};

/***************************************************************************************************/
/*                                        Functions' definations                                   */
/***************************************************************************************************/


void mdio_setPinStatus(u8_t au8_port, u8_t au8_pin, u8_t au8_status){
    /*switching on pin status*/

    switch(au8_status){
        case INPUT_FLOAT:

            /*Clearing the specified pins in DDRx register*/
            *garr_ddrArray[au8_port] &= ~(au8_pin);

            break;
        case INPUT_PULLUP:

            /*Clearing the specified pins in DDRx register*/
            *garr_ddrArray[au8_port] &= ~(au8_pin);

            /*Setting the specified pins in PORTx register*/
            *garr_portArray[au8_port] |= (au8_pin);

            /*Break from this case*/
            break;

        case OUTPUT:

            *garr_ddrArray[au8_port] |= ~(au8_pin);

            break;
        
        /*In case of default*/
        default:

            /*Break from this case*/
            break;



    }
    
    /*Return from this function*/
    return ;
}


void mdio_setPinValue(u8_t au8_port, u8_t au8_pin, u8_t au8_value){
    /*Return from this function*/
     switch(au8_value){
        case HIGH:

            /*Clearing the specified pins in DDRx register*/
            *garr_portArray[au8_port] |= (au8_pin);

            break;
        case LOW:

            /*Clearing the specified pins in DDRX register*/
            *garr_portArray[au8_port] &= ~(au8_pin);

            
            break;

        

        
        default:
            break;



    }

    return;

}

void mdio_togglePinValue(u8_t au8_port, u8_t au8_pin){
    /*Return from this function*/
   

            /*Clearing the specified pins in DDRx register*/
            *garr_portArray[au8_port] ^= (au8_pin);

        return ;



    }




void mdio_getPinValue(u8_t au8_port, u8_t au8_pin, u8_t* pu8_pinValue){
    /*Checking the pinx value for a specified pin if it's low or not*/

    if((*garr_pinArray[au8_port] & au8_pin) == LOW){

        /*setting the pin value as low*/
        *pu8_pinValue = LOW;
    }
    else
    {   /*setting */
        *pu8_pinValue = HIGH;
    }
    return;

}

//#endif /*__MDIO_INTERFACE_H__*/