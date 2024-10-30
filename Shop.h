#ifndef SHOP_H
#define SHOP_H

#include "CommercialBuildings.h"
#include "string"
using namespace std;

class Shop : public CommercialBuildings {

private:
	int shopSize;
public:
	Shop(int shopSize, string businessType);

	double getCost();

	string getBuildingType();

	std::string getName();

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
