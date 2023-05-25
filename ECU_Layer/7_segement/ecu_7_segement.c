/* 
 * File:   ecu_7_segement.c
 * Author: Alsikely
 *
 * Created on April 11, 2023, 11:11 PM
 */

#include "ecu_7_segement.h"


Std_ReturnType seven_segement_intialize(const seven_seg_t *_seg){
    Std_ReturnType ret = E_OK;
    if(NULL == _seg)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_intialize(&(_seg->sev_seg_pin[0]));
        ret = gpio_pin_intialize(&(_seg->sev_seg_pin[1]));
        ret = gpio_pin_intialize(&(_seg->sev_seg_pin[2]));
        ret = gpio_pin_intialize(&(_seg->sev_seg_pin[3]));
    }
    return ret;
}
Std_ReturnType seven_segement_write_number(const seven_seg_t *_seg , uint8 number){
    Std_ReturnType ret = E_OK;
    if(NULL == _seg || number >9)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(_seg->sev_seg_pin[0]),number & 0x01);
        ret = gpio_pin_write_logic(&(_seg->sev_seg_pin[1]),(number >> 1) & 0x01);
        ret = gpio_pin_write_logic(&(_seg->sev_seg_pin[2]),(number >> 2) & 0x01);
        ret = gpio_pin_write_logic(&(_seg->sev_seg_pin[3]),(number >> 3) & 0x01);
    }
    return ret;
}