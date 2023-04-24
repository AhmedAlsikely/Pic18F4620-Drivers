/* 
 * File:   hal_eeprom.c
 * Author: Alsikely
 *
 * Created on April 23, 2023, 3:30 PM
 */
#include "hal_eeprom.h"

Std_ReturnType Data_EEPROM_WriteByte(uint16 bAdd, uint8 bData){
    Std_ReturnType ret = E_OK;
    /* Read the Interrupt status "Enabled or Disabled" */
    uint8  Global_Interrupt_Status = INTCONbits.GIE;
    /* Updata the address Register */ 
    EEADRH = (uint8)((bAdd >> 8)&0x3);
    EEADR = (uint8)(bAdd &0xFF);
    /* Updata the Data Register */
    EEDATA = bData;
    /* Select Access Data EEPROM memory */
    EECON1bits.EEPGD = ACCESS_EEPROM_PROGRAM_MEMORY;
    EECON1bits.CFGS = ACCESS_FLASH_EEPROM_MEMORY;
    /* Allows Write Cycles to Flash program/data EEPROM */
    EECON1bits.WREN = ALLOW_WRITE_CYCLES_FLASH_EEPROM;
    /* Disable all interrupts "General Interrupt" */
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
    INTERRUPT_GlobalInterruptHighDisable();
#else
    INTERRUPT_GlobalInterruptDisable();
#endif 
    /* Write the required sequence :0x55 -> 0xAA */
    EECON2 = 0x55;
    EECON2 = 0xAA;
    /* Initiates a data EEPROM erase/write cycle */
    EECON1bits.WR = INITIATE_DATA_EEPROM_WRITE_ERASE;
    /* wait for write to complete */
    while(EECON1bits.WR);
    /* Inhibits write cycles to flash program/data EPPROM */
    EECON1bits.WREN = INHIBTS_WRITE_CYCLES_FLASH_EEPROM;
    /* Restore the Interrupt Status "Enabled or Disabled" */
    INTCONbits.GIE = Global_Interrupt_Status;
    return ret;
            
}
Std_ReturnType Data_EEPROM_ReadByte(uint16 bAdd, uint8 *bData){
    Std_ReturnType ret = E_OK;
    if(NULL == bData){
        ret = E_NOT_OK;
    }
    else
    {
        /* Updata the address Register */
        EEADRH = (uint8)((bAdd >> 8)&0x3);
        EEADR = (uint8)(bAdd &0xFF);
        /* Select Access data EEPROM Memory */
        EECON1bits.EEPGD = ACCESS_EEPROM_PROGRAM_MEMORY;
        EECON1bits.CFGS = ACCESS_FLASH_EEPROM_MEMORY;
        /* Initiates a data EEPROM read cycle */
        EECON1bits.RD = INITIATE_DATA_EEPROM_READ;
        NOP();
        NOP();
        /* Return data */
        *bData = EEDATA ;
    }
    return ret;
}