# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -I./

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

# Test executables

TEST_EXECUTABLES = test_Government test_Citizen test_BuildingFactory test_BuildingComponents test_Utilities	test_Budget_Resources

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

test_Citizen: $(BUILD_DIR)/test_Citizen.o $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

test_BuildingFactory: $(BUILD_DIR)/test_BuildingFactory.o $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

test_BuildingComponents: $(BUILD_DIR)/test_BuildingComponents.o $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

test_Budget_Resources: $(BUILD_DIR)/test_Budget_Resources.o $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@


test_Utilities: $(BUILD_DIR)/test_Utilities.o $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@
	
# Clean up
clean:
	rm -rf $(BUILD_DIR) $(TEST_EXECUTABLES)
