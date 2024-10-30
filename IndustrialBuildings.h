#ifndef INDUSTRIALBUILDINGS_H
#define INDUSTRIALBUILDINGS_H

#include "BuildingComponent.h"
#include <string>

using namespace std;

class IndustrialBuildings : public BuildingComponent {

protected:
	double productionCapacity;
	int numWorkers;

public:
	IndustrialBuildings(double production, int workers){
		this->productionCapacity = production;
		this->numWorkers = workers;
	}
	
	virtual string getBuildingType() = 0;

	virtual int getOccupancy() = 0;

	virtual double getCost() = 0;

	virtual double getMaintenanceCost() = 0;

	virtual double getEnergyConsumption() = 0;

	virtual double getWaterConsumption() = 0;

	virtual void demolish() = 0;

	virtual void upgrade(BuildingComponent* building) = 0;

	virtual double getArea() = 0;

	virtual double getProduction(){
		return productionCapacity;
	}

	int getNumWorkers() {
		return numWorkers;
	}
};

#endif
