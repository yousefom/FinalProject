/*
 * ON_OFF_BUTTONS.h
 *
 *  Created on: Nov 18, 2021
 *      Author: omarg
 */

#ifndef ON_OFF_BUTTONS_H_
#define ON_OFF_BUTTONS_H_

#define INCREASE_BUTTON PIN6
#define DECREASE_BUTTON PIN0


#define PRESSED         1
#define NOT_PRESSED         0

void BUTTONS_VoidInit(void);
u8 BUTTON_INCREASE_CHECK_PRESSED(void);
u8 BUTTON_DECREASE_CHECK_PRESSED(void);

#endif /* ON_OFF_BUTTONS_H_ */
