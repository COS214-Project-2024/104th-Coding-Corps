# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++14 -I./

# Directories
SRC_DIR = .
TEST_DIR = transportTestBranch
BUILD_DIR = build

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Test files
TESTS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(TESTS:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Executable for test
TEST_EXECUTABLE = TransportTests

# Default target
.PHONY: all clean

all: $(TEST_EXECUTABLE)

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files to object files
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link all objects into the test executable
$(TEST_EXECUTABLE): $(TEST_OBJS) $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean up
clean:
	rm -rf $(BUILD_DIR) $(TEST_EXECUTABLE)
