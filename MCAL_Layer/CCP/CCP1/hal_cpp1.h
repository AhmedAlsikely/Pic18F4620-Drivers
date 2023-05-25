/* 
 * File:   hal_cpp1.h
 * Author: Alsikely
 *
 * Created on May 25, 2023, 4:00 PM
 */

#ifndef HAL_CPP1_H
#define	HAL_CPP1_H
/*--------------Section : Includes-------------------------*/
#include <pic18f4620.h>
#include "../../mcal_std_types.h"
#include "../../GPIO/hal_gpio.h"
#include "../../Interrupt/mcal_internal_interrupt.h"
#include "hal_cpp1_cfg.h"

/*--------------Section : Macro Declarations---------------*/
/* CCP1 Module Mode Select */
#define CCP1_MODULE_DISABLE                       ((uint8)0x00)
#if CCP1_CFG_SELECTED_MODE == CCP1_CFG_CAPTURE_MODE_SELECTED
#define CCP1_CAPTURE_MODE_EVERY_FALLING_EDGE      ((uint8)0x04)
#define CCP1_CAPTURE_MODE_EVERY_RISING_EDGE       ((uint8)0x05)
#define CCP1_CAPTURE_MODE_EVERY_4TH_RISING_EDGE   ((uint8)0x06)
#define CCP1_CAPTURE_MODE_EVERY_16TH_RISING_EDGE  ((uint8)0x07)
#endif
#if CCP1_CFG_SELECTED_MODE == CCP1_CFG_COMPARE_MODE_SELECTED
#define CCP1_COMPARE_MODE_TOGGLE_OUTPUT_ON_MATCH  ((uint8)0x02)
#define CCP1_COMPARE_MODE_FORCE_CCP1_PIN_HIGH     ((uint8)0x08)
#define CCP1_COMPARE_MODE_FORCE_CCP1_PIN_LOW      ((uint8)0x09)
#define CCP1_COMPARE_MODE_GEN_SW_INTERRUPT        ((uint8)0x0A)
#define CCP1_COMPARE_MODE_TRIGGER_SPECIAL_EVENT   ((uint8)0x0B)
#endif
#if CCP1_CFG_SELECTED_MODE == CCP1_CFG_PWM_MODE_SELECTED
#define CCP1_PWM_MODE                             ((uint8)0x0C)
#endif

/* CCP1 Capture Mode State */
#if CCP1_CFG_SELECTED_MODE == CCP1_CFG_CAPTURE_MODE_SELECTED
#define CCP1_CAPTURE_NOT_READY                    0x00
#define CCP1_CAPTURE_READY                        0x01
#endif

/* CCP1 Compare Mode State */
#if CCP1_CFG_SELECTED_MODE == CCP1_CFG_COMPARE_MODE_SELECTED
#define CCP1_COMPARE_NOT_READY                    0x00
#define CCP1_COMPARE_READY                        0x01
#endif

/*--------------Section : Macro Functions Declarations-----*/
#define CCP1_SET_MODE(_MODE_CFG_) (CCP1CONbits.CCP1M = _MODE_CFG_) 

/*--------------Section : Data Type Declarations-----------*/

typedef enum{
    CCP1_CAPTURE_MODE_SELECTED =0,
    CCP1_COMPARE_MODE_SELECTED,
    CCP1_PWM_MODE_SELECTED
}ccp1_mode_t;

/**
 * @Summary      Defines the values to convert from 16bit to two 8 bit and vice versa
 * @Description  Used to get two 8 bit values from 16bit also two 8 bit value are combine to get 16bit.
 */
typedef union{
    struct{
        uint8 ccpr1_low;
        uint8 ccpr1_high;
    };
    uint16 ccpr1_16Bit;
}CCP1_PRELOAD_REG_T;

typedef struct{
    ccp1_mode_t ccp1_mode;  
    pin_config_t ccp1_pin;
#if INTERRUPT_FEATURE_ENABLE == CCP1_INTERRUPT_FEATURE_ENABLE
    void (* CCP1_InterruptHandler)(void);
    interrupt_priority_cfg priority;
#endif
#if ((CCP1_CFG_SELECTED_MODE == CCP1_CFG_CAPTURE_MODE_SELECTED) || (CCP1_CFG_SELECTED_MODE == CCP1_CFG_COMPARE_MODE_SELECTED))
    uint8 ccp1_mode_variant;
#endif
#if CCP1_CFG_SELECTED_MODE == CCP1_CFG_PWM_MODE_SELECTED
    uint32 PWM_Frequency;    
#endif
}ccp1_t;

/*--------------Section : Functions Declarations-----------*/

Std_ReturnType CCP1_Init(const ccp1_t *_ccp);
Std_ReturnType CCP1_DeInit(const ccp1_t *_ccp);
 
#if CCP1_CFG_SELECTED_MODE == CCP1_CFG_CAPTURE_MODE_SELECTED
Std_ReturnType CCP1_IsCaptureDataReady(uint8 *_capture_status);
Std_ReturnType CCP1_Capture_Mode_Read_Value(uint16 *_capture_value);
#endif

#if CCP1_CFG_SELECTED_MODE == CCP1_CFG_COMPARE_MODE_SELECTED
Std_ReturnType CCP1_IsCompareDataReady(uint8 *_compare_status);
Std_ReturnType CCP1_Compare_Mode_Set_Value(uint16 *_compare_value);
#endif

#if CCP1_CFG_SELECTED_MODE == CCP1_CFG_PWM_MODE_SELECTED
Std_ReturnType CCP1_PWM1_Set_Duty_Cycle(const uint16 _duty);
Std_ReturnType CCP1_PWM1_Start(void);
Std_ReturnType CCP1_PWM1_Stop(void);
#endif


#endif	/* HAL_CPP1_H */

