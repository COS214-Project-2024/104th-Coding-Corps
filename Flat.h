#ifndef FLAT_H
#define FLAT_H
#include <iostream>

#include "ResidentialBuildings.h"

class Flat : public ResidentialBuildings {

private:
	int numUnits;
public:
	Flat(int units, int residents, int floors, bool hasGarden);

	int getNumUnits();

	string getBuildingType();

    std::string getName() override {
        return "Flat";
    }

	double getCost();

	double getMaintenanceCost();

	double getEnergyConsumption();

	double getWaterConsumption();

	void demolish();

	void construct();

	int getNumResidents();

	int getNumFloors();

	bool hasGarden();

	double getArea();

	int getOccupancy() override;

	void upgrade(BuildingComponent* building) override;
};

#endif
