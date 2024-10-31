#include "mall.h"
#include <iostream>

Mall::Mall(int numShops, std::string businessType, int numBusinesses, int x, int y, const std::string& district, int quality)
    : CommercialBuildings(x, y, district, quality, businessType, numBusinesses), numShops(numShops) {
		this->construct();
	}

int Mall::getNumShops() {
    return this->numShops;
}

std::string Mall::getBuildingType() {
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

int Mall::getOccupancy(){
	return 100;
}

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
        std::cout << "Estate upgraded successfully!" << std::endl;
    } else {
        std::cout << "Upgrade failed due to insufficient resources." << std::endl;
    }
}
