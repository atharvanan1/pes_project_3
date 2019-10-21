/*
 * logger.c
 *
 *  Created on: Oct 9, 2019
 *      Author: azzentys
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

void log_data(void)
{
	if(logger_instance -> status == 1)
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
}

void log_address(void)
{
	if(logger_instance -> status == 1)
	{
		printf("Logger Instance - defunct addresses----------\n\r");
		uint32_t* temp = logger_instance->data;
		volatile uint8_t i;
		printf("Addresses\n\r");
		for (i = 0; i < logger_instance->length; i++)
		{
			printf("%#p\n\r", *(temp + i));
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
