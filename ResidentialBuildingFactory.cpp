#include "ResidentialBuildingFactory.h"
#include "BuildingComponent.h"
#include "Flat.h"
#include "House.h"
#include "Estate.h"
#include <random>

/**
 * @brief Creates a flat building.
 * 
 * @param units The number of units in the flat.
 * @param residents The number of residents.
 * @param floors The number of floors.
 * @param hasGarden Whether the flat has a garden.
 * @return A unique pointer to the created flat building.
 */
std::unique_ptr<BuildingComponent> ResidentialBuildingFactory::createFlat(int units, int residents, int floors, bool hasGarden) {
    std::mt19937 gen(static_cast<unsigned>(std::time(0))); 
    std::uniform_int_distribution<> positionDist(0, 159);
    x = positionDist(gen);
    y = positionDist(gen);
    return std::make_unique<Flat>(units, residents, floors, hasGarden);
}

/**
 * @brief Creates a house building.
 * 
 * @param garageSize The size of the garage.
 * @param hasPool Whether the house has a pool.
 * @param residents The number of residents.
 * @param floors The number of floors.
 * @param hasGarden Whether the house has a garden.
 * @return A unique pointer to the created house building.
 */
std::unique_ptr<BuildingComponent> ResidentialBuildingFactory::createHouse(int garageSize, bool hasPool, int residents, int floors, bool hasGarden) {
    std::mt19937 gen(static_cast<unsigned>(std::time(0))); 
    std::uniform_int_distribution<> positionDist(0, 159);
    x = positionDist(gen);
    y = positionDist(gen);
    return std::make_unique<House>(garageSize, hasPool, residents, floors, hasGarden);
}

/**
 * @brief Creates an estate building.
 * 
 * @param garageSize The size of the garage.
 * @param hasPool Whether the estate has a pool.
 * @param residents The number of residents.
 * @param floors The number of floors.
 * @param hasGarden Whether the estate has a garden.
 * @param units The number of units in the estate.
 * @return A unique pointer to the created estate building.
 */
std::unique_ptr<BuildingComponent> ResidentialBuildingFactory::createEstate(int garageSize, bool hasPool, int residents, int floors, bool hasGarden, int units) {
    return std::make_unique<Estate>(garageSize, hasPool, residents, floors, hasGarden, units);
}
