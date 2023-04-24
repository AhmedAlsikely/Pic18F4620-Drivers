/* 
 * File:   application.c
 * Author: Alsikely
 *
 * Created on April 8, 2023, 1:35 PM
 */

#include "application.h"
#include "MCAL_Layer/GPIO/hal_gpio.h"


    led_t led1 = {.port_name = PORTC_INDEX, .pin = PIN0, .led_status = GPIO_LOW};
    led_t led2 = {.port_name = PORTC_INDEX, .pin = PIN1, .led_status = GPIO_LOW};
    led_t led3 = {.port_name = PORTC_INDEX, .pin = PIN2, .led_status = GPIO_LOW};
    led_t led4 = {.port_name = PORTC_INDEX, .pin = PIN3, .led_status = GPIO_LOW};

Std_ReturnType ret = E_NOT_OK;
int main() {

    
    app_initialize();
    while(1){
        ret = led_turn_on(&led1);
        ret = led_turn_on(&led2);
        ret = led_turn_on(&led3);
        ret = led_turn_on(&led4);
        __delay_ms(1000);
        ret = led_turn_off(&led1);
        ret = led_turn_off(&led2);
        ret = led_turn_off(&led3);
        ret = led_turn_off(&led4);
        __delay_ms(1000);
        ret = led_turn_toggle(&led1);
        ret = led_turn_toggle(&led3);
        __delay_ms(1000);
        ret = led_turn_toggle(&led1);
        ret = led_turn_toggle(&led2);
        ret = led_turn_toggle(&led3);
        ret = led_turn_toggle(&led4);
        __delay_ms(1000);
    }
    return (0);
}

void app_initialize(void){
    ret = led_initialize(&led1);
    ret = led_initialize(&led2);
    ret = led_initialize(&led3);
    ret = led_initialize(&led4);

}