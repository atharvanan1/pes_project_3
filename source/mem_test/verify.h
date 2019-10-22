/**
  * File Name 		- verify.h
  * Description 	- builds C project
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */

#ifndef MEM_TEST_VERIFY_H_
#define MEM_TEST_VERIFY_H_
#include <stdint.h>
#include <stdlib.h>
#include "pattern_gen/pattern_gen.h"
#include "common.h"
extern uint8_t length;
ARCH_SIZE * verify_pattern(uint32_t * loc, size_t length, int8_t seed);
#endif /* MEM_TEST_VERIFY_H_ */
