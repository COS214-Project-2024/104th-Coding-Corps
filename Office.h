#ifndef OFFICE_H
#define OFFICE_H

#include "CommercialBuildings.h"
#include "string"
using namespace std;
class Office : public CommercialBuildings {

public:
	Office(int numEmployees, string businessType);

	int numEmployees;

	int getNumEmployees();

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
