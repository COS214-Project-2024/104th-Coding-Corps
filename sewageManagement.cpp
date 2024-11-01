#include "sewageManagement.h"
#include <iostream>

/**
 * @brief Constructs a SewageManagement utility instance.
 * 
 * This constructor initializes the SewageManagement utility with 
 * a name and an active status.
 */
SewageManagement::SewageManagement() : Utilities("Sewage Management", true) {}

/**
 * @brief Retrieves the consumption rate of the sewage management system.
 * 
 * This method returns the base consumption rate of sewage 
 * in cubic meters per month.
 * 
 * @return The base consumption rate (units consumed per cubic meter).
 */
double SewageManagement::getConsumptionRate() {
    const double baseConsumptionRate = 15.0; // Units consumed per cubic meter
    return baseConsumptionRate;
}

/**
 * @brief Retrieves the monthly cost of the sewage management system.
 * 
 * This method returns the base monthly cost of operating the 
 * sewage management system in ZAR.
 * 
 * @return The base monthly cost of sewage management.
 */
double SewageManagement::getCost() {
    const double baseCost = 120000.0; // Monthly cost in ZAR
    return baseCost;
}

/**
 * @brief Activates the sewage management utility.
 * 
 * This method changes the status of the sewage management utility 
 * to active and outputs a message indicating its activation.
 */
void SewageManagement::activateUtility() {
    changeStatus(true);
    std::cout << "Sewage Management Utility is now active." << std::endl;
}

/**
 * @brief Deactivates the sewage management utility.
 * 
 * This method changes the status of the sewage management utility 
 * to inactive and outputs a message indicating its deactivation.
 */
void SewageManagement::deactivateUtility() {
    changeStatus(false);
    std::cout << "Sewage Management Utility has been deactivated." << std::endl;
}

/**
 * @brief Manages sewage processing for a specific building.
 * 
 * This method calculates the total sewage processed based on 
 * the sewage generated per building and outputs the amount 
 * of sewage being processed from the specified building.
 * 
 * @param building A pointer to the BuildingComponent object 
 *                 whose sewage is being managed.
 */
void SewageManagement::manageSewage(BuildingComponent* building) {
    const double sewageGeneratedPerBuilding = 2.0; // Cubic meters per month
    double totalSewageProcessed = sewageGeneratedPerBuilding * getConsumptionRate();

    std::cout << "Processing " << totalSewageProcessed << " cubic meters of sewage from " 
              << building->getBuildingType() << "." << std::endl;
}
