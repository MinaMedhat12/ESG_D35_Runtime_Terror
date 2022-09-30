#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "stdbool.h"
#include "HLCD_interface.h"
#include "HKPD_interface.h"
#include "util/delay.h"


int main(void)
{
  bool firstNumState = true;
  u8_t firstNum =' ' ;
  u8_t secondNum = ' ' ;
  u8_t result = " ";
  u8_t operatr = ' ';
  u8_t newKey;

  hlcd_init();
  hkpd_init();

  
    while (1)
  {
    hkpd_getPressedButton(&newKey);

  if ((newKey != 0) && (newKey == '1' || newKey == '2' || newKey == '3' || newKey == '4' || newKey == '5' || newKey == '6' || newKey == '7' || newKey == '8' || newKey == '9' || newKey == '0'))
  {

    if (firstNumState == true) 
    {
      firstNum = firstNum + newKey;

      hlcd_displayCharacter(newKey);
    }
    else 
    {
      secondNum = secondNum + newKey;

      hlcd_displayCharacter(newKey);
    }
  }

  if ((newKey != 0) && (newKey == '+' || newKey == '-' || newKey == '*' || newKey == '/')) {
    if (firstNumState == true) 
    {
      operatr = newKey;
      firstNumState = false;
      hlcd_displayPosition(LCD_ROW_0 , LCD_COL_2);
      hlcd_displayCharacter(operatr);
      hlcd_displayPosition(LCD_ROW_0, LCD_COL_3);
    }
  }

  if ((newKey != 0 ) && (newKey == '=')) 
  {
    if (operatr == '+') 
    {
      result = firstNum + secondNum;
      hlcd_displayString(result);
    }

    if (operatr == '-') {
      result = firstNum- secondNum;
      hlcd_displayString(result);
    }

    if (operatr == '*') {
      result = firstNum * secondNum;
      hlcd_displayString(result);
    }

    if (operatr == '/') {
      result = firstNum / secondNum;
      hlcd_displayString( result);

    }
    
    hlcd_init();
    hlcd_displayPosition(LCD_ROW_0, LCD_COL_0);
    hlcd_displayCharacter(firstNum);
    hlcd_displayCharacter(operatr);
    hlcd_displayCharacter(secondNum);
    hlcd_displayPosition(LCD_ROW_0, LCD_COL_1);
    hlcd_displayCharacter('=');
    hlcd_displayString( result);
    firstNumState = true;
  }

  if (newKey != 0 && newKey == 'C') 
  {
    hlcd_init();
  }


  
  }
    return 0;
}


