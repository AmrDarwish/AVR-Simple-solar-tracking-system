/*
 * HServo_program.c
 *
 *  Created on: Aug 18, 2023
 *      Author: Amr-a
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "MTIMER_interface.h"
#include "HServo_interface.h"
#include "HServo_private.h"
#include "HServo_config.h"

/*
 * sonfig this part as
 * simulation: DUTY: 2000:1000 while ADC_s32Mapped_Servo and HServo_voidSetAngleSimulation takes from 90:90-
 * real      : DUTY: 2550:450  while ADC_s32Mapped_Servo and HServo_voidSetAngle			 takes from 180:0
 * */

void HServo_voidSetAngle(u32 Copy_u8Angle){

	u64 duty = MAX_DUTY - ((f64)((MAX_DUTY - MINI_DUTY)*(MAX_ANGLE - Copy_u8Angle))/(f64)(MAX_ANGLE - MINI_ANGLE));

#if SERVO_PIN == PD5_OC1A
	MTIMER1_voidSetDutyCycle(duty);
#elif SERVO_PIN == PD4_OC1B
#elif SERVO_PIN == PD7_OC2
#elif SERVO_PIN == PB3_OC0
#endif
}


void HServo_voidSetAngleSimulation(s32 Copy_u8Angle){
	Copy_u8Angle+= 90;

	u64 duty = MAX_DUTY - ((f64)((MAX_DUTY - MINI_DUTY)*(MAX_ANGLE - Copy_u8Angle))/(f64)(MAX_ANGLE - MINI_ANGLE));

#if SERVO_PIN == PD5_OC1A
	MTIMER1_voidSetDutyCycle(duty);
#elif SERVO_PIN == PD4_OC1B
#elif SERVO_PIN == PD7_OC2
#elif SERVO_PIN == PB3_OC0
#endif
}
