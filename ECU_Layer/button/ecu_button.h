 /* 
 * File:   ecu_button.h
 * Author: Alsikely
 *
 * Created on April 10, 2023, 7:46 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */

typedef enum{
    BUTTON_RELEASED = 0,
    BUTTON_PRESSED 
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_LOW = 0,
    BUTTON_ACTIVE_HIGH 
}button_active_t;

typedef struct{
    pin_config_t button_pin;
    button_active_t button_connection;
}button_t;


/* Section : Functions Declarations */
Std_ReturnType button_initialize(const button_t *btn);
Std_ReturnType button_read_state(const button_t *btn ,button_state_t *btn_state);
#endif	/* ECU_BUTTON_H */