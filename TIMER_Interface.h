/*
 * TIMER_Interface.h
 *
 *  Created on: Oct 15, 2021
 *      Author: omarg
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


void TIMER0_VoidInit(void);
void TIMER1_VoidInit(void);
void TIMER2_VoidInit(void);
void TIMER_VoidSetPreLoadValue(u8 Copy_u8TimerNumber,u8 Copy_u16PreloadValue);
void TIMER_VoidCTC_REGISTER(u8 Copy_u8TimerNumber,u8 Copy_u16CTCValue);

#endif /* TIMER_INTERFACE_H_ */
