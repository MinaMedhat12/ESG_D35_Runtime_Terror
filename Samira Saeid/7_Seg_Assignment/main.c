
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HSEV_SEG_interface.h"
#include "HPBUTT_interface.h"
#include "HLED_interface.h"
#include "util/delay.h"

void SEV_SEG(u8_t number){
    hsev_seg_init(SEV_SEG_1);
    hsev_seg_init(SEV_SEG_2);

    if (number < 100 && number >0){
        u8_t right = number%10;
        u8_t left = number / 10;
        for(u8_t i=0; i<=9;i++){
        hsev_seg_disable(SEV_SEG_2);
        hsev_seg_disable(SEV_SEG_1);
        hsev_seg_displayNumber(left);
        hsev_seg_enable(SEV_SEG_1);
        _delay_ms(10);
        hsev_seg_disable(SEV_SEG_1);
        hsev_seg_displayNumber(right);
        hsev_seg_enable(SEV_SEG_2);
        _delay_ms(10);
        
        }
    }
    
}


int main(void){
    u8_t pb_status;
    u8_t pb_status2;
    u8_t pb_status0;
    hled_init(LED0);
    hled_init(LED1);
    hled_init(LED2);
    hpbutt_init(PUSH_BUTTON_0);
    hpbutt_init(PUSH_BUTTON_1);
    hpbutt_init(PUSH_BUTTON_2);
    
    
    
    hsev_seg_init(SEV_SEG_1);
    hsev_seg_init(SEV_SEG_2);
    u8_t au8_looping;
     
   
    while(1){

        hpbutt_getStatus(PUSH_BUTTON_0, &pb_status0);
        hpbutt_getStatus(PUSH_BUTTON_1, &pb_status);
        hpbutt_getStatus(PUSH_BUTTON_2, &pb_status2);
        

        if(pb_status0 == PRESSED){
            _delay_ms(200);
            hled_ledValueON(LED0);
                
            for(au8_looping =30; au8_looping>0; au8_looping--){   
                
                    SEV_SEG(au8_looping);   
                }
                hsev_seg_disable(SEV_SEG_1);
                hsev_seg_disable(SEV_SEG_2);
                hled_ledValueOFF(LED0);
        
        }
        else if(pb_status == PRESSED){
            _delay_ms(200);
            hled_ledValueON(LED1);
               
            for(au8_looping =50; au8_looping<100; au8_looping++){   
                
                    SEV_SEG(au8_looping);   
                }
                hsev_seg_disable(SEV_SEG_1);
                hsev_seg_disable(SEV_SEG_2);
                hled_ledValueOFF(LED1); 
        }
        else if (pb_status2 == PRESSED){
            _delay_ms(200);
            hled_ledValueON(LED2);
               
            for(au8_looping =0; au8_looping<41; au8_looping++){   
                
                    SEV_SEG(au8_looping);   
                }
                hsev_seg_disable(SEV_SEG_1);
                hsev_seg_disable(SEV_SEG_2);
                hled_ledValueOFF(LED2);
        }
        else {

        }
                

            

        

        
        
        

    }
    return 0;

}
