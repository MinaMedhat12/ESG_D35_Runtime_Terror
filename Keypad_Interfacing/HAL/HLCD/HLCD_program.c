/**
 * @file    HLCD_program.c
 * @author  Omar Mohamed (Amooory1888@gmail.com)
 * @brief   This file contains logical implementation related to LCD module
 * @version 1.0
 * @date    2022-09-23
 * 
 * 
 */

/***************************************************************************************************/
/*                                             Includes                                            */
/***************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HLCD_cfg.h"
#include "HLCD_interface.h"
#include "util/delay.h"

/***************************************************************************************************/
/*                                          Important Macros                                       */
/***************************************************************************************************/

/* Data byte Bits */
#define BIT_0                   (0)
#define BIT_1                   (1)
#define BIT_2                   (2)
#define BIT_3                   (3)
#define BIT_4                   (4)
#define BIT_5                   (5)
#define BIT_6                   (6)
#define BIT_7                   (7)

/* LCD write operation triggerring time delay in Microseconds */
#define TRIGGER_DELAY_US        (50)

/* LCD delay time in Milliseconds */
#define POWER_ON_DELAY_MS       (50)
#define INSRUCTION_DELAY_MS     (1)
#define CLEAR_DELAY_MS          (2)

/* DDRAM address controller header */
#define SET_DDRAM_ADD_HEADER    (0x80)

/***************************************************************************************************/
/*                                       Functions' definitions                                    */
/***************************************************************************************************/

static void hlcd_sendData(u8_t au8_Data)
{
    /* Setting RS PIN to HIGH to displaying data */
    mdio_setPinValue(LCD_CONTROL_LINES_PORT, LCD_RS_PIN, HIGH);
    
    /* Setting R/W PIN to LOW to write data */
    mdio_setPinValue(LCD_CONTROL_LINES_PORT, LCD_RW_PIN, LOW);
    
    /* Sending the high nibble 4_Bits */
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D4_PIN, GET_BIT(au8_Data, BIT_4));
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D5_PIN, GET_BIT(au8_Data, BIT_5));
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D6_PIN, GET_BIT(au8_Data, BIT_6));
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D7_PIN, GET_BIT(au8_Data, BIT_7));

    /*Triggering the LCD MCU to read the writing data */
    mdio_setPinValue(LCD_CONTROL_LINES_PORT,LCD_EN_PIN, LOW);
    _delay_ms(TRIGGER_DELAY_US);
    mdio_setPinValue(LCD_CONTROL_LINES_PORT,LCD_EN_PIN, HIGH);
    
    /* Sending the Low nibble 4_Bits */
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D4_PIN, GET_BIT(au8_Data, BIT_0));
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D5_PIN, GET_BIT(au8_Data, BIT_1));
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D6_PIN, GET_BIT(au8_Data, BIT_2));
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D7_PIN, GET_BIT(au8_Data, BIT_3));

    /*Triggering the LCD MCU to read the writing data */
    mdio_setPinValue(LCD_CONTROL_LINES_PORT,LCD_EN_PIN, LOW);
    _delay_ms(TRIGGER_DELAY_US);
    mdio_setPinValue(LCD_CONTROL_LINES_PORT,LCD_EN_PIN, HIGH);
    
    /*Return from this function */
    return;

}

static void hlcd_sendCommand(u8_t au8_Command)
{
    /* Setting RS PIN to LOW to send instruction code */
    mdio_setPinValue(LCD_CONTROL_LINES_PORT, LCD_RS_PIN, LOW);
    
    /* Setting R/W PIN to LOW to write data */
    mdio_setPinValue(LCD_CONTROL_LINES_PORT, LCD_RW_PIN, LOW);
    
    /* Sending the high nibble 4_Bits */
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D4_PIN, GET_BIT(au8_Command, BIT_4));
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D5_PIN, GET_BIT(au8_Command, BIT_5));
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D6_PIN, GET_BIT(au8_Command, BIT_6));
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D7_PIN, GET_BIT(au8_Command, BIT_7));

    /*Triggering the LCD MCU to read the writing data */
    mdio_setPinValue(LCD_CONTROL_LINES_PORT,LCD_EN_PIN, LOW);
    _delay_ms(TRIGGER_DELAY_US);
    mdio_setPinValue(LCD_CONTROL_LINES_PORT,LCD_EN_PIN, HIGH);
    
    /* Sending the Low nibble 4_Bits */
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D4_PIN, GET_BIT(au8_Command, BIT_0));
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D5_PIN, GET_BIT(au8_Command, BIT_1));
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D6_PIN, GET_BIT(au8_Command, BIT_2));
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D7_PIN, GET_BIT(au8_Command, BIT_3));

    /*Triggering the LCD MCU to read the writing data */
    mdio_setPinValue(LCD_CONTROL_LINES_PORT,LCD_EN_PIN, LOW);
    _delay_ms(TRIGGER_DELAY_US);
    mdio_setPinValue(LCD_CONTROL_LINES_PORT,LCD_EN_PIN, HIGH);

    /*Return from this function */
    return;    
}
void hlcd_init(void)
{
    /* Setting he LCD control lines to output */
    mdio_setPinStatus(LCD_CONTROL_LINES_PORT,(LCD_RS_PIN | LCD_RW_PIN | LCD_EN_PIN), OUTPUT);
    
    /* Setting he LCD data lines to output */
    mdio_setPinStatus(LCD_DATA_LINES_PORT,(LCD_D4_PIN | LCD_D5_PIN | LCD_D6_PIN | LCD_D7_PIN), OUTPUT);

    /* Setting the enable PIN to high */
    mdio_setPinValue(LCD_CONTROL_LINES_PORT, LCD_EN_PIN, HIGH);

    /* Waiting for VDD to rise up to 4.5V */
    _delay_ms(POWER_ON_DELAY_MS);

    /* Sending he High nibble 4_bits */
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D4_PIN, LOW);
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D5_PIN, HIGH);
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D6_PIN, LOW);
    mdio_setPinValue(LCD_DATA_LINES_PORT, LCD_D7_PIN, LOW);
    
    /*Triggering the LCD MCU to read the writing data */
    mdio_setPinValue(LCD_CONTROL_LINES_PORT,LCD_EN_PIN, LOW);
    _delay_ms(TRIGGER_DELAY_US);
    mdio_setPinValue(LCD_CONTROL_LINES_PORT,LCD_EN_PIN, HIGH);

    /* Sending Function set command */
    hlcd_sendCommand(LCD_FUNCTION_SET);

    /* Waitnig for instruction to be excuted */
    _delay_ms(INSRUCTION_DELAY_MS);
    
    /* Sending the Display ON/OFF command */
    hlcd_sendCommand(LCD_DISP_ON_OFF_CTRL);

    /* Waitnig for instruction to be excuted */
    _delay_ms(INSRUCTION_DELAY_MS);
    
    /* Sending the clear command */
    hlcd_sendCommand(LCD_CLEAR);

    /* Waitnig for instruction to be excuted */
    _delay_ms(CLEAR_DELAY_MS);
    
    /* Sending Entry mode set command */
    hlcd_sendCommand(LCD_ENTRY_MODE_SET);

    /* Waitnig for instruction to be excuted */
    _delay_ms(INSRUCTION_DELAY_MS);
    
    /*Return from this function */
    return;
}


void hlcd_displayCharacter(u8_t au8_CharacterData)
{
    /* Sending character data to LCD */
    hlcd_sendData(au8_CharacterData);

    /*Return from this function */
    return;
}

void hlcd_displayString(u8_t *pu8_StringData)
{
    /* Looping over string character */
    while(*pu8_StringData != '\0')
    {
        /* Sending characters data to LCD */
        hlcd_sendData(*pu8_StringData);

        /* Increasing the pointer to get the next character */
        pu8_StringData ++;
    }

    /*Return from this function */
    return;
}


void hlcd_displayPosition(u8_t au8_Row, u8_t au8_Col)
{
    /* Setting DDRAM address with specific ROW and COLUMNS value */
    hlcd_sendCommand(SET_DDRAM_ADD_HEADER | (au8_Row | au8_Col));

    /*Return from this function */
    return;
}

