#include "IndustrialBuildingFactory.h"
#include "Factory.h"
#include "plant.h"
#include "warehouse.h"
#include <memory>

std::unique_ptr<BuildingComponent> IndustrialBuildingFactory::createFactory(int x, int y, const std::string& district, int quality, int numWorkers, const std::string& factoryType, double production) {
    return std::make_unique<factory>(x, y, district, quality, numWorkers, factoryType, production);
}

std::unique_ptr<BuildingComponent> IndustrialBuildingFactory::createPlant(int x, int y, const std::string& district, int quality, double production, int workers) {
    return std::make_unique<plant>(x, y, district, quality, production, workers);
}

std::unique_ptr<BuildingComponent> IndustrialBuildingFactory::createWarehouse(int x, int y, const std::string& district, int quality, int storageCapacity, int numWorkers) {
    return std::make_unique<Warehouse>(x, y, district, quality, storageCapacity, numWorkers);
}
