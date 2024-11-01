#include "PowerPlant.h"
#include <iostream>

/**
 * @brief Constructs a PowerPlant object.
 * 
 * Initializes the power plant utility with a specific name and status.
 */
PowerPlant::PowerPlant() : Utilities("Power Plant", true) {}

/**
 * @brief Gets the consumption rate of the power plant.
 * 
 * @return The base production rate of the power plant in kWh per building per day.
 */
double PowerPlant::getConsumptionRate() {
    const double baseProductionRate = 1500.0; // kWh per building per day
    return baseProductionRate;
}

/**
 * @brief Gets the monthly cost of operating the power plant.
 * 
 * @return The base monthly cost in ZAR.
 */
double PowerPlant::getCost() {
    const double baseCost = 200000.0; // Monthly cost in ZAR
    return baseCost;
}

/**
 * @brief Activates the power plant utility.
 * 
 * Changes the status of the utility to active and prints a message.
 */
void PowerPlant::activateUtility() {
    changeStatus(true);
    std::cout << "Power Plant Utility is now active." << std::endl;
}

/**
 * @brief Deactivates the power plant utility.
 * 
 * Changes the status of the utility to inactive and prints a message.
 */
void PowerPlant::deactivateUtility() {
    changeStatus(false);
    std::cout << "Power Plant Utility has been deactivated." << std::endl;
}

/**
 * @brief Generates energy for a specified building.
 * 
 * Calculates the energy produced based on the consumption rate and prints a message.
 * 
 * @param building A shared pointer to the building component that receives energy.
 */
void PowerPlant::generateEnergy(std::shared_ptr<BuildingComponent> building) {
    const double energyProduced = 1.1 * getConsumptionRate(); // Adjusted production rate per building
    std::cout << "Generating " << energyProduced << " kWh of energy for " 
              << building->getBuildingType() << "." << std::endl;
}
