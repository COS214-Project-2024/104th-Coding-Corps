#include "Hospital.h"
#include <iostream>

Hospital::Hospital(int x, int y, const std::string& district, int quality, int numWorkers)
    : ServiceBuildings(x, y, district, quality, numWorkers), qualityOfCare(0) {}

/**
 * @brief Gets the type of building.
 * @return The string "Hospital".
 */
std::string Hospital::getBuildingType() {
    return "Hospital";
}

/**
 * @brief Gets the occupancy of the hospital.
 * @return The number of patients the hospital can accommodate.
 */
int Hospital::getOccupancy() {
    return 5000;
}

/**
 * @brief Gets the cost of constructing the hospital.
 * @return The construction cost in ZAR.
 */
double Hospital::getCost() {
    return 7000000.0; // Example cost in ZAR
}

/**
 * @brief Gets the maintenance cost of the hospital.
 * @return The maintenance cost as a percentage of the total cost.
 */
double Hospital::getMaintenanceCost() {
    return 0.05 * getCost(); // 5% of cost as maintenance
}

/**
 * @brief Gets the energy consumption of the hospital.
 * @return The monthly energy consumption in kWh.
 */
double Hospital::getEnergyConsumption() {
    return numWorkers * 400.0; // 400 kWh per worker per month
}

/**
 * @brief Gets the water consumption of the hospital.
 * @return The monthly water consumption in liters.
 */
double Hospital::getWaterConsumption() {
    return numWorkers * 150.0; // 150 liters per worker per month
}

/**
 * @brief Demolishes the hospital building and resets its attributes.
 */
void Hospital::demolish() {
    std::cout << "Demolishing the hospital building." << std::endl;
    qualityOfCare = 0;
    quality = 0;
    numWorkers = 0;
}

/**
 * @brief Upgrades the hospital building.
 * @param building A shared pointer to a BuildingComponent (for resource management).
 */
void Hospital::upgrade(std::shared_ptr<BuildingComponent> building) {
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
        qualityOfCare += 5; // Example improvement in quality of care
        std::cout << "Hospital upgraded successfully!" << std::endl;
    } else {
        std::cout << "Upgrade failed due to insufficient resources." << std::endl;
    }
}

/**
 * @brief Calculates the area of the hospital building.
 * @return The area of the building.
 */
double Hospital::getArea() {
    return getX() * getY();
}

/**
 * @brief Gets the quality of care provided by the hospital.
 * @return The quality of care.
 */
int Hospital::getQualityOfCare() {
    return qualityOfCare;
}