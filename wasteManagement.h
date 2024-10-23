#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

class wasteManagement : Utilities {


public:
	string getUtilityType();

	double getConsumptionRate();

	double getCost();

	void activateUtility();

	void deactivateUtility();

	void processWaste(BuilidingComponent* building);
};

#endif
