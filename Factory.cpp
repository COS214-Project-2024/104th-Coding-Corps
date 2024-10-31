#include "Factory.h"
#include <iostream>
#include "Government.h" // Assuming there is a Government class to manage resources

/**
 * @brief Constructs a factory with the given parameters and initializes the base class.
 * 
 * @param x The x-coordinate of the factory.
 * @param y The y-coordinate of the factory.
 * @param district The district where the factory is located.
 * @param quality The quality rating of the factory.
 * @param numWorkers The number of workers in the factory.
 * @param factoryType The type of the factory.
 * @param production The production capacity of the factory.
 */
factory::factory(int x, int y, const std::string& district, int quality, int numWorkers, const std::string& factoryType, double production)
    : IndustrialBuildings(x, y, district, quality, production, numWorkers), factoryType(factoryType) {
    this->construct();
}

/**
 * @brief Gets the type of the factory.
 * 
 * @return The factory type.
 */
std::string factory::getFactoryType() {
    return factoryType;
}

/**
 * @brief Produces goods based on the occupancy of the factory.
 */
void factory::produceGoods() {
    const double goodsPerWorker = 10.0; // Units per worker per cycle
    double totalGoodsProduced = goodsPerWorker * getOccupancy();
    
    std::string productType = getFactoryType();
    std::cout << "Factory (" << productType << ") produced " << totalGoodsProduced << " units of goods this cycle." << std::endl;
}

/**
 * @brief Gets the type of building.
 * 
 * @return A string representing the type of building ("Factory").
 */
std::string factory::getBuildingType() {
    return "Factory";
}

/**
 * @brief Gets the occupancy of the factory.
 * 
 * @return The occupancy level of the factory.
 */
int factory::getOccupancy() {
    return 150; // Example occupancy value
}

/**
 * @brief Gets the cost of constructing the factory.
 * 
 * @return The cost of the factory.
 */
double factory::getCost() {
    return 150000000;  // Cost in ZAR
}

/**
 * @brief Calculates the maintenance cost of the factory.
 * 
 * @return The maintenance cost of the factory.
 */
double factory::getMaintenanceCost() {
    const double maintenanceRate = 0.05; // 5% of the cost
    return getCost() * maintenanceRate;
}

/**
 * @brief Calculates the energy consumption of the factory.
 * 
 * @return The energy consumption based on the number of workers.
 */
double factory::getEnergyConsumption() {
    const double energyPerWorker = 500.0; // kWh per worker per month
    return energyPerWorker * getOccupancy();
}

/**
 * @brief Calculates the water consumption of the factory.
 * 
 * @return The water consumption based on the number of workers.
 */
double factory::getWaterConsumption() {
    const double waterPerWorker = 2000.0; // liters per worker per month
    return waterPerWorker * getOccupancy();
}

/**
 * @brief Demolishes the factory by resetting its attributes.
 */
void factory::demolish() {
    std::cout << "Factory is being demolished." << std::endl;
    this->factoryType = "";
    this->numWorkers = 0;
    this->productionCapacity = 0; // Ensure to reset production capacity
}

/**
 * @brief Upgrades the factory by checking for available resources and updating attributes.
 * 
 * @param building A shared pointer to the building component to upgrade.
 */
void factory::upgrade(std::shared_ptr<BuildingComponent> building) {
    auto government = Government::getInstance();
    
    // Example resource requirements for upgrading
    const int requiredSteel = 300; // Example requirement
    const int requiredMachines = 100; // Example requirement

    // Request resources from Government
    bool hasSteel = government->useResource("Steel", requiredSteel);
    bool hasMachines = government->useResource("Machines", requiredMachines);

    if (hasSteel && hasMachines) {
        // Perform upgrade logic if resources are available
        factoryType += " (Upgraded)"; // Mark the factory as upgraded
        std::cout << "Factory upgraded successfully!" << std::endl;
    } else {
        std::cout << "Upgrade failed due to insufficient resources." << std::endl;
    }
}

/**
 * @brief Gets the area of the factory based on its dimensions.
 * 
 * @return The area of the factory.
 */
double factory::getArea() {
    return getX() * getY();
}
