#include "House.h"
#include <stdexcept>

House::House(int x, int y, const std::string& district, int quality, int garageSize, bool hasPool, int residents, int floors, bool hasGarden)
    : ResidentialBuildings(x, y, district, quality, residents, floors, hasGarden), garageSize(garageSize), pool(hasPool) {}

int House::getGarageSize() const {
    return garageSize;
}

bool House::hasSwimmingPool() const {
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
    auto government = Government::getInstance();
    
    // Example resource requirements for upgrading
    const int requiredConcrete = 50;
    const int requiredSteel = 30;

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