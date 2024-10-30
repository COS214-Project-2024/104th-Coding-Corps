#include "ResidentialBuildings.h"

ResidentialBuildings::ResidentialBuildings(int residents, int floors, bool garden){
	this->numResidents = residents;
	this->numFloors = floors;
	this->garden = garden;
}

int ResidentialBuildings::getNumResidents() {
	return this->numResidents;
}

int ResidentialBuildings::getNumFloors() {
	return this->numFloors;
}

bool ResidentialBuildings::hasGarden() {
	if(garden) {
		return true;
	} else {
		return false;
	}
}
