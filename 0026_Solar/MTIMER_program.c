/*
 * MTIMER_program.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Amr-a
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MTIMER_interface.h"
#include "MTIMER_regesters.h"
#include "MTimer_config.h"
#include "MTIMER_private.h"


void MTIMER0_voidInit(void){
#if TIMER0_MODE == TIMER0_NORMAL

	/*selecting  wave generation mode as normal mode */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	/* enable timer 0 interrupt SIE */
	SET_BIT(TIMSK,TIMSK_TOIE0);
	/* setting preload value */
	TCNT0 = PRELOAD_VALUE;

#elif TIMER0_MODE == TIMER0_CTC
	/* selecting  wave generation mode as CTC mode */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	/* set out compare mat reg */
	OCR0 = COMPARE_MATCH_VALUE;
	/* Enable ctc ISR */
	SET_BIT(TIMSK , TIMSK_OCIE0);
#elif TIMER0_MODE == FAST_PWM
	/* selecting  wave generation mode as FAST_PWM mode */
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	/* selecting non inverting mode */
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#endif

	/* selecting timer 0 prescaler as dev by 8*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);





}
void MTIMER0_voidDisable(void){
	/*No clock source */
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);


}
void MTIMER0_voidSetPreload(u8 Copy_u8Preload){
	TCNT0 = Copy_u8Preload;

}
void MTIMER0_voidSetDutyCycle(u8 Copy_u8DutyCycle){
	OCR0 = Copy_u8DutyCycle;
}

void MTIMER1_voidInit( Timer1Modes_t Copy_Timer1_Mode , Top_t Copy_Timer1TopMode , Prescaler_t Copy_enuPrescalerValue ){
	switch (Copy_Timer1_Mode) {
	case NORMAL_MODE : {
		CLR_BIT(TCCR1A,TCCR1A_COM1A0);
		CLR_BIT(TCCR1A,TCCR1A_COM1B0);
		CLR_BIT(TCCR1A,TCCR1A_COM1A1);
		CLR_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	}
	case CTC_TOGGLE : {
		SET_BIT(TCCR1A,TCCR1A_COM1A0);
		SET_BIT(TCCR1A,TCCR1A_COM1B0);
		CLR_BIT(TCCR1A,TCCR1A_COM1A1);
		CLR_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	}
	case CTC_SET : {
		SET_BIT(TCCR1A,TCCR1A_COM1A0);
		SET_BIT(TCCR1A,TCCR1A_COM1B0);
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	}
	case CTC_CLR : {
		CLR_BIT(TCCR1A,TCCR1A_COM1A0);
		CLR_BIT(TCCR1A,TCCR1A_COM1B0);
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	}
	case FAST_PWM_NON_INVERTING : {
		CLR_BIT(TCCR1A,TCCR1A_COM1A0);
		CLR_BIT(TCCR1A,TCCR1A_COM1B0);
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	}
	case FAST_PWM_INVERTING : {
		SET_BIT(TCCR1A,TCCR1A_COM1A0);
		SET_BIT(TCCR1A,TCCR1A_COM1B0);
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
		SET_BIT(TCCR1A,TCCR1A_COM1B1);
		break;
	}

	default: break;
	}

	switch(Copy_Timer1TopMode) {
	case TOP_CTC_ICR1 : {
		CLR_BIT(TCCR1A,TCCR1A_WGM10);
		CLR_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1B,TCCR1B_WGM12);
		SET_BIT(TCCR1B,TCCR1B_WGM13);
		break;
	}
	case TOP_CTC_OCR1A : {
		CLR_BIT(TCCR1A,TCCR1A_WGM10);
		CLR_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1B,TCCR1B_WGM12);
		CLR_BIT(TCCR1B,TCCR1B_WGM13);
		break;
	}
	case TOP_FPWM_ICR1 : {
		CLR_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1B,TCCR1B_WGM12);
		SET_BIT(TCCR1B,TCCR1B_WGM13);
		break;
	}
	case TOP_FPWM_OCR1A : {
		SET_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1B,TCCR1B_WGM12);
		SET_BIT(TCCR1B,TCCR1B_WGM13);
		break;
	}
	//
	//
	//
	default: break;
	}

	switch (Copy_enuPrescalerValue){
	case DIV_8: {
			CLR_BIT(TCCR1B,TCCR1B_CS10);
			SET_BIT(TCCR1B,TCCR1B_CS11);
			CLR_BIT(TCCR1B,TCCR1B_CS12);
			break;
		}
	case DIV_64: {
			SET_BIT(TCCR1B,TCCR1B_CS10);
			SET_BIT(TCCR1B,TCCR1B_CS11);
			CLR_BIT(TCCR1B,TCCR1B_CS12);
			break;
		}
	case DIV_256: {
			CLR_BIT(TCCR1B,TCCR1B_CS10);
			CLR_BIT(TCCR1B,TCCR1B_CS11);
			SET_BIT(TCCR1B,TCCR1B_CS12);
			break;
		}
	//
	//
	//
	default: break;
	}

}
void MTIMER1_voidSetTopValue(u16 Copy_u16TopValue , Top_t Copy_Timer1TopMode){
	switch (Copy_Timer1TopMode) {
		case TOP_FPWM_ICR1 : ICR1 = Copy_u16TopValue; break;
		case TOP_FPWM_OCR1A: OCR1A = Copy_u16TopValue; break;
		default: break;
	}

}
void MTIMER1_voidSetDutyCycle(u16 Copy_u16DutyCycleValue){
	OCR1A = Copy_u16DutyCycleValue;
}
