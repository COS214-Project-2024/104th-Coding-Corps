#ifndef INDUSTRIALBUILDINGS_H
#define INDUSTRIALBUILDINGS_H

#include "BuildingComponent.h"

class IndustrialBuildings : public BuildingComponent {

private:
	double productionCapacity;
	int numWorkers;

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

	virtual double getProduction() = 0;

	virtual int getNumWorkers() = 0;
};

#endif
