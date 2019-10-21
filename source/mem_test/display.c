/**
  * File Name 		- display.c
  * Description 	- returns a pointer which accesses bytes in the
  * 				  allocated memory
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */

#include "display.h"

uint8_t * display_memory(uint32_t *loc, size_t length)
{
	return (uint8_t*) loc;
}
