/* 
 * File:   hal_SPI.c
 * Author: Alsikely
 *
 * Created on May 31, 2023, 11:56 AM
 */

#include "hal_SPI.h"

#if INTERRUPT_FEATURE_ENABLE == MSSP_SPI_INTERRUPT_FEATURE_ENABLE  
static void(* SPI_InterruotHandler)(void) = NULL;
static void config_interrupt(const SPI_Slave_t *_spi);
#endif

/**
 * 
 * @param _spi
 * @return 
 */
Std_ReturnType SPI_Init_Master(const SPI_Master_t *_spi){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _spi){
        ret = E_NOT_OK;
    }
    else{
        /*DIsable SPI MODULE*/
        SPI_DISABLE();
        /* Configure SPI GPIO Pins */
        TRISCbits.RC4 = 1;	/* RC4 as input(SDI) */
        TRISCbits.RC3 = 0;	/* RC3 as output(SCK) */
        TRISAbits.RA5 = 0;	/* RA5 as output(SS') */
        TRISCbits.RC5 = 0;	/* RC5 as output(SDO) */
        /* Interrupt Configure */
#if INTERRUPT_FEATURE_ENABLE == MSSP_SPI_INTERRUPT_FEATURE_ENABLE 
        config_interrupt(_spi);
#endif
        /* Select Clock Polarity */
        SPI_CLOCK_POLARITY_CONFIG(_spi->clock_idle);
        /* Select Clock Phase */
        SPI_CLOCK_PHASE_CONFIG(_spi->clock_phase);
        /* Select Sampled master Mode */
        SPI_MASTER_SAMPLED_DATA_CONFIG(_spi->sample_data);
        /* Select Master Clock Rate and Slave Mode*/
        SPI_MASTER_CLOCK_RATE(_spi->master_clk_rate);
        /*Enable SPI MODULE*/        
        SPI_ENABLE();
        ret = E_OK;
    }
    return ret;
}

/**
 * 
 * @param _spi
 * @return 
 */
Std_ReturnType SPI_Init_Slave(const SPI_Slave_t *_spi){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _spi){
        ret = E_NOT_OK;
    }
    else{
        /*DIsable SPI MODULE*/
        SPI_DISABLE();
        /* Configure SPI GPIO Pins */
        TRISCbits.RC4 = 1;	/* RC4 as input(SDI) */
        TRISCbits.RC3 = 1;	/* RC3 as input(SCK) */
        TRISAbits.RA5 = 1;	/* RA5 as input(SS') */
        TRISCbits.RC5 = 0;	/* RC5 as output(SDO) */
        /* Interrupt Configure */
#if INTERRUPT_FEATURE_ENABLE == MSSP_SPI_INTERRUPT_FEATURE_ENABLE 
        config_interrupt(_spi);
#endif
        /* Select Clock Polarity */
        SPI_CLOCK_POLARITY_CONFIG(_spi->clock_idle);
        /* Select Clock Phase */
        SPI_CLOCK_PHASE_CONFIG(_spi->clock_phase);
        /* configure SMP Bit */
        SPI_MASTER_SAMPLED_DATA_CONFIG(0);
        /* Select Slave Mode */
        SPI_SLAVE_MODE_SELECT(_spi->slave_mode);
        /*Enable SPI MODULE*/        
        SPI_ENABLE();
        ret = E_OK;
    }
    return ret;
}
/**
 * 
 * @param _spi
 * @return 
 */
Std_ReturnType SPI_DeInit_Master(const SPI_Master_t *_spi){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _spi){
        ret = E_NOT_OK;
    }
    else{
        /*Enable SPI MODULE*/        
        SPI_ENABLE();
        /* Disable Interrupt */
#if INTERRUPT_FEATURE_ENABLE == MSSP_SPI_INTERRUPT_FEATURE_ENABLE
        MSSP_SPI_InterruptDisable()
#endif
        ret = E_OK;
    }
    return ret;
}
/**
 * 
 * @param _spi
 * @return 
 */
Std_ReturnType SPI_DeInit_Slave(const SPI_Slave_t *_spi){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _spi){
        ret = E_NOT_OK;
    }
    else{
        /*Enable SPI MODULE*/        
        SPI_ENABLE();
        /* Disable Interrupt */
#if INTERRUPT_FEATURE_ENABLE == MSSP_SPI_INTERRUPT_FEATURE_ENABLE
        MSSP_SPI_InterruptDisable()
#endif
        ret = E_OK;
    }
    return ret;
}
/**
 * 
 * @param _data
 * @return 
 */
Std_ReturnType SPI_ReadByteBlocking(uint8 *_data){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }
    else{
        //SSPBUF = 0x00; 
        while(!SSPSTATbits.BF); // Wait for the reception to complete
        *_data = SSPBUF;
        ret = E_OK;
    }
    return ret;
}
/**
 * 
 * @param _data
 * @return 
 */
Std_ReturnType SPI_ReadByteNonBlocking(uint8 *_data){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }
    else{
        if(PIR1bits.SSPIF)
        {
            *_data = SSPBUF;
            PIR1bits.SSPIF = 0;
            ret = E_OK;
        }else{
        ret = E_NOT_OK;
        }
    }
    return ret;
}
/**
 * 
 * @param _data
 * @return 
 */
Std_ReturnType SPI_WriteByteBlocking( uint8 _data){
    Std_ReturnType ret = E_NOT_OK;
    uint8 buff_removed = 0;
    SSPBUF = _data; 
    while(!SSPSTATbits.BF);
    PIR1bits.SSPIF = 0;
    buff_removed = SSPBUF;
    ret = E_OK;
}
/**
 * 
 * @param _data
 * @return 
 */
Std_ReturnType SPI_WriteByte_NotBlocking( uint8 _data){
    Std_ReturnType ret = E_NOT_OK;
    
    if(1 == SSPSTATbits.BF || PIR1bits.SSPIF == 0){
        PIR1bits.SSPIF = 0;
        SSPBUF = _data;
    }
    ret = E_OK;
}

/**
 * 
 * @param _data
 * @return 
 */
Std_ReturnType SPI_WriteStringBlocking( uint8 *_data){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }
    else{
        while(*_data){
            SPI_WriteByteBlocking(*_data);
            _data++;
        }
        ret = E_OK;
    }
    return ret;
}

/**
 * 
 * @param _data
 * @return 
 */
Std_ReturnType SPI_WriteStringNotBlocking( uint8 *_data){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }
    else{
        while(*_data){
            SPI_WriteByte_NotBlocking(*_data);
            _data++;
        }
        ret = E_OK;
    }
    return ret;
}

#if INTERRUPT_FEATURE_ENABLE == MSSP_SPI_INTERRUPT_FEATURE_ENABLE  
void SPI_ISR(void){
   
    if(SPI_InterruotHandler){
        SPI_InterruotHandler();
    }
}
#endif


#if INTERRUPT_FEATURE_ENABLE == MSSP_SPI_INTERRUPT_FEATURE_ENABLE
static void config_interrupt(const SPI_Slave_t *_spi){
    MSSP_SPI_InterruptEnable();
    SPI_InterruotHandler = _spi->SPI_DefailtInterruptHandler;
    #if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PeriorityLevelsEnable();
        if(INTERRUPT_HIGH_PRIORITY == _spi->SPI_priority){
            INTERRUPT_GlobalInterruptHighEnable();
            MSSP_SPI_HighPrioritySet();
        }else if(INTERRUPT_LOW_PRIORITY == _spi->SPI_priority){
            INTERRUPT_GlobalInterruptLowEnable();
            MSSP_SPI_LowPrioritySet();
        }else{/*NoThing*/}
#else 
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
}
#endif