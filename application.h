/* 
 * File:   application.h
 * Author: Alsikely
 *
 * Created on April 8, 2023, 2:20 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H


/* Section : Includes */

#include "ECU_Layer/ecu_layer_init.h"

/* Section : Macro Declarations */
#define _XTAL_FREQ 8000000UL
/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */

/* Section : Functions Declarations */
void app_initialize(void);
//void ecu_layer_intialize(void);

#endif	/* APPLICATION_H */

