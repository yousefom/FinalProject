/*
   * TIMER_Private.h
 *
 *  Created on: Oct 15, 2021
 *      Author: omarg
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


/*Defining The Timer Interrupt Mask Register */
#define TIMSK           *((volatile u8*)0x59)
#define TIFR            *((volatile u8*)0x58)



/*Defining Timer 0 Timer Control Register and Timer Register and Output Compare Register */
#define TCCR0           *((volatile u8*)0x53)
#define TCNT0           *((volatile u8*)0x52)
#define OCR0            *((volatile u8*)0x5C)



/*Defining Timer 1 Timer Control Register and Timer Register and Output Compare Register */
#define ICR1L           *((volatile u16*)0x46)
#define TCNT1L          *((volatile u16*)0x4C)
 /*Defining The Registers For unit A */
#define TCCR1A          *((volatile u16*)0x4F)
#define OCR1AL          *((volatile u16*)0x4A)
/*Defining The Registers For Unit B */
#define TCCR1B          *((volatile u16*)0x4E)
#define OCR1BL          *((volatile u16*)0x48)





/*Defining Timer 2 Timer Control Register and Timer Register and Output Compare Register */
#define TCCR2           *((volatile u8*)0x45)
#define TCNT2           *((volatile u8*)0x44)
#define OCR2            *((volatile u8*)0x43)







#define TIMER_DISCONNECT_FASTPWM_MODE        1
#define TIMER_INVERTING_FASTPWM_MODE         2
#define TIMER_NON_INVERTING_FASTPWM_MODE     3




#define NON_PWM_DISABLE_MODE_OPERATION       1
#define NON_PWM_TOGGLE_OC0_PIN_MODE          2
#define NON_PWM_CLEAR_OC0_PIN_MODE           3
#define NON_PWM_SET_OC0_PIN_MODE             4



#define TIMER_OVERFLOW_MODE                  1
#define TIMER_CTC_MODE                       2
#define TIMER_PWM_FASTPWM_MODE               3
#define TIMER_PWM_PHASE_CORRECT_MODE         4

#define OC1A_DISCONNECT_PIN_MODE             1
#define OC1A_TOGGLE_PIN_MODE                 2
#define OC1A_CLEAR_PIN_MODE                  3
#define OC1A_SET_PIN_MODE                    4

#define TIMER_OFF                                   0
#define TIMER_NO_PRESCALER                          1
#define TIMER_8_PRESCALER                           2
#define TIMER_64_PRESCALER                          3
#define TIMER_256_PRESCALER                         4
#define TIMER_1024_PRESCALER                        5
#define TIMER_EXTERNAL_SOURCE_WITH_FALLING_EDGE     6
#define TIMER_EXTERNAL_SOURCE_WITH_RISING_EDGE      7

//Timer Interrupts Control Register TIMSK
enum{
	TOIE0=0,
	OCIE0,
	TOIE1,
	OCIEB,
	OCIEA,
	TICIE1,
	TOIE2,
	OCIE2
}Timer_Interrupts_Control;
//Timer Interrupts Flags Register TIFR
enum{
	TOV0=0,
	OCF0,
	TOV1,
	OCF1B,
	OCF1A,
	ICF1,
	TOV2,
	OCF2
}Timer_Interrupt_Flags;
//Timer/Counter Control Timer 0 Register TCCR0
enum{
    CS00=0,
	CS01,
	CS02,
	WGM01,
	COM00,
	COM01,
	WGM00,
	FOC0
}Timer0_Control_Register;
//Timer/Counter Control Timer 1 Register A TCCR1A
enum{
	WGM10=0,
	WGM11,
	FOC1B,
	FOC1A,
	COM1B0,
	COM1B1,
	COM1A0,
	COM1A1
}Timer1_Control_RegisterA;
//Timer/Counter Control Timer 1 Register A TCCR1A
enum{
	CS10=0,
	CS11,
	CS12,
	WGM12,
	WGM13,
	ICES1=6,
	ICNC1
}Timer1_Control_RegisterB;
//Timer/Counter Control Timer 2 Register TCCR2
enum{
	CS20=0,
	CS21,
	CS22,
	WGM21,
	COM20,
	COM21,
	WGM20,
	FOC2,
}Timer2_Control_Register;
//Timer Numbers
enum{
	Timer0=0,
	Timer1,
	Timer2
}Timer_Numbers;
#define CHANNEL_A   1
#define CHANNEL_B   2














#endif /* TIMER_PRIVATE_H_ */
