/* 
 * File:   hal_timer3.h
 * Author: Alsikely
 *
 * Created on May 24, 2023, 6:30 PM
 */

#ifndef HAL_TIMER3_H
#define	HAL_TIMER3_H
/*-----Section : Includes-----*/
#include <pic18f4620.h>
#include "../../mcal_std_types.h"
#include "../../GPIO/hal_gpio.h"
#include "../../Interrupt/mcal_internal_interrupt.h"
/*-----Section : Macro Declarations-----*/
/* Timer3 Clock Source (Timer or Counter) */
#define TIMER3_TIMER_MODE_CFG          0
#define TIMER3_COUNTER_MODE_CFG        1
/* Timer3 External Clock Input Synchronization */
#define TIMER3_ASYNC_COUNTER_MODE_CFG  1
#define TIMER3_SYNC_COUNTER_MODE_CFG   0
/* Timer3 Prescaler */
#define TIMER3_PRESCALER_DIV_BY_1      0
#define TIMER3_PRESCALER_DIV_BY_2      1
#define TIMER3_PRESCALER_DIV_BY_4      2
#define TIMER3_PRESCALER_DIV_BY_8      3
/* 16-Bit Read/Write Mode */
#define TIMER3_RW_REG_8BIT_MODE_CFG    0
#define TIMER3_RW_REG_16BIT_MODE_CFG   1


/*-----Section : Macro Functions Declarations-----*/
#define TIMER3_MODULE_ENABLE()               (T3CONbits.TMR3ON = 1)
#define TIMER3_MODULE_DISABLE()              (T3CONbits.TMR3ON = 0)
/* Timer1 Clock Source (Timer or Counter) */
#define TIMER3_COUNTER_MODE_ENABLE()         (T3CONbits.TMR3CS = 1)
#define TIMER3_TIMER_MODE_ENABLE()           (T3CONbits.TMR3CS = 0)
/* Timer1 External Clock Input Synchronization */
#define TIMER3_ASYNC_COUNTER_MODE_ENABLE()   (T3CONbits.T3SYNC = 1)
#define TIMER3_SYNC_COUNTER_MODE_ENABLE()    (T3CONbits.T3SYNC = 0)
/* Timer3 Pre-scaler Select */ 
#define TIMER3_PRESCALER_SELECT(_PRESCALER_) (T3CONbits.T3CKPS = _PRESCALER_)
/* 16-Bit Read/Write Mode */
#define TIMER3_RW_REG_8_16BIT_MODE_Enable(_MODE_)     (T3CONbits.RD16 = _MODE_)
/*-----Section : Data Type Declarations-----*/
typedef struct{
    #if INTERRUPT_FEATURE_ENABLE == TIMER3_INTERRUPT_FEATURE_ENABLE
    void (* TMR3_InterruptHandler)(void);
    interrupt_priority_cfg priority;
    #endif
    uint16 timer3_preload_value;
    uint8 timer3_prescaler_value :2;
    uint8 timer3_mode :1;
    uint8 timer3_counter_mode :1;
    uint8 timer3_reg_wr_mode :1; 
    uint8 reserved :3;
}timer3_t;
/*-----Section : Functions Declarations-----*/
Std_ReturnType Timer3_Init(const timer3_t *_timer);
Std_ReturnType Timer3_DeInit(const timer3_t *_timer);
Std_ReturnType Timer3_Write_value(const timer3_t *_timer,uint16 _value);
Std_ReturnType Timer3_Read_value(const timer3_t *_timer,uint16 *_value);

#endif	/* HAL_TIMER3_H */

