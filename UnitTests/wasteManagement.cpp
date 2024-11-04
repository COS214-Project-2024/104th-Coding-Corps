#include "wasteManagement.h"
#include <iostream>

/**
 * @brief Constructs a WasteManagement utility service.
 */
WasteManagement::WasteManagement() : Utilities("Waste Management", true) {}

/**
 * @brief Gets the consumption rate of the Waste Management utility.
 * 
 * @return The base consumption rate per ton in energy.
 */
double WasteManagement::getConsumptionRate() {
    const double baseConsumptionRate = 20.0; // Consumption rate per ton in energy 
    return baseConsumptionRate;
}

/**
 * @brief Gets the monthly cost of the Waste Management utility.
 * 
 * @return The base monthly cost of the utility.
 */
double WasteManagement::getCost() {
    const double baseCost = 100000.0; 
    return baseCost;
}

/**
 * @brief Activates the Waste Management utility service.
 */
void WasteManagement::activateUtility() {
    changeStatus(true);
    std::cout << "Waste Management Utility is now active." << std::endl;
}

/**
 * @brief Deactivates the Waste Management utility service.
 */
void WasteManagement::deactivateUtility() {
    changeStatus(false);
    std::cout << "Waste Management Utility has been deactivated." << std::endl;
}

/**
 * @brief Processes waste generated from a building.
 * 
 * @param building A pointer to the BuildingComponent from which waste is processed.
 */
void WasteManagement::processWaste(BuildingComponent* building) {
    const double wasteGeneratedPerBuilding = 1.5; 
    double totalWasteProcessed = wasteGeneratedPerBuilding * getConsumptionRate();

    std::cout << "Processing " << totalWasteProcessed << " tons of waste from " 
              << building->getBuildingType() << "." << std::endl;
}
