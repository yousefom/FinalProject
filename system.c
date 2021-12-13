/*
 * system.c
 *
 *  Created on: Dec 4, 2021
 *      Author: omarg
 */

//#include"BIT_MATH.h"
//#include"STD_TYPES.h"
//#include"DIO_Interface.h"
//#include"ADC_Interface.h"
//#include"HEATING_COOLING.h"
//#include"H_C_LED.h"
//#include"EEPROM_Interface.h"
//#include"GIE_Interface.h"
//#include"ON_OFF_BUTTONS.h"
//#include"Segment_Behavior.h"
#include"system.h"
//

void System_VoidInit(void)
{
	ADC_voidInit();
	HEATING_COOLING_VoidInit();
	LED_VoidInit();
	BUTTONS_VoidInit();
	Segment_VoidInit();
	TIMER0_VoidInit();
	TIMER2_VoidInit();

	STATE=OFF;
	if(EEPROM_voidRead_Data(0x00)!=NULL)
	{
		TARGET_TEMP=EEPROM_voidRead_Data(0x00);
	}
	else
	{
		TARGET_TEMP=INIT_TEMP;
	}

	ARR_VoidTemp_Init();

	EEPROM_voidWrite_Data(0x00,TARGET_TEMP);

}


void ON_VoidState(void)

{
	if(SENSOR_FLAG ==1)
	{
		ADC_voidStartConversion(1);
		CURRENT_TEMP=(ADC_u16Read_DigitalValue()/10);
		ADD_VoidNew_Temp(ARR_TEMP,CURRENT_TEMP);
		AVG_TEMP=AVG_u16Temp(ARR_TEMP);
		SENSOR_FLAG=0;
	}
	Segmnet_Void_SET_TEMP(CURRENT_TEMP,1);
	Change_VoidTemp();
	if(BUTTON_INCREASE_CHECK_PRESSED()==PRESSED || BUTTON_DECREASE_CHECK_PRESSED()==PRESSED)
	{
		Segment_VoidDisableLEFT();
		Segment_VoidDisableRIGHT();
		SETTING_COUNTER=0;
		STATE=SETTING;

	}
}


void OFF_VoidState(void)
{
	LED_VoidOFF();
	HEATING_VoidOFF();
	COOLING_VoidOFF();
}


void Set_VoidState(void)
{
	HEATING_VoidOFF();
	COOLING_VoidOFF();
	LED_VoidOFF();
	if(TOGGLE_FLAG==1)
	{
		Segmnet_Void_SET_TEMP(TARGET_TEMP,1);
		Segment_VoidEnableLEFT();
		Segment_VoidEnableRIGHT();

	}
	else
	{
		Segment_VoidDisableLEFT();
		Segment_VoidDisableRIGHT();
	}
	if((BUTTON_INCREASE_CHECK_PRESSED()==PRESSED)&&(TARGET_TEMP<MAX_TEMP))
	{
		CURRENT_TEMP+=5;
		SETTING_COUNTER=0;
		Segmnet_Void_SET_TEMP(TARGET_TEMP,1);
		Segment_VoidEnableLEFT();
		Segment_VoidEnableRIGHT();
	}
	else if ((BUTTON_DECREASE_CHECK_PRESSED()==PRESSED)&&TARGET_TEMP<MIN_TEMP)
	{
		CURRENT_TEMP -=5;
		SETTING_COUNTER=0;
		Segmnet_Void_SET_TEMP(TARGET_TEMP,1);
		Segment_VoidEnableLEFT();
		Segment_VoidEnableRIGHT();
	}
	EEPROM_voidWrite_Data(0x0000,TARGET_TEMP);

}

void Change_VoidTemp(void)

{
	if( (TARGET_TEMP < AVG_TEMP + TEMP_CHANGE) && (TARGET_TEMP > AVG_TEMP - TEMP_CHANGE) ) //==if(target temp. = current temp. )
	{
			// Current Temperature equals Target Temperature
			// No need for Heating or Cooling
		HEATING_VoidOFF();
		COOLING_VoidOFF();
		}
		else if(TARGET_TEMP < AVG_TEMP + TEMP_CHANGE)
		{
			// Current Temperature is Larger
			// we need the Cooling element

			HEATING_VoidOFF();
			COOLING_VoidON();
			LED_VoidON();
		}
		else if (TARGET_TEMP > AVG_TEMP - TEMP_CHANGE)
		{
			// Current Temperature is Smaller
			// Heating element needed

			HEATING_VoidON();
			COOLING_VoidOFF();
			if (TOGGLE_FLAG == 1)
			{
				LED_VoidON();
			}
			else {
				LED_VoidOFF();
			}
		}
}


void ADD_VoidNew_Temp(u16 *Copy_u16Arr , u16 Copy_u16New_Value)
{
	Copy_u16Arr[ARR_COUNTER] = Copy_u16New_Value;
	ARR_COUNTER++;

		if (ARR_COUNTER == 10){
			ARR_COUNTER = 0;
		}
}

u16 AVG_u16Temp(u16 *Copy_u16Arr)
{
	u16 sum=0,avg=0;
	for(u8 i =0;i<TEMP_MEASURES;i++)
	{
		sum+=Copy_u16Arr[i];
	}
	avg= sum/TEMP_MEASURES;
	return avg;
}

void ARR_VoidTemp_Init(void)
{
	ADC_voidStartConversion(1);
	u16 first_temp =(ADC_u16Read_DigitalValue()/10);
	for(u8 i =0;i<TEMP_MEASURES;i++)
	{
		ARR_TEMP[i]=first_temp;
	}
	AVG_TEMP=AVG_u16Temp(ARR_TEMP);
	ARR_COUNTER=0;
}
