#ifndef HOUSE_H
#define HOUSE_H
#include <iostream>

#include "ResidentialBuildings.h"
class House : public ResidentialBuildings {

private:
	int garageSize;
	bool pool;

public:
	House(int garageSize, bool hasPool, int residents, int floors, bool hasGarden);

	int getGarageSize();

	bool hasSwimmingPool();

	string getBuildingType();

    std::string getName() override {
        return "House";
    }

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