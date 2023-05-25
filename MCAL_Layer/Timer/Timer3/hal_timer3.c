/* 
 * File:   hal_timer3.C
 * Author: Alsikely
 *
 * Created on May 24, 2023, 6:30 PM
 */

#include "hal_timer3.h"

#if INTERRUPT_FEATURE_ENABLE == TIMER3_INTERRUPT_FEATURE_ENABLE
static void (* TMR3_InterruptHandler)(void) = NULL;    
#endif
static uint16 timer3_preload = ZERO_INIT;

static inline void Timer3_Mode_Select(const timer3_t *_timer);

/**
 * 
 * @param _timer
 * @return 
 */
Std_ReturnType Timer3_Init(const timer3_t *_timer){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else
    {
        TIMER3_MODULE_DISABLE();
        TIMER3_PRESCALER_SELECT(_timer->timer3_prescaler_value);
        TIMER3_RW_REG_8_16BIT_MODE_Enable(_timer->timer3_reg_wr_mode);
        Timer3_Mode_Select(_timer);
        TMR3H = (_timer->timer3_preload_value) >>8;
        TMR3L = (uint8)(_timer->timer3_preload_value);
        timer3_preload = _timer->timer3_preload_value;
      
        /* Interrupt Configrations */
#if INTERRUPT_FEATURE_ENABLE == TIMER3_INTERRUPT_FEATURE_ENABLE
        TIMER3_InterruptEnable();
        TIMER3_InterruptFlagClear();
        TMR3_InterruptHandler = _timer->TMR3_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PeriorityLevelsEnable();
        if(INTERRUPT_HIGH_PRIORITY == _timer->priority){
            INTERRUPT_GlobalInterruptHighEnable();
            TIMER1_HighPrioritySet();
        }else if(INTERRUPT_LOW_PRIORITY == _timer->priority){
            INTERRUPT_GlobalInterruptLowEnable();
            TIMER1_LowPrioritySet();
        }else{/*NoThing*/}
#else 
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
        
        TIMER3_MODULE_ENABLE();
        
        ret = E_OK;
    }
    
    return ret;
}

/**
 * 
 * @param _timer
 * @return 
 */
Std_ReturnType Timer3_DeInit(const timer3_t *_timer){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else
    {
        TIMER3_MODULE_DISABLE();
        #if INTERRUPT_FEATURE_ENABLE == TIMER3_INTERRUPT_FEATURE_ENABLE
        TIMER3_InterruptDisable();
        TIMER3_InterruptFlagClear();
        #endif
        ret = E_OK;
    }
    
    return ret;
    
}

/**
 * 
 * @param _timer
 * @param _value
 * @return 
 */
Std_ReturnType Timer3_Write_value(const timer3_t *_timer,uint16 _value){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else
    {
        TMR3H = (_value) >>8;
        TMR3L = (uint8)(_value);
        ret = E_OK;
    }
    
    return ret;
    
}

/**
 * 
 * @param _timer
 * @param _value
 * @return 
 */
Std_ReturnType Timer3_Read_value(const timer3_t *_timer,uint16 *_value){
    Std_ReturnType ret = E_NOT_OK;
    uint8 tmr3l = ZERO_INIT;
    uint8 tmr3h = ZERO_INIT;
    if(NULL == _timer || NULL == _value){
        ret = E_NOT_OK;
    }
    else
    {
        tmr3l = TMR1L;
        tmr3h = TMR1H;
        *_value = (uint16)((256 * tmr3h) + tmr3l);
        ret = E_OK;
    }
    
    return ret;
    
}

#if INTERRUPT_FEATURE_ENABLE == TIMER3_INTERRUPT_FEATURE_ENABLE
void TMR3_ISR(void){
    TIMER3_InterruptFlagClear();
    TMR3H = timer3_preload >>8;
    TMR3L = (uint8)timer3_preload;
    if(TMR3_InterruptHandler){
        TMR3_InterruptHandler();
    }
}    
#endif

static inline void Timer3_Mode_Select(const timer3_t *_timer){
    if(TIMER3_TIMER_MODE_CFG == _timer->timer3_mode){
        TIMER3_TIMER_MODE_ENABLE();
    }else if(TIMER3_COUNTER_MODE_CFG == _timer->timer3_mode){
        TIMER3_COUNTER_MODE_ENABLE();
        if(TIMER3_ASYNC_COUNTER_MODE_CFG == _timer->timer3_counter_mode){
            TIMER3_ASYNC_COUNTER_MODE_ENABLE();
        }else if(TIMER3_SYNC_COUNTER_MODE_CFG == _timer->timer3_counter_mode){
            TIMER3_SYNC_COUNTER_MODE_ENABLE();
        }else{/*NoThing*/}
    }else{/*NoThing*/}
}