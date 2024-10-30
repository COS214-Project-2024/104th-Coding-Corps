#ifndef BUILDINGCOMPOSITE_H
#define BUILDINGCOMPOSITE_H
#include "BuildingComponent.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>


class BuildingComposite : BuildingComponent {

private:
	vector<BuildingComponent*> buildings;
	vector<Utilities*> utilities;
	map<string, string> policies;

public:
	virtual void addBuilding(BuildingComponent* building) = 0;

	virtual void removeBuilding(BuildingComponent* building) = 0;

	virtual BuildingComponent* getBuilding(int index) = 0;

	virtual double calculateTotalCost() = 0;

	virtual double calculateTotalEnergyConsumption() = 0;

	virtual double calculateTotalWaterConsumption() = 0;

	void enforcePolicy(std::string policyType) {
		std::cout << "somethin";
	};
};

#endif
