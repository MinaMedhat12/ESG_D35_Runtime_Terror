
/*Header file guard*/
#ifndef __HLED_INTERFACE_H__
#define __HLED_INTERFACE_H__

/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/

#define LED0     (0)
#define LED1     (1)
#define LED2     (2)

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/


void hled_init(u8_t au8_lednumber);

void hled_on(u8_t au8_lednumber);

void hled_off(u8_t au8_lednumber);

void hled_toggle(u8_t au8_lednumber);

#endif