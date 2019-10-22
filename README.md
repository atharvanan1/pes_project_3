# Welcome!

## Principles of Embedded Software Project 3

#### Name: Atharva Nandanwar

**Source files - source folder**

- source
  
  - main.c - main code procedures
  
  - main.h - header file for main
  
  - common.h - common declarations
  
  - logger/
    
    - logger.c - logger functions
    
    - logger.h - header file for logger
  
  - led_control/
    
    - led_control.c - LED Control Functions
    
    - led_control.h - header file for LED Control
  
  - mem_test/
    
    - allocate.c - Function for allocating memory
    
    - allocate.h
    
    - display.c - Function for displaying data
    
    - display.h
    
    - free.c - Function for freeing data
    
    - free.h
    
    - get_addr.c - Function for getting address from offset
    
    - get_addr.h
    
    - invert.c - Function for inverting data
    
    - invert.h
    
    - mem_write.c - Function for writing into memory region
    
    - mem_write.h
    
    - pattern_write.c - Function for writing pattern into memory region
    
    - pattern_write.h
    
    - verify.c - Function for verifying pattern
    
    - verify.h
  
  - pattern_gen/
    
    - pattern_gen.c - Function for generating pattern
    
    - pattern_gen.h

**Compilation Instructions**

1. **Target - KL25Z**
   
   Open the project in MCUXpresso, and in Build Targets -> KL25Z or KL25Z_LOG.
   
   Press Debug, and it would run the file.
   
   To monitor the output, open a serial monitor for appropriate port at 115200 baud, no parity, and one stop bit.

2. **Target - PC**
   
   Open the project in MCUXpresso, and in Build Targets -> PC or PC_LOG.
   
   After the compilation is successful, go into the project directory -> Debug, and run the file pes_project_3.axf on Linux.
   
   It would print all the output on standard output.

**Note: if this doesn't work, then use the makefile to generate project executables. You need to have arm-none-eabi-gcc and gcc on your system to compile.**

---

Make Commands:

```bash
make -r all BUILD=(BUILD_NAME)
------------------------------
make -r all BUILD=KL25Z
make -r all BUILD=KL25Z_LOG
make -r all BUILD=PC
make -r all BUILD=PC_LOG
```

---

**UML Files**

Navigate to doc -> UML_Diagrams/

There are html and pdf documents, html documents are more representative of what I want to show.


