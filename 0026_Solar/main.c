/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Amr-a
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "util/delay.h"
#include "MDIO_interface.h"
#include "MADC_interface.h"
#include "MTIMER_interface.h"
#include "HLCD_interface.h"
#include "HServo_interface.h"
#include "HLDR_interface.h"

s16 s16MappingLuxToAngle(s16 Copy_s16MaxAngle , s16 Copy_s16MiniAngle , u16 Copy_u16MaxLux 		, u16 Copy_u16MiniLux 	   , u16 Copy_u16Lux);

int main (){

	u16 LDRLux;
	s16 servoAngle;
	HLCD_voidInit();
	Port_voidInit();
	HLCD_voidInit();

	MADC_ErrorStateInit(ADC_VREF_VCC,ADC_PRESCALER_DIV32,ADC_RIGHT_ADJUSTMENT);

	MTIMER1_voidInit(FAST_PWM_NON_INVERTING, TOP_FPWM_ICR1,DIV_8);
	MTIMER1_voidSetTopValue(20000,TOP_FPWM_ICR1);


	while(1){
		/* getting read from LDR "ADC3"*/
		LDRLux  	= HLDR_u16GetRead();

		/* Mapping ADC reading to get brightness ammount "lux" */
		/* Mapping ADC reading to get Servo Angle */

		servoAngle = s16MappingLuxToAngle(90,-90,10000,0,LDRLux);
		/* Sending Angle to servo */
		HServo_voidSetAngleSimulation(servoAngle);

		/* Sending LUX to LCD */
		HLCD_voidSendString("    LUX:");
		HLCD_voidSendInt(10000-	LDRLux);
		HLCD_voidSendString(" ");
		/* Sending Servo angle to LCD */
		HLCD_voidSetCursorPosition(2,0);
		HLCD_voidSendString("Servo Angel:");
		HLCD_voidSendInt(servoAngle);
		HLCD_voidSendString("  ");
		HLCD_voidReturnHome();
	}
}

s16 s16MappingLuxToAngle(s16 Copy_s16MaxAngle , s16 Copy_s16MiniAngle , u16 Copy_u16MaxLux 		, u16 Copy_u16MiniLux 	   , u16 Copy_u16Lux)
{
	s16 X;
	X = (s16)( ( (f64) (  (f64) (Copy_s16MaxAngle - Copy_s16MiniAngle) * (( Copy_u16Lux - Copy_u16MiniLux ) ) / (f64)( Copy_u16MaxLux - Copy_u16MiniLux )) + Copy_s16MiniAngle) + 1);
	return X ;
}
