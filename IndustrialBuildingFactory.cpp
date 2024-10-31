#include "IndustrialBuildingFactory.h"
#include "Factory.h"
#include "plant.h"  // Ensure correct casing for the class name
#include "warehouse.h"  // Ensure correct casing for the class name
#include <memory> // Include the memory header for smart pointers

std::unique_ptr<BuildingComponent> IndustrialBuildingFactory::createFactory(int numWorkers, const std::string& factoryType, double production) {
    return std::make_unique<factory>(numWorkers, factoryType, production);
}

std::unique_ptr<BuildingComponent> IndustrialBuildingFactory::createPlant(int workers, double production) {
    return std::make_unique<plant>(workers, production); // Corrected to Plant with uppercase 'P'
}

std::unique_ptr<BuildingComponent> IndustrialBuildingFactory::createWarehouse(int storageCapacity, int numWorkers) {
    return std::make_unique<Warehouse>(storageCapacity, numWorkers);
}
