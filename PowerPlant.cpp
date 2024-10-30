#include "PowerPlant.h"
#include <iostream>

PowerPlant::PowerPlant() : Utilities("Power Plant", true) {}

double PowerPlant::getConsumptionRate() {
    const double baseProductionRate = 1500.0; // kWh per building per day
    return baseProductionRate;
}

double PowerPlant::getCost() {
    const double baseCost = 200000.0; // Monthly cost in ZAR
    return baseCost;
}

void PowerPlant::activateUtility() {
    changeStatus(true);
    std::cout << "Power Plant Utility is now active." << std::endl;
}

void PowerPlant::deactivateUtility() {
    changeStatus(false);
    std::cout << "Power Plant Utility has been deactivated." << std::endl;
}

void PowerPlant::generateEnergy(BuildingComponent* building) {
    const double energyProduced = 1.1 * getConsumptionRate(); // Adjusted production rate per building
    std::cout << "Generating " << energyProduced << " kWh of energy for " 
              << building->getBuildingType() << "." << std::endl;
}
