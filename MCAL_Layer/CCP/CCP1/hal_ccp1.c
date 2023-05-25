/* 
 * File:   hal_cpp1.c
 * Author: Alsikely
 *
 * Created on May 25, 2023, 4:00 PM
 */

#if INTERRUPT_FEATURE_ENABLE == CCP1_INTERRUPT_FEATURE_ENABLE
static void (* CCP1_InterruptHandler)(void) = NULL;    
#endif


#include "hal_cpp1.h"

Std_ReturnType CCP1_Init(const ccp1_t *_ccp){
    Std_ReturnType ret = E_OK;
    if(NULL == _ccp){
        ret = E_NOT_OK;
    }
    else
    {
        /*Disable CCP1 Module*/
        CCP1_SET_MODE(CCP1_MODULE_DISABLE);
        /* CCP1 Module Mode Set */
#if CCP1_CFG_SELECTED_MODE == CCP1_CFG_CAPTURE_MODE_SELECTED
        CCP1_SET_MODE(_ccp->ccp1_mode_variant);
#elif CCP1_CFG_SELECTED_MODE == CCP1_CFG_COMPARE_MODE_SELECTED
        CCP1_SET_MODE(_ccp->ccp1_mode_variant);
#elif CCP1_CFG_SELECTED_MODE == CCP1_CFG_PWM_MODE_SELECTED
        CCP1_SET_MODE(CCP1_PWM_MODE);
#endif
        /* CCP1 PIN initialize */
        ret &= gpio_pin_intialize(&(_ccp->ccp1_pin));
        
        /* CCP1 Module interrupt configuration */
#if INTERRUPT_FEATURE_ENABLE == CCP1_INTERRUPT_FEATURE_ENABLE
        CCP1_InterruptEnable();
        CCP1_InterruptFlagClear();
        CCP1_InterruptHandler = _ccp->CCP1_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PeriorityLevelsEnable();
        if(INTERRUPT_HIGH_PRIORITY == _ccp->priority){
            INTERRUPT_GlobalInterruptHighEnable();
            CCP1_HighPrioritySet();
        }else if(INTERRUPT_LOW_PRIORITY == _ccp->priority){
            INTERRUPT_GlobalInterruptLowEnable();
            CCP1_LowPrioritySet();
        }else{/*NoThing*/}
#else 
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif

    }
    
    return ret;
}

Std_ReturnType CCP1_DeInit(const ccp1_t *_ccp){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _ccp){
        ret = E_NOT_OK;
    }
    else
    {
        
        ret = E_OK;
    }
    
    return ret;
}
 
#if CCP1_CFG_SELECTED_MODE == CCP1_CFG_CAPTURE_MODE_SELECTED
Std_ReturnType CCP1_IsCaptureDataReady(uint8 *_capture_status){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _capture_status){
        ret = E_NOT_OK;
    }
    else
    {
        
        ret = E_OK;
    }
    
    return ret;
}

Std_ReturnType CCP1_Capture_Mode_Read_Value(uint16 *_capture_value){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _capture_value){
        ret = E_NOT_OK;
    }
    else
    {
        
        ret = E_OK;
    }
    
    return ret;
}
#endif

#if CCP1_CFG_SELECTED_MODE == CCP1_CFG_COMPARE_MODE_SELECTED
Std_ReturnType CCP1_IsCompareDataReady(uint8 *_compare_status){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _compare_status){
        ret = E_NOT_OK;
    }
    else
    {
        
        ret = E_OK;
    }
    
    return ret;
}

Std_ReturnType CCP1_Compare_Mode_Set_Value(uint16 *_compare_value){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _compare_value){
        ret = E_NOT_OK;
    }
    else
    {
        
        ret = E_OK;
    }
    
    return ret;
}
#endif

#if CCP1_CFG_SELECTED_MODE == CCP1_CFG_PWM_MODE_SELECTED
Std_ReturnType CCP1_PWM1_Set_Duty_Cycle(const uint16 _duty){
     Std_ReturnType ret = E_NOT_OK;

    ret = E_OK;
   
    return ret;
}
Std_ReturnType CCP1_PWM1_Start(void){
    Std_ReturnType ret = E_NOT_OK;

    ret = E_OK;
   
    return ret;
}
Std_ReturnType CCP1_PWM1_Stop(void){
    Std_ReturnType ret = E_NOT_OK;

    ret = E_OK;
   
    return ret;
}
#endif
