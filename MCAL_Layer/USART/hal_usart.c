/* 
 * File:   hal_usart.c
 * Author: Alsikely
 *
 * Created on May 28, 2023, 1:18 PM
 */

#include "hal_usart.h"


#if INTERRUPT_FEATURE_ENABLE == EUSART_TX_INTERRUPT_FEATURE_ENABLE
static void (* EUSART_Tx_InterruptHandler)(void) = NULL;
#endif
#if INTERRUPT_FEATURE_ENABLE == EUSART_RX_INTERRUPT_FEATURE_ENABLE
static void (* EUSART_Rx_InterruptHandler)(void) = NULL;
static void (* EUSART_FramingErrorHandler)(void) = NULL;
static void (* EUSART_OverrunErrorHandler)(void) = NULL;
#endif
static void EUSART_Baud_Rate_Calculation(const usart_t *_eusart);
static void EUSART_ASYNC_TX_Init(const usart_t *_eusart);
static void EUSART_ASYNC_RX_Init(const usart_t *_eusart);
/**
 * 
 * @param _eusart
 * @return 
 */
Std_ReturnType EUSART_ASYNC_Init(const usart_t *_eusart){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _eusart){
        ret = E_NOT_OK;
    }else{
        /* Disable EUSART Module */
        RCSTAbits.SPEN = EUSART_MODULE_DISABLE;
        TRISCbits.RC7 = 1;
        TRISCbits.RC6 = 1;
        EUSART_Baud_Rate_Calculation(_eusart);
        EUSART_ASYNC_TX_Init(_eusart);
        EUSART_ASYNC_RX_Init(_eusart);       
        RCSTAbits.SPEN = EUSART_MODULE_ENABLE;
        ret = E_OK;
    }
    return ret;
}

/**
 * 
 * @param _eusart
 * @return 
 */
Std_ReturnType EUSART_ASYNC_DeInit(const usart_t *_eusart){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _eusart){
        ret = E_NOT_OK;
    }else{
        RCSTAbits.SPEN = EUSART_MODULE_DISABLE;
        ret = E_OK;
    }
    return ret;
}

/**
 * /
 * @param _eusart
 * @param _data
 * @return 
 */
Std_ReturnType EUSART_ASYNC_ReadByteBlocking(uint8 *_data){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }else{
        while(!PIR1bits.RCIF);
        *_data = RCREG ;
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType EUSART_ASYNC_ReadByteNonBlocking(uint8 *_data){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }else{
        if(PIR1bits.RCIF)
        {
            *_data = RCREG ;
            ret = E_OK;
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 *  
 * @param _eusart
 * @param _data
 * @return 
 */
Std_ReturnType EUSART_ASYNC_WriteByteBlocking(uint8 _data){
    Std_ReturnType ret = E_NOT_OK;
        while(!TXSTAbits.TRMT);
#if INTERRUPT_FEATURE_ENABLE == EUSART_TX_INTERRUPT_FEATURE_ENABLE
        EUSART_TX_InterruptEnable();
#endif
        TXREG = _data;
        ret = E_OK;
    return ret;
}

Std_ReturnType EUSART_ASYNC_WriteStringBlocking( uint8 *_data){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }else{
        while(*_data){
            EUSART_ASYNC_WriteByteBlocking(*_data);
            _data++;
        }
        ret = E_OK;
    }
    return ret;
}

static void EUSART_Baud_Rate_Calculation(const usart_t *_eusart){
    float Baud_Rate_Temp = 0;
    switch(_eusart->baudrate_gen_cfg){
        case BAUDRATE_ASYN_8BIT_LOW_SPEED :  
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16 = EUSART_8BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ/(float)_eusart->baudrate)/64)-1;
            break;
        case BAUDRATE_ASYN_8BIT_HIGH_SPEED :  
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            BAUDCONbits.BRG16 = EUSART_8BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ/(float)_eusart->baudrate)/16)-1;
            break; 
        case BAUDRATE_ASYN_16BIT_LOW_SPEED :  
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ/(float)_eusart->baudrate)/16)-1;
            break; 
        case BAUDRATE_ASYN_16BIT_HIGH_SPEED :  
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ/(float)_eusart->baudrate)/4)-1;
            break;
        case BAUDRATE_SYN_8BIT :  
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16 = EUSART_8BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ/(float)_eusart->baudrate)/4)-1;
            break; 
        case BAUDRATE_SYN_16BIT :  
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ/(float)_eusart->baudrate)/4)-1;
            break; 
        default : ;
    }
    SPBRG  = (uint8)((uint32)Baud_Rate_Temp); 
    SPBRGH = (uint8)((uint32)Baud_Rate_Temp >> 8);
}

static void EUSART_ASYNC_TX_Init(const usart_t *_eusart){
    if( EUSART_ASYNCHRONOUS_TX_ENABLE == _eusart->usart_tx_cfg.usart_tx_enable){
        /* EUSART TX Enable */
        EUSART_ASYNC_TX_ENABLE_DISABLE_CFG(EUSART_ASYNCHRONOUS_TX_ENABLE);
        /* EUSART TX 9-Bit  Configure Enable / Disable*/
        EUSART_ASYNC_9BIT_TX_CFG(_eusart->usart_tx_cfg.usart_tx_9bit_enable);
        /* EUSART TX interrupt configuration Enable / Disable */
#if INTERRUPT_FEATURE_ENABLE == EUSART_TX_INTERRUPT_FEATURE_ENABLE
        EUSART_ASYNC_INTERRUPT_TX_CFG(_eusart->usart_tx_cfg.usart_tx_interrupt_enable);
        EUSART_Tx_InterruptHandler = _eusart->EUSART_TxDefailtInterruptHandler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PeriorityLevelsEnable();
        if(INTERRUPT_HIGH_PRIORITY == _eusart->usart_tx_cfg.usart_tx_priority){
            INTERRUPT_GlobalInterruptHighEnable();
            EUSART_TX_HighPrioritySet();
        }else if(INTERRUPT_LOW_PRIORITY == _eusart->usart_tx_cfg.usart_tx_priority){
            INTERRUPT_GlobalInterruptLowEnable();
            EUSART_TX_LowPrioritySet();
        }else{/*NoThing*/}
#else 
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
    }else{}
}
static void EUSART_ASYNC_RX_Init(const usart_t *_eusart){
    if( EUSART_ASYNCHRONOUS_RX_ENABLE == _eusart->usart_rx_cfg.usart_rx_enable)
    {
        /* EUSART RX Enable */
        EUSART_ASYNC_RX_ENABLE_DISABLE_CFG(EUSART_ASYNCHRONOUS_RX_ENABLE);
        /* EUSART RX 9-Bit  Configure Enable / Disable*/
        EUSART_ASYNC_9BIT_RX_CFG(_eusart->usart_rx_cfg.usart_rx_9bit_enable);
        /* EUSART RX interrupt configuration Enable / Disable*/
#if INTERRUPT_FEATURE_ENABLE == EUSART_RX_INTERRUPT_FEATURE_ENABLE        
        EUSART_ASYNC_INTERRUPT_RX_ENABLE(_eusart->usart_rx_cfg.usart_rx_interrupt_enable);
        EUSART_Rx_InterruptHandler = _eusart->EUSART_RxDefailtInterruptHandler;
        EUSART_FramingErrorHandler = _eusart->EUSART_FramingErrorHandler;
        EUSART_OverrunErrorHandler = _eusart->EUSART_OverrunErrorHandler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PeriorityLevelsEnable();
        if(INTERRUPT_HIGH_PRIORITY == _eusart->usart_rx_cfg.usart_rx_priority){
            INTERRUPT_GlobalInterruptHighEnable();
            EUSART_RX_HighPrioritySet();
        }else if(INTERRUPT_LOW_PRIORITY == _eusart->usart_rx_cfg.usart_rx_priority){
            INTERRUPT_GlobalInterruptLowEnable();
            EUSART_RX_LowPrioritySet();
        }else{/*NoThing*/}
#else 
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif        
    }else{}
}

#if INTERRUPT_FEATURE_ENABLE == EUSART_TX_INTERRUPT_FEATURE_ENABLE 
void EUSART_TX_ISR(void){
    EUSART_TX_InterruptDisable();
    if(EUSART_Tx_InterruptHandler){
        EUSART_Tx_InterruptHandler();
    }
}
#endif
#if INTERRUPT_FEATURE_ENABLE == EUSART_RX_INTERRUPT_FEATURE_ENABLE 
void EUSART_RX_ISR(void){
    
    if(EUSART_Rx_InterruptHandler){
        EUSART_Rx_InterruptHandler();
    }else{/*Nothing*/}
    if(EUSART_FramingErrorHandler){
        EUSART_FramingErrorHandler();
    }else{/*Nothing*/}
    if(EUSART_OverrunErrorHandler){
        EUSART_OverrunErrorHandler();
    }else{/*Nothing*/}
}
#endif