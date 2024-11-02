#ifndef OFFICE_H
#define OFFICE_H

#include "CommercialBuildings.h"
#include "string"
using namespace std;
class Office : public CommercialBuildings {

public:
	Office(int numEmployees, string businessType, int x, int y, const std::string& district, int quality);

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

	int getOccupancy();
	
	void upgrade(std::shared_ptr<BuildingComponent> building);
};

#endif
