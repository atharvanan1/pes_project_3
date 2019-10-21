/**
  * File Name 		- get_addr.c
  * Description 	- contains get_address functions which gives address
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */
#include "get_addr.h"

uint32_t* get_address(uint32_t* base, uint16_t offset)
{
    uint8_t* temp = (uint8_t*) base;
    base = (uint32_t*)(temp + offset);
    return base;
}
