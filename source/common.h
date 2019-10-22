/**
  * File Name 		- common.h
  * Description 	- common header file with global data structures
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */


#ifndef COMMON_H_
#define COMMON_H_
#include <stdint.h>
typedef enum mem_status
{
	SUCCESS = 0,
	FAIL,
	OUT_OF_MEMORY
} mem_status;

typedef struct logger{
	uint8_t status;
	char* string;
	uint32_t integer;
	ARCH_SIZE * data;
	size_t length;
}logger;
#endif /* COMMON_H_ */
