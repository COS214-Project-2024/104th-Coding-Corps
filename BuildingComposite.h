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
	BuildingComposite();
	
	void addBuilding(BuildingComponent* building) override;

	void removeBuilding(BuildingComponent* building) override;

	BuildingComponent* getBuilding(int index) override;

	double getCost() override;

	double getMaintenanceCost() override;

	double getEnergyConsumption() override;

	double getWaterConsumption() override;

	void enforcePolicy(string policy) override;
};

#endif
