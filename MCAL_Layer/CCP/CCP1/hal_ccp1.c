/* 
 * File:   hal_cpp1.c
 * Author: Alsikely
 *
 * Created on May 25, 2023, 4:00 PM
 */

#include "hal_cpp1.h"


#if INTERRUPT_FEATURE_ENABLE == CCP1_INTERRUPT_FEATURE_ENABLE
static void (* _CCP1_InterruptHandler)(void) = NULL;
#endif 


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
        PR2 = (uint8)(((_XTAL_FREQ)/(_ccp->PWM_Frequency * 4.0 *
                _ccp->CCP1_timer2_postscaler_value * _ccp->CCP1_timer2_prescaler_value))-1);
        
#endif 
        /* CCP1 PIN intialize-- */
        ret &= gpio_pin_intialize(&(_ccp->ccp1_pin));
        
        /* CCP1 Module interrupt configuration */
#if INTERRUPT_FEATURE_ENABLE == CCP1_INTERRUPT_FEATURE_ENABLE
        CCP1_InterruptEnable();
        CCP1_InterruptFlagClear();
        _CCP1_InterruptHandler = _ccp->CCP1_InterruptHandler;
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
        /*Disable CCP1 Module*/
        CCP1_SET_MODE(CCP1_MODULE_DISABLE);
#if INTERRUPT_FEATURE_ENABLE == CCP1_INTERRUPT_FEATURE_ENABLE
        CCP1_InterruptEnable();
        CCP1_InterruptFlagClear();
#endif
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
        if(CCP1_CAPTURE_READY == PIR1bits.CCP1IF){
            *_capture_status = CCP1_CAPTURE_READY;
            CCP1_InterruptFlagClear();
        }else{
            *_capture_status = CCP1_CAPTURE_NOT_READY;
        }
        ret = E_OK;
    }
    
    return ret;
}

Std_ReturnType CCP1_Capture_Mode_Read_Value(uint16 *_capture_value){
    Std_ReturnType ret = E_NOT_OK;
    CCP1_REG_T compare_temp_value = {.ccpr1_16Bit = 0};
    if(NULL == _capture_value){
        ret = E_NOT_OK;
    }
    else
    {
        compare_temp_value.ccpr1_low = CCPR1L;
        compare_temp_value.ccpr1_high = CCPR1H;
        *_capture_value = compare_temp_value.ccpr1_16Bit;
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
        if(CCP1_COMPARE_READY == PIR1bits.CCP1IF){
            *_compare_status = CCP1_COMPARE_READY;
            CCP1_InterruptFlagClear();
        }else{
            *_compare_status = CCP1_COMPARE_NOT_READY;
        }
        ret = E_OK;
    }
    
    return ret;
}

Std_ReturnType CCP1_Compare_Mode_Set_Value(uint16 _compare_value){
    Std_ReturnType ret = E_NOT_OK;
    CCP1_REG_T capture_temp_value = {.ccpr1_16Bit = _compare_value};
    CCPR1L = capture_temp_value.ccpr1_low;
    CCPR1H = capture_temp_value.ccpr1_high;
        ret = E_OK;
    
    
    return ret;
}
#endif

#if CCP1_CFG_SELECTED_MODE == CCP1_CFG_PWM_MODE_SELECTED
Std_ReturnType CCP1_PWM1_Set_Duty_Cycle(const uint8 _duty){
    Std_ReturnType ret = E_NOT_OK;
    uint16 l_duty_temp = ZERO_INIT;
    l_duty_temp = (uint16)((PR2+1)*(_duty/100.0)*4);
    CCP1CONbits.DC1B = (uint8)(l_duty_temp & 0x0003);
    CCPR1L = (uint8)(l_duty_temp >> 2);
    ret = E_OK;
   
    return ret;
}
Std_ReturnType CCP1_PWM1_Start(void){
    Std_ReturnType ret = E_NOT_OK;
    CCP1_SET_MODE(CCP1_PWM_MODE);
    ret = E_OK;
   
    return ret;
}
Std_ReturnType CCP1_PWM1_Stop(void){
    Std_ReturnType ret = E_NOT_OK;
    CCP1_SET_MODE(CCP1_MODULE_DISABLE);
    ret = E_OK;
    return ret;
}
#endif
