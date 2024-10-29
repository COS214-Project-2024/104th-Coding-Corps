#ifndef BUILDINGCOMPONENT_H
#define BUILDINGCOMPONENT_H

#include "vector"
#include "Utilities.h"
class BuildingComponent {

private:
	string type;
	double cost;
	int occupancy;
	double maintainanceCost;
	double energyConsumption;
	double waterConsumption;
	double area;
	int x;
	int y;

protected:
	vector<Utilities*> utilities;
	
public:
	virtual string getBuildingType() = 0;

	virtual int getOccupancy() = 0;

	virtual double getCost() = 0;

	virtual double getMaintenanceCost() = 0;

	virtual double getEnergyConsumption() = 0;

	virtual double getWaterConsumption() = 0;

	virtual void construct() = 0;

	virtual void demolish() = 0;

	virtual void upgrade(BuildingComponent* building) = 0;

	virtual double getArea() = 0;

	int getX();

	int getY();
};

#endif
