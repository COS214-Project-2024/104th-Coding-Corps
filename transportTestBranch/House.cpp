#include "House.h"
#include "ResidentialBuildings.h"
#include <stdexcept>
#include <iostream>

House::House(int garageSize, bool hasPool, int x, int y, const std::string& district, int quality, int residents, int floors, bool hasGarden)
    : ResidentialBuildings(x, y, district, quality, residents, floors, hasGarden) {
    this->garageSize = garageSize;
    this->pool = hasPool;
}

int House::getGarageSize() {
	return this->garageSize;
}

bool House::hasSwimmingPool() {
	return pool;
}

std::string House::getBuildingType() {
	return "House";
}

double House::getCost() {
	// Assuming a base cost for a standard house
	return 2750000.00;
}

double House::getMaintenanceCost() {
	// Maintenance cost, adjusted based on factors like pool maintenance
	double baseMaintenance = 5000.0;
	if (pool) {
		baseMaintenance += 2000.0; // Additional cost for pool maintenance
	}
	return baseMaintenance;
}

double House::getEnergyConsumption() {
	// Assuming each house consumes 400 kWh per month
	const double energyPerHouse = 400.0;
	return energyPerHouse;
}

double House::getWaterConsumption() {
	// Assuming each house uses 5000 liters of water per month
	const double waterPerHouse = 5000.0;
	return waterPerHouse;
}

void House::demolish() {
	// Reset attributes to default, simulating demolition
	this->numResidents = 0;
	this->numFloors = 0;
	pool = false;
	this->garageSize = 0;
}

int House::getNumResidents() {
	// Assuming each house accommodates an average of 4 residents
	return 4;
}

int House::getNumFloors() {
	return 2;
}

bool House::hasGarden() {
	// Assuming all houses have a garden
	return true;
}

double House::getArea() {
	// Calculate area assuming X by Y dimensions and a constant multiplier for garage size
	const double houseBaseArea = getX() * getY();
	const double garageAreaFactor = 30.0; // Garage area for each car space
	return houseBaseArea + (garageAreaFactor * this->garageSize);
}

int House::getOccupancy(){
	return 10;
}

void House::upgrade(std::shared_ptr<BuildingComponent> building) {
    std::cout << "House has been upgraded" << std::endl;
  
}