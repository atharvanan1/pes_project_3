/*
 * common.h
 *
 *  Created on: Oct 12, 2019
 *      Author: azzentys
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
