# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I"sourceCode"

# Source files
SRC = main.cpp GameEngine.cpp \
      sourceCode/CityContext.cpp \
      sourceCode/BuildingFactory.cpp \
      sourceCode/BuildingComposite.cpp \
      sourceCode/Transport.cpp \
      sourceCode/Utilities.cpp \
      sourceCode/Government.cpp \
      sourceCode/PowerPlantFactory.cpp \
      sourceCode/WaterSupplyFactory.cpp \
      sourceCode/SewageSystemFactory.cpp \
      sourceCode/WasteManagementFactory.cpp \
      sourceCode/PolicyCommand.cpp \
      sourceCode/Command.cpp \
      sourceCode/TaxationCommand.cpp \
      sourceCode/TaxCollector.cpp \
      sourceCode/Citizen.cpp

# Object files
OBJ = $(SRC:%.cpp=build/%.o)

# Output binary
BIN = bin/main

# Build all
all: $(BIN)

# Link all object files into the final binary
$(BIN): $(OBJ)
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Compile source files to object files
build/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf build bin $(OBJ) $(BIN)
