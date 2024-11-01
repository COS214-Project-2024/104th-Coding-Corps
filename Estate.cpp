#include "Estate.h"
#include <stdexcept>

/**
 * @brief Constructs an Estate object with specified parameters.
 * 
 * Initializes an Estate with the given coordinates, district, quality, 
 * garage size, pool availability, number of residents, number of floors, 
 * garden availability, and number of units.
 * 
 * @param x The x-coordinate of the estate.
 * @param y The y-coordinate of the estate.
 * @param district The district where the estate is located.
 * @param quality The quality rating of the estate.
 * @param garageSize The size of the garage in the estate.
 * @param hasPool Whether the estate has a swimming pool.
 * @param residents The number of residents in the estate.
 * @param floors The number of floors in the estate.
 * @param hasGarden Whether the estate has a garden.
 * @param units The number of units in the estate.
 */
Estate::Estate(int x, int y, const std::string& district, int quality, int garageSize, bool hasPool, int residents, int floors, bool hasGarden, int units)
    : ResidentialBuildings(x, y, district, quality, residents, floors, hasGarden), garageSize(garageSize), numUnits(units), pool(hasPool) {}

/**
 * @brief Gets the size of the garage.
 * 
 * @return The size of the garage in the estate.
 */
int Estate::getGarageSize() const {
    return garageSize;
}

/**
 * @brief Checks if the estate has a swimming pool.
 * 
 * @return True if the estate has a pool; otherwise, false.
 */
bool Estate::hasSwimmingPool() const {
    return pool;
}

/**
 * @brief Gets the type of the building.
 * 
 * @return A string representing the building type "Estate".
 */
std::string Estate::getBuildingType() {
    return "Estate";
}

/**
 * @brief Calculates the cost of the estate.
 * 
 * @return The total cost based on the number of units in the estate.
 */
double Estate::getCost() {
    const double unitCost = 3000000.0; // Base cost per unit
    return unitCost * this->numUnits;
}

/**
 * @brief Calculates the maintenance cost of the estate.
 * 
 * @return The total maintenance cost based on the number of units and pool maintenance if applicable.
 */
double Estate::getMaintenanceCost() {
    double baseMaintenance = 8000.0 * this->numUnits; // Base maintenance cost per unit
    if (pool) {
        baseMaintenance += 5000.0; // Additional maintenance for pool
    }
    return baseMaintenance;
}

/**
 * @brief Calculates the total energy consumption of the estate.
 * 
 * @return The total energy consumption based on the number of units.
 */
double Estate::getEnergyConsumption() {
    const double energyPerUnit = 500.0; // Energy consumption per unit
    return energyPerUnit * this->numUnits;
}

/**
 * @brief Calculates the total water consumption of the estate.
 * 
 * @return The total water consumption based on the number of units.
 */
double Estate::getWaterConsumption() {
    const double waterPerUnit = 7000.0; // Water consumption per unit
    return waterPerUnit * this->numUnits;
}

/**
 * @brief Constructs the estate, initializing attributes for residents and floors.
 * 
 * This function sets the number of residents to four times the number of units 
 * and assumes most estates have two floors.
 */
void Estate::construct() {
    this->numResidents = 4 * this->numUnits; // Assuming 4 residents per unit
    this->numFloors = 2; // Assuming most estates are 2 floors high
}

/**
 * @brief Demolishes the estate by resetting its attributes.
 * 
 * This function resets the number of residents, floors, pool, garage size, 
 * and number of units to simulate the demolition of the estate.
 */
void Estate::demolish() {
    this->numResidents = 0;
    this->numFloors = 0;
    this->pool = false;
    this->garageSize = 0;
    this->numUnits = 0;
}

/**
 * @brief Gets the total number of residents in the estate.
 * 
 * @return The total number of residents, calculated as four times the number of units.
 */
int Estate::getNumResidents() {
    return 4 * this->numUnits; // Assuming each unit houses 4 residents
}

/**
 * @brief Calculates the total area of the estate, accounting for units and garage size.
 * 
 * @return The total area of the estate.
 */
double Estate::getArea() {
    const double unitArea = getX() * getY(); // Area for each unit
    const double garageAreaFactor = 40.0; // Garage area for each car space
    return (unitArea * this->numUnits) + (garageAreaFactor * this->garageSize);
}

/**
 * @brief Gets the occupancy of the estate.
 * 
 * @return The number of units in the estate.
 */
int Estate::getOccupancy() {
    return numUnits;
}

/**
 * @brief Upgrades the estate if sufficient resources are available.
 * 
 * This function requests resources from the Government and, if available,
 * increases the quality of the estate. If resources are insufficient, it 
 * indicates the upgrade failed.
 * 
 * @param building A shared pointer to a BuildingComponent (not used in this implementation).
 */
void Estate::upgrade(std::shared_ptr<BuildingComponent> building) {
    auto government = Government::getInstance();
    
    // Example resource requirements for upgrading
    const int requiredConcrete = 100;
    const int requiredSteel = 50;

    // Request resources from Government
    bool hasConcrete = government->useResource("Concrete", requiredConcrete);
    bool hasSteel = government->useResource("Steel", requiredSteel);

    if (hasConcrete && hasSteel) {
        // Perform upgrade logic if resources are available
        quality += 10;  // Example improvement in quality
        std::cout << "Estate upgraded successfully!" << std::endl;
    } else {
        std::cout << "Upgrade failed due to insufficient resources." << std::endl;
    }
}
