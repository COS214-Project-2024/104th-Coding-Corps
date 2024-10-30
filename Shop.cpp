#include "Shop.h"
#include <iostream>

Shop::Shop(int shopSize, std::string businessType, int x, int y, const std::string& district, int quality)
    : CommercialBuildings(businessType, 1, x, y, district, quality), shopSize(shopSize) {
		this->construct();
	}

double Shop::getCost() {
    return 2000000; // Base cost in ZAR
}

std::string Shop::getBuildingType() {
    return "Shop";
}

double Shop::getMaintenanceCost() {
    const double maintenanceRate = 0.02; // 2% of the shop’s cost per month
    return getCost() * maintenanceRate;
}

double Shop::getEnergyConsumption() {
    // Assuming the shop uses 300 kWh per square meter per month
    const double energyPerSquareMeter = 300.0;
    return energyPerSquareMeter * getArea();
}

double Shop::getWaterConsumption() {
    // Assuming the shop uses 100 liters of water per square meter per month
    const double waterPerSquareMeter = 100.0;
    return waterPerSquareMeter * getArea();
}

void Shop::construct() {
    std::cout << "Constructing a new shop with a size of " << shopSize << " square meters." << std::endl;
}

void Shop::demolish() {
    std::cout << "The shop is being demolished." << std::endl;
    shopSize = 0; // Resetting shop size to represent demolition
}

double Shop::getArea() {
    return static_cast<double>(shopSize); // Returns the area based on `shopSize`
}

int Shop::getOccupancy(){
	return 1;
}

void Shop::upgrade(BuildingComponent* building){
	//implement
}