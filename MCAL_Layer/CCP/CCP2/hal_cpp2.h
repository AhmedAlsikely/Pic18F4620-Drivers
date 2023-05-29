/* 
 * File:   hal_cpp2.h
 * Author: Alsikely
 *
 * Created on May 25, 2023, 4:00 PM
 */

#ifndef HAL_CPP2_H
#define	HAL_CPP2_H
/*--------------Section : Includes-------------------------*/
#include <pic18f4620.h>
#include "../../mcal_std_types.h"
#include "../../GPIO/hal_gpio.h"
#include "../../Interrupt/mcal_internal_interrupt.h"
#include "hal_cpp2_cfg.h"

/*--------------Section : Macro Declarations---------------*/
/* CCP1 Module Mode Select */
#define CCP2_MODULE_DISABLE                       ((uint8)0x00)
#if CCP2_CFG_SELECTED_MODE == CCP2_CFG_CAPTURE_MODE_SELECTED
#define CCP2_CAPTURE_MODE_EVERY_FALLING_EDGE      ((uint8)0x04)
#define CCP2_CAPTURE_MODE_EVERY_RISING_EDGE       ((uint8)0x05)
#define CCP2_CAPTURE_MODE_EVERY_4TH_RISING_EDGE   ((uint8)0x06)
#define CCP2_CAPTURE_MODE_EVERY_16TH_RISING_EDGE  ((uint8)0x07)
#endif
#if CCP2_CFG_SELECTED_MODE == CCP2_CFG_COMPARE_MODE_SELECTED
#define CCP2_COMPARE_MODE_TOGGLE_OUTPUT_ON_MATCH  ((uint8)0x02)
#define CCP2_COMPARE_MODE_FORCE_CCP2_PIN_HIGH     ((uint8)0x08)
#define CCP2_COMPARE_MODE_FORCE_CCP2_PIN_LOW      ((uint8)0x09)
#define CCP2_COMPARE_MODE_GEN_SW_INTERRUPT        ((uint8)0x0A)
#define CCP2_COMPARE_MODE_TRIGGER_SPECIAL_EVENT   ((uint8)0x0B)
#endif
#if CCP2_CFG_SELECTED_MODE == CCP2_CFG_PWM_MODE_SELECTED
#define CCP2_PWM_MODE                             ((uint8)0x0C)

/* Timer2 Prescaler */
#define CCP2_TIMER2_PRESCALER_DIV_BY_1       1
#define CCP2_TIMER2_PRESCALER_DIV_BY_4       4
#define CCP2_TIMER2_PRESCALER_DIV_BY_16      16
/* Timer2 postscaler */
#define CCP2_TIMER2_POSTSCALER_DIV_BY_1      1
#define CCP2_TIMER2_POSTSCALER_DIV_BY_2      2
#define CCP2_TIMER2_POSTSCALER_DIV_BY_3      3
#define CCP2_TIMER2_POSTSCALER_DIV_BY_4      4
#define CCP2_TIMER2_POSTSCALER_DIV_BY_5      5
#define CCP2_TIMER2_POSTSCALER_DIV_BY_6      6
#define CCP2_TIMER2_POSTSCALER_DIV_BY_7      7
#define CCP2_TIMER2_POSTSCALER_DIV_BY_8      8
#define CCP2_TIMER2_POSTSCALER_DIV_BY_9      9
#define CCP2_TIMER2_POSTSCALER_DIV_BY_10     10
#define CCP2_TIMER2_POSTSCALER_DIV_BY_11     11
#define CCP2_TIMER2_POSTSCALER_DIV_BY_12     12
#define CCP2_TIMER2_POSTSCALER_DIV_BY_13     13
#define CCP2_TIMER2_POSTSCALER_DIV_BY_14     14
#define CCP2_TIMER2_POSTSCALER_DIV_BY_15     15
#define CCP2_TIMER2_POSTSCALER_DIV_BY_16     16

#endif

/* CCP2 Capture Mode State */
#if CCP2_CFG_SELECTED_MODE == CCP2_CFG_CAPTURE_MODE_SELECTED
#define CCP2_CAPTURE_NOT_READY                    0x00
#define CCP2_CAPTURE_READY                        0x01
#endif

/* CCP2 Compare Mode State */
#if CCP2_CFG_SELECTED_MODE == CCP2_CFG_COMPARE_MODE_SELECTED
#define CCP2_COMPARE_NOT_READY                    0x00
#define CCP2_COMPARE_READY                        0x01
#endif

/*--------------Section : Macro Functions Declarations-----*/
#define CCP2_SET_MODE(_MODE_CFG_) (CCP2CONbits.CCP2M = _MODE_CFG_) 

/*--------------Section : Data Type Declarations-----------*/

typedef enum{
    CCP2_CAPTURE_MODE_SELECTED =0,
    CCP2_COMPARE_MODE_SELECTED,
    CCP2_PWM_MODE_SELECTED
}ccp2_mode_t;

/**
 * @Summary      Defines the values to convert from 16bit to two 8 bit and vice versa
 * @Description  Used to get two 8 bit values from 16bit also two 8 bit value are combine to get 16bit.
 */
typedef union{
    struct{
        uint8 ccpr2_low;
        uint8 ccpr2_high;
    };
    uint16 ccpr2_16Bit;
}CCP2_REG_T;

#if ((CCP2_CFG_SELECTED_MODE == CCP2_CFG_CAPTURE_MODE_SELECTED) || (CCP2_CFG_SELECTED_MODE == CCP2_CFG_COMPARE_MODE_SELECTED))
typedef enum{
    CCP2_CCP1_TIMER3 = 0,
    CCP2_TIMER3_CCP1_TIMER1,
    CCP2_CCP1_TIMER1
}ccp2_capture_Compare_timer_t;
#endif

typedef struct{
    ccp2_mode_t ccp2_mode;  
    pin_config_t ccp2_pin;
#if INTERRUPT_FEATURE_ENABLE == CCP2_INTERRUPT_FEATURE_ENABLE
    void (* CCP2_InterruptHandler)(void);
    interrupt_priority_cfg priority;
#endif
#if ((CCP2_CFG_SELECTED_MODE == CCP2_CFG_CAPTURE_MODE_SELECTED) || (CCP2_CFG_SELECTED_MODE == CCP2_CFG_COMPARE_MODE_SELECTED))
    uint8 ccp2_mode_variant;
    ccp2_capture_Compare_timer_t ccp2_capture_Compare_timer;
#endif
#if CCP2_CFG_SELECTED_MODE == CCP2_CFG_PWM_MODE_SELECTED
    uint32 PWM_Frequency;
    uint8 CCP2_timer2_postscaler_value :4;
    uint8 CCP2_timer2_prescaler_value :2;
    uint8 reserved :2;
#endif
}ccp2_t;

/*--------------Section : Functions Declarations-----------*/

Std_ReturnType CCP2_Init(const ccp2_t *_ccp);
Std_ReturnType CCP2_DeInit(const ccp2_t *_ccp);
 
#if CCP2_CFG_SELECTED_MODE == CCP2_CFG_CAPTURE_MODE_SELECTED
Std_ReturnType CCP2_IsCaptureDataReady(uint8 *_capture_status);
Std_ReturnType CCP2_Capture_Mode_Read_Value(uint16 *_capture_value);
#endif

#if CCP2_CFG_SELECTED_MODE == CCP2_CFG_COMPARE_MODE_SELECTED
Std_ReturnType CCP2_IsCompareDataReady(uint8 *_compare_status);
Std_ReturnType CCP2_Compare_Mode_Set_Value(uint16 _compare_value);
#endif

#if CCP2_CFG_SELECTED_MODE == CCP2_CFG_PWM_MODE_SELECTED
Std_ReturnType CCP2_PWM2_Set_Duty_Cycle(const uint8 _duty);
Std_ReturnType CCP2_PWM2_Start(void);
Std_ReturnType CCP2_PWM2_Stop(void);
#endif


#endif	/* HAL_CPP2_H */

