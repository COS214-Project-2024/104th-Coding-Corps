#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "IndustrialBuildings.h"

class Warehouse : public IndustrialBuildings {

private:
	int storageCapacity;

public:
	Warehouse(int storageCapacity, int numWorkers);
	
	int storageCapacity;

	double getStorageCapacity();

	string getBuildingType();

	double getCost();

	double getMaintenanceCost();

	double getEnergyConsumption();

	double getWaterConsumption();

	void construct();

	void demolish();

	double getArea();

	void upgrade(BuildingComponent* building);

	int getOccupancy();
};

#endif
