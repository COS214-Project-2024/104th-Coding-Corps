#ifndef FACTORY_H
#define FACTORY_H

class Factory : IndustrialBuildings {

public:
	string factoryType;

	string getFactoryTyoe();

	void produceGoods();

	string getBuildingType();

	int getOccupancy();

	double getCost();

	double getMaintenanceCost();

	double getEnergyConsumption();

	double getWaterConsumption();

	void construct();

	void demolish();

	void upgrade(BuildingComponent* building);

	double getArea();
};

#endif
