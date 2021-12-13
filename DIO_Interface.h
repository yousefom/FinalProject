/*
  DIO_Interface.h
 *
 *  Created on: Sep 11, 2021
 *      Author: omarg
 */


#include"STD_TYPES.h"
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_




#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3


#define DIO_OUTPUT   1
#define DIO_INPUT    0


#define DIO_HIGH     1
#define DIO_LOW      0

#define PORT_OUTPUT  255
#define PORT_INPUT   0

#define PORT_HIGH    255
#define PORT_LOW     0

#define DIO_MSB      1
#define DIO_LSB      2


enum{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}Pin_Type;

u8 DIO_u8SetPinDirection(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8PinDirection);
u8 DIO_u8SetPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8PinValue);
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNumber,u8 Copy_u8Direction);
u8 DIO_u8SetPortValue(u8 Copy_u8PortNumber,u8 Copy_u8Value);
u8 DIO_u8GetPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 *u8PtrToValue);
u8 DIO_u8Set4PinsDirection(u8 Copy_u8PortNumber,u8 Copy_u8PinMode,u8 Copy_u8Direction);
u8 DIO_u8Set4PinsValue(u8 Copy_u8PortNumber,u8 Copy_u8PinMode,u8 Copy_u8Value);


#endif /* DIO_INTERFACE_H_ */
