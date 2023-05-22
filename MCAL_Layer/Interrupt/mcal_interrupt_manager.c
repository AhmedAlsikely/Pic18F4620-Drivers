/* 
 * File:   mcal_interrupt_manager.c
 * Author: Alsikely
 *
 * Created on April 16, 2023, 6:24 PM
 */

#include "mcal_interrupt_manager.h"

static volatile uint8 RB4_Flag = 1,RB5_Flag = 1,RB6_Flag = 1,RB7_Flag = 1;

static void InterruptCheck(void);

/*interrupt function*/
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
void __interrupt() InterruptManagerHigh(void){
    InterruptCheck();
}

void __interrupt(low_priority) InterruptManagerLow(void){
    InterruptCheck();
}
 
#else
void __interrupt() InterruptManagerHigh(void){
    InterruptCheck(); 
}
#endif


static void InterruptCheck(void){
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE)&&(INTERRUPT_OCCUR == INTCONbits.INT0IF)){
        INT0_ISR();
    }
    else{/* Nothing */}
    
    if((INTERRUPT_ENABLE == INTCON3bits.INT1IE)&&(INTERRUPT_OCCUR == INTCON3bits.INT1IF)){
        INT1_ISR();
    }
    else{/* Nothing */}
    
    if((INTERRUPT_ENABLE == INTCON3bits.INT2IE)&&(INTERRUPT_OCCUR == INTCON3bits.INT2IF)){
        INT2_ISR();
    }
    else{/* Nothing */}
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE)&&(INTERRUPT_OCCUR == INTCONbits.RBIF)&&(PORTBbits.RB4 == GPIO_HIGH) && (RB4_Flag ==1)){
        RB4_Flag = 0;
        RB4_ISR(1);
    }
    else{/* Nothing */}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE)&&(INTERRUPT_OCCUR == INTCONbits.RBIF)&&(PORTBbits.RB4 == GPIO_LOW)&& (RB4_Flag ==0)){
        RB4_Flag = 1;
        RB4_ISR(0);
    }
    else{/* Nothing */}
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE)&&(INTERRUPT_OCCUR == INTCONbits.RBIF)&&(PORTBbits.RB5 == GPIO_HIGH) && (RB5_Flag ==1)){
        RB5_Flag = 0;
        RB5_ISR(1);
    }
    else{/* Nothing */}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE)&&(INTERRUPT_OCCUR == INTCONbits.RBIF)&&(PORTBbits.RB5 == GPIO_LOW)&& (RB5_Flag ==0)){
        RB5_Flag = 1;
        RB5_ISR(0);
    }
    else{/* Nothing */}
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE)&&(INTERRUPT_OCCUR == INTCONbits.RBIF)&&(PORTBbits.RB6 == GPIO_HIGH) && (RB6_Flag ==1)){
        RB6_Flag = 0;
        RB6_ISR(1);
    }
    else{/* Nothing */}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE)&&(INTERRUPT_OCCUR == INTCONbits.RBIF)&&(PORTBbits.RB6 == GPIO_LOW)&& (RB6_Flag ==0)){
        RB6_Flag = 1;
        RB6_ISR(0);
    }
    else{/* Nothing */}
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE)&&(INTERRUPT_OCCUR == INTCONbits.RBIF)&&(PORTBbits.RB7 == GPIO_HIGH) && (RB7_Flag ==1)){
        RB7_Flag = 0;
        RB7_ISR(1);
    }
    else{/* Nothing */}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE)&&(INTERRUPT_OCCUR == INTCONbits.RBIF)&&(PORTBbits.RB7 == GPIO_LOW)&& (RB7_Flag ==0)){
        RB7_Flag = 1;
        RB7_ISR(0);
    }
    else{/* Nothing */}
    /*------------------------------- ADC INTERRUPT ----------------------------------*/
    if((INTERRUPT_ENABLE == PIE1bits.ADIE)&&(INTERRUPT_OCCUR == PIR1bits.ADIF)){
        ADC_ISR();
    }
    else{/* Nothing */}
    /*------------------------------- TIMER0 INTERRUPT ----------------------------------*/
    if((INTERRUPT_ENABLE == INTCONbits.TMR0IE)&&(INTERRUPT_OCCUR == INTCONbits.TMR0IF)){
        TMRO_ISR();
    }
    else{/* Nothing */}
}