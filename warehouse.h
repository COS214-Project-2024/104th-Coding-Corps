#ifndef WAREHOUSE_H
#define WAREHOUSE_H

class WareHouse : IndustrialBuildings {

public:
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
};

#endif
