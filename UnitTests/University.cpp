#include "University.h"
#include <iostream>

University::University(int x, int y, const std::string& district, int quality, int numWorkers, int highestQualification)
    : ServiceBuildings(x, y, district, quality, numWorkers), highestQualification(highestQualification) {}

/**
 * @brief Gets the type of building.
 * @return The string "University".
 */
std::string University::getBuildingType() {
    return "University";
}

/**
 * @brief Gets the occupancy of the university.
 * @return The number of students the university can accommodate.
 */
int University::getOccupancy() {
    return 20000; // Example occupancy
}

/**
 * @brief Gets the cost of constructing the university.
 * @return The construction cost in ZAR.
 */
double University::getCost() {
    return 10000000.0; // Example cost in ZAR
}

/**
 * @brief Gets the maintenance cost of the university.
 * @return The maintenance cost as a percentage of the total cost.
 */
double University::getMaintenanceCost() {
    return 0.04 * getCost(); // 4% of cost as maintenance
}

/**
 * @brief Gets the energy consumption of the university.
 * @return The monthly energy consumption in kWh.
 */
double University::getEnergyConsumption() {
    return numWorkers * 300.0; // 300 kWh per worker per month
}

/**
 * @brief Gets the water consumption of the university.
 * @return The monthly water consumption in liters.
 */
double University::getWaterConsumption() {
    return numWorkers * 100.0; // 100 liters per worker per month
}

/**
 * @brief Demolishes the university building and resets its attributes.
 */
void University::demolish() {
    std::cout << "Demolishing the university building." << std::endl;
    highestQualification = 0;
    quality = 0;
    numWorkers = 0;
}

/**
 * @brief Upgrades the university building.
 * @param building A shared pointer to a BuildingComponent (for resource management).
 */
void University::upgrade(std::shared_ptr<BuildingComponent> building) {
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
 * @brief Calculates the area of the university building.
 * @return The area of the building.
 */
double University::getArea() {
    return getX() * getY();
}

/**
 * @brief Gets the highest qualification level.
 * @return The highest qualification level.
 */
int University::getHighestQualification() {
    return highestQualification;
}
