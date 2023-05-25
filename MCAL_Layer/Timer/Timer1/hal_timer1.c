/* 
 * File:   hal_timer1.h
 * Author: Alsikely
 *
 * Created on May 23, 2023, 4:37 PM
 */

#include "hal_timer1.h"

#if INTERRUPT_FEATURE_ENABLE == TIMER1_INTERRUPT_FEATURE_ENABLE
static void (* TMR1_InterruptHandler)(void) = NULL;    
#endif
static uint16 timer1_preload = ZERO_INIT;

static inline void Timer1_Mode_Select(const timer1_t *_timer);

/**
 * 
 * @param _timer
 * @return 
 */
Std_ReturnType Timer1_Init(const timer1_t *_timer){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else
    {
        TIMER1_MODULE_DISABLE();
        TIMER1_PRESCALER_SELECT(_timer->timer1_prescaler_value);
        TIMER1_RW_REG_8_16BIT_MODE_Enable(_timer->timer1_reg_wr_mode);
        Timer1_Mode_Select(_timer);
        TMR1H = (_timer->timer1_preload_value) >>8;
        TMR1L = (uint8)(_timer->timer1_preload_value);
        timer1_preload = _timer->timer1_preload_value;
      
        /* Interrupt Configrations */
#if INTERRUPT_FEATURE_ENABLE == TIMER1_INTERRUPT_FEATURE_ENABLE
        TIMER1_InterruptEnable();
        TIMER1_InterruptFlagClear();
        TMR1_InterruptHandler = _timer->TMR1_InterruptHandler;
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
        
        TIMER1_MODULE_ENABLE();
        
        ret = E_OK;
    }
    
    return ret;
}

/**
 * 
 * @param _timer
 * @return 
 */
Std_ReturnType Timer1_DeInit(const timer1_t *_timer){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else
    {
        TIMER1_MODULE_DISABLE();
        #if INTERRUPT_FEATURE_ENABLE == TIMER1_INTERRUPT_FEATURE_ENABLE
        TIMER1_InterruptDisable();
        TIMER1_InterruptFlagClear();
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
Std_ReturnType Timer1_Write_value(const timer1_t *_timer,uint16 _value){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else
    {
        TMR1H = (_value) >>8;
        TMR1L = (uint8)(_value);
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
Std_ReturnType Timer1_Read_value(const timer1_t *_timer,uint16 *_value){
    Std_ReturnType ret = E_NOT_OK;
    uint8 tmr1l = ZERO_INIT;
    uint8 tmr1h = ZERO_INIT;
    if(NULL == _timer || NULL == _value){
        ret = E_NOT_OK;
    }
    else
    {
        tmr1l = TMR1L;
        tmr1h = TMR1H;
        *_value = (uint16)((256 * tmr1h) + tmr1l);
        ret = E_OK;
    }
    
    return ret;
    
}

#if INTERRUPT_FEATURE_ENABLE == TIMER1_INTERRUPT_FEATURE_ENABLE
void TMR1_ISR(void){
    TIMER1_InterruptFlagClear();
    TMR1H = timer1_preload >>8;
    TMR1L = (uint8)timer1_preload;
    if(TMR1_InterruptHandler){
        TMR1_InterruptHandler();
    }
}    
#endif

static inline void Timer1_Mode_Select(const timer1_t *_timer){
    if(TIMER1_TIMER_MODE_CFG == _timer->timer1_mode){
        TIMER1_TIMER_MODE_ENABLE();
    }else if(TIMER1_COUNTER_MODE_CFG == _timer->timer1_mode){
        TIMER1_COUNTER_MODE_ENABLE();
        if(TIMER1_ASYNC_COUNTER_MODE_CFG == _timer->timer1_counter_mode){
            TIMER1_ASYNC_COUNTER_MODE_ENABLE();
        }else if(TIMER1_SYNC_COUNTER_MODE_CFG == _timer->timer1_counter_mode){
            TIMER1_SYNC_COUNTER_MODE_ENABLE();
        }else{/*NoThing*/}
    }else{/*NoThing*/}
}