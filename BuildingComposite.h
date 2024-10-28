#ifndef BUILDINGCOMPOSITE_H
#define BUILDINGCOMPOSITE_H

class BuildingComposite : BuildingComponent {

private:
	vector<BuildingComponent*> buildings;
	vector<Utilities*> utilities;
	map<string> policies;

public:
	virtual void addBuilding(BuildingComponent* building) = 0;

	virtual void removeBuilding(BuildingComponent* building) = 0;

	virtual BuildingComponent* getBuilding(int index) = 0;

	virtual double calculateTotalCost() = 0;

	virtual double calculateTotalEnergyConsumption() = 0;

	virtual double calculateTotalWaterConsumption() = 0;
};

#endif
