/* 
 * File:   application.c
 * Author: Alsikely
 *
 * Created on April 8, 2023, 1:35 PM
 */

#include "application.h"
#include "MCAL_Layer/Interrupt/mcal_external_interrupt.h"
#include "MCAL_Layer/GPIO/hal_gpio.h"


uint8 counter = ZERO_INIT;
uint8 num_arr[4];

pin_config_t led1 ={.pin = PIN0, .logic = GPIO_HIGH, .direction = GPIO_OUTPUT, .port = PORTC_INDEX};
pin_config_t led2 ={.pin = PIN1, .logic = GPIO_HIGH, .direction = GPIO_OUTPUT, .port = PORTC_INDEX};
pin_config_t led3 ={.pin = PIN2, .logic = GPIO_HIGH, .direction = GPIO_OUTPUT, .port = PORTC_INDEX};
pin_config_t led4 ={.pin = PIN3, .logic = GPIO_HIGH, .direction = GPIO_OUTPUT, .port = PORTC_INDEX};

void RB4_HIGH_Int_APP_ISR(void){
    gpio_pin_write_logic(&led1,GPIO_HIGH);
}

void RB4_LOW_Int_APP_ISR(void){
    gpio_pin_write_logic(&led1,GPIO_LOW);
}

void RB5_HIGH_Int_APP_ISR(void){
    gpio_pin_write_logic(&led2,GPIO_HIGH);
}

void RB5_LOW_Int_APP_ISR(void){
    gpio_pin_write_logic(&led2,GPIO_LOW);
}

void RB6_HIGH_Int_APP_ISR(void){
    gpio_pin_write_logic(&led3,GPIO_HIGH);
}

void RB6_LOW_Int_APP_ISR(void){
    gpio_pin_write_logic(&led3,GPIO_LOW);
}

void RB7_HIGH_Int_APP_ISR(void){
    gpio_pin_write_logic(&led4,GPIO_HIGH);
}

void RB7_LOW_Int_APP_ISR(void){
    gpio_pin_write_logic(&led4,GPIO_LOW);
}

interrupt_RBx_t rb4_int_obj = {
  .InterruptHandler_HIGH =  RB4_HIGH_Int_APP_ISR,
  .InterruptHandler_LOW = RB4_LOW_Int_APP_ISR,
  .priority = INTERRUPT_HIGH_PRIORITY,
  .mcu_pin.port = PORTB_INDEX,
  .mcu_pin.pin =PIN4,
  .mcu_pin.direction = GPIO_INPUT
};

interrupt_RBx_t rb5_int_obj = {
  .InterruptHandler_HIGH =  RB5_HIGH_Int_APP_ISR,
  .InterruptHandler_LOW = RB5_LOW_Int_APP_ISR,
  .priority = INTERRUPT_HIGH_PRIORITY,
  .mcu_pin.port = PORTB_INDEX,
  .mcu_pin.pin =PIN5,
  .mcu_pin.direction = GPIO_INPUT
};

interrupt_RBx_t rb6_int_obj = {
  .InterruptHandler_HIGH =  RB6_HIGH_Int_APP_ISR,
  .InterruptHandler_LOW = RB6_LOW_Int_APP_ISR,
  .priority = INTERRUPT_HIGH_PRIORITY,
  .mcu_pin.port = PORTB_INDEX,
  .mcu_pin.pin =PIN6,
  .mcu_pin.direction = GPIO_INPUT
};

interrupt_RBx_t rb7_int_obj = {
  .InterruptHandler_HIGH =  RB7_HIGH_Int_APP_ISR,
  .InterruptHandler_LOW = RB7_LOW_Int_APP_ISR,
  .priority = INTERRUPT_HIGH_PRIORITY,
  .mcu_pin.port = PORTB_INDEX,
  .mcu_pin.pin =PIN7,
  .mcu_pin.direction = GPIO_INPUT
};


void Int0_App_ISR(void){
    gpio_pin_toggle_logic(&led1);
    __delay_ms(500);
}
void Int1_App_ISR(void){
    gpio_pin_toggle_logic(&led2);
    __delay_ms(500);
}
void Int2_App_ISR(void){
    gpio_pin_toggle_logic(&led3);
    __delay_ms(500);
}

interrupt_INTx_t int0_obj = {
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin = PIN0,
    .mcu_pin.logic = GPIO_LOW,
    .mcu_pin.direction = GPIO_INPUT,
    .edge = INTERRUPT_RISING_EDGE,
    .source = INTERRUPT_EXTERNAL_INT0,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .InterruptHandler = Int0_App_ISR,
};

interrupt_INTx_t int1_obj = {
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin = PIN1,
    .mcu_pin.logic = GPIO_LOW,
    .mcu_pin.direction = GPIO_INPUT,
    .edge = INTERRUPT_FALLING_EDGE,
    .source = INTERRUPT_EXTERNAL_INT1,
    .priority = INTERRUPT_LOW_PRIORITY,
    .InterruptHandler = Int1_App_ISR,
};

interrupt_INTx_t int2_obj = {
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin = PIN2,
    .mcu_pin.logic = GPIO_LOW,
    .mcu_pin.direction = GPIO_INPUT,
    .edge = INTERRUPT_RISING_EDGE,
    .source = INTERRUPT_EXTERNAL_INT2,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .InterruptHandler = Int2_App_ISR,
};

//const uint8 customChar0[] = {
//  0x04,
//  0x06,
//  0x15,
//  0x0E,
//  0x0E,
//  0x15,
//  0x06,
//  0x04
//};
//
//const uint8 customChar1[] ={
//  0x00,
//  0x0C,
//  0x1E,
//  0x1E,
//  0x1C,
//  0x18,
//  0x10,
//  0x00
//};
//const uint8 customChar2[] = {
//  0x00,
//  0x06,
//  0x0F,
//  0x0F,
//  0x07,
//  0x03,
//  0x01,
//  0x00
//};
//const uint8 customChar3[] = {0x08,0x10,0x10,0x11,0x11,0x0A,0x04,0x00};
//const uint8 customChar4[] = {0x08,0x10,0x10,0x10,0x10,0x0A,0x04,0x00};
//const uint8 customChar5[] = {0x08,0x10,0x10,0x10,0x10,0x08,0x00,0x00};
//const uint8 customChar6[] = {0x08,0x10,0x10,0x10,0x00,0x00,0x00,0x00};
//const uint8 customChar7[] = {0x08,0x10,0x00,0x00,0x00,0x00,0x00,0x00};
//


int main() {
    Std_ReturnType ret = E_NOT_OK;
    app_initialize();
//    ret = lcd_8bit_send_char_data(&lcd_2,'A');
//    ret = lcd_8bit_send_command(&lcd_2,_LCD_DISPLAT_ON_CUSOR_OFF_BLINK_OFF);
//    ret = lcd_8bit_send_char_data(&lcd_2,'A');
//    ret = lcd_8bit_send_char_data_pos(&lcd_2,1,10,'A');
//    ret = lcd_8bit_send_char_data_pos(&lcd_2,2,10,'B');
//    ret = lcd_8bit_send_char_data_pos(&lcd_2,3,10,'C');
//    ret = lcd_8bit_send_char_data_pos(&lcd_2,4,10,'D');
    
//    ret = lcd_8bit_send_String(&lcd_2,"Alsikely");
//    ret = lcd_8bit_send_string_pos(&lcd_2,2,5,"Mohamed");
//    ret = lcd_4bit_send_char_data(&lcd_1,'B');
//    ret = lcd_4bit_send_char_data(&lcd_1,'B');
//    ret = lcd_4bit_send_char_data(&lcd_1,'B');
//    ret = lcd_4bit_send_char_data(&lcd_1,'B');
//    ret = lcd_4bit_send_char_data_pos(&lcd_1,2,5,'A');
//    ret = lcd_8bit_send_custome_char(&lcd_2,1,20,customChar0,0);
    while(1)
    {
        
         ///////////////////// LCD ////////////////////////
//        ret = lcd_8bit_send_custome_char(&lcd_2,1,17,customChar1,1);__delay_ms(200);
//        ret = lcd_8bit_send_custome_char(&lcd_2,1,16,customChar2,2);__delay_ms(200);
//        
        
//        ret = lcd_8bit_send_custome_char(&lcd_2,1,19,customChar5,1);__delay_ms(200);
//        ret = lcd_8bit_send_custome_char(&lcd_2,1,19,customChar4,1);__delay_ms(200);
//        ret = lcd_8bit_send_custome_char(&lcd_2,1,19,customChar3,1);__delay_ms(200);
//        ret = lcd_8bit_send_custome_char(&lcd_2,1,19,customChar2,1);__delay_ms(200);
//        ret = lcd_8bit_send_custome_char(&lcd_2,1,19,customChar1,1);__delay_ms(200);
//        ret = lcd_8bit_send_string_pos(&lcd_2,1,1,"Ahmed");
//        ret = lcd_8bit_send_string_pos(&lcd_2,2,2,"mohamed");
//        ret = lcd_8bit_send_string_pos(&lcd_2,3,3,"Alsikely");
//        
//        ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Ahmed");
//        ret = lcd_4bit_send_string_pos(&lcd_1,2,2,"mohamed");
//        ret = lcd_4bit_send_string_pos(&lcd_1,3,3,"Alsikely");
//        ret = lcd_8bit_send_command(&lcd_2,_LCD_DISPLAY_SHIFT_RIGHT);
//        __delay_ms(200);
//        ret = lcd_8bit_send_command(&lcd_2,_LCD_DISPLAY_SHIFT_LEFT);
//        ret = lcd_8bit_send_string_pos(&lcd_2,1,1,"Counter: ");
//        ret = convert_byte_to_string(counter,num_arr);
//        ret = lcd_8bit_send_string_pos(&lcd_2,1,10,num_arr);
//        __delay_ms(200);
//        counter++;
        
        
//        
        ///////////////////// key_pad ////////////////////////
//        ret = keypad_read_value(&keypad1,&keypad_value);
        ////////////////////// 7 segement ////////////////////////
//        for(flag =0;flag<10;flag++){
//            ret = seven_segement_write_number(&segement1 , flag);
//            __delay_ms(500);
//        }

        //////////////////////////////////////////////////////////
        
        
    }
    return (0);
}

void app_initialize(void){
    
    gpio_pin_direction_intialize(&led1);
    gpio_pin_direction_intialize(&led2);
    gpio_pin_direction_intialize(&led3);
    gpio_pin_direction_intialize(&led4);
    
//    Interrupt_INTx_Init(&int0_obj);
//    Interrupt_INTx_Init(&int1_obj);
//    Interrupt_INTx_Init(&int2_obj);
    
    Interrupt_RBx_Init(&rb4_int_obj);
    Interrupt_RBx_Init(&rb5_int_obj);
    Interrupt_RBx_Init(&rb6_int_obj);
    Interrupt_RBx_Init(&rb7_int_obj);
    
//    ecu_layer_intialize();
    
}