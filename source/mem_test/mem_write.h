/*
 * mem_write.h
 *
 *  Created on: Oct 9, 2019
 *      Author: azzentys
 */

#ifndef MEM_TEST_MEM_WRITE_H_
#define MEM_TEST_MEM_WRITE_H_
#include <stdint.h>
#include <stdlib.h>
#include "../common.h"
mem_status write_memory(uint32_t* loc, uint8_t value);
#endif /* MEM_TEST_MEM_WRITE_H_ */
