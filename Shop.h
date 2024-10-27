#ifndef SHOP_H
#define SHOP_H

#include "CommercialBuildings.h"

class Shop : public CommercialBuildings {

private:
	int shopSize;
public:
	Shop(int shopSize, string businessType, int numBusinesses);

	double getCost();

	string getBuildingType();

	double getMaintenanceCost();

	double getEnergyConsumption();

	double getWaterConsumption();

	void construct();

	void demolish();

	string getBusinessType();

	int getNumBusinesses();

	double getArea();

	void upgrade(BuildingComponent* building);

	int getOccupancy();
};

#endif
