/*
 * mem_write.c
 *
 *  Created on: Oct 9, 2019
 *      Author: azzentys
 */
#include "mem_write.h"

mem_status write_memory(uint32_t* loc, uint8_t value)
{
	if (loc == NULL)
	{
		return FAIL;
	}
	uint8_t * temp = (uint8_t *) loc;
	*temp = value;
	return SUCCESS;
}
