/*
 * Segment_Behavior.h
 *
 *  Created on: Dec 6, 2021
 *      Author: omarg
 */

#ifndef SEGMENT_BEHAVIOR_H_
#define SEGMENT_BEHAVIOR_H_

void Segment_VoidInit(void);
void Segment_VoidEnableLEFT(void);
void Segment_VoidDisableLEFT(void);
void Segment_VoidEnableRIGHT(void);
void Segment_VoidDisableRIGHT(void);
void Segment_VoidSendNumber(u8 Copy_u8Number);
void Segmnet_Void_SET_TEMP(u8 Copy_u8Number,f32 time_sec);

#endif /* SEGMENT_BEHAVIOR_H_ */
