/**
  * File Name 		- logger.c
  * Description 	- contains logger functions
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */


#include "logger.h"

void logger_enable(void)
{
	logger_instance->status = 1;
	printf("Logger Instance - Logger ON-----------------\n\r");
}

void logger_disable(void)
{
	logger_instance->status = 0;
	printf("Logger Instance - Logger OFF-----------------\n\r");
}

uint8_t logger_status(void)
{
	return logger_instance->status;
}

void log_string(void)
{
	if(logger_instance -> status == 1)
	{
		printf("%s\n\r", logger_instance->string);
	}
}

// Used to print byte data from given memory address
void log_data(void)
{
	if(logger_instance -> status == 1)
	{
		if(logger_instance->data != NULL)
		{
			printf("Logger Instance - dumping data----------\n\r");
			uint8_t* temp = (uint8_t *) logger_instance->data;
			volatile uint8_t i;
			printf("Address      Data\n\r");
			for (i = 0; i < logger_instance->length; i++)
			{
				printf("%p - %#02x\n\r", (temp + i), *(temp + i));
			}
		}
		else
		{
			printf("Failed to log data - Passed NULL\n\r");
		}
	}
}

// Used to print addresses from given memory address
// Use case - verify pattern
void log_address(void)
{
	if(logger_instance -> status == 1)
	{
		printf("Logger Instance - defunct addresses----------\n\r");
		ARCH_SIZE* temp = logger_instance->data;
		volatile uint8_t i;
		printf("Addresses\n\r");
		for (i = 0; i < logger_instance->length; i++)
		{
			printf("%#lx\n\r", *(temp + i));
		}
	}
}

void log_int()
{
	if(logger_instance -> status == 1)
	{
		printf("Logger Instance - printing integer------\n\r");
		printf("%d\n\r", logger_instance->integer);
	}
}
