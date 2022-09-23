#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HSEV_SEG_interface.h"
#include "HPBUTT_interface.h"
#include "HLED_interface.h"
#include "MY_APPS.h"
#include "util/delay.h"

int main(void)
{
    hpbutt_init(PUSH_BUTTON_0 );
    hpbutt_init(PUSH_BUTTON_1 );
    hpbutt_init(PUSH_BUTTON_2 );

    hled_init(LED0);
    hled_init(LED1);
    hled_init(LED2);

    hsev_seg_init(SEV_SEG_1);
    hsev_seg_init(SEV_SEG_2);

    
        u8_t active_pb=255; 
        /*NO. 255 is chosen as initial declaration as no button is numbered 255
        used as Intrinsic Flag */       

    while(1)
    {
       //u8_t pb_status=RELEASED;

        switch(active_pb)
        {
            case PUSH_BUTTON_0: 
            hled_ledValueON(PUSH_BUTTON_0);
            asev_seg_display_Dec_Counter(30,0,250);
            hled_ledValueOFF(PUSH_BUTTON_0);
            asev_seg_display_while_watch_buttons(0,0,&active_pb);
            break;

             case PUSH_BUTTON_1: 
            hled_ledValueON(PUSH_BUTTON_1);
            asev_seg_displayCounter(50,99,250);
            hled_ledValueOFF(PUSH_BUTTON_1);
            asev_seg_display_while_watch_buttons(9,9,&active_pb);
            
            break;

             case PUSH_BUTTON_2: 
            hled_ledValueON(PUSH_BUTTON_2);
            asev_seg_displayCounter(0,40,250);
            hled_ledValueOFF(PUSH_BUTTON_2);
            asev_seg_display_while_watch_buttons(4,0,&active_pb);
            break;
        
            default:
            apbutt_get_which_pushed(&active_pb);

        }


        
        
    }

    return 0;
}
