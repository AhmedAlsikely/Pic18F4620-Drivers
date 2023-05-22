/* 
 * File:   hal_adc.c
 * Author: Alsikely
 *
 * Created on April 25, 2023, 8:39 PM
 */

#include "hal_adc.h"

#if INTERRUPT_FEATURE_ENABLE == ADC_INTERRUPT_FEATURE_ENABLE 
static void (* ADC_InterruptHandler)(void) = NULL;
#endif

static Std_ReturnType adc_input_channel_port_configure(adc_channel_select_t channel); 
static void select_result_format(const adc_conf_t *_adc);
static void select_voltage_referance(const adc_conf_t *_adc);


/**
 * @Summary Initializes the ADC
 * @Description this routine Initializes the ADC.
 *              this routine must be called before any other ADC routine is called
 *              this routine should only be called once during system initialization.
 * @Preconditions None
 * @param _adc pointer to the ADC configurations
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType ADC_Init(const adc_conf_t *_adc){
    Std_ReturnType ret = E_OK;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }
    else
    {
        /**
         * @Summary steps to config ADC
         * 1) Disable the ADC.
         * 2) configure the acquisition time.
         * 3) configure the conversion clock.
         * 4) configure the default channel.
         * 5) configure the Interrupt.
         * 6) configure the result format.
         * 7) configure the voltage reference.
         * 8) Enable the ADC.
         */
        
        /* 1) Disable the ADC */
        ADC_CONVERSION_DISABLE();
        /* 2) configure the acquisition time. */
        ADCON2bits.ACQT = _adc->acquisition_time;
        /* 3) configure the conversion clock. */
        ADCON2bits.ADCS = _adc->conversion_clock;
        /* 4) configure the default channel. */
        ADCON0bits.CHS = _adc->adc_channel;
        ret &= adc_input_channel_port_configure(_adc->adc_channel);
        /* 5) configure the Interrupt. */
#if INTERRUPT_FEATURE_ENABLE == ADC_INTERRUPT_FEATURE_ENABLE 
        ADC_InterruptEnable();
        ADC_InterruptFlagClear();
        ADC_InterruptHandler = _adc->ADC_InterruptHandler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PeriorityLevelsEnable();
        if(INTERRUPT_HIGH_PRIORITY == _adc->priority){
            INTERRUPT_GlobalInterruptHighEnable();
            ADC_HighPrioritySet();
        }else if(INTERRUPT_LOW_PRIORITY == _adc->priority){
            INTERRUPT_GlobalInterruptLowEnable();
            ADC_LowPrioritySet();
        }else{/* NOthing */}
#else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif 
#endif
        /* 6) configure the result format. */   
        select_result_format(_adc);
        /* 7) configure the voltage reference. */
        select_voltage_referance(_adc);
        /* 8) Enable the ADC */
        ADC_CONVERSION_ENABLE();
        
    }
    return ret;
}

/**
 * @Summary De-Initializes the ADC
 * @param _adc pointer to the ADC configurations
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType ADC_DeInit(const adc_conf_t *_adc){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }
    else
    {
        /**
         * @Summary steps to Disable ADC
         * 1) Disable the ADC.
         * 2) configure the Interrupt.
         */
        
        /* 1) Disable the ADC */
        ADC_CONVERSION_DISABLE();
        /* 2) configure the Interrupt */
        #if INTERRUPT_FEATURE_ENABLE == ADC_INTERRUPT_FEATURE_ENABLE 
        ADC_InterruptDisable();
        #endif
        ret = E_OK;
    }
    return ret;
}

/**
 * @Summary Allows selection of a channel for conversion
 * @Description This routine is used to select desired channel for conversion.
 * @Preconditions ADC_Init() function should have been called before calling this function.
 * @param _adc pointer to the ADC configurations
 * @param channel Defines the channel avalible for conversion
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType ADC_SelectChannel(const adc_conf_t *_adc, adc_channel_select_t channel ){
    Std_ReturnType ret = E_OK;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }
    else
    {
        /* configure the default channel. */
        ADCON0bits.CHS = channel;
        ret = adc_input_channel_port_configure(channel);
        
    }
    return ret;
}

/**
 * @Summary start conversion
 * @Description This routine is used to start convertion of desired channel.
 * @Preconditions ADC_Init() function should have been called before calling this function.
 * @param _adc pointer to the ADC configurations
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType ADC_StartConversion(const adc_conf_t *_adc){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }
    else
    {
        ADC_START_CONVERSION();
        ret = E_OK;
    }
    return ret;
}

/**
 * @Summary Returns true when the conversion is completed otherwise false.
 * @Description This routine is used to determine if conversion is completed.
 *              when conversion is complete routine returns true. It returns false otherwise.
 * @Preconditions ADC_Init() function should have been called before calling this function.
 *                ADC_StartConversion() should have been called before calling this function.
 * @param _adc pointer to the ADC configurations.
 * @param conversion_status the conversion status.
 *                          true -> If conversion is complete
 *                          false -> If conversion is not complete
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType ADC_IsConversionDone(const adc_conf_t *_adc,uint8 *conversion_status){
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == _adc) || (NULL == conversion_status)){
        ret = E_NOT_OK;
    }
    else
    {
        
        *conversion_status = (uint8)(!(ADC_CONVERSION_STATUS()));
        ret = E_OK;
    }
    return ret;
}

/**
 * @Summary Returns the ADC conversion value
 * @Description This routine is used to get the analog to digital converted value.
 *              This routine get converted value from the channel specified.
 * @Preconditions This routine returns the conversion value only after the conversion is complete.
 *                completion status can be checked using ADC_IsConversionDone() routine.
 * @param _adc pointer to the ADC configurations
 * @param conversion_result the converted value.
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType ADC_GetConversionResult(const adc_conf_t *_adc,adc_result_t *conversion_result){
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == _adc) || (NULL == conversion_result)){
        ret = E_NOT_OK;
    }
    else
    {
        if(ADC_RESULT_RIGHT == _adc->result_format)
        {
            *conversion_result = (adc_result_t)((ADRESH << 8) + ADRESL);
        }
        else if(ADC_RESULT_LEFT == _adc->result_format)
        {
       
            *conversion_result = (adc_result_t)(((ADRESH << 8) + ADRESL) >> 6);
        }
        else
        {
        
            *conversion_result = (adc_result_t)((ADRESH << 8) + ADRESL);
        }
        
        ret = E_OK;
    }
    return ret;
}

/**
 * @Summary Returns the ADC conversion value, also allows selection of a channel for conversion.
 * @Description This routine is used to get the analog to digital converted value.
 *              This routine get converted value from the channel specified.
 * @Preconditions ADC_Init() function should have been called before calling this function.
 * @param _adc pointer to the ADC configurations
 * @param channel Defines the channel available for conversion.
 * @param conversion_result the converted value.
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType ADC_GetConversion_Blocking(const adc_conf_t *_adc,adc_channel_select_t channel,
                                                        adc_result_t *conversion_result){
    Std_ReturnType ret = E_OK;
    uint8 l_conversion_status = ZERO_INIT;
    if((NULL == _adc) || (NULL == conversion_result)){
        ret = E_NOT_OK;
    }
    else
    {
        /* Select A/D channel */
        ret = ADC_SelectChannel(_adc,channel);
        /* Start the conversion*/
        ret &= ADC_StartConversion(_adc);
        /* check if conversion is completed*/
        while(ADC_CONVERSION_STATUS());
        ret &= ADC_GetConversionResult(_adc,conversion_result);
        
    }
    return ret;
}

/**
 * @Summary Returns the ADC conversion value, also allows selection of a channel for conversion.
 * @Description This routine is used to get the analog to digital converted value.
 *              This routine get converted value from the channel specified.
 * @Preconditions ADC_Init() function should have been called before calling this function.
 * @param _adc pointer to the ADC configurations
 * @param channel Defines the channel available for conversion.
 * @param conversion_result the converted value.
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType ADC_Start_Conversion_Intterrupt(const adc_conf_t *_adc,adc_channel_select_t channel ){
    Std_ReturnType ret = E_OK;
    uint8 l_conversion_status = ZERO_INIT;
    if(NULL == _adc){
        ret = E_NOT_OK;
    }
    else
    {
        /* Select A/D channel */
        ret = ADC_SelectChannel(_adc,channel);
        /* Start the conversion*/
        ret &= ADC_StartConversion(_adc);
        
    }
    return ret;
    
    
}



static Std_ReturnType adc_input_channel_port_configure(adc_channel_select_t channel){
    Std_ReturnType ret = E_NOT_OK;
    switch(channel){
        case ADC_CHANNEL_AN0 : SET_BIT(TRISA,_TRISA_RA0_POSITION); ret = E_OK; break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN1 : SET_BIT(TRISA,_TRISA_RA1_POSITION); ret = E_OK; break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN2 : SET_BIT(TRISA,_TRISA_RA2_POSITION); ret = E_OK; break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN3 : SET_BIT(TRISA,_TRISA_RA3_POSITION); ret = E_OK; break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN4 : SET_BIT(TRISA,_TRISA_RA5_POSITION); ret = E_OK; break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN5 : SET_BIT(TRISE,_TRISE_RE0_POSITION); ret = E_OK; break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN6 : SET_BIT(TRISE,_TRISE_RE1_POSITION); ret = E_OK; break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN7 : SET_BIT(TRISE,_TRISE_RE2_POSITION); ret = E_OK; break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN8 : SET_BIT(TRISB,_TRISB_RB2_POSITION); ret = E_OK; break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN9 : SET_BIT(TRISB,_TRISB_RB3_POSITION); ret = E_OK; break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN10 : SET_BIT(TRISB,_TRISB_RB1_POSITION); ret = E_OK; break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN11 : SET_BIT(TRISB,_TRISB_RB4_POSITION); ret = E_OK; break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN12 : SET_BIT(TRISB,_TRISB_RB0_POSITION); ret = E_OK; break; /* Disable the digital output driver */
        default: ret = E_NOT_OK; 
    }
    return ret;
}

static void select_result_format(const adc_conf_t *_adc){
    if(ADC_RESULT_RIGHT == _adc->result_format){
        ADC_RESULT_RIGHT_FORMAT();
        
    }else if(ADC_RESULT_LEFT == _adc->result_format){
        ADC_RESULT_LEFT_FORMAT();
    }
    else
    {
        ADC_RESULT_RIGHT_FORMAT();
    }
}

static void select_voltage_referance(const adc_conf_t *_adc){

    if(ADC_VOLTAGE_REFERANCE_ENABLE == _adc->voltage_reference){
        ADC_ENABLE_VOLTAGE_REFERANCE();
    }
    else if(ADC_VOLTAGE_REFERANCE_DISABLE == _adc->voltage_reference){
        ADC_DISABLE_VOLTAGE_REFERANCE();
    }
    else
    {
        ADC_DISABLE_VOLTAGE_REFERANCE();
    }

}

void ADC_ISR(void){
    ADC_InterruptFlagClear();
    if(ADC_InterruptHandler){
        ADC_InterruptHandler();
    }else{/*NOthing*/}
}