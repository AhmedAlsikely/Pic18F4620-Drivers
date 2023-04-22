/* 
 * File:   hal_gpio.h
 * Author: Alsikely
 *
 * Created on April 8, 2023, 1:59 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* Section : Includes */
#include <pic18f4620.h>
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "hal_gpio_cfg.h"

/* Section : Macro Declarations */
#define BIT_MASK (uint8)1
#define PORT_PIN_MAX_NUMBER 8
#define PORT_MAX_NUMBER 5


/* Section : Macro Functions Declarations */
//#define HWREG8(_x)  (*((volatile uint8 *)(_x)))

#define SET_BIT(REG,BIT_POSN)      (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)    (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG,BIT_POSN)   (REG ^= (BIT_MASK << BIT_POSN))
#define READ_BIT(REG,BIT_POSN)     ((REG >> BIT_POSN) & BIT_MASK)

/* Section : Data Type Declarations */
typedef enum{
    GPIO_LOW =0,
    GPIO_HIGH
}logic_t;

typedef enum{
    GPIO_OUTPUT =0,
    GPIO_INPUT
}direction_t;

typedef enum{
    PIN0 =0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7 
}pin_index_t;

typedef enum{
    PORTA_INDEX =0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef struct{
    uint8 port      :3; /* @ref port_index_t */
    uint8 pin       :3; /* @ref pin_index_t  */
    uint8 direction :1; /* @ref direction_t  */
    uint8 logic     :1; /* @ref logic_t      */
}pin_config_t;

/* Section : Functions Declarations */

/**
 * @brief Initialize the direction of a specific pin
 * @param _pin_config pointer to the configurations 
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config);

/**
 * 
 * @param _pin_config pointer to the configurations 
 * @param direction_status is a pointer to store the direction of pin if input or output
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config,direction_t *direction_status);

/**
 * 
 * @param _pin_config pointer to the configurations
 * @param logic is a value that we want write in the pin (HIGH or LOW)
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config ,logic_t logic);

/**
 * 
 * @param _pin_config pointer to the configurations
 * @param logic pointer to the pin status HIGH or LOW
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config ,logic_t *logic);

/**
 * 
 * @param _pin_config pointer to the configurations
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config);

/**
 * 
 * @param _pin_config pointer to the configurations
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType gpio_pin_intialize(const pin_config_t *_pin_config);



/**
 * 
 * @param port : it is a variable to Select the Port
 * @param direction : it is a variable to Select the Port direction if input or output
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction);

/**
 * 
 * @param port is a variable to Select the Port
 * @param direction_status is a pointer to store the direction of port if input or output
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType gpio_port_get_direction_status(port_index_t port,uint8 *direction_status);

/**
 * 
 * @param port is a variable to Select the Port
 * @param logic is the value that we want to write on the pins of port from 0x00 to 0xFF 
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */


Std_ReturnType gpio_port_write_logic(port_index_t port ,uint8 logic);
/**
 * 
 * @param port is a variable to Select the Port
 * @param logic is a pointer to store the values in the pins of port
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType gpio_port_read_logic(port_index_t port ,uint8 *logic);

/**
 * 
 * @param port is a variable to Select the Port
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
Std_ReturnType gpio_port_toggle_logic(port_index_t port);


#endif	/* HAL_GPIO_H */

