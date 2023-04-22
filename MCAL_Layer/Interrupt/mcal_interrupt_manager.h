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
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(uint8 RB4_Source);
void RB5_ISR(uint8 RB5_Source);
void RB6_ISR(uint8 RB6_Source);
void RB7_ISR(uint8 RB7_Source);

#endif	/* MCAL_INTERRUPT_MANAGER_H */

