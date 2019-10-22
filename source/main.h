/**
  * File Name 		- main.h
  * Description 	- header file for main.c
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */


#ifndef MAIN_H_
#define MAIN_H_
#include <stdlib.h>
#include "common.h"
#if defined(KL25Z) || defined(KL25Z_LOG)
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#endif
#include "mem_test/allocate.h"
#include "mem_test/free.h"
#include "mem_test/pattern_write.h"
#include "mem_test/mem_write.h"
#include "mem_test/verify.h"
#include "mem_test/display.h"
#include "mem_test/get_addr.h"
#include "mem_test/invert.h"
#include "logger/logger.h"
#include "led_control/led_control.h"
#endif /* MAIN_H_ */
