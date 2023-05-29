/* 
 * File:   hal_cpp2.c
 * Author: Alsikely
 *
 * Created on May 25, 2023, 4:00 PM
 */

#include "hal_cpp2.h"


#if INTERRUPT_FEATURE_ENABLE == CCP2_INTERRUPT_FEATURE_ENABLE
static void (* CCP2_InterruptHandler)(void) = NULL;
#endif 
#if ((CCP2_CFG_SELECTED_MODE == CCP2_CFG_CAPTURE_MODE_SELECTED) || (CCP2_CFG_SELECTED_MODE == CCP2_CFG_COMPARE_MODE_SELECTED))
    static void CCP2_Capture_Mode_Timer_Select(const ccp2_t *_ccp_obj);
#endif    

Std_ReturnType CCP2_Init(const ccp2_t *_ccp){
    Std_ReturnType ret = E_OK;
    if(NULL == _ccp){
        ret = E_NOT_OK;
    }
    else
    {
        /*Disable CCP2 Module*/
        CCP2_SET_MODE(CCP2_MODULE_DISABLE);
        /* CCP2 Module Mode Set */
#if CCP2_CFG_SELECTED_MODE == CCP2_CFG_CAPTURE_MODE_SELECTED
        CCP2_SET_MODE(_ccp->ccp2_mode_variant);
        CCP2_Capture_Mode_Timer_Select(_ccp);
#elif CCP2_CFG_SELECTED_MODE == CCP2_CFG_COMPARE_MODE_SELECTED
        CCP2_SET_MODE(_ccp->ccp2_mode_variant);
        CCP2_Capture_Mode_Timer_Select(_ccp);
#elif CCP2_CFG_SELECTED_MODE == CCP2_CFG_PWM_MODE_SELECTED
        CCP2_SET_MODE(CCP2_PWM_MODE);
        PR2 = (uint8)(((_XTAL_FREQ)/(_ccp->PWM_Frequency * 4.0 *
                _ccp->CCP2_timer2_postscaler_value * _ccp->CCP2_timer2_prescaler_value))-1);
        
#endif 
        /* CCP2 PIN intialize-- */
        ret &= gpio_pin_intialize(&(_ccp->ccp2_pin));
        
        /* CCP2 Module interrupt configuration */
#if INTERRUPT_FEATURE_ENABLE == CCP2_INTERRUPT_FEATURE_ENABLE
        CCP2_InterruptEnable();
        CCP2_InterruptFlagClear();
        CCP2_InterruptHandler = _ccp->CCP2_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PeriorityLevelsEnable();
        if(INTERRUPT_HIGH_PRIORITY == _ccp->priority){
            INTERRUPT_GlobalInterruptHighEnable();
            CCP2_HighPrioritySet();
        }else if(INTERRUPT_LOW_PRIORITY == _ccp->priority){
            INTERRUPT_GlobalInterruptLowEnable();
            CCP2_LowPrioritySet();
        }else{/*NoThing*/}
#else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
        

    }
    
    return ret;
}

Std_ReturnType CCP2_DeInit(const ccp2_t *_ccp){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _ccp){
        ret = E_NOT_OK;
    }
    else
    {
        /*Disable CCP2 Module*/
        CCP2_SET_MODE(CCP2_MODULE_DISABLE);
#if INTERRUPT_FEATURE_ENABLE == CCP2_INTERRUPT_FEATURE_ENABLE
        CCP2_InterruptEnable();
        CCP2_InterruptFlagClear();
#endif
        ret = E_OK;
    }
    
    return ret;
}
 
#if CCP2_CFG_SELECTED_MODE == CCP2_CFG_CAPTURE_MODE_SELECTED
Std_ReturnType CCP2_IsCaptureDataReady(uint8 *_capture_status){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _capture_status){
        ret = E_NOT_OK;
    }
    else
    {
        if(CCP2_CAPTURE_READY == PIR2bits.CCP2IF){
            *_capture_status = CCP2_CAPTURE_READY;
            CCP2_InterruptFlagClear();
        }else{
            *_capture_status = CCP2_CAPTURE_NOT_READY;
        }
        ret = E_OK;
    }
    
    return ret;
}

Std_ReturnType CCP2_Capture_Mode_Read_Value(uint16 *_capture_value){
    Std_ReturnType ret = E_NOT_OK;
    CCP2_REG_T compare_temp_value = {.ccpr2_16Bit = 0};
    if(NULL == _capture_value){
        ret = E_NOT_OK;
    }
    else
    {
        compare_temp_value.ccpr2_low = CCPR2L;
        compare_temp_value.ccpr2_high = CCPR2H;
        *_capture_value = compare_temp_value.ccpr2_16Bit;
        ret = E_OK;
    }
    
    return ret;
}
#endif

#if CCP2_CFG_SELECTED_MODE == CCP2_CFG_COMPARE_MODE_SELECTED
Std_ReturnType CCP2_IsCompareDataReady(uint8 *_compare_status){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _compare_status){
        ret = E_NOT_OK;
    }
    else
    {
        if(CCP2_COMPARE_READY == PIR2bits.CCP2IF){
            *_compare_status = CCP2_COMPARE_READY;
            CCP2_InterruptFlagClear();
        }else{
            *_compare_status = CCP2_COMPARE_NOT_READY;
        }
        ret = E_OK;
    }
    
    return ret;
}

Std_ReturnType CCP2_Compare_Mode_Set_Value(uint16 _compare_value){
    Std_ReturnType ret = E_NOT_OK;
    CCP2_REG_T capture_temp_value = {.ccpr2_16Bit = _compare_value};
    CCPR2L = capture_temp_value.ccpr2_low;
    CCPR2H = capture_temp_value.ccpr2_high;
        ret = E_OK;
    
    
    return ret;
}
#endif

#if CCP2_CFG_SELECTED_MODE == CCP2_CFG_PWM_MODE_SELECTED
Std_ReturnType CCP2_PWM2_Set_Duty_Cycle(const uint8 _duty){
    Std_ReturnType ret = E_NOT_OK;
    uint16 l_duty_temp = ZERO_INIT;
    l_duty_temp = (uint16)((PR2+1)*(_duty/100.0)*4);
    CCP2CONbits.DC2B = (uint8)(l_duty_temp & 0x0003);
    CCPR2L = (uint8)(l_duty_temp >> 2);
    ret = E_OK;
   
    return ret;
}
Std_ReturnType CCP2_PWM2_Start(void){
    Std_ReturnType ret = E_NOT_OK;
    CCP2_SET_MODE(CCP2_PWM_MODE);
    ret = E_OK;
   
    return ret;
}
Std_ReturnType CCP2_PWM2_Stop(void){
    Std_ReturnType ret = E_NOT_OK;
    CCP2_SET_MODE(CCP2_MODULE_DISABLE);
    ret = E_OK;
    return ret;
}
#endif

#if ((CCP2_CFG_SELECTED_MODE == CCP2_CFG_CAPTURE_MODE_SELECTED) || (CCP2_CFG_SELECTED_MODE == CCP2_CFG_COMPARE_MODE_SELECTED))
    static void CCP2_Capture_Mode_Timer_Select(const ccp2_t *_ccp_obj){
        if(CCP2_CCP1_TIMER3 == _ccp_obj->ccp2_capture_Compare_timer){
            T3CONbits.T3CCP1 = 0;
            T3CONbits.T3CCP2 = 1;
        }else if(CCP2_TIMER3_CCP1_TIMER1 == _ccp_obj->ccp2_capture_Compare_timer){
            T3CONbits.T3CCP1 = 1;
            T3CONbits.T3CCP2 = 0;
        }else if(CCP2_CCP1_TIMER1 == _ccp_obj->ccp2_capture_Compare_timer){
            T3CONbits.T3CCP1 = 0;
            T3CONbits.T3CCP2 = 0;
        }else{/*NoThing*/}
    }
#endif

#if INTERRUPT_FEATURE_ENABLE == CCP2_INTERRUPT_FEATURE_ENABLE
void CCP2_ISR(void){
    CCP2_InterruptFlagClear();
    
    if(CCP2_InterruptHandler){
        CCP2_InterruptHandler();
    }
}    
#endif