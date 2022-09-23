/**
 * @file HSEV_SEG_interface.h
 * @author Samira Saeid (samirasaeid264@gmail.com)
 * @brief  This file contains interfacing information related to seven segment module
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Header file guard*/
#ifndef __HSEV_SEG_INTERFACING_H__
#define __HSEV_SEG_INTERFACING_H__

/**************************************************************************************************************/
/*                                         Interfacing macros                                                 */
/**************************************************************************************************************/

/*System seven segements*/
#define SEV_SEG_1   (0)
#define SEV_SEG_2   (1)

/*Seven segment displaying numbers*/
#define NUMBER_0    (0)
#define NUMBER_1    (1)
#define NUMBER_2    (2)
#define NUMBER_3    (3)
#define NUMBER_4    (4)
#define NUMBER_5    (5)
#define NUMBER_6    (6)
#define NUMBER_7    (7)
#define NUMBER_8    (8)
#define NUMBER_9    (9)

/**********************************************************************************************************************/
/*                                         Functions' prototypes                                                      */
/**********************************************************************************************************************/

/**
 * @brief This function is responsible for initializing specific seven segement
 * 
 * 
 */
void hsev_seg_init(u8_t au8_sev_segNumber);

/**
 * @brief This function is responsible to enable specific seven segement
 * 
 * @param au8_sev_segNumber
 */
void hsev_seg_enable(u8_t au8_sev_segNumber);

/**
 * @brief This function is responsible to disable specific seven segemnet
 * 
 * @param au8_sev_segNumber
 */
void hsev_seg_disable(u8_t au8_sev_segNumber);

/**
 * @brief This function is responsible foe displaying specific number over enabled seven segment
 * 
 * @param au8_number
 */
void hsev_seg_displayNumber(u8_t au8_number);
#endif /*__HSEV_SEG_INTERFACE_H__*/