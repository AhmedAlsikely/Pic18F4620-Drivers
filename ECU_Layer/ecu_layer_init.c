/* 
 * File:   ecu_layer_init.c
 * Author: Alsikely
 *
 * Created on April 13, 2023, 2:10 PM
 */

#include "ecu_layer_init.h"
chr_lcd_4bit_t lcd_1 = {
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.pin = PIN0,
    .lcd_rs.direction = GPIO_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_en.port = PORTC_INDEX,
    .lcd_en.pin = PIN1,
    .lcd_en.direction = GPIO_OUTPUT,
    .lcd_en.logic = GPIO_LOW,
    .lcd_data[0].port = PORTC_INDEX,
    .lcd_data[0].pin = PIN2,
    .lcd_data[0].direction = GPIO_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[1].port = PORTC_INDEX,
    .lcd_data[1].pin = PIN3,
    .lcd_data[1].direction = GPIO_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[2].port = PORTC_INDEX,
    .lcd_data[2].pin = PIN4,
    .lcd_data[2].direction = GPIO_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[3].port = PORTC_INDEX,
    .lcd_data[3].pin = PIN5,
    .lcd_data[3].direction = GPIO_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW,  
};


chr_lcd_8bit_t lcd_2 = {
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.pin = PIN6,
    .lcd_rs.direction = GPIO_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_en.port = PORTC_INDEX,
    .lcd_en.pin = PIN7,
    .lcd_en.direction = GPIO_OUTPUT,
    .lcd_en.logic = GPIO_LOW,
    .lcd_data[0].port = PORTD_INDEX,
    .lcd_data[0].pin = PIN0,
    .lcd_data[0].direction = GPIO_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[1].port = PORTD_INDEX,
    .lcd_data[1].pin = PIN1,
    .lcd_data[1].direction = GPIO_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[2].port = PORTD_INDEX,
    .lcd_data[2].pin = PIN2,
    .lcd_data[2].direction = GPIO_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[3].port = PORTD_INDEX,
    .lcd_data[3].pin = PIN3,
    .lcd_data[3].direction = GPIO_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW,
    .lcd_data[4].port = PORTD_INDEX,
    .lcd_data[4].pin = PIN4,
    .lcd_data[4].direction = GPIO_OUTPUT,
    .lcd_data[4].logic = GPIO_LOW,
    .lcd_data[5].port = PORTD_INDEX,
    .lcd_data[5].pin = PIN5,
    .lcd_data[5].direction = GPIO_OUTPUT,
    .lcd_data[5].logic = GPIO_LOW,
    .lcd_data[6].port = PORTD_INDEX,
    .lcd_data[6].pin = PIN6,
    .lcd_data[6].direction = GPIO_OUTPUT,
    .lcd_data[6].logic = GPIO_LOW,
    .lcd_data[7].port = PORTD_INDEX,
    .lcd_data[7].pin = PIN7,
    .lcd_data[7].direction = GPIO_OUTPUT,
    .lcd_data[7].logic = GPIO_LOW,  
};
void ecu_layer_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
//    ret = lcd_4bit_intialize(&lcd_1);
    //ret = lcd_8bit_intialize(&lcd_2);
}