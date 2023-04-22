/* 
 * File:   mcal_interrupt_gen_cfg.h
 * Author: Alsikely
 *
 * Created on April 16, 2023, 6:20 PM
 */

#ifndef MCAL_INTERRUPT_GEN_CFG_H
#define	MCAL_INTERRUPT_GEN_CFG_H

/* Section : Includes */

/* Section : Macro Declarations */
#define INTERRUPT_FEATURE_ENABLE 1U
#define INTERRUPT_PRIORITY_LEVELS_ENABLE            INTERRUPT_FEATURE_ENABLE

#define INTERRUPT_EXTERNAL_INTx_FEATURE_ENABLE      INTERRUPT_FEATURE_ENABLE
#define INTERRUPT_EXTERNAL_OnChange_FEATURE_ENABLE  INTERRUPT_FEATURE_ENABLE

#define TIMER0_INTERRUPT_FEATURE_ENABLE             INTERRUPT_FEATURE_ENABLE
#define TIMER1_INTERRUPT_FEATURE_ENABLE             INTERRUPT_FEATURE_ENABLE
#define TIMER2_INTERRUPT_FEATURE_ENABLE             INTERRUPT_FEATURE_ENABLE
#define TIMER3_INTERRUPT_FEATURE_ENABLE             INTERRUPT_FEATURE_ENABLE

#define EUSART_TX_INTERRUPT_FEATURE_ENABLE          INTERRUPT_FEATURE_ENABLE
#define EUSART_RX_INTERRUPT_FEATURE_ENABLE  

#define MSSP_I2C_INTERRUPT_FEATURE_ENABLE           INTERRUPT_FEATURE_ENABLE

#define CCP1_INTERRUPT_FEATURE_ENABLE               INTERRUPT_FEATURE_ENABLE

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */

/* Section : Functions Declarations */

#endif	/* MCAL_INTERRUPT_GEN_CFG_H */

