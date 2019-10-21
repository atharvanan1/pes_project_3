/*
 * led_control.h
 *
 *  Created on: Oct 9, 2019
 *      Author: azzentys
 */

#ifndef LED_CONTROL_H_
#define LED_CONTROL_H_
#include <stdio.h>
#include <stdint.h>
#if defined(KL25Z) || defined(KL25Z_LOG)
#include "board.h"
#endif
#define RED 	0
#define BLUE  	1
#define GREEN  	2
void Turn_On_Only_LED(uint8_t LED_Macro);
#endif /* LED_CONTROL_H_ */
