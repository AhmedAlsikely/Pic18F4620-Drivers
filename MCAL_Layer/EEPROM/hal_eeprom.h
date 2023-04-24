/* 
 * File:   hal_eeprom.h
 * Author: Alsikely
 *
 * Created on April 23, 2023, 3:30 PM
 */

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H

/* Section : Includes */
#include <pic18f4620.h>
#include "../mcal_std_types.h"
#include "../Interrupt/mcal_internal_interrupt.h"

/* Section : Macro Declarations */
/* Flash program or Data EEPROM Memory Select */
#define ACCESS_FLASH_PROGRAM_MEMORY        1U
#define ACCESS_EEPROM_PROGRAM_MEMORY       0U
/* Flash program/Data EEPROM or configration  Select */
#define ACCESS_CONFIGRATION_REGISTERS      1U
#define ACCESS_FLASH_EEPROM_MEMORY         0U
/* Flash program/Data EEPROM write Enable */
#define ALLOW_WRITE_CYCLES_FLASH_EEPROM    1U
#define INHIBTS_WRITE_CYCLES_FLASH_EEPROM  0U
/* Write Control */
#define INITIATE_DATA_EEPROM_WRITE_ERASE   1U
#define DATA_EEPROM_WRITE_ERASE_COMPLETED  0U
/* Read Control */
#define INITIATE_DATA_EEPROM_READ          1U
#define DATA_EEPROM_READ_COMPLETED         0U
/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */

/* Section : Functions Declarations */

Std_ReturnType Data_EEPROM_WriteByte(uint16 bAdd, uint8 bData);
Std_ReturnType Data_EEPROM_ReadByte(uint16 bAdd, uint8 *bData);


#endif	/* HAL_EEPROM_H */

