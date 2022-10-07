#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "avr/interrupt.h"
#include "MDIO_interface.h"
#include "MEXTI_interface.h"
#include "util/delay.h"


int amount_of_delay = 1000;

void func(void)
{   
    if(amount_of_delay !=0)
        amount_of_delay -=200;

    else { /* do nothing */ }

    return;
}

void my_delay_ms()
{
    for( int i =0 ; i< amount_of_delay/200 ; i++)
    {
        _delay_ms(200);
    }

    return;
}

int main(void)
{   
    //LED 0
    mdio_setPinStatus(PORTC, PIN2, OUTPUT);
    //LED 1
    mdio_setPinStatus(PORTC, PIN7, OUTPUT);
    //LED 2
    mdio_setPinStatus(PORTD, PIN3, OUTPUT);

    //push button2
    mdio_setPinStatus(PORTD, PIN2, INPUT_FLOAT);

    mexti_enableExternalInterrupt(INT0_REQ_NUM);

    mexti_attachISR(INT0_REQ_NUM, RISING_EDGE_MODE, func);

    mdio_setPinValue(PORTD,PIN3,LOW);
    mdio_setPinValue(PORTC,PIN2,LOW);
    mdio_setPinValue(PORTC,PIN7,LOW);
    
    //Enable the Global interrupt
    sei();
    
    while(1)
    {  
        if(amount_of_delay!=0)
        {
        mdio_setPinValue(PORTD,PIN3,LOW);
        mdio_setPinValue(PORTC,PIN2,HIGH);
        }
        else { /* do nothing */ }


        my_delay_ms();


        if(amount_of_delay!=0)
        {
        mdio_setPinValue(PORTC,PIN2,LOW);
        mdio_setPinValue(PORTC,PIN7,HIGH);
        }
        else { /* do nothing */ }


        my_delay_ms();


        if(amount_of_delay!=0)
        {
        mdio_setPinValue(PORTC,PIN7,LOW);
        mdio_setPinValue(PORTD,PIN3,HIGH);
        }
        else { /* do nothing */ }


        my_delay_ms();
        
    }

    return 0;
}