/**
  * File Name 		- pattern_write.c
  * Description 	- contains function which writes pattern from
  * 				  pattern generator into memory block
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
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
