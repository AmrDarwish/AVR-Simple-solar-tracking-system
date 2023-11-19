/*
 * STD_TYPES.h
 *
 *  Created on	: Aug 8, 2023
 *      Author	: Amr-a
 *      version	: 1.1
 */
 
 /*
 *Release notes:
 *added NULL pointer
 *added Error_State_t enum
 */
#ifndef _STD_TYPES_H
#define _STD_TYPES_H
//#define NULL ((void*)0)

typedef  char					s8 ;
typedef  unsigned char			u8 ;
typedef  short	  int			s16;
typedef  unsigned short	int		u16;
typedef  long int				s32;
typedef  unsigned long int 		u32;
typedef  long	  long int		s64;
typedef  unsigned long long int u64;
typedef  float					f32;
typedef  double					f64;

typedef enum{
	return_Ok,
	return_Nok,
	return_NullPointer,
}Error_State_t;

#endif
