/***************************************************/
/********************	Auther	: Amr 		********/
/********************	Layer 	: MCAL		********/
/********************	Module	: DIO		********/
/********************	Version: 1.00		********/
/********************	Date	: 2/8/2023	********/
/***************************************************/
/**************************************************/

#ifndef _MDIO_INTERFACE_H
#define _MDIO_INTERFACE_H
#include "STD_TYPES.h"

/* error enum with cases*/




#define DIO_OUTPUT	1
#define DIO_INPUT	0

#define PORT_LOW	0
#define PORT_HIGH	0xff
#define DIO_LOW		0
#define DIO_HIGH	1
#define HIGH		1
#define LOW			0

#define DIO_PORTA	1
#define DIO_PORTB	2
#define DIO_PORTC	3
#define DIO_PORTD	4

#define DIO_PIN0	0
#define DIO_PIN1	1
#define DIO_PIN2	2
#define DIO_PIN3	3
#define DIO_PIN4	4
#define DIO_PIN5	5
#define DIO_PIN6	6
#define DIO_PIN7	7


void Port_voidInit();

Error_State_t MDIO_ErrorS_EnablePinPullUp( u8 Copy_u8Port , u8 Copy_u8Pin);

void MDIO_voidSetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8  Copy_U8Mode );

Error_State_t MDIO_ErrorS_SetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8  Copy_U8Mode );
Error_State_t MDIO_ErrorS_GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8* P_u8Value );
Error_State_t MDIO_ErrorS_TogPinValue( u8 Copy_u8Port , u8 Copy_u8Pin );

Error_State_t MDIO_ErrorS_SetPortValue( u8 Copy_u8Port , u8  Copy_U8Value );
Error_State_t MDIO_ErrorS_GetPortValue( u8 Copy_u8Port , u8* P_u8Value );

#endif
