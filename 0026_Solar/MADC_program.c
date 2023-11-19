#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "MADC_interface.h"
#include "MADC_register.h"
#include "MADC_private.h"
#include "MADC_config.h"
Error_State_t MADC_ErrorStateInit(u8 Copy_u8VReferencetype,u8 Copy_u8Prescale, u8 Copy_u8Adjastment){
	Error_State_t errorState = return_Ok;
	//setting refrence volt
	switch (Copy_u8VReferencetype) {
	case ADC_AREF :
			//AREF and turned off Internal Vref
			CLR_BIT(ADMUX,ADMUX_REFS1);
			CLR_BIT(ADMUX,ADMUX_REFS0);
			break;
	case ADC_VREF_VCC :
			// AVCC with capacitor at AREF pin
	 		CLR_BIT(ADMUX,ADMUX_REFS1);
			SET_BIT(ADMUX,ADMUX_REFS0);
			break;
	case ADC_INTERNAL_256mv :
			// Internal 2.56V Voltage Reference with external capacitor at AREF pin
			SET_BIT(ADMUX,ADMUX_REFS1);
			SET_BIT(ADMUX,ADMUX_REFS0);
			break;
	default : errorState = return_Nok;
		break;
	}
		switch (Copy_u8Adjastment) {
		case ADC_RIGHT_ADJUSTMENT : 	CLR_BIT(ADMUX,ADMUX_ADLAR);	break;
		case ADC_LEFT_ADJUSTMENT  :		SET_BIT(ADMUX,ADMUX_ADLAR);	break;
		default: errorState = return_Nok;							break;
		}
		/*
		    ADC_PRESCALER_DIV2		1
			ADC_PRESCALER_DIV4		2
			ADC_PRESCALER_DIV8		3
			ADC_PRESCALER_DIV16		4
			ADC_PRESCALER_DIV32		5
			ADC_PRESCALER_DIV64		6
			ADC_PRESCALER_DIV128	7
		 * */
		//prescaler devetion by 32
		switch(Copy_u8Prescale){
		case ADC_PRESCALER_DIV2:
			SET_BIT(ADCSRA,ADCSRA_ADPS0);
			CLR_BIT(ADCSRA,ADCSRA_ADPS1);
			CLR_BIT(ADCSRA,ADCSRA_ADPS2);
			break;
		case ADC_PRESCALER_DIV4:
			CLR_BIT(ADCSRA,ADCSRA_ADPS0);
			SET_BIT(ADCSRA,ADCSRA_ADPS1);
			CLR_BIT(ADCSRA,ADCSRA_ADPS2);
			break;
		case ADC_PRESCALER_DIV8:
			SET_BIT(ADCSRA,ADCSRA_ADPS0);
			SET_BIT(ADCSRA,ADCSRA_ADPS1);
			CLR_BIT(ADCSRA,ADCSRA_ADPS2);
			break;
		case ADC_PRESCALER_DIV16:
			CLR_BIT(ADCSRA,ADCSRA_ADPS0);
			CLR_BIT(ADCSRA,ADCSRA_ADPS1);
			SET_BIT(ADCSRA,ADCSRA_ADPS2);
			break;
		case ADC_PRESCALER_DIV32:
			SET_BIT(ADCSRA,ADCSRA_ADPS0);
			CLR_BIT(ADCSRA,ADCSRA_ADPS1);
			SET_BIT(ADCSRA,ADCSRA_ADPS2);
			break;
		case ADC_PRESCALER_DIV64:
			CLR_BIT(ADCSRA,ADCSRA_ADPS0);
			SET_BIT(ADCSRA,ADCSRA_ADPS1);
			SET_BIT(ADCSRA,ADCSRA_ADPS2);
			break;
		case ADC_PRESCALER_DIV128:
			SET_BIT(ADCSRA,ADCSRA_ADPS0);
			SET_BIT(ADCSRA,ADCSRA_ADPS1);
			SET_BIT(ADCSRA,ADCSRA_ADPS2);
			break;
		default: errorState = return_Nok;
		}

		//enable ADC
		SET_BIT(ADCSRA,ADCSRA_ADEN);
		return errorState;

}
void MADC_voidInitDefault(void){

	//setting refrence volt internal
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);

	//setting adjust right
	CLR_BIT(ADMUX,ADMUX_ADLAR);

	//prescaler devetion by 32
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

	//enable ADC
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}
u16 MADC_u16GetValue(u8 Copy_u8AdcChannel){
	//clearing selection bits in order to choose
	ADMUX &= 0b11100000 ;
	// selceting chunnle
	ADMUX |= Copy_u8AdcChannel;
	// ADC start convertion
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	// busy wait until finish
	while ((GET_BIT(ADCSRA,ADCSRA_ADIF) == 0));
		// clear flag
		SET_BIT(ADCSRA,ADCSRA_ADIF);

	return ADC_DATA_REG;

}

s32 MADC_s32Mapping(s32 Copy_s32MaxOut ,s32 Copy_s32MiniOut,u16 Copy_u16MaxDigitalSensorRead , u16 Copy_u16MiniDigitalSensorRead ,u16 Copy_u16DigitalSensorRead)
{
	s32 X;
	X =(s32) (( (f64) (  (f64) (Copy_s32MaxOut - Copy_s32MiniOut) * ((Copy_u16DigitalSensorRead-Copy_u16MiniDigitalSensorRead) )/ (f64)( Copy_u16MaxDigitalSensorRead -Copy_u16MiniDigitalSensorRead)) + Copy_s32MiniOut) + 1);
	return X ;
}
