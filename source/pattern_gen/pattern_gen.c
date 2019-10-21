/*
 * pattern_gen.c
 *
 *  Created on: Oct 9, 2019
 *      Author: azzentys
 */

#include "pattern_gen.h"

void pattern_generator(uint8_t *pattern, uint8_t length, int8_t seed)
{
	volatile uint8_t i, j;
	uint8_t lookup[15] = {17, 2, 32, 66, 1, 99, 30, 23, 53, 6, 14, 67, 59, 89, 48};
	uint8_t temporary[length];
	for (i = 0, j = 0; i < length; i++, j++)
	{
		temporary[i] = seed * seed + lookup[j] + (i % 13);
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
