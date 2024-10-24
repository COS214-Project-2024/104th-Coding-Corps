#ifndef FLAT_H
#define FLAT_H

class Flat : ResidentialBuildings {

public:
	int numUnits;

	int getNumUnits();

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
