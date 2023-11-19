/***************************************************/
/********************	Auther	: Amr 		********/
/********************	Layer 	:  HLCD		********/
/********************	Module	:  LCD		********/
/********************	Version : 11.00		********/
/********************	Date	:  3/8/2023	********/
/***************************************************/
/***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "STD_TYPES.h"
#include "util/delay.h"
#include "BIT_MATH.h"
#include "MDIO_interface.h"
#include "HLCD_interface.h"
#include "HLCD_private.h"
#include "HLCD_config.h"



void HLCD_voidInit(){
	_delay_ms(40);
	HLCD_voidSendCommand(0b00111100); 		// function set
	HLCD_voidSendCommand(0b00001100); 		// display on/off control
	HLCD_voidSendCommand(0b00000001); 		// clear display

}
void HLCD_voidSendData(u8 Copy_u8Data){
	/*	SET RS to send data */
	MDIO_ErrorS_SetPinValue(LCD_PORT_CTRL,LCD_RS,DIO_HIGH);
	/*	CLR RS to Enable write */
	MDIO_ErrorS_SetPinValue(LCD_PORT_CTRL,LCD_RW,DIO_LOW);
	/*Send Data */
	MDIO_ErrorS_SetPortValue(LCD_PORT_DATA,Copy_u8Data);
	/* set EN for 2ms to make LCD CPU reads the data  */
	MDIO_ErrorS_SetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_HIGH);
	_delay_ms(2);
	MDIO_ErrorS_SetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_LOW);



}
void HLCD_voidSendCommand(u8 Copy_u8Command){

	/*	CLR RS to send command */
	MDIO_ErrorS_SetPinValue(LCD_PORT_CTRL,LCD_RS,DIO_LOW);

	/*	CLR RS to Enable write */
	MDIO_ErrorS_SetPinValue(LCD_PORT_CTRL,LCD_RW,DIO_LOW);

	/*Send Command */
	MDIO_ErrorS_SetPortValue(LCD_PORT_DATA,Copy_u8Command);

	/* set EN for 2ms to make LCD CPU reads the command  */
	MDIO_ErrorS_SetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_HIGH);

	_delay_ms(2);

	MDIO_ErrorS_SetPinValue(LCD_PORT_CTRL,LCD_EN,DIO_LOW);

}


void HLCD_voidSendString(s8 Copy_u8Data[]){
	int i = 0 ;
	while (Copy_u8Data[i]!='\0'){
		HLCD_voidSendData(Copy_u8Data[i]);
		i++;
	}
}

void HLCD_voidSendInt(s32 Copy_u32Data){
	s8 s[20];
		itoa(Copy_u32Data, s, 10);
		HLCD_voidSendString(s);
}

void HLCD_voidClearDisplay(){
	HLCD_voidSendCommand(0b00000001);
}

void HLCD_voidReturnHome(){
	HLCD_voidSendCommand(0b00000010);
}

void HLCD_voidSetCursorPosition(u8 x , u8 y){
	u8 command = 0b10000000;
	if (x == 2) command  |=0x40 ;
	command  +=y ;
	HLCD_voidSendCommand(command);
}
