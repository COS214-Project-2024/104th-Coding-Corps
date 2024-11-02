#include "plant.h"
#include <iostream>

/**
 * @brief Constructs a plant with the given parameters and initializes the base class.
 * 
 * @param x The x-coordinate of the building.
 * @param y The y-coordinate of the building.
 * @param district The district where the building is located.
 * @param quality The quality rating of the building.
 * @param production The production capacity of the plant.
 * @param workers The number of workers in the plant.
 */
plant::plant(int x, int y, const std::string& district, int quality, double production, int workers)
    : IndustrialBuildings(x, y, district, quality, production, workers) {}

/**
 * @brief Generates electricity based on the number of workers.
 * 
 * @param building A shared pointer to the associated building component.
 */
void plant::generateElectricity(std::shared_ptr<BuildingComponent> building) {
    const double electricityPerWorker = 200.0; // kWh per worker per cycle
    double totalElectricityGenerated = electricityPerWorker * getNumWorkers();
    std::cout << "Plant generated " << totalElectricityGenerated << " kWh of electricity this cycle." << std::endl;
}

/**
 * @brief Gets the type of the building.
 * 
 * @return A string representing the type of building ("Plant").
 */
std::string plant::getBuildingType() {
    return "Plant";
}

/**
 * @brief Gets the cost of constructing the plant.
 * 
 * @return The cost of the plant.
 */
double plant::getCost() {
    return 220000000; 
}

/**
 * @brief Calculates the maintenance cost of the plant.
 * 
 * @return The maintenance cost of the plant.
 */
double plant::getMaintenanceCost() {
    const double maintenanceRate = 0.04; // 4% of the cost
    return getCost() * maintenanceRate;
}

/**
 * @brief Calculates the energy consumption of the plant.
 * 
 * @return The energy consumption based on the number of workers.
 */
double plant::getEnergyConsumption() {
    const double energyPerWorker = 300.0; // kWh per worker per month
    return energyPerWorker * getNumWorkers();
}

/**
 * @brief Calculates the water consumption of the plant.
 * 
 * @return The water consumption based on the number of workers.
 */
double plant::getWaterConsumption() {
    const double waterPerWorker = 2500.0; // liters per worker per month
    return waterPerWorker * getNumWorkers();
}

/**
 * @brief Demolishes the plant by resetting its attributes.
 */
void plant::demolish() {
    std::cout << "Plant is being demolished." << std::endl;
    this->productionCapacity = 0;
    this->numWorkers = 0;
}

/**
 * @brief Upgrades the plant's production capacity if sufficient resources are available.
 * 
 * @param building A shared pointer to the building component to upgrade.
 */
void plant::upgrade(std::shared_ptr<BuildingComponent> building) {
    auto government = Government::getInstance();
    
    // Example resource requirements for upgrading
    const int requiredConcrete = 50;
    const int requiredSteel = 30;

    // Request resources from Government
    bool hasConcrete = government->useResource("Concrete", requiredConcrete);
    bool hasSteel = government->useResource("Steel", requiredSteel);

    if (hasConcrete && hasSteel) {
        // Perform upgrade logic if resources are available
        this->productionCapacity *= 1.2; // Example improvement in production capacity
        std::cout << "Plant upgraded successfully!" << std::endl;
    } else {
        std::cout << "Upgrade failed due to insufficient resources." << std::endl;
    }
}

/**
 * @brief Gets the area of the plant based on its dimensions.
 * 
 * @return The area of the plant.
 */
double plant::getArea() {
    return getX() * getY();
}

/**
 * @brief Gets the occupancy of the plant.
 * 
 * @return The occupancy level of the plant.
 */
int plant::getOccupancy() {
    return 150;
}
