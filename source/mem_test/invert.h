/**
  * File Name 		- invert.h
  * Description 	- header file for invert.c
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */

#ifndef MEM_TEST_INVERT_H_
#define MEM_TEST_INVERT_H_
#include <stdlib.h>
#include <stdint.h>
#include "../common.h"
mem_status invert_block(uint32_t* loc, size_t length);
#endif /* MEM_TEST_INVERT_H_ */
