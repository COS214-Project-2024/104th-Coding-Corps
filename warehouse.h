#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "IndustrialBuildings.h"

class Warehouse : public IndustrialBuildings {

public:
	Warehouse(int shopSize, string businessType, int numBusinesses);
	
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
			
	double getProduction() override;

	int getNumWorkers() override;

	void upgrade(BuildingComponent* building);

	int getOccupancy();
};

#endif
