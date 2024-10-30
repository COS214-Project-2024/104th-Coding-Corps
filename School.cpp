#include "School.h"
#include <iostream>

School::School(int x, int y, const std::string& district, int quality, int numWorkers, int highestQualification)
    : ServiceBuildings(x, y, district, quality, numWorkers), highestQualification(highestQualification) {}

/**
 * @brief Gets the type of building.
 * @return The string "School".
 */
std::string School::getBuildingType() {
    return "School";
}

/**
 * @brief Gets the occupancy of the school.
 * @return The number of students the school can accommodate.
 */
int School::getOccupancy() {
    return 1500; // Example occupancy
}

/**
 * @brief Gets the cost of constructing the school.
 * @return The construction cost in ZAR.
 */
double School::getCost() {
    return 3000000.0; // Example cost in ZAR
}

/**
 * @brief Gets the maintenance cost of the school.
 * @return The maintenance cost as a percentage of the total cost.
 */
double School::getMaintenanceCost() {
    return 0.03 * getCost(); // 3% of cost as maintenance
}

/**
 * @brief Gets the energy consumption of the school.
 * @return The monthly energy consumption in kWh.
 */
double School::getEnergyConsumption() {
    return numWorkers * 200.0; // 200 kWh per worker per month
}

/**
 * @brief Gets the water consumption of the school.
 * @return The monthly water consumption in liters.
 */
double School::getWaterConsumption() {
    return numWorkers * 80.0; // 80 liters per worker per month
}

/**
 * @brief Demolishes the school building and resets its attributes.
 */
void School::demolish() {
    std::cout << "Demolishing the school building." << std::endl;
    highestQualification = 0;
    quality = 0;
    numWorkers = 0;
}

/**
 * @brief Upgrades the school building.
 * @param building A shared pointer to a BuildingComponent (for resource management).
 */
void School::upgrade(std::shared_ptr<BuildingComponent> building) {
    auto government = Government::getInstance();
    
    // Example resource requirements for upgrading
    const int requiredConcrete = 50; // Adjust as needed
    const int requiredSteel = 30; // Adjust as needed

    // Request resources from Government
    bool hasConcrete = government->useResource("Concrete", requiredConcrete);
    bool hasSteel = government->useResource("Steel", requiredSteel);

    if (hasConcrete && hasSteel) {
        // Perform upgrade logic if resources are available
        quality += 10; // Example improvement in quality
        std::cout << "School upgraded successfully!" << std::endl;
    } else {
        std::cout << "Upgrade failed due to insufficient resources." << std::endl;
    }
}

/**
 * @brief Calculates the area of the school building.
 * @return The area of the building.
 */
double School::getArea() {
    return getX() * getY();
}

/**
 * @brief Gets the highest qualification level.
 * @return The highest qualification level.
 */
int School::getHighestQualification() {
    return highestQualification;
}
