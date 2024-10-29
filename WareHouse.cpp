#include "warehouse.h"
#include <iostream>

Warehouse::Warehouse(int storageCapacity, int numEmployees)
    : IndustrialBuildings(storageCapacity, numEmployees), storageCapacity(storageCapacity) {
		this->construct();
	}

double Warehouse::getStorageCapacity() {
    return storageCapacity; // Return the maximum storage capacity of the warehouse
}

std::string Warehouse::getBuildingType() {
    return "Warehouse";
}

double Warehouse::getCost() {
    return 90000000; // Warehouse-specific cost in ZAR
}

double Warehouse::getMaintenanceCost() {
    const double maintenanceRate = 0.03; // 3% of the total cost
    return getCost() * maintenanceRate;
}

double Warehouse::getEnergyConsumption() {
    // Assuming each employee requires 400 kWh for warehouse operations per month
    const double energyPerEmployee = 400.0;
    return energyPerEmployee * getNumWorkers();
}

double Warehouse::getWaterConsumption() {
    // Assuming each employee uses 1500 liters of water per month
    const double waterPerEmployee = 1500.0;
    return waterPerEmployee * getNumWorkers();
}

void Warehouse::construct() {
    std::cout << "Warehouse is under construction." << std::endl;
    // Custom logic for initializing or setting up a new warehouse, if necessary
}

void Warehouse::demolish() {
    // Reset attributes to represent the demolition of the warehouse
    std::cout << "Warehouse is being demolished." << std::endl;
    this->storageCapacity = 0;
    this->numWorkers = 0;
}

void Warehouse::upgrade(BuildingComponent* building) {
    // Simulating an upgrade by increasing storage capacity by 25%
    std::cout << "Upgrading warehouse storage capacity." << std::endl;
    this->storageCapacity *= 1.25;
}

double Warehouse::getArea() {
    // Calculate area, assuming a fixed square meter size per employee
    return getX() * getY();
}
