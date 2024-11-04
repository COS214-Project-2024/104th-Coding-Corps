#include "IndustrialBuildingFactory.h"
#include "Factory.h"
#include "plant.h"
#include "warehouse.h"
#include <memory>

/**
 * @brief Creates a factory building component.
 * 
 * This function constructs a unique pointer to a factory instance
 * with the specified parameters.
 * 
 * @param x The x-coordinate of the factory.
 * @param y The y-coordinate of the factory.
 * @param district The district where the factory is located.
 * @param quality The quality rating of the factory.
 * @param numWorkers The number of workers in the factory.
 * @param factoryType The type of factory being created.
 * @param production The production capacity of the factory.
 * 
 * @return A unique pointer to the created factory building component.
 */
std::unique_ptr<BuildingComponent> IndustrialBuildingFactory::createFactory(int x, int y, const std::string& district, int quality, int numWorkers, const std::string& factoryType, double production) {
    return std::make_unique<factory>(x, y, district, quality, numWorkers, factoryType, production);
}

/**
 * @brief Creates a plant building component.
 * 
 * This function constructs a unique pointer to a plant instance
 * with the specified parameters.
 * 
 * @param x The x-coordinate of the plant.
 * @param y The y-coordinate of the plant.
 * @param district The district where the plant is located.
 * @param quality The quality rating of the plant.
 * @param production The production capacity of the plant.
 * @param workers The number of workers in the plant.
 * 
 * @return A unique pointer to the created plant building component.
 */
std::unique_ptr<BuildingComponent> IndustrialBuildingFactory::createPlant(int x, int y, const std::string& district, int quality, double production, int workers) {
    return std::make_unique<plant>(x, y, district, quality, production, workers);
}

/**
 * @brief Creates a warehouse building component.
 * 
 * This function constructs a unique pointer to a warehouse instance
 * with the specified parameters.
 * 
 * @param x The x-coordinate of the warehouse.
 * @param y The y-coordinate of the warehouse.
 * @param district The district where the warehouse is located.
 * @param quality The quality rating of the warehouse.
 * @param storageCapacity The storage capacity of the warehouse.
 * @param numWorkers The number of workers in the warehouse.
 * 
 * @return A unique pointer to the created warehouse building component.
 */
std::unique_ptr<BuildingComponent> IndustrialBuildingFactory::createWarehouse(int x, int y, const std::string& district, int quality, int storageCapacity, int numWorkers) {
    return std::make_unique<Warehouse>(x, y, district, quality, storageCapacity, numWorkers);
}
