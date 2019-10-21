/*
 * invert.c
 *
 *  Created on: Oct 9, 2019
 *      Author: azzentys
 */

#include "invert.h"

mem_status invert_block(uint32_t* loc, size_t length)
{
	if (loc == NULL)
	{
		return FAIL;
	}
	uint8_t* temp = (uint8_t*) loc;
	volatile uint8_t i;
	for (i = 0; i < length; i++)
	{
		*(temp + i) ^= 0xFF;
	}
	return SUCCESS;
}
