MSPGCC_ROOT_DIR = /opt/ti/msp430-gcc
MSPGCC_BIN_DIR = $(MSPGCC_ROOT_DIR)/bin
MSPGCC_INCLUDE_DIR = $(MSPGCC_ROOT_DIR)/include
BUILD_DIR = build
SRC_DIR = src
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

TI_CCS_DIR = /opt/ti/ccs1220/ccs

DEBUG_DRIVERS_DIR = $(TI_CCS_DIR)/ccs_base/DebugServer/drivers
MSPDEBUG = /usr/local/bin/mspdebug

# Toolchain
CC = $(MSPGCC_BIN_DIR)/msp430-elf-gcc
DEBUG = LD_LIBRARY_PATH=$(DEBUG_DRIVERS_DIR) $(MSPDEBUG)

# Files
TARGET = $(BIN_DIR)/peripheral

SOURCES = $(SRC_DIR)/main.c \
		  $(SRC_DIR)/spi.c \
		  $(SRC_DIR)/rfm69.c

OBJECTS = $(OBJ_DIR)/main.o \
		  $(OBJ_DIR)/spi.o \
		  $(OBJ_DIR)/rfm69.o

# Build
$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CC) \
	-mmcu=msp430g2553 \
	-L $(MSPGCC_INCLUDE_DIR) \
	$^ -o $(TARGET)

# Compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) \
	-mmcu=msp430g2553 \
	-I $(MSPGCC_INCLUDE_DIR) \
	-Og -g -Wall -c -o $@ $^

flash: $(TARGET)
	$(DEBUG) tilib "prog $(TARGET)"