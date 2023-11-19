/*
 * MTIMER_regesters.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Amr-a
 */

#ifndef MTIMER_REGESTERS_H_
#define MTIMER_REGESTERS_H_

#define OCR0			*((volatile u8 *)0x5C)
#define TCCR0			*((volatile u8 *)0x53)
#define TCCR0_FOC0 		7
#define TCCR0_WGM00 	6
#define TCCR0_COM01 	5
#define TCCR0_COM00 	4
#define TCCR0_WGM01 	3
#define TCCR0_CS02 		2
#define TCCR0_CS01 		1
#define TCCR0_CS00		0

#define TIMSK			*((volatile u8*)0x59)
#define TIMSK_OCIE2    7
#define TIMSK_TOIE2    6
#define TIMSK_TICIE1   5
#define TIMSK_OCIE1A   4
#define TIMSK_OCIE1B   3
#define TIMSK_TOIE1    2
#define TIMSK_OCIE0    1
#define TIMSK_TOIE0    0

#define TIFR			*((volatile u8*)0x58)
#define TIFR_OCF2      7
#define TIFR_TOV2      6
#define TIFR_ICF1      5
#define TIFR_OCF1A     4
#define TIFR_OCF1B     3
#define TIFR_TOV1      2
#define TIFR_OCF0      1
#define TIFR_TOV0      0

#define TCNT0			*((volatile u8 *)0x52)


#define TCCR1A 			*((volatile u8*)0x4f)
#define TCCR1A_COM1A1	7
#define TCCR1A_COM1A0   6
#define TCCR1A_COM1B1   5
#define TCCR1A_COM1B0   4
#define TCCR1A_FOC1A    3
#define TCCR1A_FOC1B    2
#define TCCR1A_WGM11    1
#define TCCR1A_WGM10    0

#define TCCR1B 			*((volatile u8*)0x4e)
#define TCCR1B_ICNC1  7
#define TCCR1B_ICES1  6
#define TCCR1B_WGM13  4
#define TCCR1B_WGM12  3
#define TCCR1B_CS12   2
#define TCCR1B_CS11   1
#define TCCR1B_CS10   0


#define TCNT1		*((volatile u16*)0x4c)
#define OCR1A		*((volatile u16*)0x4a)
#define OCR1B		*((volatile u16*)0x48)
#define ICR1 		*((volatile u16*)0x46)



#endif /* MTIMER_REGESTERS_H_ */
