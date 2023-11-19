/***************************************************/
/********************	Auther	: Amr 		********/
/********************	Layer 	: MCAL		********/
/********************	Module	: DIO		********/
/********************	Version: 1.00		********/
/********************	Date	: 2/8/2023	********/
/***************************************************/
/***************************************************/
#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "MDIO_interface.h"
#include "MDIO_registers.h"
#include "MDIO_private.h"
#include "MDIO_config.h"

void Port_voidInit(void){

	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;
	PORTA = PORTA_INITAL_VAL;
	PORTB = PORTB_INITAL_VAL;
	PORTC = PORTC_INITAL_VAL;
	PORTD = PORTD_INITAL_VAL;





}
Error_State_t MDIO_ErrorS_EnablePinPullUp( u8 Copy_u8Port , u8 Copy_u8Pin){
	Error_State_t errorState = return_Ok;

	if (Copy_u8Pin > 7){
		errorState = return_Nok;
	}

	SFIOR &= ~(1<<2);
	switch (Copy_u8Port){
					case DIO_PORTA : SET_BIT(PORTA,Copy_u8Pin);break;
					case DIO_PORTB : SET_BIT(PORTB,Copy_u8Pin);break;
					case DIO_PORTC : SET_BIT(PORTC,Copy_u8Pin);break;
					case DIO_PORTD : SET_BIT(PORTD,Copy_u8Pin);break;
					default: errorState = return_Nok; break;
				}
	return errorState;

}

void MDIO_voidSetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8  Copy_U8Mode ){
	if(Copy_U8Mode == DIO_INPUT){
			switch (Copy_u8Port){
				case DIO_PORTA : CLR_BIT(DDRA,Copy_u8Pin);break;
				case DIO_PORTB : CLR_BIT(DDRB,Copy_u8Pin);break;
				case DIO_PORTC : CLR_BIT(DDRC,Copy_u8Pin);break;
				case DIO_PORTD : CLR_BIT(DDRD,Copy_u8Pin);break;
				default: break;
			}

	}
	else if(Copy_U8Mode == DIO_OUTPUT){
			switch (Copy_u8Port){
				case DIO_PORTA : SET_BIT(DDRA,Copy_u8Pin);break;
				case DIO_PORTB : SET_BIT(DDRB,Copy_u8Pin);break;
				case DIO_PORTC : SET_BIT(DDRC,Copy_u8Pin);break;
				case DIO_PORTD : SET_BIT(DDRD,Copy_u8Pin);break;
				default: break;
			}
	}

}
Error_State_t MDIO_ErrorS_SetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8  Copy_U8Mode ){
	Error_State_t errorState = return_Ok;
	if (Copy_u8Pin > 7){
		errorState = return_Nok;
	}

	if(Copy_U8Mode == DIO_LOW){
				switch (Copy_u8Port){
					case DIO_PORTA : CLR_BIT(PORTA,Copy_u8Pin);break;
					case DIO_PORTB : CLR_BIT(PORTB,Copy_u8Pin);break;
					case DIO_PORTC : CLR_BIT(PORTC,Copy_u8Pin);break;
					case DIO_PORTD : CLR_BIT(PORTD,Copy_u8Pin);break;
					default: errorState = return_Nok; break;
				}

		}
		else if(Copy_U8Mode == DIO_HIGH){
				switch (Copy_u8Port){
					case DIO_PORTA : SET_BIT(PORTA,Copy_u8Pin);break;
					case DIO_PORTB : SET_BIT(PORTB,Copy_u8Pin);break;
					case DIO_PORTC : SET_BIT(PORTC,Copy_u8Pin);break;
					case DIO_PORTD : SET_BIT(PORTD,Copy_u8Pin);break;
					default:errorState = return_Nok; break;
				}
		}
	return errorState;
}

Error_State_t MDIO_ErrorS_GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8* P_u8Value ){
	Error_State_t errorState = return_Ok;
	if (Copy_u8Pin > 7){
			errorState = return_Nok;
		}

	switch (Copy_u8Port){
						case DIO_PORTA : *P_u8Value = GET_BIT(PINA,Copy_u8Pin);break;
						case DIO_PORTB : *P_u8Value = GET_BIT(PINB,Copy_u8Pin);break;
						case DIO_PORTC : *P_u8Value = GET_BIT(PINC,Copy_u8Pin);break;
						case DIO_PORTD : *P_u8Value = GET_BIT(PIND,Copy_u8Pin);break;
						default: errorState = return_Nok; break;
					}
	return errorState;

}

Error_State_t MDIO_ErrorS_SetPortValue( u8 Copy_u8Port , u8  Copy_U8Value ){
	Error_State_t errorState = return_Ok;
	switch (Copy_u8Port){
		case DIO_PORTA : PORTA = Copy_U8Value ;break;
		case DIO_PORTB : PORTB = Copy_U8Value ;break;
		case DIO_PORTC : PORTC = Copy_U8Value ;break;
		case DIO_PORTD : PORTD = Copy_U8Value ;break;
		default:errorState = return_Nok; break;
	}

		return errorState;


}
Error_State_t MDIO_ErrorS_GetPortValue( u8 Copy_u8Port , u8* P_u8Value ){
	Error_State_t errorState = return_Ok;
	switch (Copy_u8Port){
		case DIO_PORTA : *P_u8Value = PINA ;break;
		case DIO_PORTB : *P_u8Value = PINB ;break;
		case DIO_PORTC : *P_u8Value = PINC ;break;
		case DIO_PORTD : *P_u8Value = PIND ;break;
		default: errorState = return_Nok; break;
	}
	return errorState;

}

Error_State_t MDIO_ErrorS_TogPinValue( u8 Copy_u8Port , u8 Copy_u8Pin ){
	Error_State_t errorState = return_Ok;
		switch (Copy_u8Port){
			case DIO_PORTA :  TOGGLE_BIT(PORTA,Copy_u8Pin) ; break;
			case DIO_PORTB :  TOGGLE_BIT(PORTB,Copy_u8Pin) ;break;
			case DIO_PORTC :  TOGGLE_BIT(PORTC,Copy_u8Pin) ;break;
			case DIO_PORTD :  TOGGLE_BIT(PORTD,Copy_u8Pin) ;break;
			default: errorState = return_Nok; break;
		}
		return errorState;
}
