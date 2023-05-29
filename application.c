#include "application.h"
#include "ECU_Layer/7_segement/ecu_7_segement.h"
#include "MCAL_Layer/Timer/Timer2/hal_timer2.h"
led_t led1 = {.port_name = PORTC_INDEX, .pin = PIN4, .led_status = GPIO_LOW};
led_t led2 = {.port_name = PORTC_INDEX, .pin = PIN7, .led_status = GPIO_LOW};

volatile uint8 timer0_count = 0;
volatile uint8 timer1_count = 0;
volatile uint8 CCP1_Interrupt_flag = 0;
volatile uint8 CCP1_Interrupt_flag_2 = 0;
volatile uint32 ccp1_capature_value = 0;
volatile uint32 timer3_overflow = 0;
volatile uint32 usart_rx_valid = 0;
volatile uint32 usart_tx_valid = 0;
uint32 Total_period_microSecond = 0;
uint32 freqenct_measured = 0;


void timer0_interruptHundler(void);
void timer1_interruptHundler(void);
void timer2_interruptHundler(void);
void timer3_interruptHundler(void);
void CCP1_interruptHundler(void);
void EUSART_Tx_InterruptHandler(void);
void EUSART_Rx_InterruptHandler(void);
ccp1_t ccp1_obj ={
  .CCP1_InterruptHandler = CCP1_interruptHundler, 
  .priority = INTERRUPT_HIGH_PRIORITY,
  .ccp1_capture_Compare_timer = CCP1_CCP2_TIMER3,
  .ccp1_mode_variant = CCP1_CAPTURE_MODE_EVERY_RISING_EDGE,
  .ccp1_pin.port = PORTC_INDEX,
  .ccp1_pin.pin = PIN2,
  .ccp1_pin.direction =GPIO_INPUT,
};


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
    .TMR1_InterruptHandler = NULL,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .timer1_mode = TIMER1_COUNTER_MODE_CFG,
    .timer1_osc_cfg = TIMER1_OSCILLATOR_DISABLE_CFG,
    .timer1_preload_value = 0,
    .timer1_prescaler_value = TIMER1_PRESCALER_DIV_BY_1,
    .timer1_reg_wr_mode = TIMER1_RW_REG_16BIT_MODE_CFG
};
timer2_t timer2 = {
    .TMR2_InterruptHandler = NULL,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .timer2_preload_value = 0,
    .timer2_prescaler_value = TIMER2_PRESCALER_DIV_BY_1,
    .timer2_postscaler_value = TIMER2_POSTSCALER_DIV_BY_1
};
timer3_t timer3 = {
    .TMR3_InterruptHandler = timer3_interruptHundler,
    .priority = INTERRUPT_LOW_PRIORITY,
    .timer3_mode = TIMER3_TIMER_MODE_CFG,
    .timer3_preload_value = 0,
    .timer3_prescaler_value = TIMER3_PRESCALER_DIV_BY_1,
    .timer3_reg_wr_mode = TIMER3_RW_REG_8BIT_MODE_CFG
    
};


usart_t usart_obj = {
    .EUSART_FramingErrorHandler = NULL,
    .EUSART_OverrunErrorHandler= NULL,
    .EUSART_RxDefailtInterruptHandler = EUSART_Rx_InterruptHandler,
    .EUSART_TxDefailtInterruptHandler= EUSART_Tx_InterruptHandler,
    
    .baudrate = 9600,
    .baudrate_gen_cfg = BAUDRATE_ASYN_8BIT_LOW_SPEED,
  
    .usart_tx_cfg.usart_tx_enable = EUSART_ASYNCHRONOUS_TX_ENABLE,
    .usart_tx_cfg.usart_tx_interrupt_enable = EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE,
    .usart_tx_cfg.usart_tx_9bit_enable = EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE,
    .usart_tx_cfg.usart_tx_priority = INTERRUPT_HIGH_PRIORITY,
  
    .usart_rx_cfg.usart_rx_enable = EUSART_ASYNCHRONOUS_RX_ENABLE,
    .usart_rx_cfg.usart_rx_interrupt_enable = EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE,
    .usart_rx_cfg.usart_rx_9bit_enable = EUSART_ASYNCHRONOUS_9BIT_RX_DISABLE,
    .usart_rx_cfg.usart_rx_priority = INTERRUPT_LOW_PRIORITY,
};

uint8 rec_uart_data;
void app_intialize(void);

int main() { 
    Std_ReturnType ret = E_NOT_OK;
    app_intialize();

    while(1){
        
        ret = EUSART_ASYNC_WriteStringBlocking("AHMED\r");
//        ret = EUSART_ASYNC_ReadByteNonBlocking(&rec_uart_data);
//        if(E_OK){
//            if('a' == rec_uart_data){
//                led_turn_on(&led1);
//            }else if('b' ==rec_uart_data){
//                led_turn_off(&led1);
//            }else{
//                
//            }
//        }
        
    }
    return (0);
}

void app_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    
//    ret = button_initialize(&btn_high);
    ret = led_initialize(&led1);
//    ret = led_initialize(&led2);
    //ret = Timer0_Init(&timer0);
   // ret = Timer1_Init(&timer1);
    //ret = Timer2_Init(&timer2);
    //ret = Timer3_Init(&timer3);
    //ret = CCP1_Init(&ccp1_obj);
    ret = EUSART_ASYNC_Init(&usart_obj);
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
void timer3_interruptHundler(void){
    timer3_overflow++;
}
void CCP1_interruptHundler(void){
    CCP1_Interrupt_flag++;
    CCP1_Interrupt_flag_2++;
    if(CCP1_Interrupt_flag == 1){
        Timer3_Write_value(&timer3,0);
        timer3_overflow = 0;
    }
    else if(CCP1_Interrupt_flag == 2){
        
        CCP1_Interrupt_flag = 0;
        CCP1_Capture_Mode_Read_Value(&ccp1_capature_value);

    }
}

void EUSART_Tx_InterruptHandler(void){
    usart_tx_valid++;
}
void EUSART_Rx_InterruptHandler(void){
    usart_rx_valid++;
}