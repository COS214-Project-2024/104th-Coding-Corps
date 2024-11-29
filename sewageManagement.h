#ifndef SEWAGEMANAGEMENT_H
#define SEWAGEMANAGEMENT_H

class sewageManagement : Utilities {


public:
	string getUtilityType();

	double getConsumptionRate();

	double getCost();

	void activateUtility();

	void deactivateUtility();

	void manageSewage(BuildingComponent* building);
};

#endif
