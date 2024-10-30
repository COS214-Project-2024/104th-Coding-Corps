#include "Flat.h"
#include <stdexcept>

Flat::Flat(int units, int residents, int floors, bool hasGarden) : ResidentialBuildings(residents, floors, hasGarden) {
	this->numUnits = units;
}
int Flat::getNumUnits() {
	return this->numUnits;
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

int Flat::getNumFloors() {
	const int unitsPerFloor = 4;
	return (this->numUnits + unitsPerFloor - 1) / unitsPerFloor; // Round up
}

bool Flat::hasGarden() {
	return false;
}

double Flat::getArea() {
	return getX() * getY()* this->numUnits;
}

int Flat::getOccupancy(){
	return 200;
}

void Flat::upgrade(BuildingComponent* building){
	//implement
}