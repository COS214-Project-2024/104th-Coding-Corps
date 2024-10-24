#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

class WaterSupply : Utilities {


public:
	string getUtilityType();

	double getConsumptionRate();

	double getCost();

	void activateUtility();

	void deactivateUtility();

	void distributeWater(BuildingComponent* building);
};

#endif
