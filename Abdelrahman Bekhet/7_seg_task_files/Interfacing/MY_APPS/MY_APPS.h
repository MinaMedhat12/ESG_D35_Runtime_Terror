/*Header file guard*/
#ifndef __MY_APPS_H__
#define __MY_APPS_H__

void asev_seg_displayCounter(u8_t au8_start,u8_t au8_end,unsigned int a32_Count_Periodic_Time);

/**
 * @brief same as previous function but in reverese
 * 
 * @param au8_start 
 * @param au8_end 
 * @param a32_Count_Periodic_Time 
 */
void asev_seg_display_Dec_Counter(u8_t au8_start,u8_t au8_end,unsigned int a32_Count_Periodic_Time);


void asev_seg_display_while_watch_buttons(u8_t au8_seg_1,u8_t au8_seg_2,u8_t * active_pb);


/**
 * @brief BY  ME
 * 
 * @param pu8_active_button 
 */

void apbutt_get_which_pushed(u8_t* pu8_active_button);


#endif 