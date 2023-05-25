/* 
 * File:   ecu_7_segement.h
 * Author: Alsikely
 *
 * Created on April 11, 2023, 11:11 PM
 */

#ifndef ECU_7_SEGEMENT_H
#define	ECU_7_SEGEMENT_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section : Macro Declarations */
#define DC_MOTOR_STATE_ON  0x01U
#define DC_MOTOR_STATE_OFF 0x00U

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef enum{
    SEGEMENT_COMMON_ANODE = 0,
    SEGEMENT_COMMON_CHATHOD
}sev_seg_type;

typedef struct{
    pin_config_t sev_seg_pin[4];
    sev_seg_type sev_seg_type;
}seven_seg_t;

/* Section : Functions Declarations */
Std_ReturnType seven_segement_intialize(const seven_seg_t *_seg);
Std_ReturnType seven_segement_write_number(const seven_seg_t *_seg , uint8 number);

#endif	/* ECU_7_SEGEMENT_H */

