#ifndef OFFICE_H
#define OFFICE_H

#include "CommercialBuildings.h"

class Office : public CommercialBuildings {

public:
	Office(int numEmployees, string businessType, int numBusinesses);

	int numEmployees;

	int getNumEmployees();

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

	void upgrade(BuildingComponent* building);

	int getOccupancy();
};

#endif
