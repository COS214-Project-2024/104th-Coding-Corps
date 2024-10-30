#ifndef SEWAGEMANAGEMENT_H
#define SEWAGEMANAGEMENT_H

#include "BuildingComponent.h"
#include "string"
using namespace std;

class SewageManagement : public Utilities {


public:
	SewageManagement();

	double getConsumptionRate();

	double getCost();

	void activateUtility();

	void deactivateUtility();

	void manageSewage(BuildingComponent* building);
};

#endif
