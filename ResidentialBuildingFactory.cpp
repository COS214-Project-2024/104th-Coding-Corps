#include "ResidentialBuildingFactory.h"
#include "BuildingComponent.h"
#include "Flat.h"
#include "House.h"
#include "Estate.h"
#include <random>
#include <ctime>

/**
 * @brief Creates a flat building with randomly generated x and y coordinates.
 * 
 * @param units The number of units in the flat.
 * @param residents The number of residents.
 * @param floors The number of floors.
 * @param hasGarden Whether the flat has a garden.
 * @param district The district where the flat is located.
 * @param quality The quality level of the flat.
 * @return A unique pointer to the created flat building.
 */
std::unique_ptr<BuildingComponent> ResidentialBuildingFactory::createFlat(int units, int residents, int floors, bool hasGarden, const std::string& district, int quality) {
    std::mt19937 gen(static_cast<unsigned>(std::time(0))); 
    std::uniform_int_distribution<> positionDist(0, 159);
    int x = positionDist(gen);
    int y = positionDist(gen);
    return std::make_unique<Flat>(x, y, district, quality, units, residents, floors, hasGarden);
}

/**
 * @brief Creates a house building with randomly generated x and y coordinates.
 * 
 * @param garageSize The size of the garage.
 * @param hasPool Whether the house has a pool.
 * @param residents The number of residents.
 * @param floors The number of floors.
 * @param hasGarden Whether the house has a garden.
 * @param district The district where the house is located.
 * @param quality The quality level of the house.
 * @return A unique pointer to the created house building.
 */
std::unique_ptr<BuildingComponent> ResidentialBuildingFactory::createHouse(int garageSize, bool hasPool, int residents, int floors, bool hasGarden, const std::string& district, int quality) {
    std::mt19937 gen(static_cast<unsigned>(std::time(0))); 
    std::uniform_int_distribution<> positionDist(0, 159);
    int x = positionDist(gen);
    int y = positionDist(gen);
    return std::make_unique<House>(x, y, district, quality, garageSize, hasPool, residents, floors, hasGarden);
}

/**
 * @brief Creates an estate building with randomly generated x and y coordinates.
 * 
 * @param garageSize The size of the garage.
 * @param hasPool Whether the estate has a pool.
 * @param residents The number of residents.
 * @param floors The number of floors.
 * @param hasGarden Whether the estate has a garden.
 * @param units The number of units in the estate.
 * @param district The district where the estate is located.
 * @param quality The quality level of the estate.
 * @return A unique pointer to the created estate building.
 */
std::unique_ptr<BuildingComponent> ResidentialBuildingFactory::createEstate(int garageSize, bool hasPool, int residents, int floors, bool hasGarden, int units, const std::string& district, int quality) {
    std::mt19937 gen(static_cast<unsigned>(std::time(0))); 
    std::uniform_int_distribution<> positionDist(0, 159);
    int x = positionDist(gen);
    int y = positionDist(gen);
    return std::make_unique<Estate>(x, y, district, quality, garageSize, hasPool, residents, floors, hasGarden, units);
}
