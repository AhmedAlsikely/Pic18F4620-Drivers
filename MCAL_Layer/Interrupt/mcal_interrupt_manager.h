/* 
 * File:   mcal_interrupt_manager.h
 * Author: Alsikely
 *
 * Created on April 16, 2023, 6:24 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/* Section : Includes */
#include "mcal_interrupt_config.h"

/* Section : Macro Declarations */


/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */


/* Section : Functions Declarations */
#if INTERRUPT_FEATURE_ENABLE == INTERRUPT_EXTERNAL_INTx_FEATURE_ENABLE
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
#endif
#if INTERRUPT_FEATURE_ENABLE == INTERRUPT_EXTERNAL_OnChange_FEATURE_ENABLE
void RB4_ISR(uint8 RB4_Source);
void RB5_ISR(uint8 RB5_Source);
void RB6_ISR(uint8 RB6_Source);
void RB7_ISR(uint8 RB7_Source);
#endif
#if INTERRUPT_FEATURE_ENABLE == ADC_INTERRUPT_FEATURE_ENABLE
void ADC_ISR(void);
#endif
#if INTERRUPT_FEATURE_ENABLE == TIMER0_INTERRUPT_FEATURE_ENABLE
void TMRO_ISR(void);
#endif
#if INTERRUPT_FEATURE_ENABLE == TIMER1_INTERRUPT_FEATURE_ENABLE
void TMR1_ISR(void);
#endif
#if INTERRUPT_FEATURE_ENABLE == TIMER2_INTERRUPT_FEATURE_ENABLE
void TMR2_ISR(void);
#endif
#if INTERRUPT_FEATURE_ENABLE == TIMER3_INTERRUPT_FEATURE_ENABLE
void TMR3_ISR(void);
#endif
#if INTERRUPT_FEATURE_ENABLE == CCP1_INTERRUPT_FEATURE_ENABLE
void CCP1_ISR(void);
#endif
//#if INTERRUPT_FEATURE_ENABLE == CCP2_INTERRUPT_FEATURE_ENABLE
//void CCP2_ISR(void);
//#endif
#if INTERRUPT_FEATURE_ENABLE == EUSART_TX_INTERRUPT_FEATURE_ENABLE
void EUSART_TX_ISR(void);
#endif
#if INTERRUPT_FEATURE_ENABLE == EUSART_RX_INTERRUPT_FEATURE_ENABLE
void EUSART_RX_ISR(void);
#endif
#if INTERRUPT_FEATURE_ENABLE == MSSP_SPI_INTERRUPT_FEATURE_ENABLE  
void SPI_ISR(void);
#endif


#endif	/* MCAL_INTERRUPT_MANAGER_H */

