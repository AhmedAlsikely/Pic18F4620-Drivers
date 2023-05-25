/* 
 * File:   hal_timer2.c
 * Author: Alsikely
 *
 * Created on May 24, 2023, 2:21 PM
 */

#include "hal_timer2.h"

#if INTERRUPT_FEATURE_ENABLE == TIMER2_INTERRUPT_FEATURE_ENABLE
static void (* TMR2_InterruptHandler)(void) = NULL;    
#endif
static uint8 timer2_preload = ZERO_INIT;

/**
 * 
 * @param _timer
 * @return 
 */
Std_ReturnType Timer2_Init(const timer2_t *_timer){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else
    {
        TIMER2_MODULE_DISABLE();
        TIMER2_PRESCALER_SELECT(_timer->timer2_prescaler_value);
        TIMER2_POSTSCALER_SELECT(_timer->timer2_postscaler_value);
        TMR2 = (_timer->timer2_preload_value);
        timer2_preload = _timer->timer2_preload_value;
      
        /* Interrupt Configrations */
#if INTERRUPT_FEATURE_ENABLE == TIMER2_INTERRUPT_FEATURE_ENABLE
        TIMER2_InterruptEnable();
        TIMER2_InterruptFlagClear();
        TMR2_InterruptHandler = _timer->TMR2_InterruptHandler;
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
        
        TIMER2_MODULE_ENABLE();
        
        ret = E_OK;
    }
    
    return ret;  
}

/**
 * 
 * @param _timer
 * @return 
 */
Std_ReturnType Timer2_DeInit(const timer2_t *_timer){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else
    {
        TIMER2_MODULE_DISABLE();
        #if INTERRUPT_FEATURE_ENABLE == TIMER2_INTERRUPT_FEATURE_ENABLE
        TIMER2_InterruptDisable();
        TIMER2_InterruptFlagClear();
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
Std_ReturnType Timer2_Write_value(const timer2_t *_timer,uint8 _value){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else
    {
        TMR2 = _value;
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
Std_ReturnType Timer2_Read_value(const timer2_t *_timer,uint8 *_value){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer || NULL == _value){
        ret = E_NOT_OK;
    }
    else
    {
        *_value = TMR2;
        ret = E_OK;
    }
    return ret;
}

#if INTERRUPT_FEATURE_ENABLE == TIMER2_INTERRUPT_FEATURE_ENABLE
void TMR2_ISR(void){
    TIMER2_InterruptFlagClear();
    TMR2 = timer2_preload;
    if(TMR2_InterruptHandler){
        TMR2_InterruptHandler();
    }
}    
#endif

