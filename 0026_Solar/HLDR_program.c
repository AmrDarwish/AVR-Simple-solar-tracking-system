/*
 * HLDR_program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Amr-a
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MADC_interface.h"
#include "HLDR_interface.h"
#include "HLDR_private.h"
#include "HLDR_config.h"

u16 HLDR_u16GetRead(void){

	u16 Lux = MADC_u16GetValue(HLDR_ADC_ChANNEL);
    Lux		= MADC_s32Mapping(HLDR_MAX_LUX,HLDR_MINI_LUX,HLDR_MAX_DIGIT_VAL,HLDR_MINI_DIGIT_VAL,Lux);
	return Lux;
}
