#ifndef FACTORY_H
#define FACTORY_H

#include "IndustrialBuildings.h"
#include <string>
using namespace std;

class Factory : public IndustrialBuildings {

public:
	Factory(int numEmployees, string businessType, int numBusinesses);

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

	void upgrade(BuildingComponent* building) override;

	double getArea();
	
	double getProduction() override;

	int getNumWorkers() override;
};

#endif
