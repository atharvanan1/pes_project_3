/**
  * File Name 		- allocate.c
  * Description 	- contains function which allocates memory
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */

#include "allocate.h"

uint32_t * allocate_words(size_t length)
{
	uint32_t * p = (uint32_t *)malloc(length);
	return p;
}
