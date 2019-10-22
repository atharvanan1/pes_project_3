/**
  * File Name 		- pattern_write.h
  * Description 	- header file for pattern_write.c
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */

#ifndef MEM_TEST_PATTERN_WRITE_H_
#define MEM_TEST_PATTERN_WRITE_H_
#include <stdint.h>
#include <stdlib.h>
#include "../common.h"
#include "pattern_gen/pattern_gen.h"
mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed);
#endif /* MEM_TEST_PATTERN_WRITE_H_ */
