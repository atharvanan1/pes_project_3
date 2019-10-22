/**
  * File Name 		- mem_write.c
  * Description 	- contains function that writes individual bytes
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */

#include "mem_write.h"

mem_status write_memory(uint32_t* loc, uint8_t value)
{
	if (loc == NULL)
	{
		return FAIL;
	}
	// Writing into the individual byte
	uint8_t * temp = (uint8_t *) loc;
	*temp = value;
	return SUCCESS;
}
