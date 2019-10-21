/**
  * File Name 		- free.c
  * Description 	- header file for free.c
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */

#include "free.h"

void free_words(uint32_t* src)
{
	free(src);
}

