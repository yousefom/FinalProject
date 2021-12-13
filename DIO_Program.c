/*
 * DIO_Program.c
 *
 *  Created on: Sep 11, 2021
 *      Author: omarg
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"



u8 DIO_u8SetPinDirection(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8PinDirection)
	{
		u8 Error_State=OK;
			if(Copy_u8PinNumber>8)
			{
				Error_State =NOK;
			}
			else
			{
				switch(Copy_u8PortNumber)
				{
				case DIO_PORTA:
					if(Copy_u8PinDirection==DIO_OUTPUT)
					{
						SET_BIT(DDRA,Copy_u8PinNumber);
					}
					else if(Copy_u8PinDirection==DIO_INPUT)
					{
						CLR_BIT(DDRA,Copy_u8PinNumber);
					}
					else
					{
						Error_State=NOK;
					}
					break;
				case DIO_PORTB:
					if(Copy_u8PinDirection==DIO_OUTPUT)
					{
						SET_BIT(PORTB,Copy_u8PinNumber);
					}
					else if(Copy_u8PinDirection==DIO_INPUT)
					{
						CLR_BIT(PORTB,Copy_u8PinNumber);
					}
					else
					{
						Error_State=NOK;
					}
					break;
				case DIO_PORTC:
					if(Copy_u8PinDirection==DIO_OUTPUT)
					{
						SET_BIT(DDRC,Copy_u8PinNumber);
					}
					else if(Copy_u8PinDirection==DIO_INPUT)
					{
						CLR_BIT(DDRC,Copy_u8PinNumber);
					}
					else
					{
						Error_State=NOK;
					}
					break;
				case DIO_PORTD:
					if(Copy_u8PinDirection==DIO_OUTPUT)
					{
						SET_BIT(DDRD,Copy_u8PinNumber);
					}
					else if(Copy_u8PinDirection==DIO_INPUT)
					{
						CLR_BIT(DDRD,Copy_u8PinNumber);
					}
					else
					{
						Error_State=NOK;
					}
					break;
				}
			}
			return Error_State;
	}
u8 DIO_u8SetPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8PinValue)
{
	u8 Error_State=OK;
	if(Copy_u8PinNumber>8)
	{
		Error_State =NOK;
	}
	else
	{
		switch(Copy_u8PortNumber)
		{
		case DIO_PORTA:
			if(Copy_u8PinValue==DIO_HIGH)
			{
				SET_BIT(PORTA,Copy_u8PinNumber);
			}
			else if(Copy_u8PinValue==DIO_LOW)
			{
				CLR_BIT(PORTA,Copy_u8PinNumber);
			}
			else
			{
				Error_State=NOK;
			}
			break;
		case DIO_PORTB:
			if(Copy_u8PinValue==DIO_HIGH)
			{
				SET_BIT(PORTB,Copy_u8PinNumber);
			}
			else if(Copy_u8PinValue==DIO_LOW)
			{
				CLR_BIT(PORTB,Copy_u8PinNumber);
			}
			else
			{
				Error_State=NOK;
			}
			break;
		case DIO_PORTC:
			if(Copy_u8PinValue==DIO_HIGH)
			{
				SET_BIT(PORTC,Copy_u8PinNumber);
			}
			else if(Copy_u8PinValue==DIO_LOW)
			{
				CLR_BIT(PORTC,Copy_u8PinNumber);
			}
			else
			{
				Error_State=NOK;
			}
			break;
		case DIO_PORTD:
			if(Copy_u8PinValue==DIO_HIGH)
			{
				SET_BIT(PORTD,Copy_u8PinNumber);
			}
			else if(Copy_u8PinValue==DIO_LOW)
			{
				CLR_BIT(PORTD,Copy_u8PinNumber);
			}
			else
			{
				Error_State=NOK;
			}
			break;
		}
	}
	return Error_State;
}
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNumber,u8 Copy_u8Direction)
{
	u8 Error_State=OK;
	switch(Copy_u8PortNumber)
	{
	case DIO_PORTA:
		if(Copy_u8Direction==PORT_OUTPUT)
		{
			DDRA=PORT_OUTPUT;
		}
		else if(Copy_u8Direction==PORT_INPUT)
		{
			DDRA=PORT_INPUT;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	case DIO_PORTB:
		if(Copy_u8Direction==PORT_OUTPUT)
		{
			PORTB=PORT_OUTPUT;
		}
		else if(Copy_u8Direction==PORT_INPUT)
		{
			PORTB=PORT_INPUT;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	case DIO_PORTC:
		if(Copy_u8Direction==PORT_OUTPUT)
		{
			DDRC=PORT_OUTPUT;
		}
		else if(Copy_u8Direction==PORT_INPUT)
		{
			DDRC=PORT_INPUT;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	case DIO_PORTD:
		if(Copy_u8Direction==PORT_OUTPUT)
		{
			DDRD=PORT_OUTPUT;
		}
		else if(Copy_u8Direction==PORT_INPUT)
		{
			DDRD=PORT_INPUT;
		}
		else
		{
			Error_State=NOK;
		}
		break;
	}
	return Error_State;
}
u8 DIO_u8SetPortValue(u8 Copy_u8PortNumber,u8 Copy_u8Value)
{
	u8 Error_State=OK;
	switch(Copy_u8PortNumber)
	{
	case DIO_PORTA:
		if(Copy_u8Value==DIO_HIGH)
		{
			PORTA = PORT_HIGH;
		}
		else if(Copy_u8Value==DIO_LOW)
		{
			PORTA= PORT_LOW;
		}
		else
		{
			Error_State =NOK;
		}
		break;
	case DIO_PORTB:
			if(Copy_u8Value==DIO_HIGH)
			{
				PORTB = PORT_HIGH;
			}
			else if(Copy_u8Value==DIO_LOW)
			{
				PORTB= PORT_LOW;
			}
			else
			{
				Error_State =NOK;
			}
			break;
	case DIO_PORTC:
			if(Copy_u8Value==DIO_HIGH)
			{
				PORTC = PORT_HIGH;
			}
			else if(Copy_u8Value==DIO_LOW)
			{
				PORTC= PORT_LOW;
			}
			else
			{
				Error_State =NOK;
			}
			break;
	case DIO_PORTD:
			if(Copy_u8Value==DIO_HIGH)
			{
				PORTD = PORT_HIGH;
			}
			else if(Copy_u8Value==DIO_LOW)
			{
				PORTD= PORT_LOW;
			}
			else
			{
				Error_State =NOK;
			}
			break;

	}
	return Error_State ;
}
u8 DIO_u8GetPinValue(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber,u8* u8PtrToValue)
{
	u8 Error_State=OK;
	if((Copy_u8PinNumber<8)&&(u8PtrToValue!=NULL_POINTER))
	{
		switch(Copy_u8PortNumber)
		{
		case DIO_PORTA:
			*u8PtrToValue=GET_BIT(PINA,Copy_u8PinNumber);
			break;
		case DIO_PORTB:
			*u8PtrToValue=GET_BIT(PINB,Copy_u8PinNumber);
			break;
		case DIO_PORTC:
			*u8PtrToValue=GET_BIT(PINC,Copy_u8PinNumber);
			break;
		case DIO_PORTD:
			*u8PtrToValue=GET_BIT(PIND,Copy_u8PinNumber);
			break;
		default:
			Error_State=NOK;
		}
	}
	return Error_State;
}
u8 DIO_u8Set4PinsDirection(u8 Copy_u8PortNumber,u8 Copy_u8PinMode,u8 Copy_u8Direction)

{
	u8 Error_State =OK;
	switch(Copy_u8PortNumber)
	{
	case DIO_PORTA:
		if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Direction==DIO_OUTPUT))
		{
			DDRA |= 0xF0;
		}
		else if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Direction==DIO_INPUT))
		{
			DDRA &=0x0F;
		}
		else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Direction==DIO_OUTPUT))
		{
			DDRA |= 0x0F;
		}
		else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Direction==DIO_INPUT))
		{
			DDRA &=0xF0;
		}
		else
		{
			Error_State = NOK;
		}
		break;


	case DIO_PORTB:
			if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Direction==DIO_OUTPUT))
			{
				PORTB |= 0xF0;
			}
			else if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Direction==DIO_INPUT))
			{
				PORTB &=0x0F;
			}
			else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Direction==DIO_OUTPUT))
			{
				PORTB |= 0x0F;
			}
			else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Direction==DIO_INPUT))
			{
				PORTB &=0xF0;
			}
			else
			{
				Error_State = NOK;
			}
			break;


	case DIO_PORTC:
			if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Direction==DIO_OUTPUT))
			{
				DDRC |= 0xF0;
			}
			else if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Direction==DIO_INPUT))
			{
				DDRC &=0x0F;
			}
			else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Direction==DIO_OUTPUT))
			{
				DDRC |= 0x0F;
			}
			else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Direction==DIO_INPUT))
			{
				DDRC &=0xF0;
			}
			else
			{
				Error_State = NOK;
			}
			break;


	case DIO_PORTD:
			if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Direction==DIO_OUTPUT))
			{
				DDRD |= 0xF0;
			}
			else if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Direction==DIO_INPUT))
			{
				DDRD &=0x0F;
			}
			else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Direction==DIO_OUTPUT))
			{
				DDRD |= 0x0F;
			}
			else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Direction==DIO_INPUT))
			{
				DDRD &=0xF0;
			}
			else
			{
				Error_State = NOK;
			}
			break;
	}
	return Error_State;
}
u8 DIO_u8Set4PinsValue(u8 Copy_u8PortNumber,u8 Copy_u8PinMode,u8 Copy_u8Value)
{
	u8 Error_State =OK;

	switch(Copy_u8PortNumber)
		{
		case DIO_PORTA:
			if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Value==DIO_HIGH))
			{
				PORTA |= 0xF0;
			}
			else if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Value==DIO_LOW))
			{
				PORTA &=0x0F;
			}
			else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Value==DIO_HIGH))
			{
				PORTA |= 0x0F;
			}
			else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Value==DIO_LOW))
			{
				PORTA &=0xF0;
			}
			else
			{
				Error_State = NOK;
			}
			break;


		case DIO_PORTB:
				if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Value==DIO_HIGH))
				{
					PORTB |= 0xF0;
				}
				else if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Value==DIO_LOW))
				{
					PORTB &=0x0F;
				}
				else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Value==DIO_HIGH))
				{
					PORTB |= 0x0F;
				}
				else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Value==DIO_LOW))
				{
					PORTB &=0xF0;
				}
				else
				{
					Error_State = NOK;
				}
				break;


		case DIO_PORTC:
				if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Value==DIO_HIGH))
				{
					PORTC |= 0xF0;
				}
				else if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Value==DIO_LOW))
				{
					PORTC &=0x0F;
				}
				else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Value==DIO_HIGH))
				{
					PORTC |= 0x0F;
				}
				else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Value==DIO_LOW))
				{
					PORTC &=0xF0;
				}
				else
				{
					Error_State = NOK;
				}
				break;


		case DIO_PORTD:
				if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Value==DIO_HIGH))
				{
					PORTD |= 0xF0;
				}
				else if((Copy_u8PinMode==DIO_MSB)&&(Copy_u8Value==DIO_LOW))
				{
					PORTD &=0x0F;
				}
				else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Value==DIO_HIGH))
				{
					PORTD |= 0x0F;
				}
				else if((Copy_u8PinMode==DIO_LSB)&&(Copy_u8Value==DIO_LOW))
				{
					PORTD &=0xF0;
				}
				else
				{
					Error_State = NOK;
				}
				break;
		}


	return Error_State;
}
