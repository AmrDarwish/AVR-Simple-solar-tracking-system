/*
 * HServo_config.h
 *
 *  Created on: Aug 18, 2023
 *      Author: Amr-a
 */

#ifndef HSERVO_CONFIG_H_
#define HSERVO_CONFIG_H_
/*
 * PD4_OC1B
 * PD5_OC1A
 * PD7_OC2
 * PD3_OC0
 *
 * */
#define SERVO_PIN	PD5_OC1A
/*
 * sonfig this part as
 * simulation: DUTY: 2000:1000 while ADC_s32Mapped_Servo and HServo_voidSetAngleSimulation takes from 90:90-
 * real      : DUTY: 2550:450  while ADC_s32Mapped_Servo and HServo_voidSetAngle			 takes from 180:0
 * */
#define MAX_DUTY	2000
#define MINI_DUTY	1000



#endif /* HSERVO_CONFIG_H_ */
