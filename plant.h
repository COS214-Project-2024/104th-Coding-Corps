#ifndef PLANT_H
#define PLANT_H

#include "IndustrialBuildings.h"

class plant : public IndustrialBuildings {

public:
	plant(int numShops, string businessType, int numBusinesses);

	int electricityUnits;

	void generateElectricity(BuildingComponent* building);

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
