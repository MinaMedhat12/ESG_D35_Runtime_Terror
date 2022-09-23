/**
 * @file HSEV_SEG_program.c
 * @author samira saeid (samirasaeid264@gmail.com)
 * @brief This file contains logical implementation related to seven segement module
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/******************************************************************************************************************************/
/*                                              Includes                                                                      */
/******************************************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HSEV_SEG_cfg.h"
#include "HSEV_SEG_interface.h"

/*******************************************************************************************************************************/
/*                                             Important macros                                                                */
/*******************************************************************************************************************************/

#define BIT_0 (0)
#define BIT_1 (1)
#define BIT_2 (2)
#define BIT_3 (3)

/********************************************************************************************************************************/
/*                                              Functions' definations                                                          */
/********************************************************************************************************************************/

void hsev_seg_init(u8_t au8_sev_segNumber){
    /*Setting seven segment decoder pins as output*/
    mdio_setPinStatus(SEV_SEG_DECODER_PORT,SEV_SEG_A_PIN,OUTPUT);
    mdio_setPinStatus(SEV_SEG_DECODER_PORT,SEV_SEG_B_PIN,OUTPUT);
    mdio_setPinStatus(SEV_SEG_DECODER_PORT,SEV_SEG_C_PIN,OUTPUT);
    mdio_setPinStatus(SEV_SEG_DECODER_PORT,SEV_SEg_D_PIN,OUTPUT);

    /*Switching over seven segement modules*/
    switch(au8_sev_segNumber)
    {
        /*In case of seven segement 1*/
        case SEV_SEG_1:

            /*Setting the seven segement 1 pin as output*/
            mdio_setPinStatus(SEV_SEG_1_EN_PORT,SEV_SEG_1_EN_PIN,OUTPUT);

            /*Break from this case*/
            break;

        /*In case of seven segment 2*/
        case SEV_SEG_2:

            /*Setting the seven segement 2 pin as output*/
            mdio_setPinStatus(SEV_SEG_2_EN_PORT,SEV_SEG_2_EN_PIN,OUTPUT);

            /*Break from this case*/
            break;

        /*In case of default*/
        default:

            /*Break from this case*/
            break;

        /*Return from this function*/
        return;
    }
}
void hsev_seg_enable(u8_t au8_sev_segNumber){

    /*Switching over seven segment module*/
    switch(au8_sev_segNumber){
        /*In case of seven segment 1*/
        case SEV_SEG_1:
            
            /*Setting the seven segment 1 pin to HIGH*/
            mdio_setPinValue(SEV_SEG_1_EN_PORT,SEV_SEG_1_EN_PIN,HIGH);

            /*Break from this case*/
            break;

        /*In case of seven segmnet 2*/
        case SEV_SEG_2:

            /*Setting the seven segment 2 pin as HIGH*/
            mdio_setPinValue(SEV_SEG_2_EN_PORT,SEV_SEG_2_EN_PIN,HIGH);

            /*Break from this case*/
            break;

        /*In case of default*/
        default:
            /*Break from this case*/
            break;

    }
    
    /*return from this function */
    return;
}

void hsev_seg_disable(u8_t au8_sev_segNumber)
{
    /*Switching over seven segment modules*/
    switch (au8_sev_segNumber)
    {
        /*In case of seven segment 1*/
        case SEV_SEG_1:

            /*Setting the seven segment 1 pin to LOw*/
            mdio_setPinValue(SEV_SEG_1_EN_PORT,SEV_SEG_1_EN_PIN,LOW);

           /*break from this case*/ 
        break;

        /*In case of Seven segment 2*/
        case SEV_SEG_2:

            /*Setting the seven segment 2 pin to LOW*/
            mdio_setPinValue(SEV_SEG_2_EN_PORT,SEV_SEG_2_EN_PIN,LOW);

            /*break from this case*/
        break;

        /*In case of default*/
        default:
        /*break from this case*/
        break;
    }
}
void hsev_seg_displayNumber(u8_t au8_number){
    /*Checking if the number is smaller than or equal 9 or not*/

    if(au8_number <= NUMBER_9){
        /*Setting the A, B, C, D pins values*/
        mdio_setPinValue(SEV_SEG_DECODER_PORT, SEV_SEG_A_PIN, GET_BIT(au8_number,BIT_0));
        mdio_setPinValue(SEV_SEG_DECODER_PORT,SEV_SEG_B_PIN, GET_BIT(au8_number, BIT_1));
        mdio_setPinValue(SEV_SEG_DECODER_PORT, SEV_SEG_C_PIN, GET_BIT(au8_number, BIT_2));
        mdio_setPinValue(SEV_SEG_DECODER_PORT, SEV_SEg_D_PIN, GET_BIT(au8_number, BIT_3));
    }
    else{

    }
    /*Return from this function*/
    return;

}
