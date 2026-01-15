# ==============================
# TL-Decomp Auto PC/3DS Makefile (Windows-safe)
# ==============================

REGION := eu
PLATFORM ?= pc
BUILD_DIR := build/$(REGION)_$(PLATFORM)
BIN := tomodachi

# Compiler & flags
ifeq ($(PLATFORM),pc)
    CC := g++
    CFLAGS := -std=c++17 -O2 -Wall -Iinclude -mconsole
    EXT := exe
else ifeq ($(PLATFORM),3ds)
    CC := $(DEVKITARM)/bin/arm-none-eabi-g++
    CFLAGS := -O2 -Wall -Iinclude -march=armv6 -mtune=mpcore
    EXT := 3dsx
else
    $(error Unknown platform: $(PLATFORM))
endif

# ----------------------------
# Auto-detect all .cpp files recursively under Source/
# ----------------------------
SRCS := $(shell find Source -name '*.cpp' 2>/dev/null)

# Build object file list
OBJS := $(addprefix $(BUILD_DIR)/, $(SRCS:.cpp=.o))

# Default target
all: $(BUILD_DIR)/$(BIN).$(EXT)

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile all sources manually (Windows-safe)
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Link
# Link
$(BUILD_DIR)/$(BIN).$(EXT): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(OBJS) -lraylib -lopengl32 -lgdi32 -lwinmm -o $@


# Clean
clean:
	-rmdir /s /q build 2>nul || rm -rf build/*

.PHONY: all clean