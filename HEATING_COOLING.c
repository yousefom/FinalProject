/*
 * HEATING_COOLING.c
 *
 *  Created on: Nov 14, 2021
 *      Author: omarg
 */

#include"DIO_Interface.h"
#include"HEATING_COOLING.h"

void HEATING_COOLING_VoidInit(void)
{
	/*Initializing The Heating and Cooling Pins  */
	DIO_u8SetPinDirection(DIO_PORTC,HEAT_PIN,DIO_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTC,COOL_PIN,DIO_OUTPUT);
    /*Setting The Heating and Cooling Pins to Low*/
	DIO_u8SetPinValue(DIO_PORTC,HEAT_PIN,DIO_LOW);
	DIO_u8SetPinDirection(DIO_PORTC,COOL_PIN,DIO_LOW);
}

void HEATING_VoidON(void)
{
	/*Set Heat Pin To high To Start Heating */
	DIO_u8SetPinValue(DIO_PORTC,HEAT_PIN,DIO_HIGH);
}

void HEATING_VoidOFF(void)
{
	/*Clear Heat Pin To high To Stop Heating */
	DIO_u8SetPinValue(DIO_PORTC,HEAT_PIN,DIO_LOW);
}

void COOLING_VoidON(void)
{
	/*Set Cool Pin To high To Start Cooling */
	DIO_u8SetPinValue(DIO_PORTC,HEAT_PIN,DIO_HIGH);
}

void COOLING_VoidOFF(void)
{
	/*Clear COOLING Pin To  Stop Cooling */
	DIO_u8SetPinValue(DIO_PORTC,COOL_PIN,DIO_LOW);
}
