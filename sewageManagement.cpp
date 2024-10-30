#include "sewageManagement.h"
#include <iostream>

SewageManagement::SewageManagement() : Utilities("Sewage Management", true) {}

double SewageManagement::getConsumptionRate() {
    const double baseConsumptionRate = 15.0; // Units consumed per cubic meter
    return baseConsumptionRate;
}

double SewageManagement::getCost() {
    const double baseCost = 120000.0; // Monthly cost in ZAR
    return baseCost;
}

void SewageManagement::activateUtility() {
    changeStatus(true);
    std::cout << "Sewage Management Utility is now active." << std::endl;
}

void SewageManagement::deactivateUtility() {
    changeStatus(false);
    std::cout << "Sewage Management Utility has been deactivated." << std::endl;
}

void SewageManagement::manageSewage(BuildingComponent* building) {
    const double sewageGeneratedPerBuilding = 2.0; // Cubic meters per month
    double totalSewageProcessed = sewageGeneratedPerBuilding * getConsumptionRate();

    std::cout << "Processing " << totalSewageProcessed << " cubic meters of sewage from " 
              << building->getBuildingType() << "." << std::endl;
}
