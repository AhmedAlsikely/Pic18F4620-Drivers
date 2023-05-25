#include "application.h"
#include "ECU_Layer/7_segement/ecu_7_segement.h"
#include "MCAL_Layer/Timer/Timer2/hal_timer2.h"
led_t led1 = {.port_name = PORTC_INDEX, .pin = PIN6, .led_status = GPIO_LOW};
led_t led2 = {.port_name = PORTC_INDEX, .pin = PIN7, .led_status = GPIO_LOW};

volatile uint8 timer0_count = 0;
volatile uint8 timer1_count = 0;

void timer0_interruptHundler(void);
void timer1_interruptHundler(void);
void timer2_interruptHundler(void);
timer0_t  timer0 ={
    .TMR0_InterruptHandler = timer0_interruptHundler,
    .prescaler_enable = TIMER0_PRESCALER_ENABLE_CFG,
    .prescaler_value = TIMER0_PRESCALER_DIV_BY_32,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .timer0_counter_edge = TIMER0_RISING_EDGE_CFG,
    .timer0_mode = TIMER0_TIMER_MODE_CFG,
    .timer0_register_size = TIMER0_16BIT_REGISTER_MODE_CFG,
    .timer0_preload_value =3036,
};

timer1_t timer1 = {
    .TMR1_InterruptHandler = timer1_interruptHundler,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .timer1_mode = TIMER1_COUNTER_MODE_CFG,
    .timer1_osc_cfg = TIMER1_OSCILLATOR_DISABLE_CFG,
    .timer1_preload_value = 0,
    .timer1_prescaler_value = TIMER1_PRESCALER_DIV_BY_1,
    .timer1_reg_wr_mode = TIMER1_RW_REG_16BIT_MODE_CFG
};
timer2_t timer2 = {
    .TMR2_InterruptHandler = timer2_interruptHundler,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .timer2_preload_value = 1,
    .timer2_prescaler_value = TIMER2_PRESCALER_DIV_BY_1,
    .timer2_postscaler_value = TIMER2_POSTSCALER_DIV_BY_1
};

void app_intialize(void);

int main() { 
    Std_ReturnType ret = E_NOT_OK;
    app_intialize();

    while(1){
        Timer1_Read_value(&timer1,&timer1_count);
    }
    return (0);
}

void app_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    
//    ret = button_initialize(&btn_high);
    ret = led_initialize(&led1);
    ret = led_initialize(&led2);
    //ret = Timer0_Init(&timer0);
    //ret = Timer1_Init(&timer1);
    ret = Timer2_Init(&timer2);
}

void timer0_interruptHundler(void){
    Timer1_Read_value(&timer1,&timer1_count);
    Timer1_Write_value(&timer1,0);
}

void timer1_interruptHundler(void){
    led_turn_toggle(&led1);
}
void timer2_interruptHundler(void){
    led_turn_toggle(&led1);
}