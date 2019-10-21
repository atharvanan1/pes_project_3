/**
 * @file    main.c
 * @brief   Application entry point.
 */
#include "main.h"
/* TODO: insert other include files here. */
logger logger_1 = {
		0,
		NULL,
		0,
		NULL,
		0,
};
logger* logger_instance = &logger_1;

uint32_t buffer_address[16];

uint8_t length = 0;
/* TODO: insert other definitions and declarations here. */
uint8_t get_length(uint32_t* address, uint8_t length_of_array);
void delay(void);
#if defined(KL25Z) || defined(KL25Z_LOG)
void init(void);
#endif
/*
 * @brief   Application entry point.
 */
int main(void) {

#if defined(KL25Z) || defined(KL25Z_LOG)
	init();
#endif

#if defined(KL25Z_LOG) || defined(PC_LOG)
	logger_enable();
#else
	logger_disable();
#endif

	uint32_t* base = NULL;
	uint8_t* data = NULL;
	uint32_t* address = NULL;
	size_t length = 16;
	int8_t seed = -45;
	uint8_t test_status = SUCCESS;
	volatile uint8_t status;

	// Starting the tests
	Turn_On_Only_LED(BLUE);
	base = allocate_words(length);

	status = write_pattern(base, length, seed);
	if(status == SUCCESS)
	{
		logger_instance->data = (uint32_t*) display_memory(base, 16);
		logger_instance->length = 16;
		log_data();
	}
	else
	{
		logger_instance->string = "Failed to write";
		log_string();
		test_status++;
	}

	address = verify_pattern(base, length, seed);
	if(address[0] == 0)
	{
		logger_instance->string = "Verifying Pattern - Successful verification";
		log_string();
	}
	else
	{
		logger_instance->string = "Verifying Pattern - Failure to verify";
		log_string();
		logger_instance->data = address;
		logger_instance->length = get_length(address, 16);
		log_address();
		test_status++;
	}

	write_memory(get_address(base, 7), 0xEE);
	write_memory(get_address(base, 8), 0xFF);

	logger_instance->data = (uint32_t*) display_memory(get_address(base, 7), 2);
	logger_instance->length = 2;
	log_data();

	address = verify_pattern(base, length, seed);
	if(address[0] == 0)
	{
		logger_instance->string = "Verifying Pattern - Successful verification";
		log_string();
		test_status++; //Since the verify pattern is supposed to fail
	}
	else
	{
		logger_instance->string = "Verifying Pattern - Failure to verify";
		log_string();
		logger_instance->data = address;
		logger_instance->length = get_length(address, length);
		log_address();
	}

	delay();
	if (test_status == SUCCESS)
	{
		Turn_On_Only_LED(GREEN);
	}
	else
	{
		Turn_On_Only_LED(RED);
	}
	free_words(base);
    return 0;
}


/* Function definitions */
uint8_t get_length(uint32_t* address, uint8_t length_of_array)
{
	uint8_t length = 0;
	for (uint8_t i = 0; i < length_of_array; i++)
	{
		if (*(address + i) != 0)
			length++;
	}
	return length;
}

void delay(void)
{
	volatile uint32_t i = 2300 * 3000;
	while(i != 0)
	{
		i--;
		__asm volatile ("nop");
	}
}

#if defined(KL25Z) || defined(KL25Z_LOG)
void init(void)
{
	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();
}
#endif