#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HSEV_SEG_cfg.h"
#include "HSEV_SEG_interface.h"
#include "util/delay.h"
#include "HPBUTT_interface.h "


void apbutt_get_which_pushed(u8_t* pu8_active_button)
{   
    
      u8_t pb_status=RELEASED;

        for(u8_t pb_index=PUSH_BUTTON_0;pb_index<=PUSH_BUTTON_2;pb_index++)
            {
                hpbutt_getStatus(pb_index,&pb_status);
                if(pb_status==PRESSED)
                {
                    *pu8_active_button=pb_index;
                    break;
                }
                else { * pu8_active_button =255;}
            }
    return;
}





/* I Think this Function should be in app layer */
void asev_seg_displayCounter(u8_t au8_start,u8_t au8_end,unsigned int a32_Count_Periodic_Time)
{
    unsigned int Inner_Loop_MAX = a32_Count_Periodic_Time/20;

    if(au8_start>99 || au8_end >99 || Inner_Loop_MAX == 0 || !(au8_start <= au8_end) )
    {return;}

else  { /*DO NOTHING */ } 


    u8_t seg_2_upper = au8_end % 10; 
    u8_t seg_2_lower = au8_start % 10;


    u8_t seg_1_upper = (au8_end / 10) % 10; 
    u8_t seg_1_lower = (au8_start / 10) % 10;

    u8_t big_Number = seg_1_lower;

    u8_t looping= seg_2_lower;


    while(1)
    {
        for( ;(seg_1_upper != big_Number) ? looping <=NUMBER_9 : looping<=seg_2_upper ; looping++)
            {
                for(unsigned int looping_2=0; looping_2<Inner_Loop_MAX; looping_2++)
                {
                hsev_seg_enable(SEV_SEG_1);
                hsev_seg_displayNumber(big_Number);
                _delay_ms(10);
                hsev_seg_disable(SEV_SEG_1);

                hsev_seg_enable(SEV_SEG_2);
                hsev_seg_displayNumber(looping);
                _delay_ms(10);
                hsev_seg_disable(SEV_SEG_2);

                }
            }

            big_Number++;
            looping=0;
            if(big_Number>seg_1_upper)
            {
                break;
            }
    }


return;
}




void asev_seg_display_Dec_Counter(u8_t au8_start,u8_t au8_end,unsigned int a32_Count_Periodic_Time)
{
unsigned int Inner_Loop_MAX = a32_Count_Periodic_Time/20;

    if(au8_start>99 || au8_end >99 || Inner_Loop_MAX == 0 ||  !(au8_start >= au8_end) )
    {return;}

else  { /*DO NOTHING */ } 


    u8_t seg_2_upper = au8_end % 10; 
    u8_t seg_2_lower = au8_start % 10;


    u8_t seg_1_upper = (au8_end / 10) % 10; 
    u8_t seg_1_lower = (au8_start / 10) % 10;

    u8_t big_Number = seg_1_lower;

    u8_t looping= seg_2_lower;

    u8_t exit_flag = 0;
    if(seg_1_upper == big_Number)
    {
        exit_flag = 1;
    }
    else { /* do nothing */}
    while(1)
    {   
        for( ;(seg_1_upper == big_Number) ? (looping >=seg_2_upper && looping!=255): (looping>=0 && looping!=255) ; looping--)
            {
                for(unsigned int looping_2=0; looping_2<Inner_Loop_MAX; looping_2++)
                {
                hsev_seg_enable(SEV_SEG_1);
                hsev_seg_displayNumber(big_Number);
                _delay_ms(10);
                hsev_seg_disable(SEV_SEG_1);

                hsev_seg_enable(SEV_SEG_2);
                hsev_seg_displayNumber(looping);
                _delay_ms(10);
                hsev_seg_disable(SEV_SEG_2);

                }
            }

    if( exit_flag ==1 )
    {
        break;
    }

    else { /* do nothing */ }
            big_Number--;
            looping=9;
            if(big_Number==seg_1_upper)
            {
                exit_flag= 1;
            }
            else { /* do nothing */ }
    }


return;
}


void asev_seg_display_while_watch_buttons(u8_t au8_seg_1,u8_t au8_seg_2,u8_t * active_pb)
    {
        while(1)
                {   //Displays Static Number
                        hsev_seg_enable(SEV_SEG_1);
                        hsev_seg_displayNumber(au8_seg_1);
                        _delay_ms(10);
                        hsev_seg_disable(SEV_SEG_1);

                        hsev_seg_enable(SEV_SEG_2);
                        hsev_seg_displayNumber(au8_seg_2);
                        _delay_ms(10);
                        hsev_seg_disable(SEV_SEG_2);
                        
                    /*
                    u8_t Inner_Status_0=0;
                    u8_t Inner_Status_1=0;
                    u8_t Inner_Status_2=0;
                    hpbutt_getStatus(PUSH_BUTTON_0,&Inner_Status_0);
                    hpbutt_getStatus(PUSH_BUTTON_1,&Inner_Status_1);
                    hpbutt_getStatus(PUSH_BUTTON_2,&Inner_Status_2);
                    if(Inner_Status_0+Inner_Status_1+Inner_Status_2>=1)
                    break;
                    */
                   apbutt_get_which_pushed(&(*active_pb));
                   if(*active_pb !=255)
                   {
                    break;
    
                   }
                    else{ /* DO NOTHING */}
                }
            return;
    }

