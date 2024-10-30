#include "Estate.h"
#include <stdexcept>

Estate::Estate(int x, int y, const std::string& district, int quality, int garageSize, bool hasPool, int residents, int floors, bool hasGarden, int units)
    : ResidentialBuildings(x, y, district, quality, residents, floors, hasGarden), garageSize(garageSize), numUnits(units), pool(hasPool) {}

int Estate::getGarageSize() const {
    return garageSize;
}

bool Estate::hasSwimmingPool() const {
    return pool;
}


std::string Estate::getBuildingType() {
	return "Estate";
}

double Estate::getCost() {
	// Assuming each unit in the estate has a base cost
	const double unitCost = 3000000.0;
	return unitCost * this->numUnits;
}

double Estate::getMaintenanceCost() {
	// Maintenance cost based on the number of units and pool maintenance if applicable
	double baseMaintenance = 8000.0 * this->numUnits;
	if (pool) {
		baseMaintenance += 5000.0; // Additional maintenance for pool
	}
	return baseMaintenance;
}

double Estate::getEnergyConsumption() {
	// Assuming each unit consumes 500 kWh per month
	const double energyPerUnit = 500.0;
	return energyPerUnit * this->numUnits;
}

double Estate::getWaterConsumption() {
	// Assuming each unit uses 7000 liters of water per month
	const double waterPerUnit = 7000.0;
	return waterPerUnit * this->numUnits;
}

void Estate::construct() {
	// Code to initialize or prepare the estate's construction
	this->numResidents = 4 * this->numUnits; // Assuming 4 residents per unit
	this->numFloors = 2; // Assuming most estates are 2 floors high
}

void Estate::demolish() {
	// Reset attributes to simulate demolition
	this->numResidents = 0;
	this->numFloors = 0;
	this->pool = false;
	this->garageSize = 0;
	this->numUnits = 0;
}

int Estate::getNumResidents() {
	// Assuming each unit houses 4 residents
	return 4 * this->numUnits;
}




double Estate::getArea() {
	// Calculate the area of the estate, accounting for all units and garage size
	const double unitArea = getX() * getY();
	const double garageAreaFactor = 40.0; // Garage area for each car space
	return (unitArea * this->numUnits) + (garageAreaFactor * this->garageSize);
}

int Estate::getOccupancy() {
    return numUnits;
}


void Estate::upgrade(std::shared_ptr<BuildingComponent> building) {
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