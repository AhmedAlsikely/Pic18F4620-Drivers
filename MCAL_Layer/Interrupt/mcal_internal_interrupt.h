/* 
 * File:   mcal_internal_interrupt.h
 * Author: Alsikely
 *
 * Created on April 16, 2023, 6:23 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H


/* Section : Includes */
#include "mcal_interrupt_config.h"

/* Section : Macro Declarations */


/* Section : Macro Functions Declarations */
/*-----------------------------ADC Module-------------------------------*/
#if INTERRUPT_FEATURE_ENABLE == ADC_INTERRUPT_FEATURE_ENABLE  
/* This routine Sets the interrupt enable for the ADC Module */
#define ADC_InterruptEnable()       (PIE1bits.ADIE = 1)
/* This routine clears the interrupt enable for the ADC Module */
#define ADC_InterruptDisable()      (PIE1bits.ADIE = 0)
/* This routine clears the interrupt Flag for the ADC Module */
#define ADC_InterruptFlagClear()    (PIR1bits.ADIF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/* This routine Sets the ADC Interrupt Priority to be High Priority, ADC. */
#define ADC_HighPrioritySet()       (IPR1bits.ADIP = 1)
/* This routine Sets the ADC Interrupt Priority to be Low Priority, ADC. */
#define ADC_LowPrioritySet()        (IPR1bits.ADIP  = 0)
#endif
#endif
/*------------------------------------------------------------------------*/
/*-----------------------------TIMER0 Module------------------------------*/
#if INTERRUPT_FEATURE_ENABLE == TIMER0_INTERRUPT_FEATURE_ENABLE  
/* This routine Sets the interrupt enable for the TIMER0 Module */
#define TIMER0_InterruptEnable()       (INTCONbits.TMR0IE = 1)
/* This routine clears the interrupt enable for the TIMER0 Module */
#define TIMER0_InterruptDisable()      (INTCONbits.TMR0IE  = 0)
/* This routine clears the interrupt Flag for the TIMER0 Module */
#define TIMER0_InterruptFlagClear()    (INTCONbits.TMR0IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/* This routine Sets the TIMER0 Interrupt Priority to be High Priority, TIMER0. */
#define TIMER0_HighPrioritySet()       (INTCON2bits.TMR0IP = 1)
/* This routine Sets the TIMER0 Interrupt Priority to be Low Priority, TIMER0. */
#define TIMER0_LowPrioritySet()        (INTCON2bits.TMR0IP = 0)
#endif
#endif
/*------------------------------------------------------------------------*/

/* Section : Data Type Declarations */

/* Section : Functions Declarations */

#endif	/* MCAL_INTERNAL_INTERRUPT_H */

