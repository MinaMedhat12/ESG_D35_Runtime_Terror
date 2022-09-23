#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HSEV_SEG_interface.h"
#include "HLED_interface.h"
#include "HPBUTT_interface.h"
#include "util/delay.h"


int main(void)
{
    u8_t pb0_status;
    u8_t pb1_status;
    u8_t pb2_status;
    
    /* Initialization Push Buttons */
    hpbutt_init(PUSH_BUTTON_0);
    hpbutt_init(PUSH_BUTTON_1);
    hpbutt_init(PUSH_BUTTON_2);
  
    while(1)
    {
        hpbutt_getStatus(PUSH_BUTTON_0, &pb0_status);
        hpbutt_getStatus(PUSH_BUTTON_1, &pb1_status);
        hpbutt_getStatus(PUSH_BUTTON_2, &pb2_status);

        /*********************************************************************************************************/
        /*                                          First Case                                                   */
        /*********************************************************************************************************/

        /*
        * This case is responsible to make (LED0 -> off) during Seven segment counting (from 30 to 00) *
        */

        if( pb0_status == PRESSED)
        {
            _delay_ms(200);
            hled_toggleledValue(LED0);

            u8_t OnesNum;
            u8_t TensNum;

            for(u8_t au8_looping = 30; au8_looping >= 0; au8_looping--)
            {    

                hsev_seg_init(SEV_SEG_1);
                hsev_seg_init(SEV_SEG_2);

                OnesNum = au8_looping % 10;              //* Right Number *//
                TensNum = au8_looping / 10;              //* Left Number  *//


           
                for(u8_t i = 0; i < 50; i++)
                {
                    hsev_seg_disable(SEV_SEG_2);
                    hsev_seg_disable(SEV_SEG_1);

                    hsev_seg_displayNumber(TensNum);
                    hsev_seg_enable(SEV_SEG_1);
                    _delay_ms(10);
                    hsev_seg_disable(SEV_SEG_1);


                    hsev_seg_displayNumber(OnesNum);
                    hsev_seg_enable(SEV_SEG_2);
                    _delay_ms(10);

                }

                if ((OnesNum == 0) && (TensNum == 0))
                {
                   
                    hsev_seg_enable(SEV_SEG_1);
                    hsev_seg_enable(SEV_SEG_2);
                    break;
                  

                }
                else
                {
                    /* Do nothing */
                }
                
            }
               
            hled_toggleledValue(LED0);
        }

        /*********************************************************************************************************/
        /*                                         Second Case                                                   */
        /*********************************************************************************************************/

        /*
        * This case is responsible to make (LED1 -> off) during Seven segment counting (from 50 to 99) *
        */

        else if( pb1_status == PRESSED)
        {
            _delay_ms(200);
            hled_toggleledValue(LED1);

            u8_t OnesNum;                  //* RIght Number *//
            u8_t TensNum;                  //* Left Number  *//

            for(u8_t au8_looping = 50; au8_looping <= 99; au8_looping++)
            {    

                hsev_seg_init(SEV_SEG_1);
                hsev_seg_init(SEV_SEG_2);

                OnesNum = au8_looping % 10;          
                TensNum = au8_looping / 10;          

           
                for(u8_t i = 0; i < 50; i++)
                {
                    hsev_seg_disable(SEV_SEG_2);
                    hsev_seg_disable(SEV_SEG_1);

                    hsev_seg_displayNumber(TensNum);
                    hsev_seg_enable(SEV_SEG_1);
                    _delay_ms(10);
                    hsev_seg_disable(SEV_SEG_1);


                    hsev_seg_displayNumber(OnesNum);
                    hsev_seg_enable(SEV_SEG_2);
                    _delay_ms(10);

                }
                
            }
               
            hled_toggleledValue(LED1);

            while(1)
            {
                hsev_seg_disable(SEV_SEG_2);
                hsev_seg_disable(SEV_SEG_1);
                hsev_seg_displayNumber(TensNum);
                hsev_seg_enable(SEV_SEG_1);
                _delay_ms(10);
                hsev_seg_disable(SEV_SEG_1); 
                
                hsev_seg_displayNumber(OnesNum);
                hsev_seg_enable(SEV_SEG_2);
                _delay_ms(10);
                hpbutt_getStatus(PUSH_BUTTON_0, &pb0_status);
                hpbutt_getStatus(PUSH_BUTTON_2, &pb2_status);
                if((pb0_status) || (pb2_status) == PRESSED)
                {
                    break;
                }
                else
                {
                    /* Do nothing */
                }
            }

        }

        /*********************************************************************************************************/
        /*                                          Third Case                                                   */
        /*********************************************************************************************************/

        /*
        * This case is responsible to make (LED2 -> off) during Seven segment counting (from 00 to 40) *
        */

        else if( pb2_status == PRESSED)
        {
            _delay_ms(200);
            hled_toggleledValue(LED2);

            u8_t OnesNum ;               //* RIght Number *//
            u8_t TensNum ;               //* Left Number  *//

            for(u8_t au8_looping = 0; au8_looping <= 40; au8_looping++)
            {    

                hsev_seg_init(SEV_SEG_1);
                hsev_seg_init(SEV_SEG_2);

                OnesNum = au8_looping % 10;
                TensNum = au8_looping / 10; 

           
                for(u8_t i = 0; i < 50; i++)
                {
                    hsev_seg_disable(SEV_SEG_2);
                    hsev_seg_disable(SEV_SEG_1);

                    hsev_seg_displayNumber(TensNum);
                    hsev_seg_enable(SEV_SEG_1);
                    _delay_ms(10);
                    hsev_seg_disable(SEV_SEG_1);


                    hsev_seg_displayNumber(OnesNum);
                    hsev_seg_enable(SEV_SEG_2);
                    _delay_ms(10);

                }
                   
            }
               
            hled_toggleledValue(LED2);

            while(1)
            {
                hsev_seg_disable(SEV_SEG_2);
                hsev_seg_disable(SEV_SEG_1);
                hsev_seg_displayNumber(TensNum);
                hsev_seg_enable(SEV_SEG_1);
                _delay_ms(10);
                hsev_seg_disable(SEV_SEG_1);
                hsev_seg_displayNumber(OnesNum);
                hsev_seg_enable(SEV_SEG_2);
                _delay_ms(10);
                hpbutt_getStatus(PUSH_BUTTON_0, &pb0_status);
                hpbutt_getStatus(PUSH_BUTTON_1, &pb1_status);
                
                if((pb0_status) || (pb1_status) == PRESSED)
                {
                    break;
                }
                else
                {
                    /* Do nothing */
                }
            }

        }

        else
        {
            /* Do Noting */

        }
        
    }
             
    return 0; 
}