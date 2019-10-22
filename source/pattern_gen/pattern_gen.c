/**
  * File Name 		- pattern_gen.c
  * Description 	- contains function generating pattern from a seed
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */


#include "pattern_gen.h"

void pattern_generator(uint8_t *pattern, uint8_t length, int8_t seed)
{
	volatile uint8_t i, j;
	// Random lookup table for calculations
	uint8_t lookup[15] = {17, 2, 32, 66, 1, 99, 30, 23, 53, 6, 14, 67, 59, 89, 48};
	uint8_t temporary[length];
	for (i = 0, j = 0; i < length; i++, j++)
	{
		// Random function to calculate random values
		temporary[i] = seed * seed + lookup[j] + (i % 13);
		// Lookup table operated circularly
		if (j == 14)
		{
			j = 0;
		}
	}
	for (i = 0; i < length; i++)
	{
		*(pattern + i) = temporary[i];
	}
}
