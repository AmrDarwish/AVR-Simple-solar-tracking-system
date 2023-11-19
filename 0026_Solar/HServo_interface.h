/*
 * HServo_interface.h
 *
 *  Created on: Aug 18, 2023
 *      Author: Amr-a
 */

#ifndef HSERVO_INTERFACE_H_
#define HSERVO_INTERFACE_H_

/*
 * sonfig this part as
 * simulation: DUTY: 2000:1000 while ADC_s32Mapped_Servo and HServo_voidSetAngleSimulation takes from 90:90-
 * real      : DUTY: 2550:450  while ADC_s32Mapped_Servo and HServo_voidSetAngle			 takes from 180:0
 * */

/*angel from 0 : 180 */
void HServo_voidSetAngle(u32 Copy_u8Angle);
/*angel from -90 : 90 */
void HServo_voidSetAngleSimulation(s32 Copy_u8Angle);

#endif /* HSERVO_INTERFACE_H_ */
