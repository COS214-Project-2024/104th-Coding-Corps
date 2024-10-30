#include "Flat.h"
#include <stdexcept>

// Constructor calls base constructor
Flat::Flat(int x, int y, const std::string& district, int quality, int units, int residents, int floors, bool hasGarden)
    : ResidentialBuildings(x, y, district, quality, residents, floors, hasGarden), numUnits(units) {}

int Flat::getNumUnits() const {
    return numUnits;
}

std::string Flat::getBuildingType() {
	return "Flat";
}

double Flat::getCost() {
	return 1595000.00;
}

double Flat::getMaintenanceCost() {
	return 10000.00;
}

double Flat::getEnergyConsumption() {
	// Assuming each unit consumes 300 kWh per month
	const double energyPerUnit = 300.0;
	return energyPerUnit * this->numUnits;
}

double Flat::getWaterConsumption() {
	// Assuming each unit uses 2500 liters of water per month
	const double waterPerUnit = 2500.0;
	return waterPerUnit * this->numUnits;
}

void Flat::demolish() {
	// Code to handle demolition of the flat, such as resetting attributes
	this->numResidents = 0;
	this->numFloors = 0;
}

int Flat::getNumResidents() {
	// Return total residents assuming each unit has 3 residents
	return this->numUnits * 3;
}



double Flat::getArea() {
	return getX() * getY()* this->numUnits;
}

int Flat::getOccupancy() {
    return numUnits;
}

void Flat::upgrade(std::shared_ptr<BuildingComponent> building) {
    auto government = Government::getInstance();
    
    // Example resource requirements for upgrading
    const int requiredConcrete = 200;
    const int requiredSteel = 100;

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