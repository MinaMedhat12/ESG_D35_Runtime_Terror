/**
 * @file    HLCD_interface.h
 * @author  Omar Mohamed (Amooory1888@gmail.com)
 * @brief   This file contains interfacing information related to LCD module
 * @version 1.0
 * @date    2022-09-23
 * 
 * 
 */

/*Header file guard*/
#ifndef __HLCD_INTERFACE_H__
#define __HLCD_INTERFACE_H__

/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/

/* LCD ROWS ====== */
#define LCD_ROW_0             (0x00)
#define LCD_ROW_1             (0x40)

/* LCD Columns ||| */
#define LCD_COL_0             (0x00)
#define LCD_COL_1             (0x01)
#define LCD_COL_2             (0x02)
#define LCD_COL_3             (0x03)
#define LCD_COL_4             (0x04)
#define LCD_COL_5             (0x05)
#define LCD_COL_6             (0x06)
#define LCD_COL_7             (0x07)
#define LCD_COL_8             (0x08)
#define LCD_COL_9             (0x09)
#define LCD_COL_10            (0x0A)
#define LCD_COL_11            (0x0B)
#define LCD_COL_12            (0x0C)
#define LCD_COL_13            (0x0D)
#define LCD_COL_14            (0x0E)
#define LCD_COL_15            (0x0F)

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

/**
 * @brief This function is responsible for initializing the LCD module
 * 
 */
void hlcd_init(void);

/**
 * @brief This finction is responsible for displaying single character over LCD
 * 
 * @param au8_CharacterData 
 */
void hlcd_displayCharacter(u8_t au8_CharacterData);

/**
 * @brief This finction is responsible for displaying string over LCD
 * 
 * @param pu8_StringData 
 */
void hlcd_displayString(u8_t *pu8_StringData);

/**
 * @brief This finction is responsible for choosing the diplay position
 * 
 * @param au8_Row 
 * @param au8_Col 
 */
void hlcd_displayPosition(u8_t au8_Row, u8_t au8_Col);



#endif /*__HLCD_INTERFACE_H__*/