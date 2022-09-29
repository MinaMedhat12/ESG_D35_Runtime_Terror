#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLCD_interface.h"
#include "HKPD_interface.h"
#include "util/delay.h"

int main(void)
{
    u8_t button;
    hlcd_init();
    hkpd_init();
  
    u8_t operand_1;
    u8_t operation;
    u8_t operand_2;
    char result;

    

    u8_t ready_to_print =0;

    char char_pos = 0;
    
    while(1)
    {   
        if(ready_to_print == 1)
        {
            while(1)
            {
                hkpd_getPressedButton(&button);
                if(button == 'C')
                {
                    hlcd_clear();
                    char_pos=0;
                    button=0;
                    ready_to_print = 0;
                break;
                }
                else { /* DO nothing */ }
            }
        }
        else { /* Do nothing */}

        hkpd_getPressedButton(&button);
        
        // Checking operands in range and Clear
        if(operand_1 > 9 || operand_2 >9 || button == 'C')
         {
            hlcd_clear();
            char_pos=0;
            operand_1 =0;
            operand_2 =0;
            button=0;
        }
        else { /* do nothing */}

        
        


        if(button != 0)
        { 
            hlcd_displayCharacter(button);
            
            // Filling operands and operation
            switch(char_pos)
        {
            case 0 : operand_1 = button - '0';
                break;
            case 1 : operation = button;
                break;
            case 2 :    operand_2 = button - '0';
                break;

             default: { /* do nothing */}
        }

            // Checking the position of '='
            if(char_pos == 3)
            {
                //Checking if 4th place is '='
                if(button == '=')
                {
                    switch (operation)
                    {
                        case '+' :  result = operand_1 + operand_2;
                        ready_to_print=1;
                        break;

                        case '-' :  result = operand_1 - operand_2;
                        ready_to_print=1;
                        break;

                        case '*' :  result = operand_1 * operand_2;
                        ready_to_print=1;
                        break;

                        case '/' :  result = operand_1 / operand_2;
                        ready_to_print =1;
                        break;

                        //Clear the whole calculator because operation not valid
                        default : hlcd_clear();
                                char_pos=-1;
                    }
                }
                else
                {
                    //Give user a second chance to enter '=' Char
                hlcd_displayPosition(0, 3);
                hlcd_displayCharacter(0);
                hlcd_displayPosition(0, 3);
                char_pos--;
                }
            }
            else { /* do nothing */ }

            char_pos ++;
        }

        else
        {
            /*Do nothing*/
        }

        if(ready_to_print ==1)
        {  
             hlcd_displayPosition(1,0);

            if(result<0)
            {
                hlcd_displayCharacter('-');
                hlcd_displayCharacter(-result+ '0');
            }
            else if(result >= 10)
            {   
                hlcd_displayCharacter(result/10 + '0' );
                hlcd_displayCharacter(result%10 + '0');
            }
            else 
            {
                hlcd_displayCharacter(result + '0');
            }
        }
        else { /* do nothing */}
    }

    return 0;
}