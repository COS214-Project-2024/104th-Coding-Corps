#include "WaterSupply.h"
#include <iostream>

WaterSupply::WaterSupply() : Utilities("Water Supply", true) {}

double WaterSupply::getConsumptionRate() {
    const double baseConsumptionRate = 1000.0; // Liters per building per day
    return baseConsumptionRate;
}

double WaterSupply::getCost() {
    const double baseCost = 50000.0; // Monthly cost in ZAR
    return baseCost;
}

void WaterSupply::activateUtility() {
    changeStatus(true);
    std::cout << "Water Supply Utility is now active." << std::endl;
}

void WaterSupply::deactivateUtility() {
    changeStatus(false);
    std::cout << "Water Supply Utility has been deactivated." << std::endl;
}

void WaterSupply::distributeWater(BuildingComponent* building) {
    const double waterDemandPerBuilding = 1.2 * getConsumptionRate(); // Adjusted demand per building
    std::cout << "Distributing " << waterDemandPerBuilding << " liters of water to " 
              << building->getBuildingType() << "." << std::endl;
}
