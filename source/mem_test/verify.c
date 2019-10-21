/**
  * File Name 		- verify.c
  * Description 	- builds C project
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */
#include "verify.h"
uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed)
{
	uint8_t* temp = (uint8_t*) loc;
	extern uint32_t buffer_address[16];
	uint8_t pattern_holder[length];
	pattern_generator(pattern_holder, length, seed);
	volatile uint8_t i, j = 0;
	for (i = 0; i < length; i++)
	{
		if (*(temp + i) == pattern_holder[i])
		{
			continue;
		}
		else if (*(temp + i) != pattern_holder[i])
		{
			*(buffer_address + j) = (uint64_t) (temp + i);
			j++;
		}
	}
	if(j == 0)
	{
		for (i = 0; i < length; i++)
		{
			buffer_address[i] = 0;
		}
	}
	return buffer_address;
}
