/* 
 * File:   hal_timer1.h
 * Author: Alsikely
 *
 * Created on May 23, 2023, 4:37 PM
 */

#ifndef HAL_TIMER1_H
#define	HAL_TIMER1_H
/*-----Section : Includes-----*/
#include <pic18f4620.h>
#include "../../mcal_std_types.h"
#include "../../GPIO/hal_gpio.h"
#include "../../Interrupt/mcal_internal_interrupt.h"

/*-----Section : Macro Declarations-----*/

/* Timer1 Clock Source (Timer or Counter) */
#define TIMER1_TIMER_MODE_CFG          0
#define TIMER1_COUNTER_MODE_CFG        1
/* Timer1 External Clock Input Synchronization */
#define TIMER1_ASYNC_COUNTER_MODE_CFG  1
#define TIMER1_SYNC_COUNTER_MODE_CFG   0
/* Timer1 Oscillator */
#define TIMER1_OSCILLATOR_ENABLE_CFG   1
#define TIMER1_OSCILLATOR_DISABLE_CFG  0
/* Timer1 Prescaler */
#define TIMER1_PRESCALER_DIV_BY_1      0
#define TIMER1_PRESCALER_DIV_BY_2      1
#define TIMER1_PRESCALER_DIV_BY_4      2
#define TIMER1_PRESCALER_DIV_BY_8      3
/* 16-Bit Read/Write Mode */
#define TIMER1_RW_REG_8BIT_MODE_CFG    0
#define TIMER1_RW_REG_16BIT_MODE_CFG   1

/*-----Section : Macro Functions Declarations-----*/
#define TIMER1_MODULE_ENABLE()               (T1CONbits.TMR1ON = 1)
#define TIMER1_MODULE_DISABLE()              (T1CONbits.TMR1ON = 0)
/* Timer1 Clock Source (Timer or Counter) */
#define TIMER1_COUNTER_MODE_ENABLE()         (T1CONbits.TMR1CS = 1)
#define TIMER1_TIMER_MODE_ENABLE()           (T1CONbits.TMR1CS = 0)
/* Timer1 External Clock Input Synchronization */
#define TIMER1_ASYNC_COUNTER_MODE_ENABLE()   (T1CONbits.T1SYNC = 1)
#define TIMER1_SYNC_COUNTER_MODE_ENABLE()    (T1CONbits.T1SYNC = 0)
/* Timer1 Oscillator */
#define TIMER1_OSC_ENABLE()                  (T1CONbits.T1OSCEN = 1)
#define TIMER1_OSC_DISABLE()                 (T1CONbits.T1OSCEN = 0)
/* Timer1 Pre-scaler Select */ 
#define TIMER1_PRESCALER_SELECT(_PRESCALER_) (T1CONbits.T1CKPS = _PRESCALER_)
/* Timer 1 system clock status */
#define TIMER1_SYSTEM_CLK_STATUS()           (T1CONbits.T1RUN)
/* 16-Bit Read/Write Mode */
#define TIMER1_RW_REG_8_16BIT_MODE_Enable(_MODE_)     (T1CONbits.RD16 = _MODE_)
/*-----Section : Data Type Declarations-----*/
typedef struct{
    #if INTERRUPT_FEATURE_ENABLE == TIMER1_INTERRUPT_FEATURE_ENABLE
    void (* TMR1_InterruptHandler)(void);
    interrupt_priority_cfg priority;
    #endif
    uint16 timer1_preload_value;
    uint8 timer1_prescaler_value :2;
    uint8 timer1_mode :1;
    uint8 timer1_counter_mode :1;
    uint8 timer1_osc_cfg :1;
    uint8 timer1_reg_wr_mode :1; 
    uint8 reserved :2;
}timer1_t;

/*-----Section : Functions Declarations-----*/
Std_ReturnType Timer1_Init(const timer1_t *_timer);
Std_ReturnType Timer1_DeInit(const timer1_t *_timer);
Std_ReturnType Timer1_Write_value(const timer1_t *_timer,uint16 _value);
Std_ReturnType Timer1_Read_value(const timer1_t *_timer,uint16 *_value);


#endif	/* HAL_TIMER1_H */

