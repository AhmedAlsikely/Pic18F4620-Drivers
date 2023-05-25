/* 
 * File:   hal_timer0.C
 * Author: Alsikely
 *
 * Created on May 22, 2023, 4:26 PM
 */

#include "hal_timer0.h"

#if INTERRUPT_FEATURE_ENABLE == TIMER0_INTERRUPT_FEATURE_ENABLE
static void (* TMR0_InterruptHandler)(void) = NULL;    
#endif
static uint16 timer0_preload = ZERO_INIT;

static inline void Timer0_prescaler_config(const timer0_t *_timer);
static inline void Timer0_Mode_Select(const timer0_t *_timer);
static inline void Timer0_Register_Size(const timer0_t *_timer);

/**
 * 
 * @param _timer
 * @return 
 */
Std_ReturnType Timer0_Init(const timer0_t *_timer){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else
    {
        TIMER0_MODULE_DISABLE();
        Timer0_prescaler_config(_timer);
        Timer0_Mode_Select(_timer);
        Timer0_Register_Size(_timer);
        TMR0H = (_timer->timer0_preload_value) >>8;
        TMR0L = (uint8)(_timer->timer0_preload_value);
        timer0_preload = _timer->timer0_preload_value;
#if INTERRUPT_FEATURE_ENABLE == TIMER0_INTERRUPT_FEATURE_ENABLE
        TIMER0_InterruptEnable();
        TIMER0_InterruptFlagClear();
        TMR0_InterruptHandler = _timer->TMR0_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PeriorityLevelsEnable();
        if(INTERRUPT_HIGH_PRIORITY == _timer->priority){
            INTERRUPT_GlobalInterruptHighEnable();
            TIMER0_HighPrioritySet();
        }else if(INTERRUPT_LOW_PRIORITY == _timer->priority){
            INTERRUPT_GlobalInterruptLowEnable();
            TIMER0_LowPrioritySet();
        }else{/*NoThing*/}
#else 
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
        TIMER0_MODULE_ENABLE();
        ret = E_OK;
    }
    
    return ret;
}

/**
 * 
 * @param _timer
 * @return 
 */
Std_ReturnType Timer0_DeInit(const timer0_t *_timer){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else
    {
        TIMER0_MODULE_DISABLE();
        #if INTERRUPT_FEATURE_ENABLE == TIMER0_INTERRUPT_FEATURE_ENABLE
        TIMER0_InterruptDisable();
        TIMER0_InterruptFlagClear();
        
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
Std_ReturnType Timer0_Write_value(const timer0_t *_timer,uint16 _value){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else
    {
        TMR0H = (_value) >>8;
        TMR0L = (uint8)(_value);
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
Std_ReturnType Timer0_Read_value(const timer0_t *_timer,uint16 *_value){
    Std_ReturnType ret = E_NOT_OK;
    uint8 tmr0l = ZERO_INIT;
    uint8 tmr0h = ZERO_INIT;
    if(NULL == _timer || NULL == _value){
        ret = E_NOT_OK;
    }
    else
    {
        tmr0l = TMR0L;
        tmr0h = TMR0H;
        *_value = (uint16)((256 * tmr0h) + tmr0l);
       ret = E_OK;
    }
    
    return ret;
}

#if INTERRUPT_FEATURE_ENABLE == TIMER0_INTERRUPT_FEATURE_ENABLE
void TMRO_ISR(void){
    TIMER0_InterruptFlagClear();
    TMR0H = timer0_preload >>8;
    TMR0L = (uint8)timer0_preload;
    if(TMR0_InterruptHandler){
        TMR0_InterruptHandler();
    }
}    
#endif

static inline void Timer0_prescaler_config(const timer0_t *_timer){
    if(TIMER0_PRESCALER_ENABLE_CFG == _timer->prescaler_enable){
        TIMER0_PRESCALER_ENABLE();
        T0CONbits.T0PS = _timer->prescaler_value;
    }else if(TIMER0_PRESCALER_DISABLE_CFG == _timer->prescaler_enable){
        TIMER0_PRESCALER_DISABLE();
    }else{/*NoThing*/}
}

static inline void Timer0_Mode_Select(const timer0_t *_timer){
    if(TIMER0_TIMER_MODE_CFG == _timer->timer0_mode){
        TIMER0_TIMER_MODE_ENABLE();
    }else if(TIMER0_COUNTER_MODE_CFG == _timer->timer0_mode){
        TIMER0_COUNTER_MODE_ENABLE();
        if(TIMER0_RISING_EDGE_CFG == _timer->timer0_counter_edge){
            TIMER0_RISING_EDGE_ENABLE();
        }else if(TIMER0_FALLING_EDGE_CFD == _timer->timer0_counter_edge){
            TIMER0_FALLING_EDGE_ENABLE();
        }else{/*NoThing*/}
    }else{/*NoThing*/}
}
static inline void Timer0_Register_Size(const timer0_t *_timer){
    if(TIMER0_8BIT_REGISTER_MODE_CFG == _timer->timer0_register_size){
        TIMER0_8BIT_REGISTER_MODE_ENABLE();
    }else if(TIMER0_16BIT_REGISTER_MODE_CFG == _timer->timer0_register_size){
        TIMER0_16BIT_REGISTER_MODE_ENABLE();
    }else{/*NoThing*/}
}