# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++14 -Wall -Wextra

# Source and build directories
SRC_DIR := src
BUILD_DIR := build

# Target executable name
TARGET := timer

# Source files (assuming all .cpp files in the src directory)
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

# Header files
HEADER_FILES := $(wildcard $(SRC_DIR)/*.hpp)

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Default rule
all: $(BUILD_DIR) $(TARGET)

# Build target executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build object files from source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Create the build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# PHONY targets (targets that don't represent files)
.PHONY: all clean

# Don't remove intermediate .o files
.PRECIOUS: $(BUILD_DIR)/%.o

