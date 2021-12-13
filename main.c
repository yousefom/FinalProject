/*
 * main.c
 *
 *  Created on: Nov 14, 2021
 *      Author: youssef omar
 */

#include"system.h"
int main(void)
{
   System_VoidInit();
   ADC_voidInit();
   while(1)
   {
	   switch(STATE)
	   {
	   case ON:

		   ON_VoidState();
		   break;

	   case OFF:

		   OFF_VoidState();
		   break;

	   case SETTING :

		   Set_VoidState();
		   break;

	   default :

		   /*Nothing*/
		   break;

	  }
   }
   return 0;
}

void __vector_18(void)  __attribute__((signal));
void __vector_18(void){
	if(STATE==OFF){
		STATE = ON;
		 TARGET_TEMP = EEPROM_voidRead_DATA(0x00);
	}
	else if (STATE==ON || STATE==SETTING){
		STATE = OFF;
	}
}




void __vector_5(void)  __attribute__((signal));
void __vector_5(void){
	SENSOR_FLAG = 1;
}




void __vector_19(void)  __attribute__((signal));
void __vector_19(void){
	if ((STATE==SETTING) || (STATE==ON)){
		SETTING_COUNTER++;
		if(SETTING_COUNTER % 4 == 0)
		{
			TOGGLE_FLAG ^= 1;
		}
		if (SETTING_COUNTER > 20){

			// Write the new desired temperature in EEPROM
			STATE = ON;
		}
	}
}
