/*
 * H_C_LED.c
 *
 *  Created on: Nov 14, 2021
 *      Author: omarg
 */

#include"DIO_Interface.h"
#include "util/delay.h"
void LED_VoidInit(void)
{
	/*Initialization Of The LED */
	DIO_u8SetPinDirection(DIO_PORTD,PIN3,DIO_OUTPUT);
	DIO_u8SetPinValue(DIO_PORTD,PIN3,DIO_LOW);

}

void LED_VoidTOGGLE(void)
{
	/*Toggling The LED*/
	DIO_u8SetPinValue(DIO_PORTD,PIN3,DIO_LOW);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_PORTD,PIN3,DIO_HIGH);
}

void LED_VoidOFF(void)
{
	/*Setting The LED Off*/
	DIO_u8SetPinValue(DIO_PORTD,PIN3,DIO_LOW);
}

void LED_VoidON(void)
{
	/*Setting The LED On*/
	DIO_u8SetPinValue(DIO_PORTD,PIN3,DIO_HIGH);
}
