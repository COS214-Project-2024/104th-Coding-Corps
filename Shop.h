#ifndef SHOP_H
#define SHOP_H

class Shop : CommercialBuildings {

public:
	int shopSize;

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
};

#endif
