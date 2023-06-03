/* 
 * File:   hal_i2c.c
 * Author: Alsikely
 *
 * Created on June 3, 2023, 11:25 AM
 */
#include "hal_i2c.h"

Std_ReturnType MSSP_I2C_Init(const mssp_i2c_t *i2c_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == i2c_obj){
        ret = E_NOT_OK;
    }else
    {
        
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType MSSP_I2C_DeInit(const mssp_i2c_t *i2c_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == i2c_obj){
        ret = E_NOT_OK;
    }else
    {
        ret = E_OK;
    }
    return ret;
}


Std_ReturnType MSSP_I2C_Master_Send_Start(const mssp_i2c_t *i2c_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == i2c_obj){
        ret = E_NOT_OK;
    }else
    {
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType MSSP_I2C_Master_Send_Repeated_Start(const mssp_i2c_t *i2c_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == i2c_obj){
        ret = E_NOT_OK;
    }else
    {
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType MSSP_I2C_Master_Send_Stop(const mssp_i2c_t *i2c_obj){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == i2c_obj){
        ret = E_NOT_OK;
    }else
    {
        ret = E_OK;
    }
    return ret;
}


Std_ReturnType MSSP_I2C_Master_Write_Blocking(const mssp_i2c_t *i2c_obj, uint8 i2c_data, uint8 *_ack){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == i2c_obj || NULL == _ack){
        ret = E_NOT_OK;
    }else
    {
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType MSSP_I2C_Master_Read_Blocking(const mssp_i2c_t *i2c_obj, uint8 ack, uint8 *i2c_data){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == i2c_obj || NULL == i2c_data){
        ret = E_NOT_OK;
    }else
    {
        ret = E_OK;
    }
    return ret;
}


Std_ReturnType MSSP_I2C_Master_Write_NBlocking(const mssp_i2c_t *i2c_obj, uint8 i2c_data, uint8 *_ack){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == i2c_obj || NULL == _ack){
        ret = E_NOT_OK;
    }else
    {
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType MSSP_I2C_Master_Read_NBlocking(const mssp_i2c_t *i2c_obj, uint8 ack, uint8 *i2c_data){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == i2c_obj || NULL == i2c_data){
        ret = E_NOT_OK;
    }else
    {
        ret = E_OK;
    }
    return ret;
}
