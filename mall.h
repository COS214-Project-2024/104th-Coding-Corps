#ifndef MALL_H
#define MALL_H

class mall : CommercialBuildings {

public:
	int numShops;

	int getNumShops();

	string getBuildingType();

	double getCost();

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
