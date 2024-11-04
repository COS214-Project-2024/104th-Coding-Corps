#include "Shop.h"
#include <iostream>

/**
 * @brief Constructs a Shop object.
 * 
 * @param shopSize Size of the shop in square meters.
 * @param businessType Type of business for the shop.
 * @param x X-coordinate of the shop's location.
 * @param y Y-coordinate of the shop's location.
 * @param district District where the shop is located.
 * @param quality Quality rating of the shop.
 */
Shop::Shop(int shopSize, std::string businessType, int x, int y, const std::string& district, int quality)
    : CommercialBuildings(x, y, district, quality, businessType, 1), shopSize(shopSize) {
    this->construct();
}

/**
 * @brief Gets the cost of the shop.
 * 
 * @return The base cost of the shop in ZAR.
 */
double Shop::getCost() {
    return 2000000; // Base cost in ZAR
}

/**
 * @brief Gets the type of building.
 * 
 * @return A string representing the building type, which is "Shop".
 */
std::string Shop::getBuildingType() {
    return "Shop";
}

/**
 * @brief Gets the monthly maintenance cost of the shop.
 * 
 * @return The maintenance cost, calculated as 2% of the shop’s cost.
 */
double Shop::getMaintenanceCost() {
    const double maintenanceRate = 0.02; // 2% of the shop’s cost per month
    return getCost() * maintenanceRate;
}

/**
 * @brief Gets the monthly energy consumption of the shop.
 * 
 * @return The total energy consumption in kWh based on the area of the shop.
 */
double Shop::getEnergyConsumption() {
    const double energyPerSquareMeter = 300.0; // kWh per square meter per month
    return energyPerSquareMeter * getArea();
}

/**
 * @brief Gets the monthly water consumption of the shop.
 * 
 * @return The total water consumption in liters based on the area of the shop.
 */
double Shop::getWaterConsumption() {
    const double waterPerSquareMeter = 100.0; // liters per square meter per month
    return waterPerSquareMeter * getArea();
}

/**
 * @brief Constructs the shop and displays a message.
 */
void Shop::construct() {
    std::cout << "Constructing a new shop with a size of " << shopSize << " square meters." << std::endl;
}

/**
 * @brief Demolishes the shop and resets its size.
 */
void Shop::demolish() {
    std::cout << "The shop is being demolished." << std::endl;
    shopSize = 0; // Resetting shop size to represent demolition
}

/**
 * @brief Gets the area of the shop.
 * 
 * @return The area of the shop based on its size.
 */
double Shop::getArea() {
    return static_cast<double>(shopSize); // Returns the area based on `shopSize`
}

/**
 * @brief Gets the occupancy of the shop.
 * 
 * @return The occupancy, which is set to 1 for this implementation.
 */
int Shop::getOccupancy(){
    return 1;
}

/**
 * @brief Upgrades the shop if sufficient resources are available.
 * 
 * @param building A shared pointer to a BuildingComponent (not used in this implementation).
 */
void Shop::upgrade(std::shared_ptr<BuildingComponent> building) {
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
        std::cout << "Estate upgraded successfully!" << std::endl;
    } else {
        std::cout << "Upgrade failed due to insufficient resources." << std::endl;
    }
}
