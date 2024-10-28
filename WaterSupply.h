#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Utilities.h"
#include "string"
#include "BuildingComponent.h"

using namespace std;

class WaterSupply : public Utilities {


public:
	WaterSupply();
	
	double getConsumptionRate();

	double getCost();

	void activateUtility();

	void deactivateUtility();

	void distributeWater(BuildingComponent* building);
};

#endif
