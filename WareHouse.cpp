#include "warehouse.h"
#include <iostream>
#include "Government.h" // Assuming there is a Government class to manage resources

/**
 * @brief Constructs a warehouse with the given parameters and initializes the base class.
 * 
 * @param x The x-coordinate of the building.
 * @param y The y-coordinate of the building.
 * @param district The district where the building is located.
 * @param quality The quality rating of the building.
 * @param storageCapacity The storage capacity of the warehouse.
 * @param numWorkers The number of workers in the warehouse.
 */
Warehouse::Warehouse(int x, int y, const std::string& district, int quality, int storageCapacity, int numWorkers)
    : IndustrialBuildings(x, y, district, quality, 0.0, numWorkers), storageCapacity(storageCapacity) {
    this->construct();
}

/**
 * @brief Gets the storage capacity of the warehouse.
 * 
 * @return The maximum storage capacity of the warehouse.
 */
double Warehouse::getStorageCapacity() {
    return storageCapacity;
}

/**
 * @brief Gets the type of the building.
 * 
 * @return A string representing the type of building ("Warehouse").
 */
std::string Warehouse::getBuildingType() {
    return "Warehouse";
}

/**
 * @brief Gets the cost of constructing the warehouse.
 * 
 * @return The cost of the warehouse.
 */
double Warehouse::getCost() {
    return 90000000; // Warehouse-specific cost in ZAR
}

/**
 * @brief Calculates the maintenance cost of the warehouse.
 * 
 * @return The maintenance cost of the warehouse.
 */
double Warehouse::getMaintenanceCost() {
    const double maintenanceRate = 0.03; // 3% of the total cost
    return getCost() * maintenanceRate;
}

/**
 * @brief Calculates the energy consumption of the warehouse.
 * 
 * @return The energy consumption based on the number of workers.
 */
double Warehouse::getEnergyConsumption() {
    const double energyPerWorker = 400.0; // kWh per worker per month
    return energyPerWorker * getNumWorkers();
}

/**
 * @brief Calculates the water consumption of the warehouse.
 * 
 * @return The water consumption based on the number of workers.
 */
double Warehouse::getWaterConsumption() {
    const double waterPerWorker = 1500.0; // liters per worker per month
    return waterPerWorker * getNumWorkers();
}

/**
 * @brief Constructs the warehouse and outputs construction message.
 */
void Warehouse::construct() {
    std::cout << "Warehouse is under construction." << std::endl;
    // Custom logic for initializing or setting up a new warehouse, if necessary
}

/**
 * @brief Demolishes the warehouse by resetting its attributes.
 */
void Warehouse::demolish() {
    std::cout << "Warehouse is being demolished." << std::endl;
    this->storageCapacity = 0;
    this->numWorkers = 0;
}

/**
 * @brief Upgrades the warehouse's storage capacity.
 * 
 * @param building A shared pointer to the building component to upgrade.
 */
void Warehouse::upgrade(std::shared_ptr<BuildingComponent> building) {
    auto government = Government::getInstance();
    
    // Example resource requirements for upgrading
    const int requiredConcrete = 100; // Example requirement
    const int requiredSteel = 50;      // Example requirement

    // Request resources from Government
    bool hasConcrete = government->useResource("Concrete", requiredConcrete);
    bool hasSteel = government->useResource("Steel", requiredSteel);

    if (hasConcrete && hasSteel) {
        // Perform upgrade logic if resources are available
        storageCapacity *= 1.25; // Increase storage capacity by 25%
        std::cout << "Warehouse upgraded successfully!" << std::endl;
    } else {
        std::cout << "Upgrade failed due to insufficient resources." << std::endl;
    }
}

/**
 * @brief Gets the area of the warehouse based on its dimensions.
 * 
 * @return The area of the warehouse.
 */
double Warehouse::getArea() {
    return getX() * getY();
}

/**
 * @brief Gets the occupancy of the warehouse.
 * 
 * @return The occupancy level of the warehouse.
 */
int Warehouse::getOccupancy() {
    return 1500; // Example occupancy value
}
