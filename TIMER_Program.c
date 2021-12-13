/*
 * TIMER_Program.c
 *
 *  Created on: Oct 1COM01, 2021
 *      Author: omarg
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_Private.h"
#include "TIMER_Config.h"
#include"TIMER_Interface.h"
void TIMER0_VoidInit(void)

{

      #if MODE_REQUESTED_TIMER_0_2 == TIMER_OVERFLOW_MODE
	      /*Selecting OverFlow Mode*/
	        CLR_BIT(TCCR0,WGM00);
	        CLR_BIT(TCCR0,WGM01);
	      /*OverFlow Interrupt Enable */
	        SET_BIT(TIMSK,0);
           #if OC0_Pin_Mode_NON_PWM_MODE == NON_PWM_DISABLE_MODE_OPERATION
             CLR_BIT(TCCR0,COM00);
             CLR_BIT(TCCR0,COM01);
           #elif  OC0_Pin_Mode_NON_PWM_MODE == NON_PWM_TOGGLE_OC0_PIN_MODE
             SET_BIT(TCCR0,COM00);
             CLR_BIT(TCCR0,COM01);
           #elif OC0_Pin_Mode_NON_PWM_MODE == NON_PWM_CLEAR_OC0_PIN_MODE
             CLR_BIT(TCCR0,COM00);
             SET_BIT(TCCR0,COM01);
           #elif  OC0_Pin_Mode_NON_PWM_MODE == NON_PWM_SET_OC0_PIN_MODE
              SET_BIT(TCCR0,COM00);
              SET_BIT(TCCR0,COM01);
           #else
                #error"Invalid CTC Option.....!"
            #endif

      #elif MODE_REQUESTED_TIMER_0_2 == TIMER_CTC_MODE
	      /*Select CTC Mode */
	        SET_BIT(TCCR0,WGM00);
	        CLR_BIT(TCCR0,WGM01);
	      /*CTC Interrupt Enable*/
            SET_BIT(TIMSK,1);
           /*OUTPUT OC0 Pin Mode*/
           #if OC0_Pin_Mode_NON_PWM_MODE== NON_PWM_DISABLE_MODE_OPERATION
             CLR_BIT(TCCR0,COM00);
             CLR_BIT(TCCR0,COM01);

           #elif  OC0_Pin_Mode_NON_PWM_MODE== NON_PWM_TOGGLE_OC0_PIN_MODE
             SET_BIT(TCCR0,COM00);
             CLR_BIT(TCCR0,COM01);

           #elif OC0_Pin_Mode_NON_PWM_MODE== NON_PWM_CLEAR_OC0_PIN_MODE
             CLR_BIT(TCCR0,COM00);
             SET_BIT(TCCR0,COM01);

           #elif  OC0_Pin_Mode_NON_PWM_MODE == NON_PWM_SET_OC0_PIN_MODE
             SET_BIT(TCCR0,COM00);
             SET_BIT(TCCR0,COM01);

           #else
               #error"Invalid CTC Option.....!"
           #endif

      #elif MODE_REQUESTED_TIMER_0_2 == TIMER_PWM_FASTPWM_MODE
                 /*Select Fast PWM Mode */
 	               SET_BIT(TCCR0,WGM00);
 	               SET_BIT(TCCR0,WGM01);
                  /*OUTPUT OC0 Pin Mode*/
           #if OC0_Pin_Mode_FAST_PWM_MODE == TIMER_DISCONNECT_FASTPWM_MODE
                   CLR_BIT(TCCR0,COM00);
                   CLR_BIT(TCCR0,COM01);

           #elif OC0_Pin_Mode_FAST_PWM_MODE == TIMER_INVERTING_FASTPWM_MODE
                 SET_BIT(TCCR0,COM00);
                 SET_BIT(TCCR0,COM01);

           #elif OC0_Pin_Mode_FAST_PWM_MODE == TIMER_NON_INVERTING_FASTPWM_MODE
                 CLR_BIT(TCCR0,COM00);
                 SET_BIT(TCCR0,COM01);
           #else
              #error"Invalid Pin Mode Options.....!"
            #endif

      #elif MODE_REQUESTED_TIMER_0_2 == TIMER_PWM_PHASE_CORRECT_MODE
                  /*Select Phase Correct  Mode */
	               CLR_BIT(TCCR0,WGM00);
	               SET_BIT(TCCR0,WGM01);
                  /*OUTPUT OC0 Pin Mode*/
           #if OC0_Pin_Mode_PHASE_CORRECT_PWM_MODE  == TIMER_DISCONNECT_FASTPWM_MODE
                     CLR_BIT(TCCR0,COM00);
                     CLR_BIT(TCCR0,COM01);

           #elif OC0_Pin_Mode_PHASE_CORRECT_PWM_MODE  == TIMER_INVERTING_FASTPWM_MODE
                     SET_BIT(TCCR0,COM00);
                     SET_BIT(TCCR0,COM01);

           #elif OC0_Pin_Mode_PHASE_CORRECT_PWM_MODE  == TIMER_NON_INVERTING_FASTPWM_MODE
                     CLR_BIT(TCCR0,COM00);
                     SET_BIT(TCCR0,COM01);
           #else
              #error"Invalid Pin Mode Options.....!"
            #endif
#else
    #error "Invalid Timer Mode....1-Normal Mode("OverFlow Mode") \n 2-CTC Mode \n WGM00-Fast PWM \n COM00-Phase Correct PWM"
#endif
           //Choosing A Suitable Prescaler for Timer0
TCCR0&=0xF8;
TCCR0|=TIMER_PRESCALER;
}

void TIMER2_VoidInit(void)
{

#if MODE_REQUESTED_TIMER_0_2 == TIMER_OVERFLOW_MODE
	/*Selecting OverFlow Mode*/
	CLR_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,6);
	/*OverFlow Interrupt Enable */
	SET_BIT(TIMSK,0);
#if OC0_Pin_Mode_NON_PWM_MODE == NON_PWM_DISABLE_MODE_OPERATION
	CLR_BIT(TCCR2,COM20);
	CLR_BIT(TCCR2,COM21);
#elif  OC0_Pin_Mode_NON_PWM_MODE == NON_PWM_TOGGLE_OC0_PIN_MODE
	SET_BIT(TCCR2,COM20);
	CLR_BIT(TCCR2,COM21);
#elif OC0_Pin_Mode_NON_PWM_MODE == NON_PWM_CLEAR_OC0_PIN_MODE
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
#elif  OC0_Pin_Mode_NON_PWM_MODE == NON_PWM_SET_OC0_PIN_MODE
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
#else
#error"Invalid CTC Option.....!"
#endif

#elif MODE_REQUESTED_TIMER_0_2 == TIMER_CTC_MODE
	/*Select CTC Mode */
	SET_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,6);
	/*CTC Interrupt Enable*/
	SET_BIT(TIMSK,1);
	/*OUTPUT OC0 Pin Mode*/
#if OC0_Pin_Mode_NON_PWM_MODE== NON_PWM_DISABLE_MODE_OPERATION
	CLR_BIT(TCCR2,COM20);
	CLR_BIT(TCCR2,COM21);

#elif  OC0_Pin_Mode_NON_PWM_MODE== NON_PWM_TOGGLE_OC0_PIN_MODE
	SET_BIT(TCCR2,COM20);
	CLR_BIT(TCCR2,COM21);

#elif OC0_Pin_Mode_NON_PWM_MODE== NON_PWM_CLEAR_OC0_PIN_MODE
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);

#elif  OC0_Pin_Mode_NON_PWM_MODE == NON_PWM_SET_OC0_PIN_MODE
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);

#else
#error"Invalid CTC Option.....!"
#endif

#elif MODE_REQUESTED_TIMER_0_2 == TIMER_PWM_FASTPWM_MODE
	/*Select Fast PWM Mode */
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,6);
	/*OUTPUT OC0 Pin Mode*/
#if OC0_Pin_Mode_FAST_PWM_MODE == TIMER_DISCONNECT_FASTPWM_MODE
	CLR_BIT(TCCR2,COM20);
	CLR_BIT(TCCR2,COM21);

#elif OC0_Pin_Mode_FAST_PWM_MODE == TIMER_INVERTING_FASTPWM_MODE
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);

#elif OC0_Pin_Mode_FAST_PWM_MODE == TIMER_NON_INVERTING_FASTPWM_MODE
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
#else
#error"Invalid Pin Mode Options.....!"
#endif

#elif MODE_REQUESTED_TIMER_0_2 == TIMER_PWM_PHASE_CORRECT_MODE
	/*Select Phase Correct  Mode */
	CLR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	/*OUTPUT OC0 Pin Mode*/
#if OC0_Pin_Mode_PHASE_CORRECT_PWM_MODE  == TIMER_DISCONNECT_FASTPWM_MODE
	CLR_BIT(TCCR2,COM20);
	CLR_BIT(TCCR2,COM21);

#elif OC0_Pin_Mode_PHASE_CORRECT_PWM_MODE  == TIMER_INVERTING_FASTPWM_MODE
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);

#elif OC0_Pin_Mode_PHASE_CORRECT_PWM_MODE  == TIMER_NON_INVERTING_FASTPWM_MODE
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
#else
#error"Invalid Pin Mode Options.....!"
#endif
#else
#error "Invalid Timer Mode....1-Normal Mode("OverFlow Mode") \n 2-CTC Mode \n WGM20-Fast PWM \n COM20-Phase Correct PWM"
#endif
	//Choosing A Suitable Prescaler for Timer2
TCCR2&=0xF8;
TCCR2|=TIMER_PRESCALER;
}

void TIMER1_VoidTnit(void)
{
#if CHANNEL_SELECTED == CHANNEL_A

       #if   MODE_REQUESTED_TIMER_1 == TIMER_OVERFLOW_MODE
	          CLR_BIT(TCCR1B,WGM13);
	          CLR_BIT(TCCR1B,WGM12);
	          CLR_BIT(TCCR1A,WGM11);
	          CLR_BIT(TCCR1A,WGM10);
	          /*Selection Of the Output Mode*/
               #if  TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
              #elif TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_TOGGLE_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
               #elif TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_CLEAR_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
               #elif TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_SET_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
               #else
                  #error"Invalid OutPut Pin Mode....!"
                #endif
       #elif MODE_REQUESTED_TIMER_1 == TIMER1_PWM_PHASE_CORRECT_8BIT
	          CLR_BIT(TCCR1B,WGM13);
	          CLR_BIT(TCCR1B,WGM12);
	          CLR_BIT(TCCR1A,WGM11);
	          SET_BIT(TCCR1A,WGM10);
	          /*Selection Of the Output Mode*/
	           #if  TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_TOGGLE_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_CLEAR_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_SET_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
	           #else
	              #error"Invalid OutPut Pin Mode....!"
	            #endif
       #elif MODE_REQUESTED_TIMER_1 == TIMER1_PWM_PHASE_CORRECT_9BIT
	          CLR_BIT(TCCR1B,WGM13);
	          CLR_BIT(TCCR1B,WGM12);
	          SET_BIT(TCCR1A,WGM11);
	          CLR_BIT(TCCR1A,WGM10);
	          /*Selection Of the Output Mode*/
	           #if  TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_TOGGLE_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_CLEAR_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_SET_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
	           #else
	              #error"Invalid OutPut Pin Mode....!"
	            #endif
       #elif MODE_REQUESTED_TIMER_1 == IMER1_PWM_PHASE_CORRECT_10BIT
	          CLR_BIT(TCCR1B,WGM13);
	          CLR_BIT(TCCR1B,WGM12);
	          SET_BIT(TCCR1A,WGM11);
	          SET_BIT(TCCR1A,WGM10);
	          /*Selection Of the Output Mode*/
	           #if  TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_TOGGLE_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_CLEAR_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_SET_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
	           #else
	              #error"Invalid OutPut Pin Mode....!"
	            #endif
       #elif MODE_REQUESTED_TIMER_1 == TIMER1_CTC_MODE
	          CLR_BIT(TCCR1B,WGM13);
	          SET_BIT(TCCR1B,WGM12);
	          CLR_BIT(TCCR1A,WGM11);
	          CLR_BIT(TCCR1A,WGM10);
	          /*Selection Of the Output Mode*/
               #if  TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
               #elif TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_TOGGLE_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
               #elif TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_CLEAR_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
               #elif TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_SET_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
               #else
                  #error"Invalid OutPut Pin Mode....!"
                #endif
       #elif MODE_REQUESTED_TIMER_1 == TIMER1_FAST_PWM_8BIT
	          CLR_BIT(TCCR1B,WGM13);
	          SET_BIT(TCCR1B,WGM12);
	          CLR_BIT(TCCR1A,WGM11);
	          SET_BIT(TCCR1A,WGM10);
	          /*Selection Of The Output Mode */
             #if TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
              CLR_BIT(TCCR1A,COM1A1);
              CLR_BIT(TCCR1A,COM1A0);
             #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_TOGGLE_PIN_MODE
              CLR_BIT(TCCR1A,COM1A1);
              SET_BIT(TCCR1A,COM1A0);
             #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_CLEAR_PIN_MODE
              SET_BIT(TCCR1A,COM1A1);
              CLR_BIT(TCCR1A,COM1A0);
             #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_SET_PIN_MODE
               SET_BIT(TCCR1A,COM1A1);
               SET_BIT(TCCR1A,COM1A0);
             #else
                 #error"Invalid Fast PWM OutPut Pin Mode........!"
             #endif
       #elif MODE_REQUESTED_TIMER_1 == TIMER1_FAST_PWM_9BIT
	          CLR_BIT(TCCR1B,WGM13);
	          SET_BIT(TCCR1B,WGM12);
	          SET_BIT(TCCR1A,WGM11);
	          CLR_BIT(TCCR1A,WGM10);
	          /*Selection Of The Output Mode */
             #if TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
              CLR_BIT(TCCR1A,COM1A1);
              CLR_BIT(TCCR1A,COM1A0);
             #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_TOGGLE_PIN_MODE
              CLR_BIT(TCCR1A,COM1A1);
              SET_BIT(TCCR1A,COM1A0);
             #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_CLEAR_PIN_MODE
              SET_BIT(TCCR1A,COM1A1);
              CLR_BIT(TCCR1A,COM1A0);
             #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_SET_PIN_MODE
               SET_BIT(TCCR1A,COM1A1);
               SET_BIT(TCCR1A,COM1A0);
             #else
                 #error"Invalid Fast PWM OutPut Pin Mode........!"
             #endif
       #elif MODE_REQUESTED_TIMER_1 == TIMER1_FAST_PWM_10BIT
	          CLR_BIT(TCCR1B,WGM13);
	          SET_BIT(TCCR1B,WGM12);
	          SET_BIT(TCCR1A,WGM11);
	          SET_BIT(TCCR1A,WGM10);
	          /*Selection Of The Output Mode */
             #if TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
              CLR_BIT(TCCR1A,COM1A1);
              CLR_BIT(TCCR1A,COM1A0);
             #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_TOGGLE_PIN_MODE
              CLR_BIT(TCCR1A,COM1A1);
              SET_BIT(TCCR1A,COM1A0);
             #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_CLEAR_PIN_MODE
              SET_BIT(TCCR1A,COM1A1);
              CLR_BIT(TCCR1A,COM1A0);
             #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_SET_PIN_MODE
               SET_BIT(TCCR1A,COM1A1);
               SET_BIT(TCCR1A,COM1A0);
             #else
                 #error"Invalid Fast PWM OutPut Pin Mode........!"
             #endif
       #elif MODE_REQUESTED_TIMER_1 == TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT
	          SET_BIT(TCCR1B,WGM13);
	          CLR_BIT(TCCR1B,WGM12);
	          CLR_BIT(TCCR1A,WGM11);
	          CLR_BIT(TCCR1A,WGM10);
	          /*Selection Of the Output Mode*/
	           #if  TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_TOGGLE_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_CLEAR_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_SET_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
	           #else
	              #error"Invalid OutPut Pin Mode....!"
	            #endif
       #elif MODE_REQUESTED_TIMER_1 == TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT
	          SET_BIT(TCCR1B,WGM13);
	          CLR_BIT(TCCR1B,WGM12);
	          CLR_BIT(TCCR1A,WGM11);
	          SET_BIT(TCCR1A,WGM10);
	          /*Selection Of the Output Mode*/
	           #if  TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_TOGGLE_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_CLEAR_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_SET_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
	           #else
	              #error"Invalid OutPut Pin Mode....!"
	            #endif
       #elif MODE_REQUESTED_TIMER_1 == TIMER1_PWM_PHASE_CORRECT
	          SET_BIT(TCCR1B,WGM13);
	          CLR_BIT(TCCR1B,WGM12);
	          SET_BIT(TCCR1A,WGM11);
	          CLR_BIT(TCCR1A,WGM10);
	          /*Selection Of the Output Mode*/
	           #if  TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_TOGGLE_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_CLEAR_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_SET_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
	           #else
	              #error"Invalid OutPut Pin Mode....!"
	            #endif
       #elif MODE_REQUESTED_TIMER_1 == TIMER1_PWM_PHASE_CORRECT
	          SET_BIT(TCCR1B,WGM13);
	          CLR_BIT(TCCR1B,WGM12);
	          SET_BIT(TCCR1A,WGM11);
	          SET_BIT(TCCR1A,WGM10);
	          /*Selection Of the Output Mode*/
	           #if  TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_TOGGLE_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_CLEAR_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
	           #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_SET_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
	           #else
	              #error"Invalid OutPut Pin Mode....!"
	            #endif
       #elif MODE_REQUESTED_TIMER_1 == TIMER1_CTC_MODE
	          SET_BIT(TCCR1B,WGM13);
	          SET_BIT(TCCR1B,WGM12);
	          CLR_BIT(TCCR1A,WGM11);
	          CLR_BIT(TCCR1A,WGM10);
	          /*Selection Of the Output Mode*/
               #if  TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
               #elif TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_TOGGLE_PIN_MODE
	                CLR_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
               #elif TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_CLEAR_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                CLR_BIT(TCCR1A,COM1A0);
               #elif TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_SET_PIN_MODE
	                SET_BIT(TCCR1A,COM1A1);
	                SET_BIT(TCCR1A,COM1A0);
               #else
                  #error"Invalid OutPut Pin Mode....!"
                #endif
       #elif MODE_REQUESTED_TIMER_1 == TIMER1_FAST_PWM
	          SET_BIT(TCCR1B,WGM13);
	          SET_BIT(TCCR1B,WGM12);
	          SET_BIT(TCCR1A,WGM11);
	          CLR_BIT(TCCR1A,WGM10);
	          /*Selection Of The Output Mode */
             #if TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
              CLR_BIT(TCCR1A,COM1A1);
              CLR_BIT(TCCR1A,COM1A0);
             #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_TOGGLE_PIN_MODE
              CLR_BIT(TCCR1A,COM1A1);
              SET_BIT(TCCR1A,COM1A0);
             #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_CLEAR_PIN_MODE
              SET_BIT(TCCR1A,COM1A1);
              CLR_BIT(TCCR1A,COM1A0);
             #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_SET_PIN_MODE
               SET_BIT(TCCR1A,COM1A1);
               SET_BIT(TCCR1A,COM1A0);
             #else
                 #error"Invalid Fast PWM OutPut Pin Mode........!"
             #endif
       #elif MODE_REQUESTED_TIMER_1 == TIMER1_FAST_PWM
	          SET_BIT(TCCR1B,WGM13);
	          SET_BIT(TCCR1B,WGM12);
	          SET_BIT(TCCR1A,WGM11);
	          SET_BIT(TCCR1A,WGM10);
	          /*Selection Of The Output Mode */
             #if TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
              CLR_BIT(TCCR1A,COM1A1);
              CLR_BIT(TCCR1A,COM1A0);
             #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_TOGGLE_PIN_MODE
              CLR_BIT(TCCR1A,COM1A1);
              SET_BIT(TCCR1A,COM1A0);
             #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_CLEAR_PIN_MODE
              SET_BIT(TCCR1A,COM1A1);
              CLR_BIT(TCCR1A,COM1A0);
             #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_SET_PIN_MODE
               SET_BIT(TCCR1A,COM1A1);
               SET_BIT(TCCR1A,COM1A0);
             #else
                 #error"Invalid Fast PWM OutPut Pin Mode........!"
             #endif
        #else
        #error"Invalid Requested Mode......!"
        #endif

#elif CHANNEL_SELECTED == CHANNEL_B

    #if   MODE_REQUESTED_TIMER_1 == TIMER_OVERFLOW_MODE
       CLR_BIT(TCCR1B,WGM13);
       CLR_BIT(TCCR1B,WGM12);
       CLR_BIT(TCCR1A,WGM11);
       CLR_BIT(TCCR1A,WGM10);
       /*Selection Of the Output Mode*/
        #if  TIMER1_OC1A_PIN_MODE == OC1A_DISCONNECT_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_MODE == OC1A_TOGGLE_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_MODE == OC1A_CLEAR_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_MODE == OC1A_SET_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #else
           #error"Invalid OutPut Pin Mode....!"
         #endif
   #elif MODE_REQUESTED_TIMER_1 == TIMER1_PWM_PHASE_CORRECT_8BIT
       CLR_BIT(TCCR1B,WGM13);
       CLR_BIT(TCCR1B,WGM12);
       CLR_BIT(TCCR1A,WGM11);
       SET_BIT(TCCR1A,WGM10);
       /*Selection Of the Output Mode*/
        #if  TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_TOGGLE_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_CLEAR_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_SET_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #else
           #error"Invalid OutPut Pin Mode....!"
         #endif
   #elif MODE_REQUESTED_TIMER_1 == TIMER1_PWM_PHASE_CORRECT_9BIT
       CLR_BIT(TCCR1B,WGM13);
       CLR_BIT(TCCR1B,WGM12);
       SET_BIT(TCCR1A,WGM11);
       CLR_BIT(TCCR1A,WGM10);
       /*Selection Of the Output Mode*/
        #if  TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_TOGGLE_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_CLEAR_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_SET_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #else
           #error"Invalid OutPut Pin Mode....!"
         #endif
   #elif MODE_REQUESTED_TIMER_1 == IMER1_PWM_PHASE_CORRECT_10BIT
       CLR_BIT(TCCR1B,WGM13);
       CLR_BIT(TCCR1B,WGM12);
       SET_BIT(TCCR1A,WGM11);
       SET_BIT(TCCR1A,WGM10);
       /*Selection Of the Output Mode*/
        #if  TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_TOGGLE_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_CLEAR_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_SET_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #else
           #error"Invalid OutPut Pin Mode....!"
         #endif
   #elif MODE_REQUESTED_TIMER_1 == TIMER1_CTC_MODE
       CLR_BIT(TCCR1B,WGM13);
       SET_BIT(TCCR1B,WGM12);
       CLR_BIT(TCCR1A,WGM11);
       CLR_BIT(TCCR1A,WGM10);
       /*Selection Of the Output Mode*/
        #if  TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_TOGGLE_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_CLEAR_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_SET_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #else
           #error"Invalid OutPut Pin Mode....!"
         #endif
   #elif MODE_REQUESTED_TIMER_1 == TIMER1_FAST_PWM_8BIT
       CLR_BIT(TCCR1B,WGM13);
       SET_BIT(TCCR1B,WGM12);
       CLR_BIT(TCCR1A,WGM11);
       SET_BIT(TCCR1A,WGM10);
       /*Selection Of The Output Mode */
      #if TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
       CLR_BIT(TCCR1A,COM1B1);
       CLR_BIT(TCCR1A,COM1B0);
      #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_TOGGLE_PIN_MODE
       CLR_BIT(TCCR1A,COM1B1);
       SET_BIT(TCCR1A,COM1B0);
      #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_CLEAR_PIN_MODE
       SET_BIT(TCCR1A,COM1B1);
       CLR_BIT(TCCR1A,COM1B0);
      #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_SET_PIN_MODE
        SET_BIT(TCCR1A,COM1B1);
        SET_BIT(TCCR1A,COM1B0);
      #else
          #error"Invalid Fast PWM OutPut Pin Mode........!"
      #endif
   #elif MODE_REQUESTED_TIMER_1 == TIMER1_FAST_PWM_9BIT
       CLR_BIT(TCCR1B,WGM13);
       SET_BIT(TCCR1B,WGM12);
       SET_BIT(TCCR1A,WGM11);
       CLR_BIT(TCCR1A,WGM10);
       /*Selection Of The Output Mode */
      #if TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
       CLR_BIT(TCCR1A,COM1B1);
       CLR_BIT(TCCR1A,COM1B0);
      #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_TOGGLE_PIN_MODE
       CLR_BIT(TCCR1A,COM1B1);
       SET_BIT(TCCR1A,COM1B0);
      #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_CLEAR_PIN_MODE
       SET_BIT(TCCR1A,COM1B1);
       CLR_BIT(TCCR1A,COM1B0);
      #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_SET_PIN_MODE
        SET_BIT(TCCR1A,COM1B1);
        SET_BIT(TCCR1A,COM1B0);
      #else
          #error"Invalid Fast PWM OutPut Pin Mode........!"
      #endif
   #elif MODE_REQUESTED_TIMER_1 == TIMER1_FAST_PWM_10BIT
       CLR_BIT(TCCR1B,WGM13);
       SET_BIT(TCCR1B,WGM12);
       SET_BIT(TCCR1A,WGM11);
       SET_BIT(TCCR1A,WGM10);
       /*Selection Of The Output Mode */
      #if TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
       CLR_BIT(TCCR1A,COM1B1);
       CLR_BIT(TCCR1A,COM1B0);
      #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_TOGGLE_PIN_MODE
       CLR_BIT(TCCR1A,COM1B1);
       SET_BIT(TCCR1A,COM1B0);
      #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_CLEAR_PIN_MODE
       SET_BIT(TCCR1A,COM1B1);
       CLR_BIT(TCCR1A,COM1B0);
      #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_SET_PIN_MODE
        SET_BIT(TCCR1A,COM1B1);
        SET_BIT(TCCR1A,COM1B0);
      #else
          #error"Invalid Fast PWM OutPut Pin Mode........!"
      #endif
   #elif MODE_REQUESTED_TIMER_1 == TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT
       SET_BIT(TCCR1B,WGM13);
       CLR_BIT(TCCR1B,WGM12);
       CLR_BIT(TCCR1A,WGM11);
       CLR_BIT(TCCR1A,WGM10);
       /*Selection Of the Output Mode*/
        #if  TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_TOGGLE_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_CLEAR_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_SET_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #else
           #error"Invalid OutPut Pin Mode....!"
         #endif
   #elif MODE_REQUESTED_TIMER_1 == TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT
       SET_BIT(TCCR1B,WGM13);
       CLR_BIT(TCCR1B,WGM12);
       CLR_BIT(TCCR1A,WGM11);
       SET_BIT(TCCR1A,WGM10);
       /*Selection Of the Output Mode*/
        #if  TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_TOGGLE_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_CLEAR_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_SET_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #else
           #error"Invalid OutPut Pin Mode....!"
         #endif
   #elif MODE_REQUESTED_TIMER_1 == TIMER1_PWM_PHASE_CORRECT
       SET_BIT(TCCR1B,WGM13);
       CLR_BIT(TCCR1B,WGM12);
       SET_BIT(TCCR1A,WGM11);
       CLR_BIT(TCCR1A,WGM10);
       /*Selection Of the Output Mode*/
        #if  TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_TOGGLE_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_CLEAR_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_SET_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #else
           #error"Invalid OutPut Pin Mode....!"
         #endif
   #elif MODE_REQUESTED_TIMER_1 == TIMER1_PWM_PHASE_CORRECT
       SET_BIT(TCCR1B,WGM13);
       CLR_BIT(TCCR1B,WGM12);
       SET_BIT(TCCR1A,WGM11);
       SET_BIT(TCCR1A,WGM10);
       /*Selection Of the Output Mode*/
        #if  TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_TOGGLE_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_CLEAR_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_PHASE_CORRECT_PWM_MODE == OC1A_SET_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #else
           #error"Invalid OutPut Pin Mode....!"
         #endif
    #elif MODE_REQUESTED_TIMER_1 == TIMER1_CTC_MODE
       SET_BIT(TCCR1B,WGM13);
       SET_BIT(TCCR1B,WGM12);
       CLR_BIT(TCCR1A,WGM11);
       CLR_BIT(TCCR1A,WGM10);
       /*Selection Of the Output Mode*/
        #if  TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_TOGGLE_PIN_MODE
             CLR_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_CLEAR_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             CLR_BIT(TCCR1A,COM1B0);
        #elif TIMER1_OC1A_PIN_NON_PWM_MODE == OC1A_SET_PIN_MODE
             SET_BIT(TCCR1A,COM1B1);
             SET_BIT(TCCR1A,COM1B0);
        #else
           #error"Invalid OutPut Pin Mode....!"
         #endif
   #elif MODE_REQUESTED_TIMER_1 == TIMER1_FAST_PWM
       SET_BIT(TCCR1B,WGM13);
       SET_BIT(TCCR1B,WGM12);
       SET_BIT(TCCR1A,WGM11);
       CLR_BIT(TCCR1A,WGM10);
       /*Selection Of The Output Mode */
      #if TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
       CLR_BIT(TCCR1A,COM1B1);
       CLR_BIT(TCCR1A,COM1B0);
      #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_TOGGLE_PIN_MODE
       CLR_BIT(TCCR1A,COM1B1);
       SET_BIT(TCCR1A,COM1B0);
      #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_CLEAR_PIN_MODE
       SET_BIT(TCCR1A,COM1B1);
       CLR_BIT(TCCR1A,COM1B0);
      #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_SET_PIN_MODE
        SET_BIT(TCCR1A,COM1B1);
        SET_BIT(TCCR1A,COM1B0);
      #else
          #error"Invalid Fast PWM OutPut Pin Mode........!"
      #endif
   #elif MODE_REQUESTED_TIMER_1 == TIMER1_FAST_PWM
       SET_BIT(TCCR1B,WGM13);
       SET_BIT(TCCR1B,WGM12);
       SET_BIT(TCCR1A,WGM11);
       SET_BIT(TCCR1A,WGM10);
       /*Selection Of The Output Mode */
      #if TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_DISCONNECT_PIN_MODE
       CLR_BIT(TCCR1A,COM1B1);
       CLR_BIT(TCCR1A,COM1B0);
      #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_TOGGLE_PIN_MODE
       CLR_BIT(TCCR1A,COM1B1);
       SET_BIT(TCCR1A,COM1B0);
      #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_CLEAR_PIN_MODE
       SET_BIT(TCCR1A,COM1B1);
       CLR_BIT(TCCR1A,COM1B0);
      #elif  TIMER1_OC1A_PIN_FAST_PWM_MODE == OC1A_SET_PIN_MODE
        SET_BIT(TCCR1A,COM1B1);
        SET_BIT(TCCR1A,COM1B0);
      #else
          #error"Invalid Fast PWM OutPut Pin Mode........!"
      #endif
     #else
        #error"Invalid Mode Requested Option.....!"
     #endif
#else
#error"Invalid Channel Selection....!"
  #endif
	//Choosing A Suitable Prescaler for Timer1
	TCCR1B &= 0xF8;
	TCCR1B |= TIMER_PRESCALER;
}

void TIMER_VoidSetPreLoadValue(u8 Copy_u8TimerNumber,u8 Copy_u8PreLoadValue)
{
	u8 Error_State = OK;
	switch(Copy_u8TimerNumber)
	{
	case Timer0:
		TCNT0 =Copy_u8PreLoadValue;
		break;
	case Timer1:
		TCNT1L =Copy_u8PreLoadValue;
		break;
	case Timer2:
		TCNT2= Copy_u8PreLoadValue;
		break;
	default:
		Error_State=NOK;
		break;
	}

}

void TIMER_VoidSetCTCValue(u8 Copy_u8TimerNumber,u8 Copy_u8CTCValue)
{
	switch(Copy_u8TimerNumber)
	{
	case Timer0:
		OCR0=Copy_u8CTCValue;
		break;
	case Timer1:
  #if CHANNEL_SELECTED == CHANNEL_A
		OCR1AL=Copy_u8CTCValue;
#elif CHANNEL_SELECTED == CHANNEL_B
		OCR1BL=Copy_u8CTCValue;
#else
		/*nothing*/
#endif
		break;
	case Timer2:
		OCR2=Copy_u8CTCValue;
		break;
	}
}
