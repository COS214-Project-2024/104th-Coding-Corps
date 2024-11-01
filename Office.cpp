#include "Office.h"
#include <iostream>

/**
 * @brief Constructs an Office object.
 * 
 * Initializes the office with the specified number of employees,
 * business type, and location attributes.
 * 
 * @param numEmployees The number of employees in the office.
 * @param businessType The type of business operating in the office.
 * @param x The x-coordinate of the office.
 * @param y The y-coordinate of the office.
 * @param district The district where the office is located.
 * @param quality The quality rating of the office.
 */
Office::Office(int numEmployees, std::string businessType, int x, int y, const std::string& district, int quality)
    : CommercialBuildings(x, y, district, quality, businessType, 1), numEmployees(numEmployees) {
    this->construct();
}

/**
 * @brief Gets the number of employees in the office.
 * 
 * @return The number of employees.
 */
int Office::getNumEmployees() {
    return this->numEmployees;
}

/**
 * @brief Gets the type of building.
 * 
 * @return The building type as a string.
 */
std::string Office::getBuildingType() {
    return "Office";
}

/**
 * @brief Calculates the total cost of the office.
 * 
 * @return The fixed cost of the office.
 */
double Office::getCost() {
    return 3000000; // Fixed cost for the office
}

/**
 * @brief Calculates the monthly maintenance cost of the office.
 * 
 * @return The maintenance cost as a percentage of the total cost.
 */
double Office::getMaintenanceCost() {
    const double maintenanceRate = 0.02; // 2% of the cost per month
    return getCost() * maintenanceRate;
}

/**
 * @brief Calculates the monthly energy consumption of the office.
 * 
 * @return The energy consumption based on the number of employees.
 */
double Office::getEnergyConsumption() {
    // Assuming each employee consumes 300 kWh per month
    const double energyPerEmployee = 300.0;
    return energyPerEmployee * getNumEmployees();
}

/**
 * @brief Calculates the monthly water consumption of the office.
 * 
 * @return The water consumption based on the number of employees.
 */
double Office::getWaterConsumption() {
    // Assuming each employee uses 1500 liters of water per month
    const double waterPerEmployee = 1500.0;
    return waterPerEmployee * getNumEmployees();
}

/**
 * @brief Constructs the office.
 * 
 * Prints a message indicating that the office is being constructed.
 */
void Office::construct() {
    std::cout << "Constructing an office building for " << numEmployees 
              << " employees " << std::endl;
}

/**
 * @brief Demolishes the office.
 * 
 * Resets the number of employees to represent demolition and prints a message.
 */
void Office::demolish() {
    std::cout << "The office building is being demolished." << std::endl;
    numEmployees = 0;     // Reset number of employees to represent demolition
}

/**
 * @brief Calculates the area of the office.
 * 
 * @return The area of the office.
 */
double Office::getArea() {
    return getX() * getY();
}

/**
 * @brief Gets the occupancy of the office.
 * 
 * @return The occupancy rate, assumed to be 150.
 */
int Office::getOccupancy() {
    return 150;
}

/**
 * @brief Upgrades the office if sufficient resources are available.
 * 
 * Requests resources from the government and upgrades the quality if possible.
 * 
 * @param building A shared pointer to the building component being upgraded.
 */
void Office::upgrade(std::shared_ptr<BuildingComponent> building) {
    auto government = Government::getInstance();
    
    // Example resource requirements for upgrading
    const int requiredConcrete = 100;
    const int requiredSteel = 50;

    // Request resources from Government
    bool hasConcrete = government->useResource("Concrete", requiredConcrete);
    bool hasSteel = government->useResource("Steel", requiredSteel);

    if (hasConcrete && hasSteel) {
        // Perform upgrade logic if resources are available
        quality += 10;  // Example improvement in quality
        std::cout << "Office upgraded successfully!" << std::endl;
    } else {
        std::cout << "Upgrade failed due to insufficient resources." << std::endl;
    }
}
