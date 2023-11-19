/*
 * HLDR_interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Amr-a
 */

#ifndef HLDR_INTERFACE_H_
#define HLDR_INTERFACE_H_
/*
 * thees values must be same as what in MADC_interface
 * */
#define HLDR_ADC_ChANNEL0			0
#define HLDR_ADC_ChANNEL1			1
#define HLDR_ADC_ChANNEL2			2
#define HLDR_ADC_ChANNEL3			3
#define HLDR_ADC_ChANNEL4			4
#define HLDR_ADC_ChANNEL5			5
#define HLDR_ADC_ChANNEL6			6
#define HLDR_ADC_ChANNEL7			7

u16 HLDR_u16GetRead(void);

#endif /* HLDR_INTERFACE_H_ */
