/* 
 * File:   mcal_interrupt_config.h
 * Author: Alsikely
 *
 * Created on April 16, 2023, 6:22 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/* Section : Includes */
#include <pic18f4620.h>
#include "../mcal_std_types.h"
#include "../GPIO/hal_gpio.h"
//#include "mcal_interrupt_gen_cfg.h"
#include "mcal_interrupt_gen_cfg.h"

/* Section : Macro Declarations */
#define INTERRUPT_ENABLE           1
#define INTERRUPT_DISABLE          0
#define INTERRUPT_OCCUR            1
#define INTERRUPT_NOT_OCCUR        0
#define INTERRUPT_PRIORITY_ENABLE  1
#define INTERRUPT_PRIORITY_DISABLE 0

/* Section : Macro Functions Declarations */  

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/* This Macro Will Enable Priority Levels ON interrupts. */
#define INTERRUPT_PeriorityLevelsEnable() (RCONbits.IPEN = 1)
/* This Macro Will Disable Priority Levels ON interrupts. */
#define INTERRUPT_PeriorityLevelsDisable() (RCONbits.IPEN = 0)

/* This Macro Will Enable High Priority global interrupts. */
#define INTERRUPT_GlobalInterruptHighEnable() (INTCONbits.GIEH = 1)
/* This Macro Will Disable High Priority global interrupts. */
#define INTERRUPT_GlobalInterruptHighDisable() (INTCONbits.GIEH = 0)

/* This Macro Will Enable Low Priority global interrupts. */
#define INTERRUPT_GlobalInterruptLowEnable() (INTCONbits.GIEL = 1)
/* This Macro Will Disable Low Priority global interrupts. */
#define INTERRUPT_GlobalInterruptLowDisable() (INTCONbits.GIEL = 0)
#else
/* This Macro Will Enable global interrupts. */
#define INTERRUPT_GlobalInterruptEnable() (INTCONbits.GIE = 1)
/* This Macro Will Disable global interrupts. */
#define INTERRUPT_GlobalInterruptDisable() (INTCONbits.GIE = 0)

/* This Macro Will Enable Peripheral interrupts. */
#define INTERRUPT_PeripheralInterruptEnable() (INTCONbits.PEIE = 1)
/* This Macro Will Disable Peripheral interrupts. */
#define INTERRUPT_PeripheralInterruptDisable() (INTCONbits.PEIE = 0)
#endif
/* Section : Data Type Declarations */
typedef enum{
    INTERRUPT_LOW_PRIORITY = 0,
    INTERRUPT_HIGH_PRIORITY        
}interrupt_priority_cfg;

/* Section : Functions Declarations */


#endif	/* MCAL_INTERRUPT_CONFIG_H */

