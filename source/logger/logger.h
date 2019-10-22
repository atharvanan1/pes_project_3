/**
  * File Name 		- logger.h
  * Description 	- header file for logger.c
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */

#ifndef LOGGER_H_
#define LOGGER_H_
#include <stdio.h>
#include <stdint.h>
#include "common.h"
void logger_enable(void);
void logger_disable(void);
uint8_t logger_status(void);
void log_string(void);
void log_data(void);
void log_address(void);
void log_int(void);
extern logger* logger_instance;
#endif /* LOGGER_H_ */
