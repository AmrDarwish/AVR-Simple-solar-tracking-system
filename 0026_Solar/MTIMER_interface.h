/*
 * MTIMER_interface.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Amr-a
 */

#ifndef MTIMER_INTERFACE_H_
#define MTIMER_INTERFACE_H_

typedef enum{
	DIV_8,
	DIV_64,
	DIV_256

}Prescaler_t;
typedef enum {
	NORMAL_MODE,
	CTC_TOGGLE,
	CTC_SET,
	CTC_CLR,
	FAST_PWM_NON_INVERTING,
	FAST_PWM_INVERTING
	//phae correct
}Timer1Modes_t;
typedef enum {
	TOP_CTC_OCR1A,
	TOP_CTC_ICR1,
	TOP_FPWM_ICR1,
	TOP_FPWM_OCR1A

}Top_t;

void MTIMER0_voidInit(void);
void MTIMER0_voidDisable(void);
void MTIMER0_voidSetPreload(u8 Copy_u8Preload);
void MTIMER0_voidSetDutyCycle(u8 Copy_u8DutyCycle);
/*
 * opcr1A
 * ICR1
 * */
void MTIMER1_voidInit( Timer1Modes_t Copy_Timer1_Mode , Top_t Copy_Timer1TopMode , Prescaler_t Copy_enuPrescalerValue );
void MTIMER1_voidSetTopValue(u16 Copy_u16TopValue , Top_t Copy_Timer1TopMode);
void MTIMER1_voidSetDutyCycle(u16 Copy_u16DutyCycleValue);


#endif /* MTIMER_INTERFACE_H_ */
