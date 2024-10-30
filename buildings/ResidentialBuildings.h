#ifndef RESIDENTIALBUILDINGS_H
#define RESIDENTIALBUILDINGS_H

#include "BuildingComponent.h"
#include <string>
using namespace std;

class ResidentialBuildings : public BuildingComponent {

protected:
	int numResidents;
	int numFloors;
	bool garden;

public:
	ResidentialBuildings(int residents, int floors, bool hasGarden);

	virtual string getBuildingType() = 0;

	virtual int getOccupancy() = 0;

	virtual double getCost() = 0;

	virtual double getMaintenanceCost() = 0;

	virtual double getEnergyConsumption() = 0;

	virtual double getWaterConsumption() = 0;

	virtual void demolish() = 0;

	virtual void upgrade(BuildingComponent* building) = 0;

	int getNumResidents();

	int getNumFloors();

	bool hasGarden();
};

#endif
