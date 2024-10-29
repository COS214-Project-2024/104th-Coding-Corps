#ifndef MALL_H
#define MALL_H

#include "CommercialBuildings.h"
#include "string"
using namespace std;

class Mall : public CommercialBuildings {

private:
	int numShops;
public:
	Mall(int numShops, string businessType, int numBusinesses);

	int getNumShops();

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
