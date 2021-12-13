/*
 * system.h

 *
 *  Created on: Dec 6, 2021
 *      Author: omarg
 */


#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"DIO_Interface.h"
#include"ADC_Interface.h"
#include"HEATING_COOLING.h"
#include"H_C_LED.h"
#include"GIE_Interface.h"
#include"ON_OFF_BUTTONS.h"
#include"Segment_Behavior.h"
#include"EEPROM_Interface.h"
#include "TIMER_Interface.h"
#include"TIMER_Private.h"



#ifndef SYSTEM_H_
#define SYSTEM_H_


#define ON 1
#define OFF 0
#define SETTING 2
#define NULL 255

//#define BLINKING_PERIOD 1         //1 second blinking
#define TEMP_CHANGE 5
#define MIN_TEMP 35
#define MAX_TEMP 75
#define INIT_TEMP 60
#define TEMP_MEASURES 10

u8  STATE;
u16 ARR_TEMP[TEMP_MEASURES];
u8 TARGET_TEMP;
u16 CURRENT_TEMP;
u16 AVG_TEMP;
u8  SENSOR_FLAG;
u8  MEASURES_COUNT;
u8  SETTING_COUNTER;
u16 TOGGLE_FLAG;
u8  ARR_COUNTER;


void System_VoidInit(void);

void ON_VoidState(void);
void OFF_VoidState(void);

void Set_VoidState(void);

void Change_VoidTemp(void);

void ADD_VoidNew_Temp(u16 *Copy_u16Arr , u16 Copy_u16New_Value);

u16 AVG_u16Temp(u16 *Copy_u16Arr);

void ARR_VoidTemp_Init(void);



#endif /* SYSTEM_H_ */
