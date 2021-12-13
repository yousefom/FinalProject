/*
 * ON_OFF_BUTTONS.c
 *
 *  Created on: Nov 14, 2021
 *      Author: omarg
 */
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"ON_OFF_BUTTONS.h"
#include"DIO_Interface.h"
#include<util/delay.h>

/*This is a hardware button "switch" For The On/Off Button*/

void BUTTONS_VoidInit(void)
{
	/*Make The UP and DOWN Buttons As An Inputs */
	DIO_u8SetPinDirection(DIO_PORTB,PIN0,DIO_INPUT);
	DIO_u8SetPinDirection(DIO_PORTD,PIN2,DIO_INPUT);
	DIO_u8SetPinDirection(DIO_PORTD,PIN6,DIO_INPUT);
    /*Making all The Buttons Pull Up*/
	DIO_u8SetPinValue(DIO_PORTB,PIN0,DIO_HIGH);
	DIO_u8SetPinValue(DIO_PORTD,PIN2,DIO_HIGH);
	DIO_u8SetPinValue(DIO_PORTD,PIN6,DIO_HIGH);
}



u8 BUTTON_INCREASE_CHECK_PRESSED(void)
{
	if(!(GET_BIT(DIO_PORTD,INCREASE_BUTTON)))
	{
		_delay_ms(50);
		if(!(GET_BIT(DIO_PORTD,INCREASE_BUTTON)))
		{
			return PRESSED ;
		}
		else
		{
			/*Nothing*/
		}

	}
	else
	{
		return NOT_PRESSED ;
	}

}


u8 BUTTON_DECREASE_CHECK_PRESSED(void)
{
	if(!(GET_BIT(DIO_PORTD,DECREASE_BUTTON)))
		{
			_delay_ms(50);
			if(!(GET_BIT(DIO_PORTD,DECREASE_BUTTON)))
			{
				return PRESSED ;
			}
			else
			{
				/*Nothing*/
			}

		}
		else
		{
			return NOT_PRESSED ;
		}
}
