/* 
 * File:   hal_SPI.h
 * Author: Alsikely
 *
 * Created on May 31, 2023, 11:56 AM
 */

#ifndef HAL_SPI_H
#define	HAL_SPI_H
/*---------------------- Section : Includes ----------------------*/
#include "pic18f4620.h"
#include "../mcal_std_types.h"
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"
/*---------------------- Section : Macro Declarations------------ */

#define SPI_RECEIVE_INTERRUPT_FLAG_DONE 1
#define SPI_RECEIVE_INTERRUPT_FLAG_NOT_DONE 0

#define SPI_RECEIVE_COMPLETE_SSPBUF_IS_FULL_CFG
#define SPI_RECEIVE_NOT_COMPLETE_SSPBUF_IS_EMPTY_CFG
/* SPI OverFlow Error */
#define SPI_OVERFLOW_ERROR_DETECTED                  1
/* SPI Collision Error */
#define SPI_COLLISION_ERROR_DETECTED                  1
///* SPI clock Polarity */
//#define SPI_CLOCK_IDLE_HIGH_LEVEL_CFG 1
//#define SPI_CLOCK_IDLE_LOW_LEVEL_CFG 0
/* SPI clock phase */
//#define SPI_CLOCK_PHASE_TRANSMIT_AT_TRAILING_EDGE_CFG 1
//#define SPI_CLOCK_PHASE_TRANSMIT_AT_LEADING_EDGE_CFG 0
/* SPI Sampled Data */
//#define SPI_MASTER_SAMPLED_AT_END_OF_DATA_CFG  1
//#define SPI_MASTER_SAMPLED_AT_MIDDLE_OF_DATA_CFG  0
/*---------------------- Section : Macro Functions Declarations --*/

#define SPI_RECEIVER_INTERRUPT_FLAG_STATUS         (PIR1bits.SSPIF)
#define SPI_RECEIVE_STATUS                         (SSPSTATbits.BF)
/* SPI Enable/Disable*/
#define SPI_ENABLE()                               (SSPCON1bits.SSPEN = 1)
#define SPI_DISABLE()                              (SSPCON1bits.SSPEN = 0)
/* SPI OverFlow Error */
#define SPI_OVERFLOW_ERROR_STATUS                  (SSPCON1bits.SSPOV) 
#define SPI_OVERFLOW_ERROR_CLEAR_BIT               (SSPCON1bits.SSPOV = 0) 
/* SPI Collision Error */
#define SPI_COLLISION_ERROR_STATUS                 (SSPCON1bits.WCOL) 
#define SPI_COLLISION_ERROR_CLEAR_BIT              (SSPCON1bits.WCOL = 0)
/* SPI clock Polarity */
#define SPI_CLOCK_POLARITY_CONFIG(_CFG)          (SSPCON1bits.CKP = _CFG)
/* SPI clock phase */
#define SPI_CLOCK_PHASE_CONFIG(_CFG)             (SSPSTATbits.CKE = _CFG)
/* SPI Sampled Data */
#define SPI_MASTER_SAMPLED_DATA_CONFIG(_CFG)     (SSPSTATbits.SMP = _CFG)
/* SPI Select Master Clock Rate */
#define SPI_MASTER_CLOCK_RATE(_CFG)               (SSPCON1bits.SSPM = _CFG)
#define SPI_SLAVE_MODE_SELECT(_CFG)               (SSPCON1bits.SSPM = _CFG)
/*---------------------- Section : Data Type Declarations --------*/

typedef enum{
    SPI_CLK_IDLE_LOW_TRANSMIT_FROM_IDLE_TO_ACTIVE = 0,
    SPI_CLK_IDLE_LOW_TRANSMIT_FROM_ACTIVE_TO_IDLE,
    SPI_CLK_IDLE_HIGH_TRANSMIT_FROM_IDLE_TO_ACTIVE,
    SPI_CLK_IDLE_HIGH_TRANSMIT_FROM_ACTIVE_TO_IDLE   
}SPI_Transmit_data_mode_t;

typedef enum{
    SPI_CLOCK_IDLE_LOW_LEVEL_CFG = 0,
    SPI_CLOCK_IDLE_HIGH_LEVEL_CFG
}SPI_Clock_Polarity_t;

typedef enum{
    SPI_CLOCK_PHASE_TRANSMIT_AT_LEADING_EDGE = 0,
    SPI_CLOCK_PHASE_TRANSMIT_AT_TRAILING_EDGE
}SPI_Clock_Phase_t;

typedef enum{
    SPI_MASTER_SAMPLED_AT_MIDDLE_OF_DATA_OUTPUT_TIME = 0,
    SPI_MASTER_SAMPLED_AT_END_OF_DATA_OUTPUT_TIME,        
}SPI_Master_Sampled_Mode_t;

typedef enum{
    SPI_MASTER_MODE_CLOCK_FOSC_DEV_4 = 0,
    SPI_MASTER_MODE_CLOCK_FOSC_DEV_16,
    SPI_MASTER_MODE_CLOCK_FOSC_DEV_64,
    SPI_MASTER_MODE_CLOCK_TMR2_OUTPUT_DEV_2,
}SPI_Master_Clock_Rate_t;

typedef enum{
    SPI_SLAVE_MODE_SS_ENABLED = 4,
    SPI_SLAVE_MODE_SS_DISABLED_USED_AS_I_O_PIN = 5,
}SPI_Slave_Mode_t;

typedef struct{
#if INTERRUPT_FEATURE_ENABLE == MSSP_SPI_INTERRUPT_FEATURE_ENABLE  
     void (* SPI_DefailtInterruptHandler)(void);
     interrupt_priority_cfg SPI_priority ;
#endif
    SPI_Clock_Polarity_t clock_idle;
    SPI_Clock_Phase_t clock_phase;
    SPI_Master_Sampled_Mode_t sample_data;
    SPI_Master_Clock_Rate_t master_clk_rate;
}SPI_Master_t;

typedef struct{
#if INTERRUPT_FEATURE_ENABLE == MSSP_SPI_INTERRUPT_FEATURE_ENABLE  
     void (* SPI_DefailtInterruptHandler)(void);
     interrupt_priority_cfg SPI_priority ;
#endif
    SPI_Clock_Polarity_t clock_idle;
    SPI_Clock_Phase_t clock_phase;
    SPI_Slave_Mode_t slave_mode;
}SPI_Slave_t;

/*---------------------- Section : Functions Declarations --------*/
Std_ReturnType SPI_Init_Master(const SPI_Master_t *_spi);
Std_ReturnType SPI_Init_Slave(const SPI_Slave_t *_spi);

Std_ReturnType SPI_DeInit_Master(const SPI_Master_t *_spi);
Std_ReturnType SPI_DeInit_Slave(const SPI_Slave_t *_spi);

Std_ReturnType SPI_ReadByteBlocking(uint8 *_data);
Std_ReturnType SPI_ReadByteNonBlocking(uint8 *_data);

Std_ReturnType SPI_WriteByteBlocking( uint8 _data);
Std_ReturnType SPI_WriteByte_NotBlocking( uint8 _data);
Std_ReturnType SPI_WriteStringBlocking( uint8 *_data);
Std_ReturnType SPI_WriteStringNotBlocking( uint8 *_data);

#endif	/* HAL_SPI_H */

