#ifndef ESTATE_H
#define ESTATE_H

#include <iostream>
#include <string>
#include "ResidentialBuildings.h"
using namespace std;

class Estate : public ResidentialBuildings {

private:
	int garageSize, numUnits;
	bool pool;

public:
	Estate(int garageSize, bool hasPool, int residents, int floors, bool hasGarden, int units);

	int getGarageSize();

	bool hasSwimmingPool();

    std::string getName() override {
        return "Estate";
    }

	string getBuildingType();

	double getCost();

	double getMaintenanceCost();

	double getEnergyConsumption();

	double getWaterConsumption();

	void construct();

	void demolish();

	int getNumResidents();

	int getNumFloors();

	bool hasGarden();

	double getArea();
	
	int getOccupancy() override;

	void upgrade(BuildingComponent* building) override;
};

#endif
