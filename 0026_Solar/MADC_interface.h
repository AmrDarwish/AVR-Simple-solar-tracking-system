#ifndef MADC_INTERFACE_H
#define MADC_INTERFACE_H

#define ADC_ChANNEL0			0
#define ADC_ChANNEL1			1
#define ADC_ChANNEL2			2
#define ADC_ChANNEL3			3
#define ADC_ChANNEL4			4
#define ADC_ChANNEL5			5
#define ADC_ChANNEL6			6
#define ADC_ChANNEL7			7

#define  ADC_AREF				0
#define  ADC_VREF_VCC			1
#define  ADC_INTERNAL_256mv		3

#define ADC_PRESCALER_DIV2		1
#define ADC_PRESCALER_DIV4		2
#define ADC_PRESCALER_DIV8		3
#define ADC_PRESCALER_DIV16		4
#define ADC_PRESCALER_DIV32		5
#define ADC_PRESCALER_DIV64		6
#define ADC_PRESCALER_DIV128	7

#define ADC_RIGHT_ADJUSTMENT	0
#define ADC_LEFT_ADJUSTMENT		1

/* Voltage Reference Selections for ADC
 * ADC_VREF_INTERNAL_OFF	0
 * ADC_VREF_VCC				1
 * ADC_INTERNAL_256mv		3
 * */
Error_State_t MADC_ErrorStateInit(u8 Copy_u8VReferencetype,u8 Copy_u8Prescale, u8 Copy_u8Adjastment);
void MADC_voidInitDefault(void);

u16 MADC_u16GetValue(u8 Copy_u8AdcChannel);
void MADC_voidInitDefault(void);

s32 MADC_s32Mapping(s32 Copy_s32MaxOut ,s32 Copy_s32MiniOut,u16 Copy_u16MaxDigitalSensorRead , u16 Copy_u16MiniDigitalSensorRead ,u16 Copy_u16DigitalSensorRead);






#endif // MADC_INTERFACE_H	
