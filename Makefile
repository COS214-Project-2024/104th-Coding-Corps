# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -I./

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
TEST_EXECUTABLES = $(TEST_OBJS:$(BUILD_DIR)/%.o=%)

# Targets
.PHONY: all clean $(TEST_EXECUTABLES)

all: $(TEST_EXECUTABLES)

# Rule to compile all source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile each test file and link with source object files
$(TEST_EXECUTABLES): % : $(BUILD_DIR)/%.o $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Individual test targets
$(BUILD_DIR)/test_Government.o: $(TEST_DIR)/test_Government.cpp
Government: test_Government

$(BUILD_DIR)/test_%.o: $(TEST_DIR)/test_%.cpp
%: $(BUILD_DIR)/test_%.o $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean up
clean:
	rm -rf $(BUILD_DIR) $(TEST_EXECUTABLES)
