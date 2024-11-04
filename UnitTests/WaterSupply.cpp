#include "WaterSupply.h"
#include <iostream>

/**
 * @brief Constructs a WaterSupply utility instance.
 */
WaterSupply::WaterSupply() : Utilities("Water Supply", true) {}

/**
 * @brief Gets the consumption rate of water per building per day.
 * 
 * @return The base consumption rate in liters.
 */
double WaterSupply::getConsumptionRate() {
    const double baseConsumptionRate = 1000.0; // Liters per building per day
    return baseConsumptionRate;
}

/**
 * @brief Gets the monthly cost of the water supply utility.
 * 
 * @return The base monthly cost in ZAR.
 */
double WaterSupply::getCost() {
    const double baseCost = 50000.0; // Monthly cost in ZAR
    return baseCost;
}

/**
 * @brief Activates the water supply utility.
 */
void WaterSupply::activateUtility() {
    changeStatus(true);
    std::cout << "Water Supply Utility is now active." << std::endl;
}

/**
 * @brief Deactivates the water supply utility.
 */
void WaterSupply::deactivateUtility() {
    changeStatus(false);
    std::cout << "Water Supply Utility has been deactivated." << std::endl;
}

/**
 * @brief Distributes water to the specified building.
 * 
 * @param building A shared pointer to the BuildingComponent receiving water.
 */
void WaterSupply::distributeWater(std::shared_ptr<BuildingComponent> building) {
    const double waterDemandPerBuilding = 1.2 * getConsumptionRate(); // Adjusted demand per building
    std::cout << "Distributing " << waterDemandPerBuilding << " liters of water to " 
              << building->getBuildingType() << "." << std::endl;
}
