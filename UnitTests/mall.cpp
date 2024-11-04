#include "mall.h"
#include <iostream>

/**
 * @brief Constructs a Mall object.
 * 
 * Initializes the mall with the specified number of shops, business type,
 * number of businesses, and location attributes.
 * 
 * @param numShops The number of shops in the mall.
 * @param businessType The type of businesses operating in the mall.
 * @param numBusinesses The total number of businesses in the mall.
 * @param x The x-coordinate of the mall.
 * @param y The y-coordinate of the mall.
 * @param district The district where the mall is located.
 * @param quality The quality rating of the mall.
 */
Mall::Mall(int numShops, std::string businessType, int numBusinesses, int x, int y, const std::string& district, int quality)
    : CommercialBuildings(x, y, district, quality, businessType, numBusinesses), numShops(numShops) {
    this->construct();
}

/**
 * @brief Gets the number of shops in the mall.
 * 
 * @return The number of shops.
 */
int Mall::getNumShops() {
    return this->numShops;
}

/**
 * @brief Gets the type of building.
 * 
 * @return The building type as a string.
 */
std::string Mall::getBuildingType() {
    return "Mall";
}

/**
 * @brief Calculates the total cost of the mall.
 * 
 * @return The total cost based on the number of shops.
 */
double Mall::getCost() {
    const double costPerShop = 5000000.0; // 5 million per shop
    return numShops * costPerShop;
}

/**
 * @brief Calculates the monthly maintenance cost of the mall.
 * 
 * @return The maintenance cost as a percentage of the total cost.
 */
double Mall::getMaintenanceCost() {
    const double maintenanceRate = 0.03; // 3% of the cost per month
    return getCost() * maintenanceRate;
}

/**
 * @brief Calculates the monthly energy consumption of the mall.
 * 
 * @return The energy consumption based on the area of the mall.
 */
double Mall::getEnergyConsumption() {
    // Assuming each square meter of the mall uses 400 kWh of energy per month
    const double energyPerSquareMeter = 400.0;
    return energyPerSquareMeter * getArea();
}

/**
 * @brief Calculates the monthly water consumption of the mall.
 * 
 * @return The water consumption based on the area of the mall.
 */
double Mall::getWaterConsumption() {
    // Assuming each square meter of the mall uses 150 liters of water per month
    const double waterPerSquareMeter = 150.0;
    return waterPerSquareMeter * getArea();
}

/**
 * @brief Constructs the mall.
 * 
 * Prints a message indicating that the mall is being constructed.
 */
void Mall::construct() {
    std::cout << "Constructing a new mall with " << numShops << " shops " << std::endl;
    // Additional setup logic if needed
}

/**
 * @brief Demolishes the mall.
 * 
 * Resets the number of shops to represent demolition and prints a message.
 */
void Mall::demolish() {
    std::cout << "The mall is being demolished." << std::endl;
    numShops = 0;       // Reset the number of shops to represent demolition
}

/**
 * @brief Calculates the area of the mall.
 * 
 * @return The area of the mall.
 */
double Mall::getArea() {
    return getX() * getY();
}

/**
 * @brief Gets the occupancy of the mall.
 * 
 * @return The occupancy rate, assumed to be 100%.
 */
int Mall::getOccupancy() {
    return 100;
}

/**
 * @brief Upgrades the mall if sufficient resources are available.
 * 
 * Requests resources from the government and upgrades the quality if possible.
 * 
 * @param building A shared pointer to the building component being upgraded.
 */
void Mall::upgrade(std::shared_ptr<BuildingComponent> building) {
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
        std::cout << "Mall upgraded successfully!" << std::endl;
    } else {
        std::cout << "Upgrade failed due to insufficient resources." << std::endl;
    }
}
