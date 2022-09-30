/**
 * @file    HKPD_cfg.h
 * @author  Omar Mohamed (Amooory1888@gmail.com)
 * @brief   This file contains private information related to Keypad module
 * @version 1.0
 * @date    2022-09-24
 * 
 * 
 */

/*Header file guard*/
#ifndef __HKPD_CFG_H__
#define __HKPD_CFG_H__

/***************************************************************************************************/
/*                                        Configuration Macros'                                    */
/***************************************************************************************************/

/*Number of rows and columns configurations*/
#define KPD_NUM_ROWS        (4)
#define KPD_NUM_COLS        (4)

/*Keypad mapping configurations*/
#define KEYPAD_MAPPING      {                          \
                                {'7', '4', '1', 'C'},  \
                                {'8', '5', '2', '0'},  \
                                {'9', '6', '3', '='},  \
                                {'/', '*', '-', '+'}   \
                            }

/*Keypad pins configurations*/
#define KPD_PORT            (PORTD)
#define KPD_ROW0            (PIN4)
#define KPD_ROW1            (PIN5)
#define KPD_ROW2            (PIN6)
#define KPD_ROW3            (PIN7)
#define KPD_COL0            (PIN0)
#define KPD_COL1            (PIN1)
#define KPD_COL2            (PIN2)
#define KPD_COL3            (PIN3)

#define KPD_DEFAULT_VALUE   (0)

#endif /*__HKPD_CFG_H__*/