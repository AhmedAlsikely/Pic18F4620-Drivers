/* 
 * File:   hal_adc.h
 * Author: Alsikely
 *
 * Created on April 25, 2023, 8:39 PM
 */

#ifndef HAL_ADC_H
#define	HAL_ADC_H

/* Section : Includes */
#include <pic18f4620.h>
#include "../mcal_std_types.h"
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"
#include "hal_adc_cfg.h"

/* Section : Macro Declarations */
#define ADC_RESULT_RIGHT 0x01U
#define ADC_RESULT_LEFT  0x00U

#define ADC_VOLTAGE_REFERANCE_ENABLE   0x01U
#define ADC_VOLTAGE_REFERANCE_DISABLE  0x00U

#define ADC_CONVERSION_COMPLETED       0x01U
#define ADC_CONVERSION_INPROGRESS      0x00U

/* Section : Macro Functions Declarations */

/* A/D Conversion Status : A/D conversion in progress/ A/D Idle */
#define ADC_CONVERSION_STATUS()  (ADCON0bits.GO_nDONE)

/**
 * @brief Start the Analog-to-digital Conversion
 */
#define ADC_START_CONVERSION()  (ADCON0bits.GODONE = 1)

/**
 * @brief Analog-to-digital converter
 * @note ADC_CONVERSION_ENABLE()  : Enable the Analog-To-Digital converter
 *       ADC_CONVERSION_DISABLE() : Disable the Analog-To-Digital converter
 */
#define ADC_CONVERSION_ENABLE()   (ADCON0bits.ADON = 1)
#define ADC_CONVERSION_DISABLE()  (ADCON0bits.ADON = 0)

/**
 * @brief  Voltage Reference Configuration bit
 * @note ADC_ENABLE_VOLTAGE_REFERANCE()   : Voltage Reference is VREF- & VREF+
 *       ADC_DISABLE_VOLTAGE_REFERANCE()  : Voltage Reference is VSS & VDD
 */
#define ADC_ENABLE_VOLTAGE_REFERANCE()  do{ADCON1bits.VCFG1 = 1;\
                                           ADCON1bits.VCFG0 = 1;\
                                          }while(0)
#define ADC_DISABLE_VOLTAGE_REFERANCE() do{ADCON1bits.VCFG1 = 0;\
                                           ADCON1bits.VCFG0 = 0;\
                                          }while(0)


/**
 * @brief Analog-to-digital port configuration control
 * @note  Example : ADC_ANALOG_DIGITAL_PORT_CONFIG(ADC_AN3_TO_AN0_ANALOG_FUNCTIONALITY);
 *        when ADC_AN3_TO_AN0_ANALOG_FUNCTIONALITY is configured, this means
 *        AN3,AN2,AN1,AN0, are Analog functionality.
 *        @ref Analog-to-digital port configuration control.
 */
#define ADC_ANALOG_DIGITAL_PORT_CONFIG(_CONFIG) (ADCON1bits.PCFG = (adc_config_pin_select_t)_CONFIG)

/**
 *  @brief A/D Result Format Select
 */
#define ADC_RESULT_RIGHT_FORMAT() (ADCON2bits.ADFM = 1)
#define ADC_RESULT_LEFT_FORMAT()  (ADCON2bits.ADFM = 0)

/* Section : Data Type Declarations */
typedef uint16 adc_result_t;
typedef enum{
            ADC_ALL_PINS_ANALOG_FUNCTIONALITY = 0,
            ADC_ALL_ANALOG_FUNCTIONALITY,
            ADC_AN12_TO_AN0_ANALOG_FUNCTIONALITY,
            ADC_AN11_TO_AN0_ANALOG_FUNCTIONALITY,
            ADC_AN10_TO_AN0_ANALOG_FUNCTIONALITY,
            ADC_AN9_TO_AN0_ANALOG_FUNCTIONALITY,
            ADC_AN8_TO_AN0_ANALOG_FUNCTIONALITY,
            ADC_AN7_TO_AN0_ANALOG_FUNCTIONALITY,
            ADC_AN6_TO_AN0_ANALOG_FUNCTIONALITY,
            ADC_AN5_TO_AN0_ANALOG_FUNCTIONALITY,
            ADC_AN4_TO_AN0_ANALOG_FUNCTIONALITY,
            ADC_AN3_TO_AN0_ANALOG_FUNCTIONALITY,
            ADC_AN2_TO_AN0_ANALOG_FUNCTIONALITY,
            ADC_AN1_TO_AN0_ANALOG_FUNCTIONALITY,
            ADC_AN0_ANALOG_FUNCTIONALITY,     
            ADC_ALL_PINS_DIGITAL_FUNCTIONALITY, 
}adc_config_pin_select_t;

typedef enum{
            ADC_CHANNEL_AN0 = 0,
            ADC_CHANNEL_AN1,
            ADC_CHANNEL_AN2,
            ADC_CHANNEL_AN3,
            ADC_CHANNEL_AN4,
            ADC_CHANNEL_AN5,
            ADC_CHANNEL_AN6,
            ADC_CHANNEL_AN7,
            ADC_CHANNEL_AN8,
            ADC_CHANNEL_AN9,
            ADC_CHANNEL_AN10,
            ADC_CHANNEL_AN11,
            ADC_CHANNEL_AN12,
}adc_channel_select_t;


typedef enum{
            ADC_0_TAD = 0,
            ADC_2_TAD ,
            ADC_4_TAD ,
            ADC_6_TAD ,
            ADC_8_TAD ,
            ADC_12_TAD ,
            ADC_16_TAD ,
            ADC_20_TAD ,
}adc_acquisition_time_t;

/**
 * @breif  A/D conversion Clock Select
 * @note   if the A/D FRC source is selected, a delay of one TCY (instruction cycle)
 *         is added before the A/D clock starts.
 * @note   this allows the SLEEp instruction to be executed before starting a conversion.
 */
typedef enum{
            ADC_CONVERSION_CLOCK_FOSC_DIV_2 = 0,
            ADC_CONVERSION_CLOCK_FOSC_DIV_8,
            ADC_CONVERSION_CLOCK_FOSC_DIV_32,
            ADC_CONVERSION_CLOCK_FOSC_DIV_FRC,
            ADC_CONVERSION_CLOCK_FOSC_DIV_4,
            ADC_CONVERSION_CLOCK_FOSC_DIV_16,
            ADC_CONVERSION_CLOCK_FOSC_DIV_64,
}adc_conversion_clock_t;


typedef struct{
#if INTERRUPT_FEATURE_ENABLE == ADC_INTERRUPT_FEATURE_ENABLE  
    void(* ADC_InterruptHandler)(void);
    interrupt_priority_cfg priority;
#endif
    adc_acquisition_time_t acquisition_time; /* @ref adc_acquisition_time_t */
    adc_conversion_clock_t conversion_clock; /* @ref adc_conversion_clock_t */
    adc_channel_select_t adc_channel;        /* @ref adc_channel_select_t */
    uint8 voltage_reference :1;              /* voltage_reference configration */
    uint8 result_format :1;                  /* A/D Result Format Select */
    uint8 ADC_Resreved :6;  
    
}adc_conf_t;
/* Section : Functions Declarations */

Std_ReturnType ADC_Init(const adc_conf_t *_adc);
Std_ReturnType ADC_DeInit(const adc_conf_t *_adc);
Std_ReturnType ADC_SelectChannel(const adc_conf_t *_adc, adc_channel_select_t channel );
Std_ReturnType ADC_StartConversion(const adc_conf_t *_adc);
Std_ReturnType ADC_IsConversionDone(const adc_conf_t *_adc,uint8 *conversion_status);
Std_ReturnType ADC_GetConversionResult(const adc_conf_t *_adc,adc_result_t *conversion_result);
Std_ReturnType ADC_GetConversion_Blocking(const adc_conf_t *_adc,adc_channel_select_t channel ,adc_result_t *conversion_result);
Std_ReturnType ADC_Start_Conversion_Intterrupt(const adc_conf_t *_adc,adc_channel_select_t channel);




#endif	/* HAL_ADC_H */

