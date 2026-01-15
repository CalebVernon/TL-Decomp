# ==============================
# TL-Decomp Multi-Platform Makefile
# ==============================

# Configurable variables
REGION := eu          # change to your region if needed
PLATFORM ?= pc        # default platform: pc (use PLATFORM=3ds make to build 3ds)
BUILD_DIR := build/$(REGION)_$(PLATFORM)
SRC_DIR := source
BIN := tomodachi

# Compiler flags
ifeq ($(PLATFORM),pc)
    CC := g++
    CFLAGS := -std=c++17 -O2 -Wall -Iinclude
    EXT := exe
else ifeq ($(PLATFORM),3ds)
    CC := $(DEVKITARM)/bin/arm-none-eabi-g++
    CFLAGS := -O2 -Wall -Iinclude -march=armv6 -mtune=mpcore
    EXT := 3dsx
else
    $(error Unknown platform: $(PLATFORM))
endif

# Source files
SRCS := $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Default target
all: $(BUILD_DIR)/$(BIN).$(EXT)

# Build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile object files
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Link
$(BUILD_DIR)/$(BIN).$(EXT): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean
clean:
	rm -rf build/*

.PHONY: all clean
