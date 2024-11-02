#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "BuildingComponent.h"
#include <string>
using namespace std;

class PowerPlant : public Utilities {
private:
	std::string type = "Power Plant";
public:
	PowerPlant();
	
	string getUtilityType() {return this->type;};

	double getConsumptionRate();

	double getCost();

	void activateUtility();

	void deactivateUtility();

	void generateEnergy(std::shared_ptr<BuildingComponent> building);
};

#endif
