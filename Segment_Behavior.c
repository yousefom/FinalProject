/*
 * Segment_Behavior.c
 *
 *  Created on: Nov 14, 2021
 *      Author: omarg
 */



#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
#include<util/delay.h>
#include"Segment_Behavior.h"

void Segment_VoidInit(void)
{
	/*A,B,C,D Initialization Of the Decoder*/
	DIO_u8Set4PinsDirection(DIO_PORTA,DIO_MSB,DIO_OUTPUT);
	/*Setting The Enable Of Segment One High*/
	DIO_u8SetPinDirection(DIO_PORTB,PIN1,DIO_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB,PIN2,DIO_OUTPUT);
}

void Segment_VoidEnableLEFT(void)
{
	/*Setting The Enable Of Segment One High*/
	DIO_u8SetPinValue(DIO_PORTB,PIN2,DIO_HIGH);
}

void Segment_VoidDisableLEFT(void)
{
	/*Setting The Enable Of Segment One High*/
	DIO_u8SetPinValue(DIO_PORTB,PIN2,DIO_LOW);
}

void Segment_VoidEnableRIGHT(void)
{
	/*Setting The Enable Of Segment One High*/
	DIO_u8SetPinValue(DIO_PORTB,PIN1,DIO_HIGH);
}

void Segment_VoidDisableRIGHT(void)
{
	/*Setting The Enable Of Segment One High*/
	DIO_u8SetPinValue(DIO_PORTB,PIN1,DIO_LOW);
}

void Segment_VoidSendNumber(u8 Copy_u8Number)
{
	if(Copy_u8Number<=9)
	{
		PORTA &= 0b00001111;
		PORTA |= (Copy_u8Number<<4);
	}
	else
	{
		/*Nothing*/
	}
}


void Segmnet_Void_SET_TEMP(u8 Copy_u8Number,f32 time_sec)

{
	int time_msec = time_sec* 1000;
	u8 left,right;
	if(Copy_u8Number<100)
	{
	left =Copy_u8Number/10;
	right=Copy_u8Number%10;
	//while()
	for(u8 i = 0;i<(time_msec/20);i++)
	{
	Segment_VoidDisableRIGHT();
	Segment_VoidDisableLEFT();
	Segment_VoidSendNumber(left);
	Segment_VoidEnableLEFT();
	_delay_ms(10);
	Segment_VoidDisableLEFT();
	Segment_VoidSendNumber(right);
	Segment_VoidEnableRIGHT();
	_delay_ms(10);
	Segment_VoidDisableRIGHT();
	}
	}
	else
	{
		/*Nothing*/
	}

}

