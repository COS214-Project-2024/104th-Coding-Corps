#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "BuildingComponent.h"
#include "string"
using namespace std;

class PowerPlant : public Utilities {

public:
	string getUtilityType();

	double getConsumptionRate();

	double getCost();

	void activateUtility();

	void deactivateUtility();

	void generateEnergy(BuildingComponent* building);
};

#endif
