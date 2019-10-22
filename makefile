# Makefile for Memory Test Project
# Author : Atharva Nandanwar
# Date: 10/20/2019

#####################################################################
# Build Variables
# Program for removing files
RM := rm -rf
# Program for making directories
MK := mkdir -p

# PC compiler
PC_CC := gcc

# PC linker
PC_LL := gcc

# ARM compiler
ARM_CC := arm-none-eabi-gcc

# ARM linker
ARM_LL := arm-none-eabi-gcc

# PC_FLAGS
PC_FLAGS := -c -Wall -Werror -g -DARCH_SIZE=uint64_t

# ARM_FLAGS
ARM_FLAGS := -c \
			 -std=c99 \
			 -O0 \
			 -g3 \
			 -ffunction-sections \
			 -fmessage-length=0 \
			 -fno-common \
			 -fdata-sections \
			 -fno-builtin \
			 -mcpu=cortex-m0plus \
			 -mthumb \
			 -DARCH_SIZE=uint32_t
			 
# ARM Linker Flags
ARM_LL_FLAGS := -v \
				-nostdlib \
			    -Xlinker -Map="./Debug/pes_project_3.map" \
			    -Xlinker --gc-sections \
			    -Xlinker -print-memory-usage \
			    -Xlinker --sort-section=alignment \
			    -Xlinker --cref \
			    -mcpu=cortex-m0plus \
			    -mthumb \
			    -T linkerfile.ld \
			    -o $(EXE)
			
# ARM Defines
ARM_DEFS := \
		   -D__REDLIB__ \
		   -DCPU_MKL25Z128VLK4 \
		   -DCPU_MKL25Z128VLK4_cm0plus \
		   -DSDK_OS_BAREMETAL \
		   -DFSL_RTOS_BM \
		   -DCR_INTEGER_PRINTF \
		   -DPRINTF_FLOAT_ENABLE=0 \
		   -DSCANF_FLOAT_ENABLE=0 \
		   -DPRINTF_ADVANCED_ENABLE=0 \
		   -DSCANF_ADVANCED_ENABLE=0 \
		   -D__MCUXPRESSO \
		   -D__USE_CMSIS \
		   -DDEBUG \
		   -DFRDM_KL25Z \
		   -DFREEDOM \
		   -specs=redlib.specs \
		   -DSDK_DEBUGCONSOLE=0 \
		   -DSDK_DEBUGCONSOLE_UART 
		   
# Build Folders
SOURCE := ./source
DEBUG := ./Debug

		   
# PC Include Files
PC_INCS := \
		   -I"$(SOURCE)" \
		   -I"$(SOURCE)/led_control" \
		   -I"$(SOURCE)/logger" \
		   -I"$(SOURCE)/mem_test" \
		   -I"$(SOURCE)/pattern_gen" \
		   -I"$(SOURCE)/unit_tests" \
		   -I"ucunit"
		    
# PC Object Files
PC_OBJS := \
		   $(DEBUG)/source/logger/logger.o \
		   $(DEBUG)/source/mem_test/allocate.o \
		   $(DEBUG)/source/mem_test/display.o \
		   $(DEBUG)/source/mem_test/free.o \
		   $(DEBUG)/source/mem_test/get_addr.o \
		   $(DEBUG)/source/mem_test/invert.o \
		   $(DEBUG)/source/mem_test/mem_write.o \
		   $(DEBUG)/source/mem_test/pattern_write.o \
		   $(DEBUG)/source/mem_test/verify.o \
		   $(DEBUG)/source/pattern_gen/pattern_gen.o
		   
# PC Dependencies Files
PC_DEPS := \
		   $(DEBUG)/source/logger/logger.d \
		   $(DEBUG)/source/mem_test/allocate.d \
		   $(DEBUG)/source/mem_test/display.d \
		   $(DEBUG)/source/mem_test/free.d \
		   $(DEBUG)/source/mem_test/get_addr.d \
		   $(DEBUG)/source/mem_test/invert.d \
		   $(DEBUG)/source/mem_test/mem_write.d \
		   $(DEBUG)/source/mem_test/pattern_write.d \
		   $(DEBUG)/source/mem_test/verify.d \
		   $(DEBUG)/source/pattern_gen/pattern_gen.d

# ARM Include Files
ARM_INCS := \
		   -I"$(SOURCE)" \
		   -I"$(SOURCE)/led_control" \
		   -I"$(SOURCE)/logger" \
		   -I"$(SOURCE)/mem_test" \
		   -I"$(SOURCE)/pattern_gen" \
		   -I"$(SOURCE)/unit_tests" \
		   -I"board" \
		   -I"CMSIS" \
		   -I"drivers" \
		   -I"startup" \
		   -I"utilities" \
		   -I"ucunit"
		   
# ARM Object Files 
ARM_OBJS := \
		   $(DEBUG)/source/logger/logger.o \
		   $(DEBUG)/source/mem_test/allocate.o \
		   $(DEBUG)/source/mem_test/display.o \
		   $(DEBUG)/source/mem_test/free.o \
		   $(DEBUG)/source/mem_test/get_addr.o \
		   $(DEBUG)/source/mem_test/invert.o \
		   $(DEBUG)/source/mem_test/mem_write.o \
		   $(DEBUG)/source/mem_test/pattern_write.o \
		   $(DEBUG)/source/mem_test/verify.o \
		   $(DEBUG)/source/pattern_gen/pattern_gen.o \
		   $(DEBUG)/startup/startup_mkl25z4.o \
		   $(DEBUG)/CMSIS/system_MKL25Z4.o \
		   $(DEBUG)/board/board.o \
		   $(DEBUG)/board/clock_config.o \
		   $(DEBUG)/board/peripherals.o \
		   $(DEBUG)/board/pin_mux.o \
		   $(DEBUG)/drivers/fsl_clock.o \
		   $(DEBUG)/drivers/fsl_common.o \
		   $(DEBUG)/drivers/fsl_flash.o \
		   $(DEBUG)/drivers/fsl_gpio.o \
		   $(DEBUG)/drivers/fsl_lpsci.o \
		   $(DEBUG)/drivers/fsl_smc.o \
		   $(DEBUG)/drivers/fsl_uart.o \
		   $(DEBUG)/utilities/fsl_debug_console.o
	
# ARM Dependencies Files	   
ARM_DEPS := \
		   $(DEBUG)/source/logger/logger.d \
		   $(DEBUG)/source/mem_test/allocate.d \
		   $(DEBUG)/source/mem_test/display.d \
		   $(DEBUG)/source/mem_test/free.d \
		   $(DEBUG)/source/mem_test/get_addr.d \
		   $(DEBUG)/source/mem_test/invert.d \
		   $(DEBUG)/source/mem_test/mem_write.d \
		   $(DEBUG)/source/mem_test/pattern_write.d \
		   $(DEBUG)/source/mem_test/verify.d \
		   $(DEBUG)/source/pattern_gen/pattern_gen.d \
		   $(DEBUG)/startup/startup_mkl25z4.d \
		   $(DEBUG)/CMSIS/system_MKL25Z4.d \
		   $(DEBUG)/board/board.d \
		   $(DEBUG)/board/clock_config.d \
		   $(DEBUG)/board/peripherals.d \
		   $(DEBUG)/board/pin_mux.d \
		   $(DEBUG)/drivers/fsl_clock.d \
		   $(DEBUG)/drivers/fsl_common.d \
		   $(DEBUG)/drivers/fsl_flash.d \
		   $(DEBUG)/drivers/fsl_gpio.d \
		   $(DEBUG)/drivers/fsl_lpsci.d \
		   $(DEBUG)/drivers/fsl_smc.d \
		   $(DEBUG)/drivers/fsl_uart.d \
		   $(DEBUG)/utilities/fsl_debug_console.d
		   
# Executable file
EXE := $(DEBUG)/pes_project_3.axf

#####################################################################
# Build Rules
# Rules for making all
all : $(EXE)

#####################################################################
# Selecting Platform
ifeq ($(BUILD), KL25Z)
build_option := kl25z
PLATFORM := KL25Z
else ifeq ($(BUILD), KL25Z_LOG)
build_option := kl25z_log
PLATFORM := KL25Z
else ifeq ($(BUILD), KL25Z_TESTS)
build_option := kl25z_tests
PLATFORM := KL25Z
else ifeq ($(BUILD), PC)
build_option := pc
PLATFORM := PC
else ifeq ($(BUILD), PC_LOG)
build_option := pc_log
PLATFORM := PC
else ifeq ($(BUILD), PC_TESTS)
build_option := pc_tests
PLATFORM := PC
endif
#####################################################################

$(EXE) : $(build_option)
	

# Rules for making EXE files
kl25z : directories $(ARM_OBJS) $(SOURCE)/main.c $(SOURCE)/led_control/led_control.c
	@$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -DKL25Z ./source/main.c -o $(DEBUG)/source/main.o
	@$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -DKL25Z $(SOURCE)/led_control/led_control.c -o $(DEBUG)/source/led_control/led_control.o
	@arm-none-eabi-gcc -nostdlib -Xlinker -Map="./Debug/pes_project_3.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m0plus -mthumb -T linkerfile.ld -o ./Debug/pes_project_3.axf ./Debug/source/logger/logger.o ./Debug/source/mem_test/allocate.o ./Debug/source/mem_test/display.o  ./Debug/source/mem_test/free.o ./Debug/source/mem_test/get_addr.o ./Debug/source/mem_test/invert.o ./Debug/source/mem_test/mem_write.o ./Debug/source/mem_test/pattern_write.o ./Debug/source/mem_test/verify.o ./Debug/source/pattern_gen/pattern_gen.o ./Debug/startup/startup_mkl25z4.o ./Debug/CMSIS/system_MKL25Z4.o ./Debug/board/board.o ./Debug/board/clock_config.o ./Debug/board/peripherals.o ./Debug/board/pin_mux.o ./Debug/drivers/fsl_clock.o ./Debug/drivers/fsl_common.o ./Debug/drivers/fsl_flash.o ./Debug/drivers/fsl_gpio.o ./Debug/drivers/fsl_lpsci.o ./Debug/drivers/fsl_smc.o ./Debug/drivers/fsl_uart.o ./Debug/utilities/fsl_debug_console.o ./Debug/source/main.o ./Debug/source/led_control/led_control.o
	@echo "KL25Z without logging made"
	
kl25z_log : directories $(ARM_OBJS) $(SOURCE)/main.c $(SOURCE)/led_control/led_control.c
	@$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -DKL25Z_LOG $(SOURCE)/main.c -o $(DEBUG)/source/main.o
	@$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -DKL25Z_LOG $(SOURCE)/led_control/led_control.c -o $(DEBUG)/source/led_control/led_control.o
	@arm-none-eabi-gcc -nostdlib -Xlinker -Map="./Debug/pes_project_3.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m0plus -mthumb -T linkerfile.ld -o ./Debug/pes_project_3.axf ./Debug/source/logger/logger.o ./Debug/source/mem_test/allocate.o ./Debug/source/mem_test/display.o  ./Debug/source/mem_test/free.o ./Debug/source/mem_test/get_addr.o ./Debug/source/mem_test/invert.o ./Debug/source/mem_test/mem_write.o ./Debug/source/mem_test/pattern_write.o ./Debug/source/mem_test/verify.o ./Debug/source/pattern_gen/pattern_gen.o ./Debug/startup/startup_mkl25z4.o ./Debug/CMSIS/system_MKL25Z4.o ./Debug/board/board.o ./Debug/board/clock_config.o ./Debug/board/peripherals.o ./Debug/board/pin_mux.o ./Debug/drivers/fsl_clock.o ./Debug/drivers/fsl_common.o ./Debug/drivers/fsl_flash.o ./Debug/drivers/fsl_gpio.o ./Debug/drivers/fsl_lpsci.o ./Debug/drivers/fsl_smc.o ./Debug/drivers/fsl_uart.o ./Debug/utilities/fsl_debug_console.o ./Debug/source/main.o ./Debug/source/led_control/led_control.o
	@echo "KL25Z with logging made"
	
pc : directories $(PC_OBJS) $(SOURCE)/main.c $(SOURCE)/led_control/led_control.c $(SOURCE)/mem_test/verify.c
	@$(PC_CC) $(PC_FLAGS) $(PC_INCS) -DPC $(SOURCE)/main.c -o $(DEBUG)/source/main.o
	@$(PC_CC) $(PC_FLAGS) $(PC_INCS) -DPC $(SOURCE)/led_control/led_control.c -o $(DEBUG)/source/led_control/led_control.o
	@$(PC_CC) $(PC_FLAGS) $(PC_INCS) -DPC $(SOURCE)/mem_test/verify.c -o $(DEBUG)/source/mem_test/verify.o
	@$(PC_LL) $(DEBUG)/source/main.o $(DEBUG)/source/mem_test/verify.o $(DEBUG)/source/led_control/led_control.o $(PC_OBJS) -o $(EXE)
	@echo "PC without logging made"
	
pc_log : directories $(PC_OBJS) $(SOURCE)/main.c $(SOURCE)/led_control/led_control.c
	@$(PC_CC) $(PC_FLAGS) $(PC_INCS) -DPC_LOG $(SOURCE)/main.c -o $(DEBUG)/source/main.o
	@$(PC_CC) $(PC_FLAGS) $(PC_INCS) -DPC_LOG $(SOURCE)/led_control/led_control.c -o $(DEBUG)/source/led_control/led_control.o
	@$(PC_CC) $(PC_FLAGS) $(PC_INCS) -DPC_LOG $(SOURCE)/mem_test/verify.c -o $(DEBUG)/source/mem_test/verify.o
	@$(PC_LL) $(DEBUG)/source/main.o $(DEBUG)/source/mem_test/verify.o $(DEBUG)/source/led_control/led_control.o $(PC_OBJS) -o $(EXE)
	@echo "PC with logging made"

#####################################################################
# Essesntial ARM Object Files
$(DEBUG)/board/%.o: ./board/%.c
	@echo 'Building file: $<'
	@$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

$(DEBUG)/CMSIS/%.o: ./CMSIS/%.c
	@echo 'Building file: $<'
	@$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

$(DEBUG)/drivers/%.o: ./drivers/%.c
	@echo 'Building file: $<'
	@$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
$(DEBUG)/startup/%.o: ./startup/%.c
	@echo 'Building file: $<'
	@$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
$(DEBUG)/utilities/%.o: ./utilities/%.c
	@echo 'Building file: $<'
	@$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
#####################################################################
# Compiling files for ARM Builds
ifeq ($(PLATFORM), KL25Z)
$(DEBUG)/source/logger/logger.o : $(SOURCE)/logger/logger.c
	@echo 'Building file: $<'
	@$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

$(DEBUG)/source/mem_test/%.o : $(SOURCE)/mem_test/%.c
	@echo 'Building file: $<'
	@$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
$(DEBUG)/source/pattern_gen/%.o : $(SOURCE)/pattern_gen/%.c
	@echo 'Building file: $<'
	@$(ARM_CC) $(ARM_FLAGS) $(ARM_DEFS) $(ARM_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
#####################################################################
# Compiling files for PC Builds
else ifeq ($(PLATFORM), PC)
$(DEBUG)/source/logger/logger.o : $(SOURCE)/logger/logger.c
	@echo 'Building file: $<'
	$(PC_CC) $(PC_FLAGS) $(PC_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

$(DEBUG)/source/mem_test/%.o : $(SOURCE)/mem_test/%.c
	@echo 'Building file: $<'
	$(PC_CC) $(PC_FLAGS) $(PC_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
$(DEBUG)/source/pattern_gen/%.o : $(SOURCE)/pattern_gen/%.c
	@echo 'Building file: $<'
	$(PC_CC) $(PC_FLAGS) $(PC_INCS) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
endif

.PHONY : directories
directories :
	$(MK) \
	$(DEBUG) \
	$(DEBUG)/board \
	$(DEBUG)/CMSIS \
	$(DEBUG)/drivers \
	$(DEBUG)/startup \
	$(DEBUG)/utilities \
	$(DEBUG)/ucunit \
	$(DEBUG)/source/led_control \
	$(DEBUG)/source/logger \
	$(DEBUG)/source/mem_test \
	$(DEBUG)/source/pattern_gen \
	$(DEBUG)/source/unit_tests
	
clean:
	@$(RM) \
	$(DEBUG)/board \
	$(DEBUG)/CMSIS \
	$(DEBUG)/drivers \
	$(DEBUG)/startup \
	$(DEBUG)/utilities \
	$(DEBUG)/source \
	$(DEBUG)/pes_project_3.axf \
	$(DEBUG)/pes_project_3.map
	@echo "Build cleaned"	