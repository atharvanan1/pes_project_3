/**
  * File Name 		- verify.c
  * Description 	- contains function which verifies pattern and
  * 				  return defunct addresses
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */
#include "verify.h"

ARCH_SIZE * verify_pattern(uint32_t * loc, size_t length, int8_t seed)
{
	// For byte wise operations
	uint8_t* temp = (uint8_t*) loc;
	// global array to hold defunct addresses
	extern ARCH_SIZE buffer_address[16];
	// local array to hold pattern generator values
	uint8_t pattern_holder[length];
	pattern_generator(pattern_holder, length, seed);
	// i for looping through the length of pattern,
	// j for storing defunct addresses if any
	if(loc != NULL)
	{
		volatile uint8_t i, j = 0;
		for (i = 0; i < length; i++)
		{
			// If pattern matches
			if (*(temp + i) == pattern_holder[i])
			{
				continue;
			}
			// If pattern doesn't match
			else if (*(temp + i) != pattern_holder[i])
			{
				*(buffer_address + j) = (ARCH_SIZE) (temp + i);
				j++;
			}
		}
		// If verify pattern sucessful, empty buffer for extra
		// precautions
		if(j == 0)
		{
			for (i = 0; i < length; i++)
			{
				buffer_address[i] = 0;
			}
		}
		return buffer_address;
	}
	else
	{
		return NULL;
	}
}
