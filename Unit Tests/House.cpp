#include "House.h"
#include <iostream>

House::House(int x, int y, const std::string& district, int quality, int garageSize, bool hasPool, int residents, int floors, bool hasGarden)
    : ResidentialBuildings(x, y, district, quality, residents, floors, hasGarden), garageSize(garageSize), pool(hasPool), residents(residents) {}

/**
 * @brief Gets the type of building.
 * @return The string "House".
 */
std::string House::getBuildingType() {
    return "House";
}

/**
 * @brief Gets the occupancy of the house.
 * @return The number of residents the house can accommodate.
 */
int House::getOccupancy() {
    return 10;
}

/**
 * @brief Gets the cost of constructing the house.
 * @return The construction cost in ZAR.
 */
double House::getCost() {
    return 7000000.0; // Example cost in ZAR
}

/**
 * @brief Gets the maintenance cost of the house.
 * @return The maintenance cost as a percentage of the total cost.
 */
double House::getMaintenanceCost() {
    return 0.05 * getCost(); // 5% of cost as maintenance
}

/**
 * @brief Gets the energy consumption of the house.
 * @return The monthly energy consumption in kWh.
 */
double House::getEnergyConsumption() {
    return numResidents * 400.0; // 400 kWh per worker per month
}

/**
 * @brief Gets the water consumption of the house.
 * @return The monthly water consumption in liters.
 */
double House::getWaterConsumption() {
    return numResidents * 150.0; // 150 liters per worker per month
}

/**
 * @brief Demolishes the house building and resets its attributes.
 */
void House::demolish() {
    std::cout << "Demolishing the house building." << std::endl;
    garageSize = 0;
    pool = false;
}

/**
 * @brief Upgrades the house building.
 * @param building A shared pointer to a BuildingComponent (for resource management).
 */
void House::upgrade(std::shared_ptr<BuildingComponent> building) {
    auto government = Government::getInstance();
    
    // Example resource requirements for upgrading
    const int requiredConcrete = 100; // Adjust as needed
    const int requiredSteel = 60; // Adjust as needed

    // Request resources from Government
    bool hasConcrete = government->useResource("Concrete", requiredConcrete);
    bool hasSteel = government->useResource("Steel", requiredSteel);

    if (hasConcrete && hasSteel) {
        // Perform upgrade logic if resources are available
        quality += 10; // Example improvement in quality
        std::cout << "House upgraded successfully!" << std::endl;
    } else {
        std::cout << "Upgrade failed due to insufficient resources." << std::endl;
    }
}

/**
 * @brief Calculates the area of the house building.
 * @return The area of the building.
 */
double House::getArea() {
    return getX() * getY();
}

/**
 * @brief Gets the quality of care provided by the house.
 * @return The quality of care.
 */




int House::getGarageSize() const {
    return this->garageSize;
}

bool House::hasSwimmingPool() const {
    return this->pool;
}

int House::getNumResidents() {
    return this->residents;
}