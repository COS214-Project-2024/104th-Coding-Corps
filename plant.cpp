#include "plant.h"
#include <iostream>

plant::plant(int numWorkers, double productionCapacity)
    : IndustrialBuildings(productionCapacity, numWorkers) {}

void plant::generateElectricity(BuildingComponent* building) {
    // Generate electricity based on the production capacity
    const double electricityPerWorker = 200.0; // kWh per worker per cycle
    double totalElectricityGenerated = electricityPerWorker * getNumWorkers();
    std::cout << "Plant generated " << totalElectricityGenerated << " kWh of electricity this cycle." << std::endl;
}

std::string plant::getBuildingType() {
    return "Plant";
}

double plant::getCost() {
    return 220000000; 
}

double plant::getMaintenanceCost() {
    const double maintenanceRate = 0.04; // 4% of the cost
    return getCost() * maintenanceRate;
}

double plant::getEnergyConsumption() {
    // Plants usually consume energy for operations, calculated based on the number of workers
    const double energyPerWorker = 300.0; // kWh per worker per month
    return energyPerWorker * getNumWorkers();
}

double plant::getWaterConsumption() {
    // Assuming each worker requires 2500 liters of water per month for plant operations
    const double waterPerWorker = 2500.0;
    return waterPerWorker * getNumWorkers();
}

void plant::demolish() {
    // Reset attributes to default, simulating demolition
    std::cout << "Plant is being demolished." << std::endl;
    this->productionCapacity = 0;
    this->numWorkers = 0;
}

void plant::upgrade(BuildingComponent* building) {
    // Upgrading the plant increases production capacity
    std::cout << "Upgrading the plant's production capacity." << std::endl;
    this->productionCapacity *= 1.2; // Increase capacity by 20%
}

double plant::getArea() {
    return getX() * getY();
}

int plant::getOccupancy() {
    return 0;
}

void plant::construct() {
    std::cout << "not yet implemented";
}
