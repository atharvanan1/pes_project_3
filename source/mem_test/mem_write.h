/**
  * File Name 		- mem_write.h
  * Description 	- header file for mem_write.c
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */

#ifndef MEM_TEST_MEM_WRITE_H_
#define MEM_TEST_MEM_WRITE_H_
#include <stdint.h>
#include <stdlib.h>
#include "../common.h"
mem_status write_memory(uint32_t* loc, uint8_t value);
#endif /* MEM_TEST_MEM_WRITE_H_ */
