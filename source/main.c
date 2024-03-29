/**
  * File Name 		- main.c
  * Description 	- contains main program sequence
  * Author			- Atharva Nandanwar
  * Tools			- GNU C Compiler / ARM Compiler Toolchain
  * Leveraged Code 	-
  * URL				-
  */

#include "main.h"

// Global Data types
logger logger_1 = {
		0,
		NULL,
		0,
		NULL,
		0,
};
logger* logger_instance = &logger_1;
ARCH_SIZE buffer_address[16];
uint8_t length = 0;

// Function declarations
uint8_t get_length(ARCH_SIZE* address, uint8_t length_of_array);
void delay(void);
#if defined(KL25Z) || defined(KL25Z_LOG)
void init(void);
#endif

// Start of main
int main(void)
{
// Board pins and peripherals initialization - KL25Z only
#if defined(KL25Z) || defined(KL25Z_LOG)
	init();
#endif

// Logger control
#if defined(KL25Z_LOG) || defined(PC_LOG)
	logger_enable();
#else
	logger_disable();
#endif

	uint32_t* base = NULL;
	ARCH_SIZE* address = NULL;
	size_t length = 16;
	int8_t seed = 74;
	uint8_t test_status = SUCCESS;
	volatile uint8_t status;

	// Starting the tests--------------------------------------------
	Turn_On_Only_LED(BLUE);
	// Memory allocation---------------------------------------------
	base = allocate_words(length);
	if(base == NULL)
	{
		logger_instance->string = "Failed to allocate memory";
		log_string();
		test_status++;
	}
	else
	{
		logger_instance->string = "Successful memory allocation";
		log_string();

	}


	// Writing pattern into allocated memory-------------------------
	status = write_pattern(base, length, seed);
	if(status == SUCCESS)
	{
		// Display the pattern
		logger_instance->data = (ARCH_SIZE*) display_memory(base, 16);
		logger_instance->length = 16;
		log_data();
	}
	else
	{
		logger_instance->string = "Failed to write";
		log_string();
		test_status++;
	}

	// Verifying the pattern-----------------------------------------
	address = verify_pattern(base, length, seed);
	if(address != NULL)
	{
		if(address[0] == 0) // Verification successful
		{
			logger_instance->string = "Verifying Pattern - Successful verification";
			log_string();
		}
		else
		{
			logger_instance->string = "Verifying Pattern - Failure to verify";
			log_string();
			logger_instance->data = address;
			logger_instance->length = get_length(address, length);
			log_address();
			test_status++; //Since the verify pattern is supposed to fail
		}
	}
	else
	{
		logger_instance->string = "Failed - Passed NULL";
		log_string();
		test_status++; //Since NULL means failure
	}

	// Write 0xEE into a memory region-------------------------------
	if(write_memory(get_address(base, 7), 0xEE))
	{
		logger_instance->string = "Failed to write at memory location";
		log_string();
	}
	else
	{
		logger_instance->string = "Failed to write at memory location";
		log_string();
	}
	// Write 0xFF into a memory region-------------------------------
	if(write_memory(get_address(base, 8), 0xFF))
	{
		logger_instance->string = "Failed to write at memory location";
		log_string();
	}
	else
	{
		logger_instance->string = "Failed to write at memory location";
		log_string();
	}


	// Display the pattern-------------------------------------------
	logger_instance->data = (ARCH_SIZE*) display_memory(get_address(base, 7), 2);
	logger_instance->length = 2;
	log_data();

	// Verifying the pattern-----------------------------------------
	address = verify_pattern(base, length, seed);
	if(address != NULL)
	{
		if(address[0] == 0) // Verification successful
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
	}
	else
	{
		logger_instance->string = "Verify Failed - Passed NULL";
		log_string();
		test_status++;
	}

	// Write the pattern---------------------------------------------
	status = write_pattern(base, length, seed);
	if(status == SUCCESS)
	{
		// Displaying the pattern
		logger_instance->data = (ARCH_SIZE*) display_memory(base, 16);
		logger_instance->length = 16;
		log_data();
	}
	else
	{
		logger_instance->string = "Failed to write";
		log_string();
		test_status++;
	}

	// Verifying the pattern-----------------------------------------
	address = verify_pattern(base, length, seed);
	if(address != NULL)
	{
		if(address[0] == 0) // Verification successful
		{
			logger_instance->string = "Verifying Pattern - Successful verification";
			log_string();
		}
		else
		{
			logger_instance->string = "Verifying Pattern - Failure to verify";
			log_string();
			logger_instance->data = address;
			logger_instance->length = get_length(address, length);
			log_address();
			test_status++; //Since the verify pattern is supposed to fail
		}
	}
	else
	{
		logger_instance->string = "Failed - Passed NULL";
		log_string();
		test_status++;
	}

	// Invert a block of memory--------------------------------------
	status = invert_block(get_address(base, 9), 4);
	if(status == SUCCESS)
	{
		// Display the pattern
		logger_instance->data = (ARCH_SIZE*) display_memory(get_address(base, 9), 16);
		logger_instance->length = 4;
		log_data();
	}
	else
	{
		logger_instance->string = "Failed to invert";
		log_string();
		test_status++;
	}

	// Verifying the pattern-----------------------------------------
	address = verify_pattern(base, length, seed);
	if(address != NULL)
	{
		if(address[0] == 0) // Verification successful
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
	}
	else
	{
		logger_instance->string = "Failed - Passed NULL";
		log_string();
		test_status++;
	}


	// Inverting a block of memory-----------------------------------
	status = invert_block(get_address(base, 9), 4);
	if(status == SUCCESS)
	{
		logger_instance->data = (ARCH_SIZE*) display_memory(get_address(base, 9), 16);
		logger_instance->length = 4;
		log_data();
	}
	else
	{
		logger_instance->string = "Failed to invert";
		log_string();
		test_status++;
	}

	// Verifying the pattern-----------------------------------------
	address = verify_pattern(base, length, seed);
	if(address != NULL)
	{
		if(address[0] == 0) // Verification successful
		{
			logger_instance->string = "Verifying Pattern - Successful verification";
			log_string();
		}
		else
		{
			logger_instance->string = "Verifying Pattern - Failure to verify";
			log_string();
			logger_instance->data = address;
			logger_instance->length = get_length(address, length);
			log_address();
			test_status++; //Since the verify pattern is supposed to fail
		}
	}
	else
	{
		logger_instance->string = "Failed - Passed NULL";
		log_string();
		test_status++;
	}

	// LED Test Status-----------------------------------------------
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
// To determine how many defunct addresses are present
uint8_t get_length(ARCH_SIZE* address, uint8_t length_of_array)
{
	uint8_t length = 0;
	for (uint8_t i = 0; i < length_of_array; i++)
	{
		if (*(address + i) != 0)
			length++;
	}
	return length;
}

// Just some minor delay
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
