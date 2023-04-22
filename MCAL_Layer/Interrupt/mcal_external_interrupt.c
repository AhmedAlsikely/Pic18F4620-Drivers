/* 
 * File:   mcal_external_interrupt.c
 * Author: Alsikely
 *
 * Created on April 16, 2023, 6:23 PM
 */
#include "mcal_external_interrupt.h"

static void (*INT0_InterruptHandler)(void) = NULL;
static void (*INT1_InterruptHandler)(void) = NULL;
static void (*INT2_InterruptHandler)(void) = NULL;

static void (*RB4_InterruptHandler_HIGH)(void) = NULL;
static void (*RB4_InterruptHandler_LOW)(void) = NULL;
static void (*RB5_InterruptHandler_HIGH)(void) = NULL;
static void (*RB5_InterruptHandler_LOW)(void) = NULL;
static void (*RB6_InterruptHandler_HIGH)(void) = NULL;
static void (*RB6_InterruptHandler_LOW)(void) = NULL;
static void (*RB7_InterruptHandler_HIGH)(void) = NULL;
static void (*RB7_InterruptHandler_LOW)(void) = NULL;

static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj);

static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj);

static Std_ReturnType Interrupt_RBx_Enable(const interrupt_RBx_t *int_obj);
static Std_ReturnType Interrupt_RBx_Disable(const interrupt_RBx_t *int_obj);
static Std_ReturnType Interrupt_RBx_Priority_Init(const interrupt_RBx_t *int_obj);
static Std_ReturnType Interrupt_RBx_Pin_Init(const interrupt_RBx_t *int_obj);

/**
 * 
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_INTx_Init(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else
    {
        /* Disable the External Interrupt, INTx */
        Interrupt_INTx_Disable(int_obj);
        /* Clear Interrupt Flag  : External interrupt did not occur, INTx */
        ret &= Interrupt_INTx_Clear_Flag(int_obj);
        /* Configure External Interrupt edge, INTx */
        Interrupt_INTx_Edge_Init(int_obj);
        #if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        /* Configure External Interrupt Priority, INTx */
        ret &= Interrupt_INTx_Priority_Init(int_obj);
        #endif
        /* Configure External Interrupt I/O pin, INTx */
        ret &= Interrupt_INTx_Pin_Init(int_obj);        
        /* Configure Default Interrupt Callback, INTx */
        ret = Interrupt_INTx_SetInterruptHandler(int_obj);
        /* Enable the External Interrupt, INTx */
        ret &= Interrupt_INTx_Enable(int_obj);
    }
    return ret;
}

/**
 * 
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else
    {
        ret = Interrupt_INTx_Disable(int_obj);
    }
    return ret;
}

/**
 * 
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_RBx_Init(const interrupt_RBx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else
    {
        /* Disable the External Interrupt, RBx */
        EXT_RBx_InterruptDisable();
        /* Clear Interrupt Flag  : External interrupt did not occur, RBx */
        EXT_RBx_InterruptFlagClear();
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PeriorityLevelsEnable();
        if(INTERRUPT_LOW_PRIORITY == int_obj->priority){
            INTERRUPT_GlobalInterruptLowEnable();
            EXT_RBx_Low_Priority();
        }
        else if(INTERRUPT_HIGH_PRIORITY == int_obj->priority){
            INTERRUPT_GlobalInterruptHighEnable();
            EXT_RBx_High_Priority();
        }
        else{/* Nothing*/};
#else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
        /* Intilaze the BRx pin to be input, RBx */
        ret = gpio_pin_direction_intialize(&(int_obj->mcu_pin));
        /* Intilaze the call back functions, RBx*/
        switch(int_obj->mcu_pin.pin){
            case PIN4:
                RB4_InterruptHandler_HIGH = int_obj->InterruptHandler_HIGH ;
                RB4_InterruptHandler_LOW = int_obj->InterruptHandler_LOW ;
                break;
            case PIN5:
                RB5_InterruptHandler_HIGH = int_obj->InterruptHandler_HIGH ;
                RB5_InterruptHandler_LOW = int_obj->InterruptHandler_LOW ;
                break;
            case PIN6:
                RB6_InterruptHandler_HIGH = int_obj->InterruptHandler_HIGH ;
                RB6_InterruptHandler_LOW = int_obj->InterruptHandler_LOW ;
                break;
            case PIN7:
                RB7_InterruptHandler_HIGH = int_obj->InterruptHandler_HIGH ;
                RB7_InterruptHandler_LOW = int_obj->InterruptHandler_LOW ;
                break;
            default: ret = E_NOT_OK;  
        }
        EXT_RBx_InterruptEnable();
    }
    return ret;
}

/**
 * 
 * @param int_obj
 * @return 
 */
Std_ReturnType Interrupt_RBx_DeInit(const interrupt_RBx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else
    {
        /* Disable the External Interrupt, RBx */
        EXT_RBx_InterruptDisable();
        /* Clear Interrupt Flag  : External interrupt did not occur, RBx */
        EXT_RBx_InterruptFlagClear();
    }
    return ret;
}

/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0  :
                #if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PeriorityLevelsEnable();
                INTERRUPT_GlobalInterruptHighEnable();
                #else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
                #endif
         
                EXT_INT0_InterruptEnable();
                break;
            case INTERRUPT_EXTERNAL_INT1 :
                #if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PeriorityLevelsEnable();
                if(INTERRUPT_LOW_PRIORITY == int_obj->priority){INTERRUPT_GlobalInterruptLowEnable();}
                else if(INTERRUPT_HIGH_PRIORITY == int_obj->priority){INTERRUPT_GlobalInterruptHighEnable();}
                else{/* Nothing*/};
                #else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
                #endif
                EXT_INT1_InterruptEnable();
                break;
            case INTERRUPT_EXTERNAL_INT2 :
                #if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PeriorityLevelsEnable();
                if(INTERRUPT_LOW_PRIORITY == int_obj->priority){INTERRUPT_GlobalInterruptLowEnable();}
                else if(INTERRUPT_HIGH_PRIORITY == int_obj->priority){INTERRUPT_GlobalInterruptHighEnable();}
                else{/* Nothing*/};
                #else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
                #endif
                EXT_INT2_InterruptEnable();
                break;
            default : ret = E_NOT_OK ;
             
        }
    }
    return ret;
}

/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0 : EXT_INT0_InterruptDisable();ret = E_OK; break;
            case INTERRUPT_EXTERNAL_INT1 : EXT_INT1_InterruptDisable();ret = E_OK; break;
            case INTERRUPT_EXTERNAL_INT2 : EXT_INT2_InterruptDisable();ret = E_OK; break;
            default : ret = E_NOT_OK ;
             
        }
    }
    return ret;
}

/**
 * 
 * @param int_obj
 * @return 
 */
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
static Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0 : 
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1 : 
                if(INTERRUPT_LOW_PRIORITY == int_obj->priority){EXT_INT1_LowPrioritySet();}
                else if(INTERRUPT_HIGH_PRIORITY == int_obj->priority){EXT_INT1_HighPrioritySet();}
                else{/* Nothing*/};
                ret = E_OK;
                break;
                
            case INTERRUPT_EXTERNAL_INT2 : 
                if(INTERRUPT_LOW_PRIORITY == int_obj->priority){EXT_INT2_LowPrioritySet();}
                else if(INTERRUPT_HIGH_PRIORITY == int_obj->priority){EXT_INT2_HighPrioritySet();}
                else{/* Nothing*/};
                ret = E_OK;
                break;
                
            default : ret = E_NOT_OK ;
             
        }
    }
    return ret;
}
#endif
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0 : 
                if(INTERRUPT_FALLING_EDGE == int_obj->edge){EXT_INT0_FallingEdgeSet();}
                else if(INTERRUPT_RISING_EDGE == int_obj->edge){EXT_INT0_RisingEdgeSet();}
                else{/* Nothing*/};
                ret = E_OK;
                break;
            
            case INTERRUPT_EXTERNAL_INT1 : 
                if(INTERRUPT_FALLING_EDGE == int_obj->edge){EXT_INT1_FallingEdgeSet();}
                else if(INTERRUPT_RISING_EDGE == int_obj->edge){EXT_INT1_RisingEdgeSet();}
                else{/* Nothing*/};
                ret = E_OK;
                break;
                
            case INTERRUPT_EXTERNAL_INT2 : 
                if(INTERRUPT_FALLING_EDGE == int_obj->edge){EXT_INT2_FallingEdgeSet();}
                else if(INTERRUPT_RISING_EDGE == int_obj->edge){EXT_INT2_RisingEdgeSet();}
                else{/* Nothing*/};
                ret = E_OK;
                break;
                
            default : ret = E_NOT_OK ;
             
        }
    }
    return ret;
}

/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_direction_intialize(&(int_obj->mcu_pin));
    }
    return ret;
}
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0 : EXT_INT0_InterruptFlagClear();ret = E_OK; break;
            case INTERRUPT_EXTERNAL_INT1 : EXT_INT1_InterruptFlagClear();ret = E_OK; break;
            case INTERRUPT_EXTERNAL_INT2 : EXT_INT2_InterruptFlagClear();ret = E_OK; break;
            default : ret = E_NOT_OK ;
             
        }
    }
    return ret;
}

/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_RBx_Enable(const interrupt_RBx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else
    {
        EXT_RBx_InterruptEnable();
    }
    return ret;
}
/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_RBx_Disable(const interrupt_RBx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else
    {
        EXT_RBx_InterruptDisable();
    }
    return ret;
}

/**
 * 
 * @param int_obj
 * @return 
 */
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
static Std_ReturnType Interrupt_RBx_Priority_Init(const interrupt_RBx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->priority){
            case INTERRUPT_LOW_PRIORITY  : EXT_RBx_Low_Priority(); ret = E_OK ;break;
            case INTERRUPT_HIGH_PRIORITY :EXT_RBx_High_Priority(); ret = E_OK ;break;
            default : ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif

/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_RBx_Pin_Init(const interrupt_RBx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_direction_intialize(&(int_obj->mcu_pin));
    }
    return ret;
}

/**
 * 
 * @param InterruptHandler
 * @return 
 */
static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void)){
    Std_ReturnType ret = E_OK;
    if(NULL == InterruptHandler){
        ret = E_NOT_OK;
    }
    else
    {
        INT0_InterruptHandler = InterruptHandler;
    }
    return ret;
}

/**
 * 
 * @param InterruptHandler
 * @return 
 */
static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void)){
    Std_ReturnType ret = E_OK;
    if(NULL == InterruptHandler){
        ret = E_NOT_OK;
    }
    else
    {
        INT1_InterruptHandler = InterruptHandler;
    }
    return ret;
}

/**
 * 
 * @param InterruptHandler
 * @return 
 */
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void)){
    Std_ReturnType ret = E_OK;
    if(NULL == InterruptHandler){
        ret = E_NOT_OK;
    }
    else
    {
        INT2_InterruptHandler = InterruptHandler;
    }
    return ret;
    
}

/**
 * 
 * @param int_obj
 * @return 
 */
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj){
    Std_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0 : 
                ret = INT0_SetInterruptHandler(int_obj->InterruptHandler);
                break;
            
            case INTERRUPT_EXTERNAL_INT1 : 
                ret = INT1_SetInterruptHandler(int_obj->InterruptHandler);
                break;
                
            case INTERRUPT_EXTERNAL_INT2 : 
                ret = INT2_SetInterruptHandler(int_obj->InterruptHandler);
                break;
            default : ret = E_NOT_OK ;
             
        }
    }
    return ret;
    
}


void INT0_ISR(void){
    /* The INT0 external interrupt occurred (must be cleared in software) */
    EXT_INT0_InterruptFlagClear();
    /* Code run in MQAL Layer*/
    
    /* Callback function gets called every time this ISR executes */
    if(INT0_InterruptHandler){INT0_InterruptHandler();}
    else{/* Nothing */}
}

void INT1_ISR(void){
    /* The INT1 external interrupt occurred (must be cleared in software) */
    EXT_INT1_InterruptFlagClear();
    /* Code run in MQAL Layer*/
    
    /* Callback function gets called every time this ISR executes */
    if(INT1_InterruptHandler){INT1_InterruptHandler();}
    else{/* Nothing */}
}

void INT2_ISR(void){
    /* The INT2 external interrupt occurred (must be cleared in software) */
    EXT_INT2_InterruptFlagClear();
    /* Code run in MQAL Layer*/
    
    /* Callback function gets called every time this ISR executes */
    if(INT2_InterruptHandler){INT2_InterruptHandler();}
    else{/* Nothing */}
}

/* External interrupt RB4 MCAL Helper function */
void RB4_ISR(uint8 RB4_Source){
    /* The RB4 external interrupt occurred (must be cleared in software) */
    EXT_RBx_InterruptFlagClear();
    /* Code run in MQAL Layer*/
    
    /* Callback function gets called every time this ISR executes */
    if(0 == RB4_Source){
        if(RB4_InterruptHandler_LOW){RB4_InterruptHandler_LOW();}
        else{/* Nothing */}
    }
    else if(1 == RB4_Source){
        if(RB4_InterruptHandler_HIGH){RB4_InterruptHandler_HIGH();}
        else{/* Nothing */}
    }
    else{/* Nothing */}
}

/* External interrupt RB5 MCAL Helper function */
void RB5_ISR(uint8 RB5_Source){
    /* The RB4 external interrupt occurred (must be cleared in software) */
    EXT_RBx_InterruptFlagClear();
    /* Code run in MQAL Layer*/
    
    /* Callback function gets called every time this ISR executes */
    if(0 == RB5_Source){
        if(RB5_InterruptHandler_LOW){RB5_InterruptHandler_LOW();}
        else{/* Nothing */}
    }
    else if(1 == RB5_Source){
        if(RB5_InterruptHandler_HIGH){RB5_InterruptHandler_HIGH();}
        else{/* Nothing */}
    }
    else{/* Nothing */}
}

/* External interrupt RB6 MCAL Helper function */
void RB6_ISR(uint8 RB6_Source){
    /* The RB4 external interrupt occurred (must be cleared in software) */
    EXT_RBx_InterruptFlagClear();
    /* Code run in MQAL Layer*/
    
    /* Callback function gets called every time this ISR executes */
    if(0 == RB6_Source){
        if(RB6_InterruptHandler_LOW){RB6_InterruptHandler_LOW();}
        else{/* Nothing */}
    }
    else if(1 == RB6_Source){
        if(RB6_InterruptHandler_HIGH){RB6_InterruptHandler_HIGH();}
        else{/* Nothing */}
    }
    else{/* Nothing */}
}

/* External interrupt RB4 MCAL Helper function */
void RB7_ISR(uint8 RB7_Source){
    /* The RB4 external interrupt occurred (must be cleared in software) */
    EXT_RBx_InterruptFlagClear();
    /* Code run in MQAL Layer*/
    
    /* Callback function gets called every time this ISR executes */
    if(0 == RB7_Source){
        if(RB7_InterruptHandler_LOW){RB7_InterruptHandler_LOW();}
        else{/* Nothing */}
    }
    else if(1 == RB7_Source){
        if(RB7_InterruptHandler_HIGH){RB7_InterruptHandler_HIGH();}
        else{/* Nothing */}
    }
    else{/* Nothing */}
}