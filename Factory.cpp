#include "Factory.h"
#include <iostream>

#include "Factory.h"
#include <iostream>

Factory::Factory(int numWorkers, string factoryType, double production)
    : IndustrialBuildings(production, numWorkers), factoryType(factoryType) {}

std::string Factory::getFactoryType() {
	return factoryType;
}

void Factory::produceGoods() {
    const double goodsPerEmployee = 10.0; // Units per employee per cycle
    double totalGoodsProduced = goodsPerEmployee * getOccupancy();
    
    std::string productType = getFactoryType();
    std::cout << "Factory (" << productType << ") produced " << totalGoodsProduced << " units of goods this cycle." << std::endl;
}

std::string Factory::getBuildingType() {
    return "Factory";
}

int Factory::getOccupancy() {
    return 150;
}

double Factory::getCost() {
    return 150000000;  // Cost in ZAR
}

double Factory::getMaintenanceCost() {
    const double maintenanceRate = 0.05; // 5% of the cost
    return getCost() * maintenanceRate;
}

double Factory::getEnergyConsumption() {
    // Assuming each employee consumes 500 kWh of energy per month
    const double energyPerEmployee = 500.0;
    return energyPerEmployee * getOccupancy();
}

double Factory::getWaterConsumption() {
    // Assuming each employee uses 2000 liters of water per month
    const double waterPerEmployee = 2000.0;
    return waterPerEmployee * getOccupancy();
}

void Factory::demolish() {
    // Demolishing the factory, reset attributes to defaults
    std::cout << "Factory is being demolished." << std::endl;
    this->factoryType = "";
	this->numWorkers = 0;
	this->productionCapacity = 0;
}

void Factory::upgrade(BuildingComponent* building) {
    // Simulating the upgrade by increasing occupancy
    std::cout << "Upgrading the factory capacity." << std::endl;
    this->factoryType += " (Upgraded)";
}

double Factory::getArea() {
	return getX() * getY();
}

void Factory::construct() {
    std::cout << "not yet implemented";
}