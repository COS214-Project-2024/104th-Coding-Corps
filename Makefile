# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++14 -I./

# Directories
SRC_DIR = .
TEST_DIR = tests
BUILD_DIR = build

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Test files
TESTS = $(wildcard $(TEST_DIR)/test_*.cpp)
TEST_OBJS = $(TESTS:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Executable for specific test
TEST_EXECUTABLES = test_Government

# Default target
.PHONY: all clean

all: $(TEST_EXECUTABLES)

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files to object files
$(BUILD_DIR)/test_%.o: $(TEST_DIR)/test_%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link each test executable with main objects
test_Government: $(BUILD_DIR)/test_Government.o $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean up
clean:
	rm -rf $(BUILD_DIR) test_Government
