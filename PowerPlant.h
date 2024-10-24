#ifndef POWERPLANT_H
#define POWERPLANT_H

class PowerPlant : Utilities {


public:
	string getUtilityType();

	double getConsumptionRate();

	double getCost();

	void activateUtility();

	void deactivateUtility();

	void generateEnergy(BuildingComponent* building);
};

#endif
