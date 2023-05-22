#include "application.h"
led_t led1 = {.port_name = PORTC_INDEX, .pin = PIN0, .led_status = GPIO_LOW};
led_t led2 = {.port_name = PORTC_INDEX, .pin = PIN1, .led_status = GPIO_LOW};

button_t btn_high = {
    .button_pin.port = PORTC_INDEX,
    .button_pin.pin = PIN2,
    .button_pin.direction = GPIO_INPUT,
    .button_pin.logic = GPIO_LOW,
    .button_connection = BUTTON_ACTIVE_HIGH,
   
};
button_t btn_low = {
    .button_pin.port = PORTC_INDEX,
    .button_pin.pin = PIN3,
    .button_pin.direction = GPIO_INPUT,
    .button_pin.logic = GPIO_LOW,
    .button_connection = BUTTON_ACTIVE_LOW,
   
};
button_state_t btn_low_status  = BUTTON_RELEASED;
button_state_t btn_high_status = BUTTON_RELEASED;

button_state_t btn_high_valid_status = BUTTON_RELEASED;
button_state_t btn_high_last_valid_status = BUTTON_RELEASED;
    
uint32 btn_high_valid = 0;
uint32 btn_low_valid = 0;
uint8 flag_low = 0;
uint8 Program_Selected = 0;

void app_intialize(void);
void program_1(void);
void program_2(void);
void program_3(void);


int main() { 
    Std_ReturnType ret = E_NOT_OK;
    app_intialize();

    while(1){
        ret = button_read_state(&btn_high, &btn_high_status);
        ret = button_read_state(&btn_low, &btn_low_status);
        
        /* ---------------- Magic button with debouncing ----------- */
        if(BUTTON_PRESSED == btn_high_status){
            btn_high_valid++;
            if(btn_high_valid > 500){
                btn_high_valid_status = BUTTON_PRESSED; //btn_high_valid_status = 1
            }
        }
        else{
            btn_high_valid = 0;
            btn_high_valid_status = BUTTON_RELEASED; //btn_high_valid_status = 0
        }
        
        if(btn_high_valid_status != btn_high_last_valid_status){
            btn_high_last_valid_status = btn_high_valid_status; //btn_high_last_valid_status = 1
            if(BUTTON_PRESSED == btn_high_valid_status){ 
                if(3 == Program_Selected){
                    Program_Selected = 0;
                }else{/*Nothing*/}
                
                Program_Selected++;
                
                switch(Program_Selected){
                    case 1 : program_1(); break;
                    case 2 : program_2(); break;
                    case 3 : program_3(); break;
                    default : break; /* Nothing */
                }
            }else{/*Nothing*/}
        }else{/*Nothing*/}
        
        /* ------------- Magic button without debouncing ----------- */
        
        if((BUTTON_PRESSED == btn_low_status) && (0 == flag_low)){
            led_turn_on(&led2);
            btn_low_valid++;
            flag_low = 1;
            
        }else if ((BUTTON_PRESSED == btn_low_status) && (1 == flag_low)){
            btn_low_valid++;
            led_turn_off(&led2);
            flag_low = 0;
        }
        else{
        btn_low_valid = 0;
        }
        
        
    }
    return (0);
}

void app_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    
    ret = button_initialize(&btn_high);
    ret = button_initialize(&btn_low);
    ret = led_initialize(&led1);
    ret = led_initialize(&led2);
}

void program_1(void){
    led_turn_on(&led1);
    __delay_ms(500);
    led_turn_off(&led1);
    __delay_ms(500);
}

void program_2(void){
    uint8 counter = 0;
    for(counter = 0; counter < 2; counter ++){
        led_turn_on(&led1);
        __delay_ms(500);
        led_turn_off(&led1);
        __delay_ms(500);
    }
}

void program_3(void){
    uint8 counter = 0;
    for(counter = 0; counter < 3; counter ++){
        led_turn_on(&led1);
        __delay_ms(500);
        led_turn_off(&led1);
        __delay_ms(500);
    }
}