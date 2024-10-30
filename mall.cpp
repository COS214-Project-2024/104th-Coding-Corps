#include "mall.h"
#include <iostream>

Mall::Mall(int numShops, std::string businessType, int numBusinesses)
    : CommercialBuildings(businessType, numBusinesses), numShops(numShops) {
		this->construct();
	}

int Mall::getNumShops() {
    return this->numShops;
}

std::string Mall::getBuildingType() {
    return "Mall";
}

std::string Mall::getName() {
    return "Mall";
}

double Mall::getCost() {
    const double costPerShop = 5000000.0; // 5 million per shop
    return numShops * costPerShop;
}

double Mall::getMaintenanceCost() {
    const double maintenanceRate = 0.03; // 3% of the cost per month
    return getCost() * maintenanceRate;
}

double Mall::getEnergyConsumption() {
    // Assuming each square meter of the mall uses 400 kWh of energy per month
    const double energyPerSquareMeter = 400.0;
    return energyPerSquareMeter * getArea();
}

double Mall::getWaterConsumption() {
    // Assuming each square meter of the mall uses 150 liters of water per month
    const double waterPerSquareMeter = 150.0;
    return waterPerSquareMeter * getArea();
}

void Mall::construct() {
    std::cout << "Constructing a new mall with " << numShops << " shops " << std::endl;
    // Additional setup logic if needed
}

void Mall::demolish() {
    std::cout << "The mall is being demolished." << std::endl;
    numShops = 0;       // Reset the number of shops to represent demolition
}

double Mall::getArea() {
	return getX() * getY();
}

void Mall::upgrade(BuildingComponent* building) {
    std::cout << "not yet implemented";
}

int Mall::getOccupancy() {
    return 0;
}
