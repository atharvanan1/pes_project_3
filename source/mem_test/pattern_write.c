/*
 * pattern_write.c
 *
 *  Created on: Oct 9, 2019
 *      Author: azzentys
 */
#include "pattern_write.h"

mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed)
{
	if(loc == NULL)
	{
		return FAIL;
	}
	uint8_t* byte_array = (uint8_t *) loc;
	pattern_generator(byte_array, length, seed);
	return SUCCESS;
}
