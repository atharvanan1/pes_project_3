/**
  * File Name 		- invert.c
  * Description 	- contains function which inverts a block of memory
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
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
	// Going byte by byte
	for (i = 0; i < length; i++)
	{
		// XOR to invert the memory
		*(temp + i) ^= 0xFF;
	}
	return SUCCESS;
}
