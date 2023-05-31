/* 
 * File:   hal_SPI.c
 * Author: Alsikely
 *
 * Created on May 31, 2023, 11:56 AM
 */

#include "hal_SPI.h"

Std_ReturnType SPI_Init(const SPI_t *_spi){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _spi){
        ret = E_NOT_OK;
    }
    else{
        /*DIsable SPI MODULE*/
        SPI_DISABLE();
        /* Configure SPI GPIO Pins */
        TRISCbits.RC5 = 0;
        if(SPI_MASTER_MODE == _spi->spi_mode){
            TRISCbits.RC3 = 0;
            TRISAbits.RA5 = 0;
        }else if(SPI_SLAVE_MODE == _spi->spi_mode){
            TRISCbits.RC3 = 1;
            TRISAbits.RA5 = 1;
        }else{/*Nothing*/}
        /* Select Clock Polarity */
        SPI_CLOCK_POLARITY_CONFIG(_spi->clock_idle);
        /* Select Clock Phase */
        SPI_CLOCK_PHASE_CONFIG(_spi->clock_phase);
        /* Select Sampled master Mode */
        if(SPI_MASTER_MODE == _spi->spi_mode){
            SPI_MASTER_SAMPLED_DATA_CONFIG(_spi->sample_data);
        }else if(SPI_SLAVE_MODE == _spi->spi_mode){
            SPI_MASTER_SAMPLED_DATA_CONFIG(0);
        }else{/*Nothing*/}
        /* Select Master Clock Rate and Slave Mode*/
        if(SPI_MASTER_MODE == _spi->spi_mode){
            SPI_MASTER_CLOCK_RATE(_spi->master_clk_rate);
        }else if(SPI_SLAVE_MODE == _spi->spi_mode){
            SPI_SLAVE_MODE_SELECT(_spi->slave_mode);
        }else{/*Nothing*/}
        /*Enable SPI MODULE*/        
        SPI_ENABLE();
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType SPI_DeInit(const SPI_t *_spi){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _spi){
        ret = E_NOT_OK;
    }
    else{
        /*Enable SPI MODULE*/        
        SPI_ENABLE();
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType SPI_ReadByteBlocking(uint8 *_data){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }
    else{
        SSPBUF = 0x00; 
        while(!SSPSTATbits.BF); // Wait for the reception to complete
        *_data = SSPBUF;
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType SPI_ReadByteNonBlocking(uint8 *_data){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _data){
        ret = E_NOT_OK;
    }
    else{
        
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType SPI_WriteByteBlocking( uint8 _data){
    Std_ReturnType ret = E_NOT_OK;
    SSPBUF = _data; 
    while(!SSPSTATbits.BF);
    ret = E_OK;
}

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
