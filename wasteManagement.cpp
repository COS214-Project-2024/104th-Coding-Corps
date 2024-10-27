#include "wasteManagement.h"
#include <iostream>

WasteManagement::WasteManagement() : Utilities("Waste Management", true) {}

double WasteManagement::getConsumptionRate() {
    const double baseConsumptionRate = 20.0; // Consumption rate per ton in energy 
    return baseConsumptionRate;
}

double WasteManagement::getCost() {
    const double baseCost = 100000.0; 
    return baseCost;
}

void WasteManagement::activateUtility() {
    changeStatus(true);
    std::cout << "Waste Management Utility is now active." << std::endl;
}

void WasteManagement::deactivateUtility() {
    changeStatus(false);
    std::cout << "Waste Management Utility has been deactivated." << std::endl;
}

void WasteManagement::processWaste(BuildingComponent* building) {
    const double wasteGeneratedPerBuilding = 1.5; 
    double totalWasteProcessed = wasteGeneratedPerBuilding * getConsumptionRate();

    std::cout << "Processing " << totalWasteProcessed << " tons of waste from " 
              << building->getBuildingType() << "." << std::endl;
}
