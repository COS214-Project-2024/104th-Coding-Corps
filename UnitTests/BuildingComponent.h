#ifndef BUILDINGCOMPONENT_H
#define BUILDINGCOMPONENT_H

#include <vector>
#include <string>
#include <memory>
#include "Utilities.h"
#include "Government.h"

class BuildingComponent {

private:
	int x;
	int y;
	string district;
	

protected:
    int quality;
	std::vector<std::shared_ptr<Utilities>> utilities;
	
public:
    BuildingComponent(int x, int y, const std::string& district, int quality);

	//virtual void addBuilding(shared_ptr<BuildingComponent> building);

	//virtual void removeBuilding(shared_ptr<BuildingComponent> building);

	//virtual shared_ptr<BuildingComponent> getBuilding(int index);

	virtual string getBuildingType() = 0;

	virtual int getOccupancy() = 0;

	virtual double getCost() = 0;

	virtual double getMaintenanceCost() = 0;

	virtual double getEnergyConsumption() = 0;

	virtual double getWaterConsumption() = 0;

	virtual void demolish() = 0;

	virtual void upgrade(std::shared_ptr<BuildingComponent> building) = 0;

	virtual double getArea() = 0;

	int getX();

	int getY();

	string getDistrict();

	//virtual void enforcePolicy(const std::string& policyKey, const std::string& newValue);

	int getQuality();	//measured on a 0 to 100 scale
	virtual ~BuildingComponent() = default;
};

#endif