# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I"sourceCode"

# Source files
SRC = main.cpp GameEngine.cpp \
      sourceCode/CityContext.cpp \
      sourceCode/Budget.cpp \
      sourceCode/BuildingComponent.cpp \
      sourceCode/BuildingFactory.cpp \
      sourceCode/BuildingComposite.cpp \
      sourceCode/CommercialBuildingFactory.cpp \
      sourceCode/Concrete.cpp \
      sourceCode/Transport.cpp \
      sourceCode/TransportStrategy.cpp \
      sourceCode/Utilities.cpp \
      sourceCode/Government.cpp \
      sourceCode/PowerPlant.cpp \
      sourceCode/PowerPlantFactory.cpp \
      sourceCode/PublicTransit.cpp \
      sourceCode/WaterSupplyFactory.cpp \
      sourceCode/WaterSupply.cpp \
      sourceCode/SewageSystemFactory.cpp \
      sourceCode/sewageManagement.cpp \
      sourceCode/RailBased.cpp \
      sourceCode/WasteManagementFactory.cpp \
      sourceCode/wasteManagement.cpp \
      sourceCode/Factory.cpp \
      sourceCode/Family.cpp \
      sourceCode/IndustrialBuildingFactory.cpp \
      sourceCode/PolicyCommand.cpp \
      sourceCode/Command.cpp \
      sourceCode/TaxationCommand.cpp \
      sourceCode/TaxCollector.cpp \
      sourceCode/TrafficManager.cpp \
      sourceCode/Estate.cpp \
      sourceCode/House.cpp \
      sourceCode/Flat.cpp \
      sourceCode/mall.cpp \
      sourceCode/Office.cpp \
      sourceCode/Shop.cpp \
      sourceCode/School.cpp \
      sourceCode/University.cpp \
      sourceCode/ResidentialBuildingFactory.cpp \
      sourceCode/Resource.cpp \
      sourceCode/ResourceManager.cpp \
      sourceCode/RoadBased.cpp \
      sourceCode/SavePoint.cpp \
      sourceCode/SavePointManager.cpp \
      sourceCode/ServiceBuildingFactory.cpp \
      sourceCode/Steel.cpp \
      sourceCode/Hospital.cpp \
      sourceCode/plant.cpp \
      sourceCode/SteelFactory.cpp \
      sourceCode/ConcreteFactory.cpp \
      sourceCode/WoodFactory.cpp \
      sourceCode/Wood.cpp \
      sourceCode/Citizen.cpp \
      sourceCode/WareHouse.cpp

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

# Run the program
run: $(BIN)
	./$(BIN)

# Clean build files
clean:
	rm -rf build bin $(OBJ) $(BIN)
