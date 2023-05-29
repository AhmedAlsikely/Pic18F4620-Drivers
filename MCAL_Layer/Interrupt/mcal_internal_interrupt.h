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
/*-----------------------------TIMER1 Module------------------------------*/
#if INTERRUPT_FEATURE_ENABLE == TIMER1_INTERRUPT_FEATURE_ENABLE  
/* This routine Sets the interrupt enable for the TIMER1 Module */
#define TIMER1_InterruptEnable()       (PIE1bits.TMR1IE = 1)
/* This routine clears the interrupt enable for the TIMER1 Module */
#define TIMER1_InterruptDisable()      (PIE1bits.TMR1IE = 0)
/* This routine clears the interrupt Flag for the TIMER1 Module */
#define TIMER1_InterruptFlagClear()    (PIR1bits.TMR1IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/* This routine Sets the TIMER1 Interrupt Priority to be High Priority, TIMER1. */
#define TIMER1_HighPrioritySet()       (IPR1bits.TMR1IP = 1)
/* This routine Sets the TIMER1 Interrupt Priority to be Low Priority, TIMER1. */
#define TIMER1_LowPrioritySet()        (IPR1bits.TMR1IP = 0)
#endif
#endif
/*------------------------------------------------------------------------*/
/*-----------------------------TIMER2 Module------------------------------*/
#if INTERRUPT_FEATURE_ENABLE == TIMER2_INTERRUPT_FEATURE_ENABLE  
/* This routine Sets the interrupt enable for the TIMER2 Module */
#define TIMER2_InterruptEnable()       (PIE1bits.TMR2IE = 1)
/* This routine clears the interrupt enable for the TIMER2 Module */
#define TIMER2_InterruptDisable()      (PIE1bits.TMR2IE = 0)
/* This routine clears the interrupt Flag for the TIMER2 Module */
#define TIMER2_InterruptFlagClear()    (PIR1bits.TMR2IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/* This routine Sets the TIMER2 Interrupt Priority to be High Priority, TIMER2. */
#define TIMER2_HighPrioritySet()       (IPR1bits.TMR2IP = 1)
/* This routine Sets the TIMER2 Interrupt Priority to be Low Priority, TIMER2. */
#define TIMER2_LowPrioritySet()        (IPR1bits.TMR2IP = 0)
#endif
#endif
/*------------------------------------------------------------------------*/
/*-----------------------------TIMER3 Module------------------------------*/
#if INTERRUPT_FEATURE_ENABLE == TIMER3_INTERRUPT_FEATURE_ENABLE  
/* This routine Sets the interrupt enable for the TIMER3 Module */
#define TIMER3_InterruptEnable()       (PIE2bits.TMR3IE = 1)
/* This routine clears the interrupt enable for the TIMER3 Module */
#define TIMER3_InterruptDisable()      (PIE2bits.TMR3IE = 0)
/* This routine clears the interrupt Flag for the TIMER3 Module */
#define TIMER3_InterruptFlagClear()    (PIR2bits.TMR3IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/* This routine Sets the TIMER3 Interrupt Priority to be High Priority, TIMER3. */
#define TIMER3_HighPrioritySet()       (IPR2bits.TMR3IP = 1)
/* This routine Sets the TIMER3 Interrupt Priority to be Low Priority, TIMER3. */
#define TIMER3_LowPrioritySet()        (IPR2bits.TMR3IP = 0)
#endif
#endif
/*------------------------------------------------------------------------*/
/*-----------------------------CCP1 Module------------------------------*/
#if INTERRUPT_FEATURE_ENABLE == CCP1_INTERRUPT_FEATURE_ENABLE  
/* This routine Sets the interrupt enable for the CCP1 Module */
#define CCP1_InterruptEnable()       (PIE1bits.CCP1IE = 1)
/* This routine clears the interrupt enable for the CCP1 Module */
#define CCP1_InterruptDisable()      (PIE1bits.CCP1IE = 0)
/* This routine clears the interrupt Flag for the CCP1 Module */
#define CCP1_InterruptFlagClear()    (PIR1bits.CCP1IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/* This routine Sets the CCP1 Interrupt Priority to be High Priority, CCP1. */
#define CCP1_HighPrioritySet()       (IPR1bits.CCP1IP = 1)
/* This routine Sets the CCP1 Interrupt Priority to be Low Priority, CCP1. */
#define CCP1_LowPrioritySet()        (IPR1bits.CCP1IP = 0)
#endif
#endif
/*------------------------------------------------------------------------*/
/*-----------------------------CCP2 Module------------------------------*/
#if INTERRUPT_FEATURE_ENABLE == CCP2_INTERRUPT_FEATURE_ENABLE  
/* This routine Sets the interrupt enable for the CCP2 Module */
#define CCP2_InterruptEnable()       (PIE2bits.CCP2IE = 1)
/* This routine clears the interrupt enable for the CCP2 Module */
#define CCP2_InterruptDisable()      (PIE2bits.CCP2IE = 0)
/* This routine clears the interrupt Flag for the CCP2 Module */
#define CCP2_InterruptFlagClear()    (PIR2bits.CCP2IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/* This routine Sets the CCP2 Interrupt Priority to be High Priority, CCP2. */
#define CCP2_HighPrioritySet()       (IPR2bits.CCP2IP = 1)
/* This routine Sets the CCP2 Interrupt Priority to be Low Priority, CCP2. */
#define CCP2_LowPrioritySet()        (IPR2bits.CCP2IP = 0)
#endif
#endif
/*------------------------------------------------------------------------*/
/*-----------------------------EUSART TX Module------------------------------*/
#if INTERRUPT_FEATURE_ENABLE == EUSART_TX_INTERRUPT_FEATURE_ENABLE  
/* This routine Sets the interrupt enable for the EUSART_TX Module */
#define EUSART_TX_InterruptEnable()       (PIE1bits.TXIE = 1)
/* This routine clears the interrupt enable for the EUSART_TX Module */
#define EUSART_TX_InterruptDisable()      (PIE1bits.TXIE = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/* This routine Sets the EUSART_TX Interrupt Priority to be High Priority, EUSART_TX. */
#define EUSART_TX_HighPrioritySet()       (IPR1bits.TXIP = 1)
/* This routine Sets the EUSART_TX Interrupt Priority to be Low Priority, EUSART_TX. */
#define EUSART_TX_LowPrioritySet()        (IPR1bits.TXIP = 0)
#endif
#endif
/*------------------------------------------------------------------------*/
/*-----------------------------EUSART RX Module------------------------------*/
#if INTERRUPT_FEATURE_ENABLE == EUSART_RX_INTERRUPT_FEATURE_ENABLE  
/* This routine Sets the interrupt enable for the EUSART_RX Module */
#define EUSART_RX_InterruptEnable()       (PIE1bits.RCIE = 1)
/* This routine clears the interrupt enable for the EUSART_RX Module */
#define EUSART_RX_InterruptDisable()      (PIE1bits.RCIE = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/* This routine Sets the EUSART_RX Interrupt Priority to be High Priority, EUSART_RX. */
#define EUSART_RX_HighPrioritySet()       (IPR1bits.RCIP = 1)
/* This routine Sets the EUSART_RX Interrupt Priority to be Low Priority, EUSART_RX. */
#define EUSART_RX_LowPrioritySet()        (IPR1bits.RCIP = 0)
#endif
#endif
/*------------------------------------------------------------------------*/

/* Section : Data Type Declarations */

/* Section : Functions Declarations */

#endif	/* MCAL_INTERNAL_INTERRUPT_H */

