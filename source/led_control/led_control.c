/*
 * led_control.c
 *
 *  Created on: Oct 9, 2019
 *      Author: azzentys
 */
#include "led_control.h"
void Turn_On_Only_LED(uint8_t LED)
{
	char* LED_string = NULL;
#if defined(KL25Z) || defined(KL25Z_LOG)
	LED_RED_INIT(LOGIC_LED_OFF);
	LED_BLUE_INIT(LOGIC_LED_OFF);
	LED_GREEN_INIT(LOGIC_LED_OFF);
#endif
	if(LED == RED)
	{
		LED_string = "RED";
		printf("LED %s is ON\n\r", LED_string);
#if defined(KL25Z) || defined(KL25Z_LOG)
		LED_RED_ON();
		LED_GREEN_OFF();
		LED_BLUE_OFF();
#endif
	}
	else if (LED == BLUE)
	{
		LED_string = "BLUE";
		printf("LED %s is ON\n\r", LED_string);
#if defined(KL25Z) || defined(KL25Z_LOG)
		LED_RED_OFF();
		LED_GREEN_OFF();
		LED_BLUE_ON();
#endif

	}
	else if (LED == GREEN)
	{
		LED_string = "GREEN";
		printf("LED %s is ON\n\r", LED_string);
#if defined(KL25Z) || defined(KL25Z_LOG)
		LED_RED_OFF();
		LED_GREEN_ON();
		LED_BLUE_OFF();
#endif
	}
}
