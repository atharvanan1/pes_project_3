/**
  * File Name 		- allocate.c
  * Description 	- builds C project
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
