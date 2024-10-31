#ifndef SHOP_H
#define SHOP_H

#include "CommercialBuildings.h"
#include "string"
using namespace std;

class Shop : public CommercialBuildings {

private:
	int shopSize;
public:
	Shop(int shopSize, string businessType, int x, int y, const std::string& district, int quality);

	double getCost();

	string getBuildingType();

	double getMaintenanceCost();

	double getEnergyConsumption();

	double getWaterConsumption();

	void construct();

	void demolish();

	double getArea();

	void upgrade(std::shared_ptr<BuildingComponent> building);

	int getOccupancy();
};

#endif
