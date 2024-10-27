#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "Utilities.h"
#include "BuildingComponent.h"
#include "string"
using namespace std;

class wasteManagement : public Utilities {


public:
	string getUtilityType();

	double getConsumptionRate();

	double getCost();

	void activateUtility();

	void deactivateUtility();

	void processWaste(BuilidingComponent* building);
};

#endif
