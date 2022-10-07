#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#define __DELAY_BACKWARD_COMPATIBLE__
#include "util/delay.h"
#include "avr/interrupt.h"
#include "MDIO_interface.h"
#include "MEXTI_interface.h"
#include "HLED_interface.h"
#include "HLCD_interface.h"
#include "HPBUTT_interface.h"

u32_t delay=1000;
u8_t value0=0;
u8_t value1=0;
u8_t value2=0;

void func(void){
    delay-=200;
    
    if (delay==200){
        mdio_getPinValue(PORTC, PIN2 , &value0);
        mdio_getPinValue(PORTC, PIN7 , &value1);
        mdio_getPinValue(PORTD, PIN3 , &value2);
    }
     
}


int main(void)
{
    hpbutt_init(PBUTT2);
    hled_init(LED0);
    hled_init(LED1);
    hled_init(LED2);

    mexti_enableExternalInterrupt(INT0_REQ_NUM);
    mexti_attachISR(INT0_REQ_NUM, RISING_EDGE_MODE, func );    
    
    sei();
    
    while(1){

        if(delay>0){
            hled_on(LED0);
            _delay_ms(delay);
            hled_off(LED0);
            _delay_ms(delay);
            
            hled_on(LED1);
            _delay_ms(delay);
            hled_off(LED1);
            _delay_ms(delay);

            hled_on(LED2);
            _delay_ms(delay);
            hled_off(LED2);
            _delay_ms(delay);
        }
        else{
            if(value0==1){
                hled_on(LED0);
                hled_off(LED1);
                hled_off(LED2);

            }
            else if(value1==1){
                hled_on(LED1);
                hled_off(LED0);
                hled_off(LED2);

            }
            else if(value2==1){
                hled_on(LED2);
                hled_off(LED1);
                hled_off(LED0);

            }
            else{}
    
        }
    

}
    

    return 0;
}

