#ifndef HOUSE_H
#define HOUSE_H

class House : ResidentialBuildings {

private:
	int garageSize;
	bool hasSwimmingPool;

public:
	int getGarageSize();

	bool hasSwimmingPool();

	string getBuildingType();

	double getCost();

	double getMaintenanceCost();

	double getEnergyConsumption();

	double getWaterConsumption();

	void construct();

	void demolish();

	int getNumResidents();

	int getNumFloors();

	bool hasGarden();

	double getArea();
};

#endif
