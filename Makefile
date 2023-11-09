# Define source and header file directories
SRC_DIR := src
INCLUDE_DIR := Include

# Define the compiler and compiler flags
CXX := g++
CXXFLAGS := -O2

# Define the source and object files
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, %.o, $(SOURCES))

# Define the target binary
TARGET := main

# Phony targets
.PHONY: all clean

# Default target
all: $(TARGET)

# Linking the target binary
$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

# Compiling source files
%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

# Clean rule to remove object files and the binary
clean:
	rm -f $(OBJECTS) $(TARGET)
