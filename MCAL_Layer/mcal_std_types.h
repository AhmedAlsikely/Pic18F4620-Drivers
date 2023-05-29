/* 
 * File:   mcal_std_types.h
 * Author: Alsikely
 *
 * Created on April 8, 2023, 2:05 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H



/* Section : Includes */
#include "std_libraries.h"
#include "compiler.h"

/* Section : Data Type Declarations */
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef uint8 Std_ReturnType;

/* Section : Macro Declarations */
#define E_OK            (Std_ReturnType)0x01
#define E_NOT_OK        (Std_ReturnType)0x00

#define ZERO_INIT 0

#define _XTAL_FREQ 8000000UL


/* Section : Macro Functions Declarations */

/* Section : Functions Declarations */

#endif	/* MCAL_STD_TYPES_H */

