#ifndef BUILDINGCOMPOSITE_H
#define BUILDINGCOMPOSITE_H

#include "BuildingComponent.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class BuildingComposite : public BuildingComponent {

private:
	vector<BuildingComponent*> buildings;
	vector<Utilities*> utilities;
	map<string,string> policies;

public:
	virtual void addBuilding(BuildingComponent* building);

	virtual void removeBuilding(BuildingComponent* building);

	virtual BuildingComponent* getBuilding(int index);

	virtual double calculateTotalCost();

	virtual double calculateTotalEnergyConsumption();

	virtual double calculateTotalWaterConsumption();

	void enforcePolicy(string policy) override;
};

#endif
