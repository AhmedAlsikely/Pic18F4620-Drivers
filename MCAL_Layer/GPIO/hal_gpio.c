/* 
 * File:   hal_gpio.c
 * Author: Alsikely
 *
 * Created on April 8, 2023, 1:35 PM
 */

#include "hal_gpio.h"

volatile uint8 *tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8 *lat_registers[] = {&LATA, &LATB, &LATC, &LATD, &LATE};
volatile uint8 *port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};

/**
 * @brief Initialize the direction of a specific pin
 * @param _pin_config pointer to the configurations 
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config){
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(_pin_config->direction){
        case GPIO_OUTPUT : 
            CLEAR_BIT(*tris_registers[_pin_config->port],_pin_config->pin);
            break;
        case GPIO_INPUT :
            SET_BIT(*tris_registers[_pin_config->port],_pin_config->pin);
            break;
        default: ret = E_NOT_OK;
        
        }
    }
    
    
    return ret;
}
#endif

/**
 * 
 * @param _pin_config pointer to the configurations 
 * @param direction_status is a pointer to store the direction of pin if input or output
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config,direction_t *direction_status){
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || NULL == direction_status || _pin_config->pin > PORT_PIN_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
       *direction_status =  READ_BIT(*tris_registers[_pin_config->port],_pin_config->pin);
    }
    
    return ret;
}
#endif

/**
 * 
 * @param _pin_config pointer to the configurations
 * @param logic is a value that we want write in the pin (HIGH or LOW)
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config ,logic_t logic){
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(logic){
        case GPIO_LOW : 
            CLEAR_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
            break;
        case GPIO_HIGH :
            SET_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
            break;
        default: ret = E_NOT_OK;
        
        }
    }
    
    return ret;
}
#endif

/**
 * 
 * @param _pin_config pointer to the configurations
 * @param logic pointer to the pin status HIGH or LOW
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config ,logic_t *logic){
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || NULL == logic || _pin_config->pin > PORT_PIN_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *logic =  READ_BIT(*port_registers[_pin_config->port],_pin_config->pin);
    }
    
    return ret;
}
#endif

/**
 * 
 * @param _pin_config pointer to the configurations
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config){
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TOGGLE_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
    }
    
    return ret;
}
#endif

/**
 * 
 * @param _pin_config pointer to the configurations
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_intialize(const pin_config_t *_pin_config){
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_direction_intialize(_pin_config);
        ret &= gpio_pin_write_logic(_pin_config ,_pin_config->logic);
        
    }
    
    return ret;
}
#endif
/**
 * 
 * @param port : it is a variable to Select the Port
 * @param direction : it is a variable to Select the Port direction if input or output
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction){
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *tris_registers[port] = direction;
    }
    
    return ret;
}
#endif
/**
 * 
 * @param port is a variable to Select the Port
 * @param direction_status is a pointer to store the direction of port if input or output
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status){
    Std_ReturnType ret = E_OK;
    if((NULL == direction_status) || (port > PORT_MAX_NUMBER-1) )
    {
        ret = E_NOT_OK;
    }
    else
    {
        *direction_status = *tris_registers[port];
    }
    
    return ret;
}
#endif

/**
 * 
 * @param port is a variable to Select the Port
 * @param logic is the value that we want to write on the pins of port from 0x00 to 0xFF 
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic(port_index_t port ,uint8 logic){
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
       *lat_registers[port] = logic ;
    }
    
    return ret;
}
#endif

/**
 * 
 * @param port is a variable to Select the Port
 * @param logic ia a pointer to store the values in the pins of port
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic(port_index_t port ,uint8 *logic){
    Std_ReturnType ret = E_OK;
    if((NULL == logic) || (port > PORT_MAX_NUMBER-1))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *logic = *lat_registers[port];
    }
    
    return ret;
}
#endif

/**
 * 
 * @param port is a variable to Select the Port
 * @return Status of the function
 *         (E_OK) : The function done successfully
 *         (E_NOT_OK) : the function has issue to program this action
 */
#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic(port_index_t port){
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *lat_registers[port] ^= 0xFF; 
    }
    
    return ret;
}
#endif
