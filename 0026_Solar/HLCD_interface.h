/***************************************************/
/********************	Auther	: Amr 		********/
/********************	Layer 	:  HLCD		********/
/********************	Module	:  LCD		********/
/********************	Version : 11.00		********/
/********************	Date	:  3/8/2023	********/
/***************************************************/
/**************************************************/

#ifndef _HLCD_INTERFACE_H
#define _HLCD_INTERFACE_H
#include "STD_TYPES.h"
void HLCD_voidInit();
void HLCD_voidSendData(u8 Copy_u8Data);
void HLCD_voidSendCommand(u8 Copy_u8Command);
void HLCD_voidSendString(s8 Copy_u8Data[]);
void HLCD_voidSendInt(s32 Copy_u32Data);

void HLCD_voidClearDisplay();
void HLCD_voidReturnHome();
void HLCD_voidClearDisplay();
void HLCD_voidSetCursorPosition(u8 x,u8 y);



#endif
