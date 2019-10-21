/*
 * led_control.h
 *
 *  Created on: Oct 9, 2019
 *      Author: azzentys
 */

#ifndef LED_CONTROL_H_
#define LED_CONTROL_H_
#include <stdint.h>
#include "board.h"
#define RED 	0
#define BLUE  	1
#define GREEN  	2
void Turn_On_Only_LED(uint8_t LED_Macro);
#endif /* LED_CONTROL_H_ */
