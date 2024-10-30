#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "Utilities.h"
#include "BuildingComponent.h"
#include "string"
using namespace std;

class WasteManagement : public Utilities {


public:
	WasteManagement();
	
	double getConsumptionRate();

	double getCost();

	void activateUtility();

	void deactivateUtility();

	void processWaste(BuildingComponent* building);

};

#endif
