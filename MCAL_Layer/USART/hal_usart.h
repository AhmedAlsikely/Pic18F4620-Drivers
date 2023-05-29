/* 
 * File:   hal_usart.h
 * Author: Alsikely
 *
 * Created on May 28, 2023, 1:18 PM
 */

#ifndef HAL_USART_H
#define	HAL_USART_H

/*---------------------- Section : Includes ----------------------*/
#include "pic18f4620.h"
#include "../mcal_std_types.h"
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_interrupt.h"

#include "hal_usart_cfg.h"
/*---------------------- Section : Macro Declarations------------ */
/* Enable / Disable EUSART Module */
#define EUSART_MODULE_ENABLE                           1
#define EUSART_MODULE_DISABLE                          0
/* Selecting EUSART Working Mode*/
#define EUSART_SYNCHRONOUS_MODE                        1
#define EUSART_ASYNCHRONOUS_MODE                       0
/* Baud Rate Generator Asynchronous Speed Mode*/
#define EUSART_ASYNCHRONOUS_HIGH_SPEED                 1
#define EUSART_ASYNCHRONOUS_LOW_SPEED                  0
/* Baud Rate Generator Register Size*/
#define EUSART_16BIT_BAUDRATE_GEN                      1
#define EUSART_8BIT_BAUDRATE_GEN                       0
/* EUSART Transmit Enable */
#define EUSART_ASYNCHRONOUS_TX_ENABLE                  1
#define EUSART_ASYNCHRONOUS_TX_DISABLE                 0
/* EUSART Transmit Interrupt Enable */
#define EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE        1
#define EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE       0
/* EUSART 9-Bit Transmit Enable*/
#define EUSART_ASYNCHRONOUS_9BIT_TX_ENABLE             1
#define EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE            0
/* EUSART Receiver Enable */
#define EUSART_ASYNCHRONOUS_RX_ENABLE                  1
#define EUSART_ASYNCHRONOUS_RX_DISABLE                 0
/* EUSART Receiver Interrupt Enable */
#define EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE        1
#define EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE       0
/* EUSART 9-Bit Receiver Enable*/
#define EUSART_ASYNCHRONOUS_9BIT_RX_ENABLE             1
#define EUSART_ASYNCHRONOUS_9BIT_RX_DISABLE            0
/* EUSART Framing Error */
#define EUSART_FRAMING_ERROR_DETECTED                  1
#define EUSART_FRAMING_ERROR_CLEARED                   0 
/* EUSART Overrun Error */
#define EUSART_OVERRUN_ERROR_DETECTED                  1
#define EUSART_OVERRUN_ERROR_CLEARED                   0
/*---------------------- Section : Macro Functions Declarations --*/

/* EUSART TX Enable / Disable */
#define EUSART_ASYNC_TX_ENABLE_DISABLE_CFG(_cfg)(TXSTAbits.TXEN = _cfg)
/* EUSART TX interrupt configuration Enable / Disable */
#define EUSART_ASYNC_INTERRUPT_TX_CFG(_cfg)     (PIE1bits.TXIE = _cfg)
/* EUSART TX 9-Bit  Configure Enable / Disable*/
#define EUSART_ASYNC_9BIT_TX_CFG(_cfg)          (TXSTAbits.TX9 = _cfg)
/* EUSART TX interrupt configuration Enable / Disable */
#define EUSART_ASYNC_INTERRUPT_TX_CFG(_cfg)     (PIE1bits.TXIE = _cfg)

/* EUSART RX Enable / Disable */
#define EUSART_ASYNC_RX_ENABLE_DISABLE_CFG(_cfg)(RCSTAbits.CREN = _cfg)
/* EUSART RX interrupt configuration Enable / Disable*/
#define EUSART_ASYNC_INTERRUPT_RX_ENABLE(_cfg)  (PIE1bits.RCIE = _cfg)
/* EUSART RX 9-Bit  Configure Enable / Disable*/
#define EUSART_ASYNC_9BIT_RX_CFG(_cfg)          (RCSTAbits.RX9 = _cfg)

/*---------------------- Section : Data Type Declarations --------*/
typedef enum{
    BAUDRATE_ASYN_8BIT_LOW_SPEED = 0,
    BAUDRATE_ASYN_8BIT_HIGH_SPEED,
    BAUDRATE_ASYN_16BIT_LOW_SPEED,
    BAUDRATE_ASYN_16BIT_HIGH_SPEED,
    BAUDRATE_SYN_8BIT,
    BAUDRATE_SYN_16BIT
}baudrate_gen_t;

typedef struct{
    interrupt_priority_cfg usart_tx_priority ; 
    
    uint8 usart_tx_enable :1;
    uint8 usart_tx_interrupt_enable :1;
    uint8 usart_tx_9bit_enable :1;
    uint8 usart_tx_reserved :4;
}usart_tx_cfg_t;

typedef struct{
    uint8 usart_rx_priority;
    
    uint8 usart_rx_enable :1;
    uint8 usart_rx_interrupt_enable :1;
    uint8 usart_rx_9bit_enable :1;
    uint8 usart_rx_reserved :4;
}usart_rx_cfg_t;

typedef union{
    struct{
        uint8 usart_tx_reserved :6;
        uint8 usart_ferr:1;
        uint8 usart_oerr;
    };
    uint8 status;
}usart_error_status_t;

typedef struct{
    uint32 baudrate;
    baudrate_gen_t baudrate_gen_cfg;
    usart_tx_cfg_t usart_tx_cfg;
    usart_rx_cfg_t usart_rx_cfg;
    usart_error_status_t error_status;
    void (* EUSART_TxDefailtInterruptHandler)(void);
    void (* EUSART_RxDefailtInterruptHandler)(void);
    void (* EUSART_FramingErrorHandler)(void);
    void (* EUSART_OverrunErrorHandler)(void);
}usart_t;
/*---------------------- Section : Software Interfaces -----------*/
Std_ReturnType EUSART_ASYNC_Init(const usart_t *_eusart);
Std_ReturnType EUSART_ASYNC_DeInit(const usart_t *_eusart);
Std_ReturnType EUSART_ASYNC_ReadByteBlocking(uint8 *_data);
Std_ReturnType EUSART_ASYNC_ReadByteNonBlocking(uint8 *_data);
Std_ReturnType EUSART_ASYNC_WriteByteBlocking( uint8 _data);
Std_ReturnType EUSART_ASYNC_WriteStringBlocking( uint8 *_data);

#endif	/* HAL_USART_H */

