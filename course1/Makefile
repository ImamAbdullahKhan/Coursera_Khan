#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <file>.i - Generates the preprocessed output of all c-program implementation files.
#	<file>.asm Generates assembly output of c-program implementation files and the final output executable.
#	<file>.o Generates the object file for all c-source files
#	compile-all - Compile all source files without linking them.
#	build - Compile all object files and link into a final executable.
# Platform Overrides:
#      Supported Platform are MSP432 and the Host machine.
#
#------------------------------------------------------------------------------
include sources.mk

TARGET = c1m2

# Platform Overrides
PLATFORM = MSP432
ifeq ($(PLATFORM),MSP432)
 # Architectures Specific Flags
        LINKER_FILE = ../msp432p401r.lds
        CPU = cortex-m4
        ARCH = armv7e-m
        SPECS = nosys.specs
        # Compiler Flags and Defines
        CC = arm-none-eabi-gcc
        LD = arm-none-eabi-ld
        LDFLAGS = -Wl,-Map=$(TARGET).map -Wl,-T $(LINKER_FILE)
        CFLAGS = $(TARGET_INCLUDES) -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard \
                 -mfpu=fpv4-sp-d16 -D $(PLATFORM) -Wall -Werror -g -O0 --specs=$(SPECS) -std=c99 -MP -MD
        CPPFLAGs = -E
        SIZE=arm-none-eabi-size
        OBJS:=$(TARGET_SOURCES:.c=.o)

endif

ifeq ($(PLATFORM),HOST)
	ARCH:=$(shell arch)
        # Compiler Flags and Defines
        CC = gcc
        LD = ld
        LDFLAGS = -Wl,-Map=$(TARGET).map
        CFLAGS = $(HOST_INCLUDES) -D $(PLATFORM) -Wall -Werror -g -O0 -std=c99 -MP -MD
        CPPFLAGs = -E
        SIZE = size
        OBJS:=$(HOST_SOURCES:.c=.o)

endif

%.i: %.c
	$(CC) $(CFLAGS) $(CPPFLAGs) -o $@ $^

%.asm: %.c
	$(CC) $(CFLAGS) -S -o $@ $^
 
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET).out $(OBJS)
	$(SIZE) $(TARGET).out

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map *.i *.asm *.d
