/*
 * HEATING_COOLING.h
 *
 *  Created on: Nov 18, 2021
 *      Author: omarg
 */

#ifndef HEATING_COOLING_H_
#define HEATING_COOLING_H_


#define HEAT_PIN 0


#define COOL_PIN 1


void HEATING_COOLING_VoidInit(void);
void HEATING_VoidON(void);
void HEATING_VoidOFF(void);
void COOLING_VoidON(void);
void COOLING_VoidOFF(void);

#endif /* HEATING_COOLING_H_ */
